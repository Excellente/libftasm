section .data
	NULL		equ	0x00	;; null terminator definition

section .text
	global	_ft_strlen
	global	start

_ft_strlen:
	xor	rcx, rcx			;; zero out rcx register
	call	start

start:
	cmp	[rdi], byte NULL	;; compare byte at location pointed by rdi with NULL/0
	je	_exit				;; exit if equal to zero
	inc	rcx					;; else increment the rcx
	inc	rdi					;; update rdi to point to next byte
	jmp	start				;; repeat the process

_exit:
	mov	rax, rcx			;; set return value
	ret