section .data
	SYS_EXIT	equ	0x2000001
	SYS_WRITE	equ	0x2000004
	STD_OUT		equ	1
	EOF			equ (-1)
	nwln		db 0xa

section	.text
	global	start
	global	_ft_puts

_ft_puts:
	;; SETUP
	push	 rbp
	mov	rbp, rsp
	sub	rsp, 8

	cmp	[rdi], byte 0
	je	_exit
	; mov	rcx, rdi

; 	mov	rdi, STD_OUT
; 	mov	rsi, rcx
; 	mov	rdx, rax
; 	mov	rax, SYS_WRITE
; 	syscall
; 	jmp	exit

; _quit:
; 	mov	rdi, STD_OUT
; 	lea	rsi, [rel nwln]
; 	mov	rdx, 1
; 	mov	rax, SYS_WRITE
; 	syscall
; 	jmp	exit

_exit:
	pop	rsp
	mov	rax, SYS_EXIT
	mov	rdi, 0
	syscall

; ; exit:
; ; 	mov	rax, rdx
; ; 	ret
