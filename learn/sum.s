section .data
;; define constants
num2: equ 50
num1: equ 100

SYS_EXIT: equ 60
SYS_WRITE: equ 1

;; initialize message
msg: db "Sum is correct", 0xa
len: equ $ - msg

section .text
    global _main
    global _start

_main:
    call _start
    ret

;; program entry point
_start:
    mov rax, num1
    mov rbx, num2
    add rax, rbx        ;; add rbx to rax, and store the value to rax
    cmp rax, 150        ;; check if rax holds the value 150
    jne _exit           ;; exit if the rax value is not 150
    jmp _corsum         ;; goto _corsum if the value is 150

_corsum:
    mov rdi, 1          ;; fd for stdout
    mov rsi, msg        ;; message to be printed onCorrectSum
    mov rdx, len        ;; the length of the message
    mov rax, SYS_WRITE  ;; the system call
    syscall             ;; calling the kernel
    jmp _exit           ;; exit the program

_exit:
    mov rax, SYS_EXIT   ;; exit syscall
    mov rdi, 0          ;; exit success
    syscall             ;; calling the kernel
