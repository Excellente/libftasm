section .data
    NWLN        db  0x0a
    INPUT       db  "Reverse me!", 0
    EXIT_SUC    equ 0
    SYS_EXIT    equ 0x2000001
    SYS_WRITE   equ 0x2000004

section .bss
    OUTPUT  resb    11

section .text
    global  _main

_main:
    xor rcx, rcx
    xor rdx, rdx
    lea rsi, [rel INPUT]
    lea rdi, [rel OUTPUT]
    call    _loop
    ret

_loop:
    cmp     byte [rsi], 0
    je      _reverse
    inc     rcx
    lodsb
    push    rax
    jmp     _loop

_reverse:
    cmp rcx, 0
    je  _print
    pop rax
    mov [rdi + rdx], rax
    inc rdx
    dec rcx
    jmp _reverse

_print:
    mov rdi, 1
    lea rsi, [rel OUTPUT]
    mov rax, SYS_WRITE
    syscall
    jmp _newline

_newline:
    mov rdi, 1
    mov rsi, NWLN
    mov rax, SYS_WRITE
    mov rdx, 1
    syscall
    jmp _exit

_exit:
    mov rax, SYS_EXIT
    mov rdi, EXIT_SUC
    syscall
    ret