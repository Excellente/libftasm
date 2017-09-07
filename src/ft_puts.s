section	.data
	SYS_EXIT	equ	60
	SYS_WRITE	equ	1
	STD_OUT		equ	1

section	.text
	global	start
	global	ft_puts
	extern	ft_strlen

ft_puts:
	cmp	[rdi], byte 0
	je	exit
	call	start
	ret
start:
	push	rdi
	call	ft_strlen
	pop	rsi
	mov	rdi, STD_OUT
	mov	rdx, rax
	mov	rax, SYS_WRITE
	syscall
	jmp	exit

exit:
	mov	rax, SYS_EXIT
	mov	rdi, 0
	syscall
