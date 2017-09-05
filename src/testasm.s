section .data
    msg db "Hello World! :)", 0xa
    len equ $ - msg

section .text
    global _main
    global start
    extern _printf

start:
    call    _main
    ret

_main:
    mov rax, 0x2000004
    mov rdi, 1
    mov rsi, msg
    mov rdx, len
    syscall

    mov rax, 0x2000001
    mov rdi, 0
    syscall