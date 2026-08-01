#!/usr/bin/env python3
"""Tiny RV64IMA S-mode payload placed at 0x80200000 as Image.

Uses SBI legacy console putchar (eid=1) then WFI-idle. Proves OpenSBI → jump
works before a real Linux Image is built.
"""
from __future__ import annotations
import struct
import sys
from pathlib import Path


def enc_i(imm, rs1, funct3, rd, opcode):
    return ((imm & 0xFFF) << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode


def enc_u(imm20, rd, opcode):
    return ((imm20 << 12) & 0xFFFFF000) | (rd << 7) | opcode


def enc_j(imm, rd):
    u = imm & 0x1FFFFF
    return (
        ((u >> 20) & 1) << 31
        | ((u >> 1) & 0x3FF) << 21
        | ((u >> 11) & 1) << 20
        | ((u >> 12) & 0xFF) << 12
        | (rd << 7)
        | 0x6F
    )


def enc_b(imm, rs2, rs1, funct3):
    u = imm & 0x1FFF
    return (
        ((u >> 12) & 1) << 31
        | ((u >> 5) & 0x3F) << 25
        | (rs2 << 20)
        | (rs1 << 15)
        | (funct3 << 12)
        | ((u >> 1) & 0xF) << 8
        | ((u >> 11) & 1) << 7
        | 0x63
    )


def main() -> int:
    out = Path(sys.argv[1] if len(sys.argv) > 1 else "Image")
    msg = b"[payload] OpenSBI jump OK\n# "
    # Layout (relative to 0x80200000):
    #  0x00 entry
    #  0x40 puts
    #  0x80 idle
    # 0x100 string
    mem = bytearray(0x180)

    def put32(addr: int, word: int) -> None:
        struct.pack_into("<I", mem, addr, word & 0xFFFFFFFF)

    # entry @ 0
    put32(0x00, enc_u(0, 5, 0x37))  # lui a0, 0 → clear then addi
    put32(0x04, enc_i(0x100, 0, 0, 5, 0x13))  # addi a0, x0, 0x100 (str) — but need auipc for reloc
    # Use auipc+addi for PC-relative string at 0x100
    # auipc a0, 0 ; addi a0, a0, 0x100 - 4? At PC=0: auipc gives 0x80200000, +0x100 = str
    put32(0x00, 0x00000517)  # auipc a0, 0
    put32(0x04, enc_i(0x100 - 4, 5, 0, 5, 0x13))  # addi a0, a0, 0xFC → 0x100 from entry
    # Wait: auipc at 0 sets a0 = pc+0 = base. addi +0x100 → base+0x100. Offset from auipc insn is 0x100-0=0x100.
    put32(0x04, enc_i(0x100, 5, 0, 5, 0x13))
    put32(0x08, enc_j(0x40 - 0x08, 1))  # jal ra, puts
    put32(0x0C, enc_j(0x80 - 0x0C, 0))  # j idle

    # puts @ 0x40: a0=str. Uses a1=ch, a6=0, a7=1, ecall; then a0+=1
    put32(0x40, enc_i(0, 10, 0, 11, 0x03))  # lb a1, 0(a0)
    put32(0x44, enc_b(0x20, 0, 11, 0))  # beqz a1, done
    put32(0x48, enc_i(0, 11, 0, 10, 0x13))  # mv a0_arg: wait — SBI wants a0=char
    # Save str ptr in s0 (x8)
    # Better rewrite puts properly:
    # redo entry/puts with s0
    mem[0x40:0x80] = b"\x00" * 0x40

    # puts: s0 = str
    put32(0x40, enc_i(0, 10, 0, 8, 0x13))  # mv s0, a0
    put32(0x44, enc_i(0, 8, 0, 11, 0x03))  # lb a1, 0(s0)
    put32(0x48, enc_b(0x1C, 0, 11, 0))  # beqz a1, +0x1C -> 0x64 ret
    put32(0x4C, enc_i(0, 11, 0, 10, 0x13))  # a0 = ch
    put32(0x50, enc_i(0, 0, 0, 16, 0x13))  # a6 = 0
    put32(0x54, enc_i(1, 0, 0, 17, 0x13))  # a7 = 1 (Console Putchar)
    put32(0x58, 0x00000073)  # ecall
    put32(0x5C, enc_i(1, 8, 0, 8, 0x13))  # s0++
    put32(0x60, enc_j(0x44 - 0x60, 0))  # j loop
    put32(0x64, enc_i(0, 1, 0, 0, 0x67))  # ret

    # idle @ 0x80
    put32(0x80, 0x10500073)  # wfi
    put32(0x84, enc_j(0x80 - 0x84, 0))

    # string @ 0x100
    mem[0x100 : 0x100 + len(msg)] = msg
    mem[0x100 + len(msg)] = 0

    # Fix entry: a0 = str via auipc/addi
    put32(0x00, 0x00000517)  # auipc a0, 0
    put32(0x04, enc_i(0x100, 5, 0, 5, 0x13))  # addi a0, a0, 0x100
    put32(0x08, enc_j(0x40 - 0x08, 1))
    put32(0x0C, enc_j(0x80 - 0x0C, 0))

    out.write_bytes(bytes(mem))
    print(f"wrote {out} ({len(mem)} bytes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
