#!/usr/bin/env bash
# Build Linux Image + BusyBox initramfs + board.dtb for Retro Studio RV64.
# Run inside WSL from the repo root:
#   bash tools/riscv64-linux/build_linux_busybox.sh
#
# Artifacts → rom/riscv64/{Image,board.dtb}
# Build tree → ~/retro-rv64-linux (override with LINUX_BUILD=)
set -euo pipefail
# Normalize CRLF if the scripts were edited on Windows (/mnt/c).
if [[ "$(uname -s)" == Linux ]]; then
  sed -i 's/\r$//' "$(dirname "$0")"/*.sh "$(dirname "$0")"/rootfs_skel/init 2>/dev/null || true
fi

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
OUT="$ROOT/rom/riscv64"
BUILD="${LINUX_BUILD:-$HOME/retro-rv64-linux}"
LINUX_DIR="$BUILD/linux"
BUSYBOX_DIR="$BUILD/busybox"
ROOTFS="$BUILD/rootfs"
INITRAMFS_CPIO="$BUILD/initramfs.cpio"

LINUX_VER="${LINUX_VER:-v6.6.63}"
BUSYBOX_VER="${BUSYBOX_VER:-1_36_1}"

# Kernel: Ubuntu cross GCC (freestanding). BusyBox: Bootlin musl lp64 (no hard-float).
KCROSS="${KCROSS:-riscv64-linux-gnu-}"
MARCH="rv64ima_zicsr_zifencei"
ABI="lp64"
JOBS="${JOBS:-$(nproc)}"

mkdir -p "$OUT" "$BUILD"

echo "==> packages (sudo)"
sudo apt-get update -qq
sudo DEBIAN_FRONTEND=noninteractive apt-get install -y -qq \
  build-essential git python3 flex bison libssl-dev libelf-dev bc \
  device-tree-compiler cpio gzip rsync curl ca-certificates \
  gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu

if ! command -v ${KCROSS}gcc >/dev/null; then
  echo "missing ${KCROSS}gcc" >&2
  exit 1
fi

echo "==> fetch musl soft-float toolchain (BusyBox)"
bash "$SCRIPT_DIR/fetch_musl_toolchain.sh"
BOOTLIN_NAME="${BOOTLIN_NAME:-riscv64--musl--bleeding-edge-2020.08-1}"
MUSL_PREFIX="${MUSL_PREFIX:-$HOME/retro-rv64-linux/toolchain/${BOOTLIN_NAME}}"
BCROSS="$MUSL_PREFIX/bin/riscv64-linux-"
if [[ ! -x "${BCROSS}gcc" ]]; then
  echo "missing musl gcc at ${BCROSS}gcc" >&2
  exit 1
fi

echo "==> kernel toolchain: $(${KCROSS}gcc --version | head -1)"
echo "==> busybox toolchain: $(${BCROSS}gcc --version | head -1)"
echo "==> build dir: $BUILD"

# ---------------------------------------------------------------------------
# BusyBox (static)
# ---------------------------------------------------------------------------
if [[ ! -d "$BUSYBOX_DIR/.git" ]]; then
  echo "==> clone BusyBox $BUSYBOX_VER"
  rm -rf "$BUSYBOX_DIR"
  git clone --depth 1 --branch "$BUSYBOX_VER" \
    https://git.busybox.net/busybox "$BUSYBOX_DIR" \
    || git clone --depth 1 --branch "$BUSYBOX_VER" \
         https://github.com/mirror/busybox.git "$BUSYBOX_DIR"
else
  echo "==> BusyBox already at $BUSYBOX_DIR"
  git -C "$BUSYBOX_DIR" fetch --depth 1 origin "refs/tags/$BUSYBOX_VER:refs/tags/$BUSYBOX_VER" 2>/dev/null || true
  git -C "$BUSYBOX_DIR" checkout -f "$BUSYBOX_VER" 2>/dev/null \
    || git -C "$BUSYBOX_DIR" checkout -f "tags/$BUSYBOX_VER" 2>/dev/null \
    || true
fi

echo "==> configure BusyBox (static, $MARCH)"
make -C "$BUSYBOX_DIR" distclean >/dev/null 2>&1 || true
make -C "$BUSYBOX_DIR" defconfig
# BusyBox has no scripts/config — edit .config directly.
BBCFG="$BUSYBOX_DIR/.config"
bb_y() {
  sed -i -E "s/^# CONFIG_$1 is not set$/CONFIG_$1=y/; s/^CONFIG_$1=.*/CONFIG_$1=y/" "$BBCFG"
  grep -q "^CONFIG_$1=y" "$BBCFG" || echo "CONFIG_$1=y" >> "$BBCFG"
}
bb_n() {
  sed -i -E "s/^CONFIG_$1=.*/# CONFIG_$1 is not set/" "$BBCFG"
  grep -qE "CONFIG_$1" "$BBCFG" || echo "# CONFIG_$1 is not set" >> "$BBCFG"
}
bb_y STATIC
bb_n FEATURE_MOUNT_NFS
bb_n FEATURE_INETD_RPC
bb_n PAM
grep -q '^CONFIG_STATIC=y' "$BBCFG" || { echo "CONFIG_STATIC not set" >&2; exit 1; }
echo "    CONFIG_STATIC=y OK"

