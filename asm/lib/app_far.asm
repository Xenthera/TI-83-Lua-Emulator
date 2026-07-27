; Flash App far-call trampoline (Tiny-C multipage apps).
; __app_base_page = physical flash page of app base (port 6 at entry).
; Logical relative page R maps to physical (base - R) in the archive.
;
;   call __far_call
;   dw target_addr
;   db rel_page

__app_base_page:
    db 0

__app_save_base:
    push af
    in a,(6)
    and 0x1F
    ld (__app_base_page),a
    pop af
    ret

__far_call:
    pop hl              ; HL -> dw / db payload
    push bc
    ld c,(hl)
    inc hl
    ld b,(hl)           ; BC = target address
    inc hl
    ld a,(hl)           ; A = relative page
    inc hl
    push hl             ; resume after payload
    ld l,a              ; L = rel
    in a,(6)
    and 0x1F
    push af             ; save previous bank
    ld a,(__app_base_page)
    sub l
    out (6),a           ; map target page
    ld hl,__far_ret
    push hl
    push bc
    ret                 ; jump to target

__far_ret:
    pop af              ; previous bank
    out (6),a
    pop hl              ; resume
    pop bc
    jp (hl)
