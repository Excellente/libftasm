section .text
    global  _ft_isupper

_ft_isupper:
    cmp     rdi, 65
    jnge    _not_upper
    cmp     rdi, 90
    jg      _not_upper
    mov     rax, 1
    jmp     _exit

_not_upper:
    mov rax, 0
    ret

_exit:
    ret