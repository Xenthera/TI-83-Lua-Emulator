; 8x8 text renderer
; Uses: font (blob), ascii_map (blob)
; draw_string: HL -> NUL-terminated ASCII, B=col, C=row

draw_string:
draw_string_loop:
    ld a,(hl)
    or a
    ret z
    push hl
    push bc
    call draw_char
    pop bc
    pop hl
    inc hl
    inc b
    ld a,b
    cp 12
    jr c,draw_string_loop
    ret

; draw_char: A=ASCII, B=col, C=row
draw_char:
    push bc
    ; map ascii -> glyph index
    ld l,a
    ld h,0
    ld de,ascii_map
    add hl,de
    ld a,(hl)          ; glyph index
    ; font offset = index * 8
    ld l,a
    ld h,0
    add hl,hl
    add hl,hl
    add hl,hl
    ld de,font
    add hl,de          ; HL -> glyph bytes
    pop bc             ; B=col C=row
    ld e,8             ; 8 rows
draw_char_row:
    push hl
    push bc
    push de
    call lcd_set_xy
    pop de
    pop bc
    pop hl
    ld a,(hl)
    call lcd_data
    inc hl
    inc c
    dec e
    jr nz,draw_char_row
    ret
