; Soft integer / Q8.8 math for Tiny-C pipeline ROM.
; Scratch: 0xC070..0xC07F (below Tiny-C locals at 0xC080).

MUL_SCR:  equ 0xC070
MUL_A:    equ 0xC070   ; multiplier
MUL_B:    equ 0xC072   ; multiplicand lo
MUL_BH:   equ 0xC074   ; multiplicand hi
MUL_P:    equ 0xC076   ; product lo
MUL_PH:   equ 0xC078   ; product hi

; HL = DE * HL (unsigned, low 16 bits of product)
mul_u16:
    push af
    push bc
    push de
    ld b,h
    ld c,l
    call mul_u32
    ; DEHL = full product; want low 16 in HL (already)
    pop de
    pop bc
    pop af
    ret

; DEHL = DE * BC (unsigned 32-bit)
mul_u32:
    push af
    ld (MUL_A),de
    ld (MUL_B),bc
    ld hl,0
    ld (MUL_BH),hl
    ld (MUL_P),hl
    ld (MUL_PH),hl
    ld a,16
mul_u32_loop:
    ld hl,(MUL_A)
    srl h
    rr l
    ld (MUL_A),hl
    jr nc,mul_u32_noadd
    ld hl,(MUL_P)
    ld de,(MUL_B)
    add hl,de
    ld (MUL_P),hl
    ld hl,(MUL_PH)
    ld de,(MUL_BH)
    adc hl,de
    ld (MUL_PH),hl
mul_u32_noadd:
    ld hl,(MUL_B)
    add hl,hl
    ld (MUL_B),hl
    ld hl,(MUL_BH)
    adc hl,hl
    ld (MUL_BH),hl
    dec a
    jr nz,mul_u32_loop
    ld hl,(MUL_P)
    ld de,(MUL_PH)
    pop af
    ret

; HL = q88_mul(DE, HL): signed Q8.8 multiply -> Q8.8
;   (int16(DE) * int16(HL)) >> 8
mul_q88:
    push af
    push bc
    ld a,d
    xor h
    push af                 ; bit7 = result negative
    bit 7,d
    jr z,mul_q88_de_pos
    ld a,e
    cpl
    ld e,a
    ld a,d
    cpl
    ld d,a
    inc de
mul_q88_de_pos:
    bit 7,h
    jr z,mul_q88_hl_pos
    ld a,l
    cpl
    ld l,a
    ld a,h
    cpl
    ld h,a
    inc hl
mul_q88_hl_pos:
    ld b,h
    ld c,l
    call mul_u32            ; DEHL = |a|*|b|
    ; take bits 23..8 -> HL  (bytes D:E:H:L -> E:H)
    ld l,h
    ld h,e
    pop af
    bit 7,a
    jr z,mul_q88_done
    ld a,l
    cpl
    ld l,a
    ld a,h
    cpl
    ld h,a
    inc hl
mul_q88_done:
    pop bc
    pop af
    ret
