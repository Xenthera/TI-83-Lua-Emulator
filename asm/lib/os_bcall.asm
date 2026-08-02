; TI-OS BCALL helpers for Tiny-C Flash Apps (mapped at 0x4000).
; Uses RST 28h + word ID (WikiTI 83Plus BCALLs).
;
; IMPORTANT: OS PutS (450A) only reads strings from RAM. App code/strings live
; in Flash at 4000-7FFF, so we implement put_str via PutC (4504) instead.

    ; void os_clr_lcd(void) - ClrLCDFull
os_clr_lcd:
    rst 0x28
    dw 0x4540
    ret

    ; void os_home_up(void) - HomeUp (cursor top-left)
os_home_up:
    rst 0x28
    dw 0x4558
    ret

    ; void os_newline(void) - NewLine
os_newline:
    rst 0x28
    dw 0x452E
    ret

    ; void os_put_str(void) - HL = NUL-terminated string (Flash or RAM OK)
    ; Own loop + PutC: OS PutS cannot fetch from the app Flash page.
os_put_str:
    ld a,(hl)
    inc hl
    or a
    ret z
    push hl
    rst 0x28
    dw 0x4504          ; PutC (char in A)
    pop hl
    jr os_put_str

    ; byte os_get_key(void) - GetKey; keycode in A
os_get_key:
    rst 0x28
    dw 0x4972
    ret

    ; void os_exit(void) - never returns (JForceCmdNoChar)
os_exit:
    rst 0x28
    dw 0x4027
