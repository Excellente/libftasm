section .text
    global  _ft_strdup
    extern  _malloc
    extern  _ft_strlen
    extern  _ft_memcpy

_ft_strdup:
    push    rdi
    call    _ft_strlen
    mov     rdi, rax
    push    rdi
    call    _malloc
    mov     rdi, rax
    pop     rdx
    pop     rsi
    push    rdx
    call    _ft_memcpy
    pop     rdx
    mov     byte[rax + rdx], 0
    ret