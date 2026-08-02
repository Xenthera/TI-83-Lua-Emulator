; Pixel graphics for TI-83+ T6A04 (ports via lcd.asm).
; draw_pixel / clear_pixel: B = x (0-95), C = y (0-63)
; erase_rect: B=x, C=y, D=w, E=h - clears by LCD byte (not per-pixel).
;
; RMW / multi-byte clears run DI so the OS ISR cannot interleave LCD ops.

pixel_masks:
    db 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01

lcd_read:
    call lcd_wait
    in a,(LCD_DATA)
    ret

; T6A04: first data read after setting X/Y is a dummy (stale latch).
lcd_read_byte:
    call lcd_wait
    in a,(LCD_DATA)
    call lcd_wait
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

    di
    ld a,b
    push af
    ld d,0
draw_pixel_col:
    cp 8
    jr c,draw_pixel_col_done
    sub 8
    inc d
    jr draw_pixel_col
draw_pixel_col_done:
    ld b,d
    push bc
    call lcd_set_xy
    call lcd_read_byte
    ld e,a
    pop bc
    pop af
    push bc
    and 0x07
    ld c,a
    ld b,0
    ld hl,pixel_masks
    add hl,bc
    ld a,(hl)
    or e
    ld e,a
    pop bc
    push de
    call lcd_set_xy
    pop de
    ld a,e
    call lcd_data
    ei

draw_pixel_done:
    pop hl
    pop de
    pop bc
    pop af
    ret

; B=x, C=y
clear_pixel:
    push af
    push bc
    push de
    push hl

    ld a,b
    cp 96
    jr nc,clear_pixel_done
    ld a,c
    cp 64
    jr nc,clear_pixel_done

    di
    ld a,b
    push af
    ld d,0
clear_pixel_col:
    cp 8
    jr c,clear_pixel_col_done
    sub 8
    inc d
    jr clear_pixel_col
clear_pixel_col_done:
    ld b,d
    push bc
    call lcd_set_xy
    call lcd_read_byte
    ld e,a
    pop bc
    pop af
    push bc
    and 0x07
    ld c,a
    ld b,0
    ld hl,pixel_masks
    add hl,bc
    ld a,(hl)
    cpl
    and e
    ld e,a
    pop bc
    push de
    call lcd_set_xy
    pop de
    ld a,e
    call lcd_data
    ei

clear_pixel_done:
    pop hl
    pop de
    pop bc
    pop af
    ret

; =====================================================================
; erase_rect - B=x, C=y, D=w, E=h
; Byte-oriented clear. Full columns: one zero write. Edges: masked RMW.
; Scratch frame on stack (Flash is not writable): IX-9 .. IX-1
;   -9 x0  -8 y0  -7 x1  -6 y1  -5 c0  -4 c1  -3 row  -2 col  -1 mask
; =====================================================================

; A = value; returns A = value/8 (clobbers B,C)
erase_div8:
    ld b,0
    ld c,a
erase_d8:
    ld a,c
    cp 8
    ld a,b
    ret c
    ld a,c
    sub 8
    ld c,a
    inc b
    jr erase_d8

; D=first bit 0..7, E=last bit 0..7 inclusive -> A = OR of masks
erase_bit_mask:
    push bc
    push hl
    xor a
    ld b,d
erase_bm_lp:
    ld c,b
    ld b,0
    ld hl,pixel_masks
    add hl,bc
    or (hl)
    ld b,c
    ld c,a
    ld a,b
    cp e
    ld a,c
    jr nc,erase_bm_done
    inc b
    jr erase_bm_lp
erase_bm_done:
    pop hl
    pop bc
    ret

erase_rect:
    push af
    push bc
    push de
    push hl
    push ix

    ld a,d
    or a
    jp z,erase_rect_done
    ld a,e
    or a
    jp z,erase_rect_done
    ld a,b
    cp 96
    jp nc,erase_rect_done
    ld a,c
    cp 64
    jp nc,erase_rect_done

    ; Allocate 9-byte scratch below SP; IX points at saved IX.
    ld ix,0
    add ix,sp
    ld hl,-9
    add hl,sp
    ld sp,hl

    ld (ix-9),b
    ld (ix-8),c

    ; x1 = min(95, x+w-1)
    ld a,b
    add a,d
    jp c,er_x1_hi
    dec a
    cp 96
    jp c,er_x1_ok
er_x1_hi:
    ld a,95
er_x1_ok:
    ld (ix-7),a

    ; y1 = min(63, y+h-1)
    ld a,c
    add a,e
    jp c,er_y1_hi
    dec a
    cp 64
    jp c,er_y1_ok
er_y1_hi:
    ld a,63
er_y1_ok:
    ld (ix-6),a

    ld a,(ix-9)
    call erase_div8
    ld (ix-5),a
    ld a,(ix-7)
    call erase_div8
    ld (ix-4),a

    di
    ld a,0x05
    call lcd_cmd

    ld a,(ix-8)
    ld (ix-3),a
er_row:
    ld a,(ix-5)
    ld (ix-2),a
er_col:
    ld a,(ix-2)
    cp (ix-5)
    jp nz,er_not_left
    cp (ix-4)
    jp nz,er_left_only
    ld a,(ix-9)
    and 0x07
    ld d,a
    ld a,(ix-7)
    and 0x07
    ld e,a
    call erase_bit_mask
    jp er_have_mask
er_left_only:
    ld a,(ix-9)
    and 0x07
    ld d,a
    ld e,7
    call erase_bit_mask
    jp er_have_mask
er_not_left:
    cp (ix-4)
    jp nz,er_full_mask
    ld d,0
    ld a,(ix-7)
    and 0x07
    ld e,a
    call erase_bit_mask
    jp er_have_mask
er_full_mask:
    ld a,0xFF
er_have_mask:
    ld (ix-1),a

    ld b,(ix-2)
    ld c,(ix-3)
    cp 0xFF
    jp nz,er_rmw
    call lcd_set_xy
    xor a
    call lcd_data
    jp er_next_col

er_rmw:
    call lcd_set_xy
    call lcd_read_byte
    ld e,a
    ld a,(ix-1)
    cpl
    and e
    ld e,a
    ld b,(ix-2)
    ld c,(ix-3)
    push de
    call lcd_set_xy
    pop de
    ld a,e
    call lcd_data

er_next_col:
    ld a,(ix-2)
    cp (ix-4)
    jp nc,er_next_row
    inc a
    ld (ix-2),a
    jp er_col

er_next_row:
    ld a,(ix-3)
    cp (ix-6)
    jp nc,er_fini
    inc a
    ld (ix-3),a
    jp er_row

er_fini:
    ei
    ld sp,ix

erase_rect_done:
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ret
