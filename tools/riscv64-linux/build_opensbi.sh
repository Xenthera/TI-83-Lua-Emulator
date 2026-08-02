#!/usr/bin/env bash
# Build OpenSBI fw_jump + board.dtb for the Retro Studio RV64 machine.
# Run inside WSL from the repo root:
#   bash tools/riscv64-linux/build_opensbi.sh
set - euo pipefail

ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
OUT="$ROOT/rom/riscv64"
# Build on the Linux filesystem (not /mnt/c) - much faster / fewer FS quirks.
BUILD="${OPENSBI_BUILD:-$HOME/retro-rv64-opensbi}"
OPENSBI_DIR="$BUILD/opensbi"
# v1.5 + GCC 15/C23 breaks on typedef bool; use a recent tag.
OPENSBI_VER="${OPENSBI_VER:-v1.7}"

mkdir - p "$OUT" "$BUILD"

echo "==> packages (sudo)"
sudo apt-get update - qq
sudo DEBIAN_FRONTEND=noninteractive apt-get install - y -qq \
  build-essential git python3 device-tree-compiler \
  gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu

CROSS=riscv64-linux-gnu-
if ! command - v ${CROSS}gcc >/dev/null; then
  echo "missing ${CROSS}gcc" >&2
  exit 1
fi

if [[ ! -d "$OPENSBI_DIR/.git" ]]; then
  echo "==> clone OpenSBI $OPENSBI_VER"
  rm - rf "$OPENSBI_DIR"
  git clone --depth 1 --branch "$OPENSBI_VER" \
    https://github.com/riscv-software-src/opensbi.git "$OPENSBI_DIR"
else
  echo "==> OpenSBI already at $OPENSBI_DIR"
  git - C "$OPENSBI_DIR" fetch --depth 1 origin "refs/tags/$OPENSBI_VER:refs/tags/$OPENSBI_VER" 2>/dev/null || true
  git - C "$OPENSBI_DIR" checkout - f "$OPENSBI_VER" 2>/dev/null \
    || git - C "$OPENSBI_DIR" checkout - f "tags/$OPENSBI_VER" 2>/dev/null \
    || true
fi

echo "==> build OpenSBI PLATFORM=generic (rv64ima, no C)"
# Match emulator: DRAM @ 0x80000000, jump to Image @ 0x80200000, FDT @ 0x82000000.
# Force gnu17 - Ubuntu's riscv64 GCC defaults to C23 and breaks older headers.
make - C "$OPENSBI_DIR" \
  CROSS_COMPILE="$CROSS" \
  PLATFORM=generic \
  PLATFORM_RISCV_XLEN=64 \
  PLATFORM_RISCV_ISA=rv64ima_zicsr_zifencei \
  PLATFORM_RISCV_ABI=lp64 \
  FW_TEXT_START=0x80000000 \
  FW_JUMP_ADDR=0x80200000 \
  FW_JUMP_FDT_ADDR=0x82000000 \
  CFLAGS_EXTRA="-std=gnu17" \
  -j"$(nproc)"

# Semihosting ebreaks panic in our emulator - force UART8250 via FDT only.
CFG="$OPENSBI_DIR/build/platform/generic/kconfig/.config"
if [[ -f "$CFG" ]] && grep - q '^CONFIG_SERIAL_SEMIHOSTING=y' "$CFG"; then
  echo "==> disable CONFIG_SERIAL_SEMIHOSTING and rebuild"
  sed - i 's/^CONFIG_SERIAL_SEMIHOSTING=y/# CONFIG_SERIAL_SEMIHOSTING is not set/' "$CFG"
  make - C "$OPENSBI_DIR" \
    CROSS_COMPILE="$CROSS" \
    PLATFORM=generic \
    PLATFORM_RISCV_XLEN=64 \
    PLATFORM_RISCV_ISA=rv64ima_zicsr_zifencei \
    PLATFORM_RISCV_ABI=lp64 \
    FW_TEXT_START=0x80000000 \
    FW_JUMP_ADDR=0x80200000 \
    FW_JUMP_FDT_ADDR=0x82000000 \
    CFLAGS_EXTRA="-std=gnu17" \
    -j"$(nproc)"
fi

FW_SRC="$OPENSBI_DIR/build/platform/generic/firmware/fw_jump.bin"
if [[ ! -f "$FW_SRC" ]]; then
  echo "build failed: missing $FW_SRC" >&2
  find "$OPENSBI_DIR/build" -name 'fw_jump*' 2>/dev/null | head
  exit 1
fi
cp - f "$FW_SRC" "$OUT/fw_jump.bin"
cp - f "$OPENSBI_DIR/build/platform/generic/firmware/fw_jump.elf" "$OUT/fw_jump.elf" 2>/dev/null || true
echo "    wrote $OUT/fw_jump.bin ($(wc - c < "$OUT/fw_jump.bin") bytes)"

echo "==> compile board.dtb"
dtc - I dts - O dtb - o "$OUT/board.dtb" "$ROOT/tools/riscv64-linux/board.dts"
echo "    wrote $OUT/board.dtb ($(wc - c < "$OUT/board.dtb") bytes)"

# Minimal next-stage payload if no Linux Image yet (SBI console banner + WFI).
if [[ ! -f "$OUT/Image" ]]; then
  echo "==> no Image yet - building tiny SBI payload as Image"
  python3 "$ROOT/tools/riscv64-linux/gen_sbi_payload.py" "$OUT/Image"
  echo "    wrote $OUT/Image ($(wc - c < "$OUT/Image") bytes) [stub payload]"
fi

echo ""
echo "OK - drop-in ready for Love RV64:"
echo "  $OUT/fw_jump.bin"
echo "  $OUT/board.dtb"
echo "  $OUT/Image"
echo "Start Studio -> select RV64 (OpenSBI boot)."
