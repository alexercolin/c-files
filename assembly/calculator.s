//****************************************
// Calculadora de Multiplicação
// Grupo: Alex Ercolin, Samuel Simon
//****************************************

//região de dados
ram 100 0    
ram 101 0    
ram 102 0    


cseg
org Inicio 0


lda ac,0      
str 102,ac    


lda ac,4094   
str 101,ac    


lda ac,101
je Fim        


Loop:
    lda ac,102    
    add ac,100    
    str 102,ac    
    
    lda ac,101    
    sub ac,1      
    str 101,ac    
    
    jz Fim        
    jmp Loop      


Fim:
    lda ac,102    
    str 4092,ac   
    hlt           