# GCC 10 (Bootlin 2020.08) does not accept zicsr/zifencei in -march; they are implied by ima.
BB_MARCH="rv64ima"
echo "==> build BusyBox (static musl / $BB_MARCH / $ABI)"
make -C "$BUSYBOX_DIR" \
  CROSS_COMPILE="$BCROSS" \
  EXTRA_CFLAGS="-march=$BB_MARCH -mabi=$ABI -Os" \
  -j"$JOBS"

echo "==> assemble rootfs"
rm -rf "$ROOTFS"
mkdir -p "$ROOTFS"/{bin,sbin,usr/bin,usr/sbin,etc,proc,sys,dev,tmp,root}
make -C "$BUSYBOX_DIR" \
  CROSS_COMPILE="$BCROSS" \
  CONFIG_PREFIX="$ROOTFS" \
  install

# Overlay our init (rdinit=/init)
install -m 0755 "$SCRIPT_DIR/rootfs_skel/init" "$ROOTFS/init"
# BusyBox install may not create /bin/sh symlink on all versions
ln -sf busybox "$ROOTFS/bin/sh" 2>/dev/null || true
ln -sf busybox "$ROOTFS/bin/ash" 2>/dev/null || true

# Tiny /etc
cat > "$ROOTFS/etc/inittab" <<'EOF'
::sysinit:/bin/mount -t proc proc /proc
::sysinit:/bin/mount -t sysfs sysfs /sys
::sysinit:/bin/mount -t devtmpfs devtmpfs /dev
::respawn:-/bin/sh
EOF
cat > "$ROOTFS/etc/passwd" <<'EOF'
root:x:0:0:root:/root:/bin/sh
EOF
echo "root::0:0:99999:7:::" > "$ROOTFS/etc/shadow"

echo "==> pack initramfs (newc cpio, uncompressed — kernel will gzip if needed)"
(
  cd "$ROOTFS"
  # shellcheck disable=SC2035
  find . -print0 | cpio --null -ov -H newc > "$INITRAMFS_CPIO"
)

# ---------------------------------------------------------------------------
# Linux
# ---------------------------------------------------------------------------
if [[ ! -d "$LINUX_DIR/.git" ]]; then
  echo "==> clone Linux $LINUX_VER"
  rm -rf "$LINUX_DIR"
  git clone --depth 1 --branch "$LINUX_VER" \
    https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git "$LINUX_DIR" \
    || git clone --depth 1 --branch "$LINUX_VER" \
         https://github.com/gregkh/linux.git "$LINUX_DIR"
else
  echo "==> Linux already at $LINUX_DIR"
  git -C "$LINUX_DIR" fetch --depth 1 origin "refs/tags/$LINUX_VER:refs/tags/$LINUX_VER" 2>/dev/null || true
  git -C "$LINUX_DIR" checkout -f "$LINUX_VER" 2>/dev/null \
    || git -C "$LINUX_DIR" checkout -f "tags/$LINUX_VER" 2>/dev/null \
    || true
fi

