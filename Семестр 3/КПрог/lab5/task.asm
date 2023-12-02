.model small
.stack 100h
.data
    inputLimitsString db "Number system - [2,16]. ", 0Dh, 0Ah, "Min value = -32768, max value = 32767.$"
    notation db "Enter the number system convert to: $"
    notation2 db "Enter the number system from: $"
    number_syst db "Enter the number from this system: $"
    inputInviteString db "Enter number: $"
    invalidLengthString db "Invalid length input. 2 <= length <= 16.$"
    invalidInputString db "Invalid input. $"
    tryAgainString db "Try again: $"
    newLine db 0Dh,0Ah,'$'
    length dw ?            
    number dw ?
    sign db ?
    signn db ?
    output_msg db "Converted number: $"
    yes dw ?
    numberTen dw 000Ah          
    sizeOfNumber equ 2
    numberStringLength equ 20
    numberString db numberStringLength dup('$') 
    askRestartString db "Do you want to restart program? 1-yes, other-no: $"              
    maxArrayLength equ 16 ; max number system       
    array dw maxArrayLength dup(?)       
    num_from dw 16    ; system conv from
    aaaa db 10 dup('$')
    nn db 0
    ar db 20 dup('$')
    ost db 1
    first_ind db ?        
.code


NumberInput proc
    call printNewLine
    lea dx, number_syst
    call outputString
    xor dx, dx
    xor ax, ax
    lea dx, aaaa
    mov ah, 0Ah
    int 21h
    call convert_to_ten    
    call printNewLine
ret 
NumberInput endp


proc convert_to_ten
    xor dx, dx
    mov dl, aaaa[1]
    add dl, 1
    mov si, dx
    xor ax, ax    
    xor dx, dx    
    mov cx, 1
    mov ax, 0   
loooop:
    xor bx, bx
    mov bl, aaaa[si]
    cmp bx, '-'
    je minuss
    cmp si, 1
    je endddd
go_after_min:
    cmp bx, 97
    je tenn
    cmp bx, 98
    je elev
    cmp bx, 99
    je twelve
    cmp bx, 100
    je thirteen
    cmp bx, 101
    je fourteen
    cmp bx, 102
    je fifteen
    sub bl, '0'

    
afterr:
    push ax
    mov ax, cx
    mul bx
    xchg ax, bx
    pop ax
    add ax, bx
    xchg ax, bx 
    mov ax, num_from
    mul cx
    mov cx, ax
    xchg ax, bx    
    dec si 
    jmp loooop  
tenn:
    mov bx, 10
    jmp afterr
elev:
    mov bx, 11
    jmp afterr    
twelve:
    mov bx, 12
    jmp afterr    
thirteen:
    mov bx, 13
    jmp afterr    
fourteen:
    mov bx, 14
    jmp afterr    
fifteen:
    mov bx, 15
    jmp afterr               
minuss:
    mov signn, '-'
    dec si
    jmp loooop    
endddd:
    mov number, ax    
ret
convert_to_ten endp

                            
inputNumbers proc
    call printNewLine
    lea dx, inputInviteString
    call outputString
repeatElementInput:
    lea dx, numberString 
    call inputString
    lea si, numberString[2]                           
    call parseString                             
    jc invalidInput     ; if flag PERENOSA (C) = 1                                
    call loadNumber
    loop inputNumbers            
ret
invalidInput:
    call printNewLine
    lea dx, invalidInputString
    call outputString
    jno tryAgainOutput  ; if flag OVERFLOW (V) = 0
tryAgainOutput:
    lea dx, tryAgainString
    call outputString
    jmp repeatElementInput    
loadNumber:
    mov [di], ax
    add di, sizeOfNumber
ret
inputNumbers endp


parseString proc
    xor dx, dx
    xor bx, bx
    xor ax, ax
    jmp inHaveSign
parseStringLoop:
    mov bl, [si]
    jmp isNumber
validString:
    sub bl, '0'     ; convert to num
    imul numberTen    
    jo invalidString    ; >32767
    js invalidString    ; -
    add ax, bx    
    js invalidString
    inc si
    jmp parseStringLoop
isNumber:
    cmp bl, 0Dh     ; Enter a key
    je endParsing
    cmp bl, '0'
    jl invalidString    ; if less than 0
    cmp bl, '9'
    jg invalidString    ; if more than 9
    jmp validString    
inHaveSign:
    cmp [si], '-'
    je negative     ; [si] = '-'
    mov sign, '+'
    cmp [si], '+'
    jne isNullString
    inc si
    jmp isNullString
negative:
    mov sign, '-'
    inc si
    jmp isNullString                   
isNullString:
    cmp [si], 0Dh
    je invalidString
    jmp parseStringLoop                      
invalidString:
    cmp ax, 32768
    je goqwe
inv:
    stc
ret
endParsing:
    clc
ret
setMinusSign:
    mov sign, '-'
    clc
ret
goqwe:
    cmp sign, '-'
    jne inv
    clc
ret                             
parseString endp
  
    
printNewLine proc
    lea dx, newLine
    call outputString
ret
printNewLine endp
 
 
outputString proc
    mov ah, 09h
    int 21h    
ret
outputString endp


inputString proc
    mov ah, 0Ah
    int 21h
ret
inputString endp


