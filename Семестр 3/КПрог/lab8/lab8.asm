.model small
.code
org 100h
start:
    public _FUNCTION_LIST
    public _KEYS
    public _NEXT_KEY
    
    
_FUNCTION_LIST PROC
    push bp 
    mov bp, sp 
    push es 
    push ss 
    push ds
    push si
   push di 
    ;pusha 
    ;push cx 
    mov si, [bp + 4] 
    lea di, cs:byte ptr string
    mov cx, [bp + 6]
    mov cs:word ptr passlen, cx
    push cs 
    pop es     
s: 
    movsb 
    loop s
    mov ah, 9
    push cs
    pop ds
    lea dx, string
    int 21h
   pop di
  pop si 
    pop ds 
    pop ss 
    pop es 
    pop bp 
    ret
    string db 150 dup('$')
   passlen dw 0 
_FUNCTION_LIST ENDP


_KEYS PROC
    push es 
    push ss 
    push ds
    push si
    push di
    ;  push ax
    mov ah, 00h
    int 16h
    ;   pop ax
    pop di
    pop si 
    pop ds 
    pop ss 
    pop es
    ret
_KEYS ENDP


_NEXT_KEY PROC
    push es 
    push ss 
    push ds
    push si
    push di
    ;  push ax
    mov ah, 00h
    int 16h
    ;   pop ax
    pop di
    pop si 
    pop ds 
    pop ss 
    pop es
    ret
_NEXT_KEY ENDP

end start