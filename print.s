segment .text
    global _print

_print:
    ; MAIN ARGUMENTS
    mov rcx, rdi            ; argument from main
    mov r8,  rsi            ; argument from main

    ; CODE
    mov rdi, 1              ; sys_call arg1
    mov rsi, rcx            ; sys_call arg2
    mov rdx, r8             ; sys_call arg3
    mov rax, 0x2000004      ; sys_call opcode
    syscall

    ; EXIT
    mov rax, 0x2000001
    mov rdx, 0
    syscall