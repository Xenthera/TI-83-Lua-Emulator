#!/usr/bin/env bash
# Fetch Bootlin riscv64 musl toolchain (soft-float / lp64 - matches ima board).
# Note: modern Bootlin only ships riscv64-lp64d (hard-float + usually C).
set - euo pipefail

TD="${TOOLCHAIN_DIR:-$HOME/retro-rv64-linux/toolchain}"
NAME="${BOOTLIN_NAME:-riscv64--musl--bleeding-edge-2020.08-1}"
URL="${BOOTLIN_URL:-https://toolchains.bootlin.com/downloads/releases/toolchains/riscv64/tarballs/${NAME}.tar.bz2}"
PREFIX="$TD/$NAME"

mkdir - p "$TD"
if [[ -x "$PREFIX/bin/riscv64-linux-gcc" ]]; then
  echo "toolchain ready: $PREFIX"
  "$PREFIX/bin/riscv64-linux-gcc" --version | head -1
  exit 0
fi

echo "==> download $URL"
ARCHIVE="$TD/${NAME}.tar.bz2"
if [[ ! -f "$ARCHIVE" ]]; then
  curl - L --fail - o "$ARCHIVE" "$URL" || wget - O "$ARCHIVE" "$URL"
fi

echo "==> extract"
tar - xjf "$ARCHIVE" -C "$TD"
"$PREFIX/bin/riscv64-linux-gcc" --version | head -1
echo "CROSS_COMPILE=$PREFIX/bin/riscv64-linux-"
