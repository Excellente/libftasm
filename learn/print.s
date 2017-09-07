section .data
    nl db 0xa

section .text
    global _print

_print:
    ; MAIN ARGUMENTS
    mov rcx, rdi            ; argument from main
    mov r8,  rsi            ; argument from main

    ; SET-UP
    push    rbp
    mov     rbp, rsp
    sub     rsp, 8

    ; CODE
    mov     rdi, 1              ; stdoutfd: sys_call arg1
    mov     rsi, rcx            ; message:  sys_call arg2
    mov     rdx, r8             ; length:   sys_call arg3
    mov     rax, 0x2000004      ; opcode:   sys_call opcode
    syscall

    ; print newline
    mov     rdi, 1              ; stdoutfd: sys_call arg1
    lea     rsi, [rel nl]
    mov     rdx, r8             ; length:   sys_call arg3
    mov     rax, 0x2000004
    syscall

    ; EXIT
    mov rax, 0x2000001
    mov rdi, 0
    syscall

    ; RETURN
    pop rbp
    mov rax, rcx
    ret