NumberSystemInput2 proc
    call printNewLine
    lea dx, notation2 
    call outputString
    lea di, num_from
    mov cx, 0001h   ; one number input
    call inputNumbers
    cmp ax, maxArrayLength
    jg invalidLengthInput   ; more than 16
    cmp ax, 0002h           
    jl invalidLengthInput   ; less than 2
    mov al, [sign]
    cmp al, '-'
    je invalidLengthInput
ret
invalidLengthInput:
    call printNewLine
    lea dx, invalidLengthString
    mov sign, '+'
    call outputString
    call printNewLine
    jmp NumberSystemInput
NumberSystemInput2 endp

   
NumberSystemInput proc
    call printNewLine
    lea dx, notation 
    call outputString
    lea di, length
    mov cx, 0001h   ; one number input
    call inputNumbers
    cmp ax, maxArrayLength
    jg invalidLengthInput2   ; more than 16
    cmp ax, 0002h           
    jl invalidLengthInput2   ; less than 2
    mov al, [sign]
    cmp al, '-'
    je invalidLengthInput2
ret
invalidLengthInput2:
    call printNewLine
    lea dx, invalidLengthString
    mov sign, '+'
    call outputString
    call printNewLine
    jmp NumberSystemInput
NumberSystemInput endp
        
        
decimalToCustomSystem proc
    lea dx, output_msg 
    call outputString
    mov ax, number
    mov bx, length
    cmp ax, 0
    je nol
    mov al, [signn]
    cmp al, '-'
    jne notMinus    
    cmp bx, 2
    je bit_one:    
    mov dl, '-'
    mov ah, 2
    int 21h
    jmp notMinus
bit_one:
    mov nn, 1     
    mov ax, number    
notMinus:    
    mov ax, number
    xor cx, cx
    xor dx, dx
    mov bx, [length]
    cmp ax, 0h
    je zeroResult    
    cmp ax, 0
    jns conversionLoop
    jz zeroResult
conversionLoop:
    mov dx, 0
    div bx
    push dx
    inc cx
    cmp ax, 0
    jz zeroResult    
    cmp ax, 0h
    je zeroResult    
    cmp ax, 0
    jns conversionLoop
    jz zeroResult
zeroResult:
    mov ah, 2
    cmp nn, 1
    je dop
printLoop:
    pop dx
    add dl, '0'
    cmp dx, '9'
    jbe notGreaterThan9
    add dl, 7
notGreaterThan9:
    int 21h
    loop printLoop
    ret 
nol:
    mov ah, 2
    mov dx, ax
    add dl, '0'
    int 21h
ret
dop:
     xor dx, dx
     mov si, 1
     xor ax, ax
     mov ar[0], 1
dop_code:
    inc si
    pop dx
    mov ar[si], dl
    loop dop_code  
    xor ax, ax
    mov dx, si
    mov first_ind, dl    
obrat_code:
    cmp si, 1
    je gotov    
    cmp ar[si], 0
    je go_one
    mov ar[si], 0
    dec si
    jmp obrat_code
go_one:
    mov ar[si], 1
    dec si
    jmp obrat_code
gotov:
    mov dl, first_ind    
    mov si, dx    
    mov al, ar[si]
    add al, 1
    cmp al, 2
    je add_2
    mov ar[si], 1    
    jmp end_perevod
add_2:
    mov ar[si], 0
    mov ost, 1    
    dec si    
perevod_dop:
    cmp si, 0
    je end_perevod    
    mov al, ar[si]
    add al, ost
    cmp al, 2    
    je if_ost_2    
    jmp end_perevod
if_ost_2:
    mov ar[si], 0
    mov ost, 1
    dec si
    jmp perevod_dop
end_perevod:
    cmp ost, 1
    je dollar_1     
dollar_1:
    mov ar[si], 1    
    mov si, 0
    push dx
    xor dx, dx
    mov dl, first_ind
    mov cx, dx
    pop dx
    mov bx, cx
    inc bx
vivod:
    cmp si, bx
    je end_end
    mov ah, 2
    mov dl, ar[si]
    cmp dl, 36
    je skipp
    add dl, '0'
    cmp dx, '9'
    jbe notGreaterThan9_2
notGreaterThan9_2:
    int 21h
    inc si
    jmp vivod 
skipp:
    inc si
    jmp vivod
end_end:
    ret
decimalToCustomSystem endp


AskToRestart proc
    call printNewLine
    lea dx, askRestartString
    call outputString
    mov ah, 01h
    int 21h
    ret   
AskToRestart endp    
 
 
ClearConsole proc
    mov ah, 06h     
    mov al, 0      
    mov bh, 07h   
    mov ch, 0     
    mov cl, 0      
    mov dh, 24      
    mov dl, 79     
    int 10h        
    mov ah, 02h    
    mov bh, 0      
    mov dh, 0       
    mov dl, 0   
    int 10h
    ret    
ClearConsole endp    

  
start:
    mov ax, @data
    mov ds, ax
    mov es, ax,
    xor ax, ax
    lea dx, inputLimitsString
    call outputString
    call printNewLine    
    call NumberSystemInput2
    call NumberInput
    call NumberSystemInput
    call printNewLine                      
    call decimalToCustomSystem
    call AskToRestart
    cmp al, '1'
    je restartProgram
    jmp programEnd
restartProgram:
    call ClearConsole
    mov sign, 0
    jmp start    
programEnd:    
    mov ah, 4Ch
    int 21h
end start