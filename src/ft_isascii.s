section .text
    global  _ft_isascii

_ft_isascii:
    cmp     rdi, 0
    jnge    _not_ascii
    cmp     rdi, 127
    jg      _not_ascii
    mov     rax, 1
    jmp     _exit

_not_ascii:
    mov rax, 0
    ret

_exit:
    ret