.model small;   
.stack 100h;    
.data
    i dw 0h
    string db 'Enter the string : $' 
    arr db 200h dup(0h)
.code   
start:
    mov ax, @data  
    mov ds, ax
    mov ah, 09h
    lea dx, string
    int 21h 
    mov ah, 1h;          
    mov bx, 0h
input:                  
    int 21h
    mov cx, si
    mov arr[bx], cl
    cmp al, 32
    jne addToArray
    cmp cl, 0h	         
    je input            
    mov si, 0h
    add bx, 15h         
    jmp input
addToArray:
    inc si
    mov arr[bx+si], al 
    cmp al, 13
    jne input
    mov arr[bx+si], 0h
    mov i, bx            
    mov bx, 0h
sort:                    
    mov di, bx           
    mov ax, bx                                                                                   
    add ax, 15h
compare:
    mov si, ax 
    mov cl, arr[di]
    cmp cl, arr[si]
    jae compareEnd         
    mov di, si           
compareEnd: 
    add ax, 15h
    cmp ax, i
    jle compare
    mov si, 0h
swap:
    mov cl, arr[bx+si]   
    mov al, arr[di]
    mov arr[bx+si], al
    mov arr[di], cl
    inc si
    inc di
    cmp si, 15h
    jb swap
    add bx, 15h
    cmp bx, i
    jb sort
    mov ah, 02h           ;func setting pos cursor
    mov bh, 0h            ;num page 
    mov dh, 2h            ;num line
    mov dl, 0h            ;num column
    int 10h
    mov bx, 0h
    mov si, 0h
    mov ah, 2h            ;func output symbol
output:                   
    inc si
    mov dx, word ptr arr[bx+si]
    cmp dx, 0h
    jne skip
    cmp bx, i
    je exit
    mov si, 0h
    add bx, 15h
    mov dx, ' ' 
skip:
    int 21h
    cmp bx, i
    jbe output
exit:
    mov ah, 4ch
    int 21h 
end Start