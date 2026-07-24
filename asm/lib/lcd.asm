; TI-83+ T6A04 LCD helpers (WikiTI command set)

LCD_CMD:  equ 0x10
LCD_DATA: equ 0x11

lcd_cmd:
    out (LCD_CMD),a
    ret

lcd_data:
    out (LCD_DATA),a
    ret

lcd_init:
    ld a,0x01          ; 8-bit mode
    call lcd_cmd
    ld a,0x05          ; X (row) auto-increment
    call lcd_cmd
    ld a,0x03          ; display on
    call lcd_cmd
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
    ret
