section .data
    NULL equ 0

section .text
    global  _ft_strlen
    global  _while
    extern  _print

_ft_strlen:
    push    rbp
    mov     rsi, 1
    call    _while

_while:
    xor     al, al          ; set lower oder byte of rax to zero
    ; xor     rcx, rcx        ; set rcx to zero
    mov rcx, -1

    ; if current byte is 0 stop
    inc     rcx
    cmp     byte [rdi + rcx], 0x00
    mov     rsi, rcx
    call    _print    
    jne     _while
    jmp     END

END:
    mov     rsi, rcx
    call    _print
    lea     rax, [rcx]
    pop     rbp
    ret