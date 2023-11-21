 org $8000
 staa $8000
 stab $8001
 lsrb
 lsrb
 lsrb
 lsrb
 anda #%11110000
 aba
 staa $8002
 ldaa $8000
 ldab $8001
 lsla
 lsla
 lsla
 lsla
 andb #%00001111
 aba
 staa $8003
 ldaa $8002
 ldab $8003
 xgdx
 ldaa $8000
 ldab $8001 
