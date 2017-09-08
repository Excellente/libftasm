section .data
	SYS_EXIT	equ	60

section .text
	global	_ft_bzero

_ft_bzero:
	mov	rcx, rsi

loop:
	cmp	rcx, 0
	je	_exit
	dec	rcx
	mov	byte [rdi], 0
	inc	rdi
	jmp	loop

_exit:
	mov	rax, SYS_EXIT
	mov	rdi, 0
	syscall
	ret
	
