section .text
    global  _ft_isalpha

_ft_isalpha:
    xor     rcx, rcx
    xor     rdx, rdx
    call    _lowercase
    ret

_lowercase:
    cmp     rdi, 97
    jnge    _Lcasebridge
    cmp     rdi, 122
    jg      __alpha_eval
    mov     rdx, 1
    mov     rax, 1
    ret

_uppercase:
    cmp     rdi, 65
    jnge    __alpha_eval
    cmp     rdi, 90
    jg      _Ucasebridge
    mov     rcx, 1
    mov     rax, 1
    ret

_Ucasebridge:
    cmp     rdi, 97
    jnge    __alpha_eval
    jmp     _lowercase

_Lcasebridge:
    cmp     rdi, 90
    jg      __alpha_eval
    jmp     _uppercase

__alpha_eval:
    xor     rdx, rcx
    cmp     rdx, 0
    je      _exit
    mov     rax, 1
    ret

_exit:
    mov rax, 0
    ret
