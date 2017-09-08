section .data
    nwln        db  0xa
    ERROR       db  "", 0x0a, 0
    SYS_WRITE   equ  0x2000004

section .text
    global  _ft_puts
    extern  _ft_strlen

_ft_puts:
    cmp     rdi, 0
    je      _error
    call    _ft_strlen
    mov     rcx, rdi
    mov     rdi, 1
    mov     rsi, rcx
    mov     rdx, rax
    mov     rax, SYS_WRITE
    syscall
    jmp     _newline

_newline:
    mov     rdi, 1
    lea     rsi, [rel nwln]
    mov     rdx, 1
    mov     rax, SYS_WRITE
    syscall
    mov     rax, 10
    jmp     _exit

_error:
    mov     rdi, 1
    lea     rsi, [rel ERROR]
    mov     rdx, 1
    mov     rax, SYS_WRITE
    syscall
    mov     rax, -10
    jmp     _exit

_exit:
    ret