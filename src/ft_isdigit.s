section .text
    global  _ft_isdigit

_ft_isdigit:
    cmp     rdi, 48
    jnge    _not_digit
    cmp     rdi, 57
    jg      _not_digit
    mov     rax, 1
    jmp     _exit

_not_digit:
    mov rax, 0
    ret

_exit:
    ret