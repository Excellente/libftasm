section .data
    SYS_WRITE   equ  0x2000004

section .text
    global  _ft_strlen

_ft_strlen:
    mov rsi, rdi
    xor rax, rax
    xor rcx, rcx

_len:
    cmp byte [rsi], 0
    je  _exit
    inc rcx
    lodsb
    jmp _len

_exit:
    mov rax, rcx
    ret