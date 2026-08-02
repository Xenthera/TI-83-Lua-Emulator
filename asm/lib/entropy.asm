; word entropy(void) - HL = seed material for PRNGs.
;
; TI-83+ has no RTC / GetTime (that is TI-84+ only). This mixes R, SP, and a
; short spin that the OS interrupt can skew - valid on real 83+ hardware.

entropy:
    push af
    push bc
    push de
    ei                      ; Flash Apps normally run with IRQs on
    ld hl,0
    ld b,0
entropy_spin:
    inc hl
    djnz entropy_spin
    ld a,r
    xor l
    ld l,a
    ld a,r
    add a,h
    ld h,a
    ld a,r
    xor h
    ld h,a
    ; fold SP into the mix
    ex de,hl
    ld hl,0
    add hl,sp
    ld a,e
    xor l
    ld l,a
    ld a,d
    xor h
    ld h,a
    pop de
    pop bc
    pop af
    ret
