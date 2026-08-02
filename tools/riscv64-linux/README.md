# RV64 custom board - OpenSBI + Linux + BusyBox

Host-side build for artifacts the Love `riscv64` machine boots. No QEMU.

## Quick start (Windows / WSL)

1. **WSL Ubuntu** (once): `wsl --install - d Ubuntu`
2. **OpenSBI + DTB stub payload** (once, or after OpenSBI upgrades):

```bat
wsl - d Ubuntu - e bash - lc "sed - i 's/\r$//' tools/riscv64-linux/build_opensbi.sh && bash tools/riscv64-linux/build_opensbi.sh"
```

3. **Linux + BusyBox initramfs** (replaces the stub `Image`):

```bat
wsl - d Ubuntu - e bash - lc "sed - i 's/\r$//' tools/riscv64-linux/*.sh tools/riscv64-linux/rootfs_skel/init && bash tools/riscv64-linux/build_linux_busybox.sh"
```

| Output | Role |
|--------|------|
| `rom/riscv64/fw_jump.bin` | OpenSBI @ `0x80000000` |
| `rom/riscv64/board.dtb` | FDT @ `0x82000000` |
| `rom/riscv64/Image` | Linux (embedded BusyBox initramfs) @ `0x80200000` |
| `rom/riscv64/linux.config` | Kernel `.config` used for the last Image build |

Build trees live on the Linux FS (faster than `/mnt/c`):

- OpenSBI -> `~/retro-rv64-opensbi`
- Linux / BusyBox -> `~/retro-rv64-linux`

4. Start Love -> select **RV64**. Expect OpenSBI banner -> `Linux version ...` -> BusyBox `ash` (bring-up may still need CPU/MMIO fixes).

Rebuild OpenSBI only (after deps installed):

```bat
wsl - d Ubuntu bash tools/riscv64-linux/rebuild_nosemi.sh
```

## Try without toolchain

```bat
lua tools/riscv64-linux/gen_console_fw.lua
```

Love -> **RV64** loads `rom/riscv64.bin` console demo (Lua SBI) if no `fw_jump.bin` is present.

## Memory map

| Region | Address |
|--------|---------|
| OpenSBI / FW | `0x80000000` |
| Kernel / payload (`Image`) | `0x80200000` |
| DTB | `0x82000000` |
| CLINT / ACLINT | `0x02000000` |
| UART NS16550 | `0x10000000` |
| Halt | `0x10000010` |
| RAM | `0x80000000` (64MiB sparse) |

Boot: `a0 = hartid`, `a1 = dtb`, reset PC = firmware (M-mode). OpenSBI jumps to `Image` in **S-mode**.

## Device tree (`board.dts`)

- `compatible = "retro,rv64-custom"`
- CPU: `rv64ima_zicsr_zifencei`, `mmu-type = "riscv,sv39"`
- UART: `ns16550a` @ `0x10000000`, IRQ 10 via PLIC
- `chosen.bootargs`: `earlycon=uart8250,mmio,0x10000000 earlycon=sbi console=ttyS0,115200n8 rdinit=/init`
- Initramfs is **embedded in the Image** (`CONFIG_INITRAMFS_SOURCE`); no separate initrd load in Love.

## OpenSBI build notes

- `PLATFORM=generic`, `PLATFORM_RISCV_ISA=rv64ima_zicsr_zifencei` (no C)
- `FW_JUMP_ADDR=0x80200000`, `FW_JUMP_FDT_ADDR=0x82000000`
- Semihosting is **disabled** (ebreak probes panic in our core)
- Emulator implements **A** (AMO) - required for the boot lottery

## Linux / BusyBox build notes

- Kernel tag default: `v6.6.63` (`LINUX_VER=...` to override)
- BusyBox tag default: `1_36_1` (`BUSYBOX_VER=...`)
- **No C extension** (`CONFIG_RISCV_ISA_C` off; `KCFLAGS=-march=rv64ima_zicsr_zifencei`)
- BusyBox linked **static** against Bootlin **musl soft-float** (`riscv64--musl--bleeding-edge-2020.08-1` via `fetch_musl_toolchain.sh`) - modern Bootlin/`riscv64-linux-gnu` are `lp64d`+C
- Kernel still uses `riscv64-linux-gnu-` with `KCFLAGS=-march=rv64ima_zicsr_zifencei - mabi=lp64`
- Rootfs skel init: `tools/riscv64-linux/rootfs_skel/init`
- Fragment: `tools/riscv64-linux/linux.config.fragment`

## Studio boot order

**OpenSBI+Image+DTB** -> Image-only (Lua SBI) -> `rom/riscv64.bin` console demo.
