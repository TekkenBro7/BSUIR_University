 org $8000
 ldaa #$3 ; номер строки
 ldab #$2 ; номер столбца
 deca
 staa $8001
 adca $8001 
 adca $8001
 staa $8002
 addb $8002
 clra
 addd #8100

 