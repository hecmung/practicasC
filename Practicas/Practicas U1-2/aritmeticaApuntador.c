#include <stdio.h>

/*
La aritmetica de punteros se hace mediante los operadores:
    ++ (incremento)
    -- (decremento)
    + (suma)
    - (resta)
Ejemplo:
    int numeros[10];
    int *ptrNum = numeros;
----Recorriendo el arreglo con un indice----
    for(int i = 0; i < 10; i++){
        numeros[i] = i;
    }
    for(int i = 0; i < 10; i++){
        *ptrNum ++ = i;
    }
*/
#define MAX 10
int main(int argc, char *argv[]){
    
    int numeros[MAX];
    int *ptrNum = numeros;
    //Recorriendo el arreglo con un indice
    for (int i = 0; i < MAX; i++)
    {
        numeros[i] = 0;
        printf("Arreglo:\t%d\n", numeros[i]);
    }
    for (int i = 0; i < MAX; i++)
    {
        *ptrNum ++ = i;
        printf("Apuntador:\t%d\n", numeros[i]);
    }
    
       
    return 0;
}