section .text
    global  _ft_isprint

_ft_isprint:
    cmp     rdi, 32
    jnge    _not_print
    cmp     rdi, 126
    jg      _not_print
    mov     rax, 1
    jmp     _exit

_not_print:
    mov rax, 0
    ret

_exit:
    ret