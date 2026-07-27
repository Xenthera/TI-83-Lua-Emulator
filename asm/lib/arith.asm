; Unsigned divide / modulo for Tiny-C.
; On entry: HL = dividend, DE = divisor
; udiv_u16: HL = quotient (divisor 0 -> 0xFFFF)
; umod_u16: HL = remainder (divisor 0 -> dividend)

udiv_u16:
    push af
    push bc
    push de
    call udiv_core
    pop bc
    pop bc
    pop af
    ret

umod_u16:
    push af
    push bc
    push de
    call udiv_core
    ex de,hl
    pop bc
    pop bc
    pop af
    ret

; HL=dividend, DE=divisor -> HL=quotient, DE=remainder
udiv_core:
    ld a,d
    or e
    jr nz,udiv_nz
    ld d,h
    ld e,l
    ld hl,0xFFFF
    ret
udiv_nz:
    ld b,16
    ld a,h
    ld c,l
    ld hl,0
udiv_loop:
    sla c
    rla
    adc hl,hl
    or a
    sbc hl,de
    jr nc,udiv_ge
    add hl,de
    djnz udiv_loop
    jr udiv_finish
udiv_ge:
    inc c
    djnz udiv_loop
udiv_finish:
    ld d,h
    ld e,l
    ld h,a
    ld l,c
    ret
