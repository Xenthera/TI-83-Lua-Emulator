#!/usr/bin/env bash
set -euo pipefail
CFG=/root/retro-rv64-opensbi/opensbi/build/platform/generic/kconfig/.config
sed -i 's/^CONFIG_SERIAL_SEMIHOSTING=y/# CONFIG_SERIAL_SEMIHOSTING is not set/' "$CFG"
grep SEMIHOST "$CFG" || true
cd /root/retro-rv64-opensbi/opensbi
make CROSS_COMPILE=riscv64-linux-gnu- PLATFORM=generic \
  PLATFORM_RISCV_XLEN=64 PLATFORM_RISCV_ISA=rv64ima_zicsr_zifencei PLATFORM_RISCV_ABI=lp64 \
  FW_TEXT_START=0x80000000 FW_JUMP_ADDR=0x80200000 FW_JUMP_FDT_ADDR=0x82000000 \
  CFLAGS_EXTRA=-std=gnu17 -j"$(nproc)"
OUT=/mnt/c/Users/Bobby/GitBackup/TI-83-Lua-Emulator/rom/riscv64
cp -f build/platform/generic/firmware/fw_jump.bin "$OUT/fw_jump.bin"
cp -f build/platform/generic/firmware/fw_jump.elf "$OUT/fw_jump.elf"
echo "DONE $(wc -c < "$OUT/fw_jump.bin") bytes"
