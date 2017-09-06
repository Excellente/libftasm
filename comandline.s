section .data
    SYS_WRITE       equ 0x2000004   ;; system write function   
    STD_IN          equ 1           ;; file descriptor for stdout
    SYS_EXIT        equ 1           ;; system exit function
    EXIT_SUCCESS    equ 0           ;; succesful exec
    EXIT_FAILURE    equ 0           ;; unsuccesful exec

    NEW_LINE        db  0xa         ;; '\n' new line character
    WRONG_ARGC      db  "Must be two command line arguments", 0xa
    LEN             equ $ - WRONG_ARGC

section .text
    global  _main

_main:
    pop     rcx             ;; argc is first in the stack | argumnt count [rsp]
    cmp     rcx, 3          ;; checks if the program did collect 2 command line args + prog name
    jne     argc_error      ;; error if arguments aint 2

    add     rsp, 8          ;; incrementing the stack pointer, past the program name
    pop     rsi             ;; copy first command line argument | [rsp + 8]
    call    str_to_int      ;; converts first arg from str to int, since its an int

    mov     r10, rax        ;; mov converted value to r10
    pop     rsi             ;; copy 2nd command line argument | [rsp + 16]
    call    str_to_int      ;; converts 2nd arg from str to int, since its an int
    mov     r11, rax        ;; mov converted value to r11

    add     r10, r11        ;; compute summ of the two arguments
    mov     rax, r10
    xor     r12, r12
    jmp     int_to_str

str_to_int:
    xor rax, rax            ;; zero out the rax register
    mov rcx, 10
next:
    cmp [rsi], byte 0       ;; compare byte currently pointed to by [rsi]
    je  return_str          ;; function return if null
    mov bl, [rsi]           ;; move the byte pointed to by [rsi] to bl byte register
    sub bl, 48              ;; convert a ascii character to its true value
    mul rcx                 ;; mutliply rax on rcx
    add rax, rbx
    inc rsi                 ;; increment [rsi] to point to the next byte
    jmp next
return_str:
    ret

int_to_str:
    mov rdx, 0              ;; zero out [rdx]
    mov rbx, 10             ;; push 10 to [rbx]
    div rbx                 ;; [rdx] = [rax] % source(rbx):[rax] divided by [rbx], remainder in rdx
    add rdx, 48             ;; take a number and convert it to its ascii value 
    add rdx, 0x0            ;; append the null terminator in the string
    push rdx                ;; save symbol to stack
    cmp rax, 0x0            ;; compare for 0, if rax is 0, we reached the end
    jne int_to_str
    jmp print

print:
	;;;; calculate number length
	mov rax, 1
	mul r12
	mov r12, 8
	mul r12
	mov rdx, rax

	;;;; print sum
	mov rax, SYS_WRITE
	mov rdi, STD_IN
	mov rsi, rsp
	;; call sys_write
	syscall

    jmp _exit

argc_error:
    mov rax, SYS_WRITE
    mov rdi, STD_IN
    mov rsi, WRONG_ARGC
    mov rdx, LEN
    syscall
    jmp _exit

_exit:
    mov rax, SYS_EXIT
    mov rdi, EXIT_FAILURE
    syscall
    ret