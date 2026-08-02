#!/usr/bin/env bash
set - euo pipefail
ROOT=/mnt/c/Users/Bobby/GitBackup/TI-83-Lua-Emulator
cd "$ROOT"
sed - i 's/\r$//' tools/riscv64-linux/*.sh tools/riscv64-linux/rootfs_skel/init
rm - f tools/riscv64-linux/build_linux.log
set +e
bash tools/riscv64-linux/build_linux_busybox.sh > tools/riscv64-linux/build_linux.log 2>&1
ec=$?
set - e
echo "EXIT:$ec" >> tools/riscv64-linux/build_linux.log
echo "EXIT:$ec"
exit "$ec"