echo "==> configure Linux (defconfig + fragment, no C)"
make -C "$LINUX_DIR" ARCH=riscv CROSS_COMPILE="$KCROSS" distclean >/dev/null 2>&1 || true
make -C "$LINUX_DIR" ARCH=riscv CROSS_COMPILE="$KCROSS" defconfig

# Merge fragment then point INITRAMFS at our cpio
FRAG="$SCRIPT_DIR/linux.config.fragment"
if [[ -x "$LINUX_DIR/scripts/kconfig/merge_config.sh" ]]; then
  "$LINUX_DIR/scripts/kconfig/merge_config.sh" -m -O "$LINUX_DIR" \
    "$LINUX_DIR/.config" "$FRAG"
else
  # Fallback: append and olddefconfig
  cat "$FRAG" >> "$LINUX_DIR/.config"
fi

# Embed initramfs so OpenSBI only needs to jump to Image (no separate initrd load).
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --set-str CONFIG_INITRAMFS_SOURCE "$INITRAMFS_CPIO"
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_INITRAMFS_COMPRESSION_GZIP
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --disable CONFIG_RISCV_ISA_C
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_RISCV_ISA_A
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_SERIAL_8250
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_SERIAL_8250_CONSOLE
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_SERIAL_OF_PLATFORM
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_DEVTMPFS
"$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --enable CONFIG_DEVTMPFS_MOUNT

make -C "$LINUX_DIR" ARCH=riscv CROSS_COMPILE="$KCROSS" olddefconfig

# olddefconfig may resurrect ISA_C (default y) — force it off again.
force_no_c() {
  "$LINUX_DIR/scripts/config" --file "$LINUX_DIR/.config" --disable CONFIG_RISCV_ISA_C || true
  sed -i -E 's/^CONFIG_RISCV_ISA_C=y/# CONFIG_RISCV_ISA_C is not set/' "$LINUX_DIR/.config"
  grep -q '^# CONFIG_RISCV_ISA_C is not set' "$LINUX_DIR/.config" \
    || echo '# CONFIG_RISCV_ISA_C is not set' >> "$LINUX_DIR/.config"
}
force_no_c
make -C "$LINUX_DIR" ARCH=riscv CROSS_COMPILE="$KCROSS" olddefconfig
force_no_c

# Sanity: C must stay off
if grep -q '^CONFIG_RISCV_ISA_C=y' "$LINUX_DIR/.config"; then
  echo "ERROR: CONFIG_RISCV_ISA_C still enabled (emulator has no C)" >&2
  grep -n 'RISCV_ISA_C' "$LINUX_DIR/.config" >&2 || true
  exit 1
fi
echo "    CONFIG_RISCV_ISA_C disabled OK"

echo "==> build Linux Image (this takes a while)"
make -C "$LINUX_DIR" \
  ARCH=riscv \
  CROSS_COMPILE="$KCROSS" \
  KCFLAGS="-march=$MARCH -mabi=$ABI" \
  -j"$JOBS" Image

IMG_SRC="$LINUX_DIR/arch/riscv/boot/Image"
if [[ ! -f "$IMG_SRC" ]]; then
  echo "build failed: missing $IMG_SRC" >&2
  exit 1
fi

# ---------------------------------------------------------------------------
# Device tree
# ---------------------------------------------------------------------------
echo "==> compile board.dtb"
dtc -I dts -O dtb -o "$OUT/board.dtb" "$SCRIPT_DIR/board.dts"

echo "==> install Image → $OUT/Image"
cp -f "$IMG_SRC" "$OUT/Image"
# Keep a copy of the config used for this Image
cp -f "$LINUX_DIR/.config" "$OUT/linux.config"
ls -la "$OUT/Image" "$OUT/board.dtb" "$OUT/fw_jump.bin" 2>/dev/null || true

echo
echo "Done."
echo "  Image     : $OUT/Image ($(wc -c < "$OUT/Image") bytes)"
echo "  board.dtb : $OUT/board.dtb"
echo "  Build tree: $BUILD"
echo
echo "Love → RV64 should boot: OpenSBI → Linux → BusyBox ash (if the core is ready)."
echo "Need OpenSBI first?  bash tools/riscv64-linux/build_opensbi.sh"
