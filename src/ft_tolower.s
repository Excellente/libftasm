section .text
    global  _ft_tolower
    extern  _ft_isupper
    extern  _ft_isalpha

_ft_tolower:
    call    _ft_isalpha
    mov     rcx, rax
    call    _ft_isupper
    and     rax, rcx
    cmp     rax, 1
    jne     _leave
    add     rdi, 32
    mov     rax, rdi
    jmp     _exit

_leave:
    mov     rax, rdi
    jmp     _exit

_exit:
    ret