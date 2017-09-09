section .data
    SYS_READ    equ 0x2000003
    SYS_WRITE   equ 0x2000004
    BUFF_S      equ 1
    EOF         equ (0)

section .bss
    tBuffer resb    2

section .text
    global  _ft_cat
    extern  _printf

_ft_cat:
    mov rcx, 1
    lea rsi, [rel tBuffer]
    mov byte[rsi + BUFF_S], 0
    mov rax, 2

_loop:
    cmp rax, EOF
    je  _exit
    push    rdi
    call    _read
    push    rax
    call    _write
    pop     rax
    pop     rdi
    jmp     _loop

_read:
    mov rdx, BUFF_S
    lea rsi, [rel tBuffer]
    mov rax, SYS_READ
    syscall
    ret

_write:
    mov rdi, 1
    lea rsi, [rel tBuffer]
    mov rdx, BUFF_S
    mov rax, SYS_WRITE
    syscall
    ret

_exit:
    ret