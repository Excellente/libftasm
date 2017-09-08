section .text
    global  _ft_memset

_ft_memset:
    mov rax, rsi
    mov rcx, rdx
    rep stosb       ;; fill memory rdi with rcx times of rax

_exit:
    mov rax, rdi
    ret