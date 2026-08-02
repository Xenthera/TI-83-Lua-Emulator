; Soft integer / Q8.8 math for Tiny-C.
; mul_u16 is register-only (safe under Flash App IRQs).
; mul_u32 uses a stack frame (no absolute 0xC070 scratch).

; HL = DE * HL (unsigned, low 16 bits)
mul_u16:
    push af
    push bc
    ld b,h
    ld c,l              ; BC = multiplier
    ld hl,0             ; product
    ld a,16
mul_u16_loop:
    srl b
    rr c
    jr nc,mul_u16_noadd
    add hl,de
mul_u16_noadd:
    sla e
    rl d
    dec a
    jr nz,mul_u16_loop
    pop bc
    pop af
    ret

; DEHL = DE * BC (unsigned 32-bit)
mul_u32:
    push af
    push ix
    ld ix,0
    add ix,sp
    ld hl,-12
    add hl,sp
    ld sp,hl
    ; -12 Alo -11 Ahi
    ; -10 Blo -9 Bhi
    ; -8  BHlo - 7 BHhi
    ; -6  Plo - 5 Phi
    ; -4  PHlo - 3 PHhi
    ld (ix-12),e
    ld (ix-11),d
    ld (ix-10),c
    ld (ix-9),b
    xor a
    ld (ix-8),a
    ld (ix-7),a
    ld (ix-6),a
    ld (ix-5),a
    ld (ix-4),a
    ld (ix-3),a

    ld a,16
mul_u32_loop:
    srl (ix-11)
    rr (ix-12)
    jr nc,mul_u32_noadd
    ld l,(ix-6)
    ld h,(ix-5)
    ld e,(ix-10)
    ld d,(ix-9)
    add hl,de
    ld (ix-6),l
    ld (ix-5),h
    ld l,(ix-4)
    ld h,(ix-3)
    ld e,(ix-8)
    ld d,(ix-7)
    adc hl,de
    ld (ix-4),l
    ld (ix-3),h
mul_u32_noadd:
    ld l,(ix-10)
    ld h,(ix-9)
    add hl,hl
    ld (ix-10),l
    ld (ix-9),h
    ld l,(ix-8)
    ld h,(ix-7)
    adc hl,hl
    ld (ix-8),l
    ld (ix-7),h
    dec a
    jr nz,mul_u32_loop

    ld l,(ix-6)
    ld h,(ix-5)
    ld e,(ix-4)
    ld d,(ix-3)
    ld sp,ix
    pop ix
    pop af
    ret

; HL = q88_mul(DE, HL): signed Q8.8 multiply -> Q8.8
;   (int16(DE) * int16(HL)) >> 8
mul_q88:
    push af
    push bc
    ld a,d
    xor h
    push af
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
    call mul_u32
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
