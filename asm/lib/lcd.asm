; TI-83+ T6A04 LCD helpers (WikiTI ports 10h/11h).
;
; Real hardware needs ≥10µs between LCD accesses. The emulator is instant,
; but we always delay so Flash Apps behave on a real TI-83+ (and 83+SE/84+
; at 15MHz). We do NOT poll port 10 bit7 — some LCD drivers break that.
;
; Multi-step RMW (draw_pixel) runs with interrupts off so the OS ISR cannot
; interleave LCD commands mid-update.

LCD_CMD:  equ 0x10
LCD_DATA: equ 0x11

; Portable ≥10µs wait @ 6MHz; still enough at 15MHz (~150 T).
lcd_wait:
    push af
    ld a,12
lcd_wait_loop:
    dec a
    jr nz,lcd_wait_loop
    pop af
    ret

lcd_cmd:
    call lcd_wait
    out (LCD_CMD),a
    ret

lcd_data:
    call lcd_wait
    out (LCD_DATA),a
    ret

lcd_init:
    push af
    di
    ld a,0x01          ; 8-bit mode
    call lcd_cmd
    ld a,0x05          ; X (row) auto-increment
    call lcd_cmd
    ld a,0x03          ; display on
    call lcd_cmd
    ei
    pop af
    ret

; B=column(0-11), C=row(0-63)
lcd_set_xy:
    ld a,c
    or 0x80            ; set row (TI "X")
    call lcd_cmd
    ld a,b
    or 0x20            ; set column (TI "Y")
    call lcd_cmd
    ret

lcd_clear:
    push af
    push bc
    push de
    di
    ld a,0x07          ; Y (column) auto-increment for row fills
    call lcd_cmd
    ld c,0
lcd_clear_row:
    ld b,0
    push bc
    call lcd_set_xy
    pop bc
    ld e,12
lcd_clear_col:
    xor a
    call lcd_data
    dec e
    jr nz,lcd_clear_col
    inc c
    ld a,c
    cp 64
    jr nz,lcd_clear_row
    ld a,0x05          ; restore row auto-increment (OS/default)
    call lcd_cmd
    ei
    pop de
    pop bc
    pop af
    ret
