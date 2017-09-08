section .text
    global  _ft_islower

_ft_islower:
    cmp     rdi, 97
    jnge    _not_lower
    cmp     rdi, 122
    jg      _not_lower
    mov     rax, 1
    jmp     _exit

_not_lower:
    mov rax, 0
    ret

_exit:
    ret