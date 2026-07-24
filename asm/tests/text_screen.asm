; Pipeline screen test: init LCD, draw text, signal PASS in RAM.
; Assembled by asm/assembler.lua into rom/pipeline.rom

    org 0x0000
    jp main

    org 0x0038
    ei
    reti

    org 0x0100
main:
    ld sp,0xFFFE
    call lcd_init
    call lcd_clear

    ; "HI TI-83" at (0,0)
    ld b,0
    ld c,0
    ld hl,msg_hi
    call draw_string

    ; "PASS" at (0,16)
    ld b,0
    ld c,16
    ld hl,msg_pass
    call draw_string

    ; "0123456789" at (0,32)
    ld b,0
    ld c,32
    ld hl,msg_digits
    call draw_string

    ; ready magic
    ld a,0xA5
    ld (0xC001),a

idle:
    halt
    jr idle

msg_hi:
    db "HI TI-83",0
msg_pass:
    db "PASS",0
msg_digits:
    db "0123456789",0

    include "asm/lib/lcd.asm"
    include "asm/lib/text.asm"

font:
    blob font8

ascii_map:
    blob ascii_map
