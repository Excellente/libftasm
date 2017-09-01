section .data
    string db "Hello"

section .text
    global  _ft_strlen
    global  _main
_main:
    push    rbp             ; setting up the stack into
    mov     rbp, rsp        ; base pointer register to access the stack contents
    
    call    _ft_strlen
    
    mov     rsp, rbp        ; getting previous stack info
    pop     rbp             ; retrieving previous ebp value 
    ret

_ft_strlen: