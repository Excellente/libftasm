section .text
    global  _ft_isalnum
    extern  _ft_isdigit
    extern  _ft_isalpha

_ft_isalnum:
    call    _ft_isalpha
    mov     rcx, rax
    call    _ft_isdigit
    or      rax, rcx
    ret    