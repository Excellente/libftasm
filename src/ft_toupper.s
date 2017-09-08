section .text
    global  _ft_toupper
    extern  _ft_islower
    extern  _ft_isalpha

_ft_toupper:
    call    _ft_isalpha
    mov     rcx, rax
    call    _ft_islower
    and     rax, rcx
    cmp     rax, 1
    jne     _leave
    sub     rdi, 32
    mov     rax, rdi
    jmp     _exit

_leave:
    mov     rax, rdi
    jmp     _exit

_exit:
    ret