.model small
.stack 100h
.data
    inputLimitsString db "Number system - [2,16]. ", 0Dh, 0Ah, "Min value = -32768, max value = 32767.$"
    notation db "Enter the number system: $"
    inputInviteString db "Enter number: $"
    invalidLengthString db "Invalid length input. 2 <= length <= 16.$"
    invalidInputString db "Invalid input. $"
    ;æoverflowInputString db "Number is too big. $"
    tryAgainString db "Try again: $"
    newLine db 0Dh,0Ah,'$'
    length dw ?            
    number dw ?
    sign db ?
    output_msg db "Converted number: $"
    yes dw ?
    numberTen dw 000Ah          
    sizeOfNumber equ 2
    numberStringLength equ 20
    numberString db numberStringLength dup('$') 
    askRestartString db "Do you want to restart program? 1-yes, other-no: $"              
    maxArrayLength equ 16 ; max number system       
    array dw maxArrayLength dup(?)        
.code
                            
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
 ;   lea dx, overflowInputString
 ;   call outputString
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
    ;push 1
    mov sign, '+'
    cmp [si], '+'
    jne isNullString
    inc si
    jmp isNullString
negative:
   ; push -1
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
   ; pop bx ; 1 or -1
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
   
 
NumberSystemInput proc
    call printNewLine
    lea dx, notation 
    call outputString
    lea di, length
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
NumberSystemInput endp
        
        
NumberInput proc
    call printNewLine
    lea di, number
    mov cx, 0001h   ; one number input
    call inputNumbers
    mov number, ax
    call printNewLine
ret
NumberInput endp


decimalToCustomSystem proc
    lea dx, output_msg 
    call outputString
    mov ax, number
    cmp ax, 0
    je nol
    mov al, [sign]
    cmp al, '-'
    jne notMinus
    mov dl, '-'
    mov ah, 2
    int 21h
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
 ;  cmp al, 0h
    cmp ax, 0h
    je zeroResult    
    cmp ax, 0
    jns conversionLoop
    jz zeroResult
zeroResult:
    mov ah, 2
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
    call NumberSystemInput
    mov ax, maxArrayLength[1]
    call NumberInput                 
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