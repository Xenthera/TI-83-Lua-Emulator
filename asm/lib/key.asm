; Bare-metal keypad (port 01). Same scancode encoding as TI-OS GetCSC:
;   code = group*8 + bitIndex + 1   (bitIndex 0..7, group 0..7)
;   0 = no key. Active-low matrix; ON is group 5 bit 0 in this emulator.

KEY_PORT: equ 1

; A = scancode, or 0 if none / ghosting.
key_scan:
    push bc
    push de
    push hl
    ld c,0xFE              ; group mask (bit0 low)
    ld d,0                 ; group index
key_scan_group:
    ld a,0xFF
    out (KEY_PORT),a       ; reset matrix
    ld a,c
    out (KEY_PORT),a
    nop
    nop
    nop
    nop
    in a,(KEY_PORT)
    cp 0xFF
    jr z,key_scan_next

    ; Exactly one low bit → scancode; else ignore (ghost / multi).
    ld e,0                 ; pressed count
    ld b,8
key_scan_bit:
    rla
    jr c,key_scan_bit_up
    inc e
    ld h,b                 ; H = 1-based bit position (8..1)
key_scan_bit_up:
    djnz key_scan_bit
    ld a,e
    cp 1
    jr nz,key_scan_next
    ; A = group*8 + H
    ld a,d
    add a,a
    add a,a
    add a,a
    add a,h
    pop hl
    pop de
    pop bc
    ret

key_scan_next:
    ld a,c
    rlc a
    ld c,a
    inc d
    ld a,d
    cp 8
    jr nz,key_scan_group
    xor a
    pop hl
    pop de
    pop bc
    ret

; Block until a key is pressed, wait for release, return scancode in A.
key_wait:
    push bc
key_wait_press:
    call key_scan
    or a
    jr z,key_wait_press
    ld b,a
key_wait_release:
    call key_scan
    or a
    jr nz,key_wait_release
    ld a,b
    pop bc
    ret

; A = scancode. Returns A=1 if that key is currently down, else 0.
key_down:
    or a
    ret z
    push bc
    push de
    dec a
    ld c,a                 ; scancode-1
    and 7
    ld b,a                 ; bit index 0..7
    ld a,c
    rrca
    rrca
    rrca
    and 7                  ; group
    ld c,a
    ; mask = ~(1 << group)
    ld a,1
    inc c
key_down_mask:
    dec c
    jr z,key_down_mask_done
    add a,a
    jr key_down_mask
key_down_mask_done:
    cpl
    ld c,a
    ld a,0xFF
    out (KEY_PORT),a
    ld a,c
    out (KEY_PORT),a
    nop
    nop
    nop
    nop
    in a,(KEY_PORT)
    ; test bit B (0=pressed)
    inc b
key_down_test:
    dec b
    jr z,key_down_bit0
    rrca
    jr key_down_test
key_down_bit0:
    and 1
    ld a,0
    jr nz,key_down_out     ; bit set → not pressed
    ld a,1
key_down_out:
    pop de
    pop bc
    ret
