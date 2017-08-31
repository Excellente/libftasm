section .data
    msg db "Hello", 0xa
    len db $ - msg

section .text
    global _main
    global start
    extern _printf

start:
    call    _main
    ret

_main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    lea     rdi, [rel msg]
    call    _printf
    leave
    ret