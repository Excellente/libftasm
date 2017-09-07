section .data
    nwln db 0xa

section .text
    global  _ft_puts
    extern  _ft_strlen

_ft_puts:
    cmp     rdi, 0
    je      _newline
    push    rbp
    mov     rbp, rsp
    sub     rsp, 8
    call    _ft_strlen
    mov     rcx, rdi

_print:
    mov     rdi, 1
    mov     rsi, rcx
    mov     rdx, rax
    mov     rax, 0x2000004
    syscall

_newline:
    mov     rdi, 1
    lea     rsi, [rel nwln]
    mov     rdx, 1
    mov     rax, 0x2000004
    syscall
    jmp     _exit

_exit:
    mov rax, 0x2000001
    mov rdi, 0
    syscall