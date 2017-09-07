section	.data
	SYS_EXIT	equ	0x2000001
	SYS_WRITE	equ	0x2000004
	STD_OUT		equ	1
	EOF			equ (-1)
	nwln		db 0xa

section	.text
	global	start
	global	_ft_puts
	extern	_ft_strlen

_ft_puts:
	; cmp	[rdi], byte 0
	; je	_quit
	mov	rcx, rdi

	call	_ft_strlen
	mov	rdi, STD_OUT
	mov	rsi, rcx
	mov	rdx, rax
	mov	rax, SYS_WRITE
	syscall
	jmp	exit

_quit:
	mov	rdi, STD_OUT
	lea	rsi, [rel nwln]
	mov	rdx, 1
	mov	rax, SYS_WRITE
	syscall
	jmp	exit

exit:
	mov	rax, rdx
	ret
