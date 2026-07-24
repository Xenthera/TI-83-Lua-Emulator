; Pixel graphics for pipeline runtime (T6A04)
; draw_pixel: B = x (0-95), C = y (0-63)

pixel_masks:
    db 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01

; Raw port read (advances pointer). Prefer lcd_read_byte after set-address.
lcd_read:
    in a,(LCD_DATA)
    ret

; T6A04: first data read after setting X/Y is a dummy (stale latch).
; Second read returns the cell at the address that was set.
lcd_read_byte:
    in a,(LCD_DATA)
    in a,(LCD_DATA)
    ret

; B=x, C=y
draw_pixel:
    push af
    push bc
    push de
    push hl

    ld a,b
    cp 96
    jr nc,draw_pixel_done
    ld a,c
    cp 64
    jr nc,draw_pixel_done

    ; save x
    ld a,b
    push af

    ; column = x / 8 via subtract loop -> B
    ld d,0
draw_pixel_col:
    cp 8
    jr c,draw_pixel_col_done
    sub 8
    inc d
    jr draw_pixel_col
draw_pixel_col_done:
    ld b,d               ; B=col, C=y still
    push bc              ; col,y
    call lcd_set_xy
    call lcd_read_byte
    ld e,a               ; E = current byte

    pop bc               ; B=col C=y
    pop af               ; A = x
    push bc              ; col,y again
    and 0x07
    ld c,a
    ld b,0
    ld hl,pixel_masks
    add hl,bc
    ld a,(hl)
    or e
    ld e,a               ; E = new byte

    pop bc               ; B=col C=y
    push de
    call lcd_set_xy
    pop de
    ld a,e
    call lcd_data

draw_pixel_done:
    pop hl
    pop de
    pop bc
    pop af
    ret
