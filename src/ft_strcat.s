section .text
    global  _ft_strcat

_ft_strcat:
    xor rcx, rcx
    mov rdx, rdi

_findnull:
    cmp byte[rdx], 0
    je  _concatenate
    inc rdx
    jmp _findnull

_concatenate:
    cmp byte[rsi], 0
    je  _terminate
    lodsb
    mov [rdx], rax
    inc rdx
    jmp _concatenate

_terminate:
    mov byte[rdx], 0
    mov rax, rdi
    ret