section .text
    global  _ft_memset

_ft_memset:
    cmp rdx, 0
    je  _exit
    mov rax, rsi
    mov rcx, rdx
    rep stosb       ;; fill memory rdi with rcx times of rax

_exit:
    mov rax, rdi
    ret