from pathlib import Path

p = Path(__file__).with_name("run_build.sh")
lines = [
    "#!/usr/bin/env bash",
    "set - euo pipefail",
    "ROOT=/mnt/c/Users/Bobby/GitBackup/TI-83-Lua-Emulator",
    'cd "$ROOT"',
    "sed - i 's/\\r$//' tools/riscv64-linux/*.sh tools/riscv64-linux/rootfs_skel/init",
    "rm - f tools/riscv64-linux/build_linux.log",
    "set +e",
    "bash tools/riscv64-linux/build_linux_busybox.sh > tools/riscv64-linux/build_linux.log 2>&1",
    "ec=$?",
    "set - e",
    'echo "EXIT:$ec" >> tools/riscv64-linux/build_linux.log',
    'echo "EXIT:$ec"',
    'exit "$ec"',
    "",
]
data = "\n".join(lines).encode("ascii")
p.write_bytes(data)
print("wrote", p, "bytes", len(data))
