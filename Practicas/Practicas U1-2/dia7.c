#include <stdio.h>
#include <stdlib.h>

/*
       Sentencias de control.
Las sentencias de control son (bloques de codigo, esto quiere decir que tienen "{ }"):

    1. if.
    2. if-else.     1, 2, y 3 trabajan evaluando sentencias tendiendo a verdadero (logica positiva), pudiendo
    3. if-else-if.  evaluar a logica negativa.
    4. switch: case: break; default;    se puede evaluar con enteros o caracteres.
Las sentencias de control se utilizan para cambiar el flujo de ejecucion de un programa, es decir, una toma de decisiones.
*/

int main(int argc, char *argv[]){

    int numero;
    //Primer sentencia de control
    if(argc < 2){
        printf("\nOlvido incluir al menos un argumento, con el nombre del programa.\n");
    }
    //Seunda sentencia de control    
    if (argc >= 2)
    {
        printf("\nTu segundo argumento es: %s \n", argv[1]);
    }
    else
    {
        printf("\nOlvido incluir al menos un argumento, con el nombre del programa.\n");
    }
    //Tercera sentencia de control
    if (argc == 2)
    {
        printf("\nTu segundo argumento es: %s \n", argv[1]);
    }
    else
    if (argc > 2 && argc < 4)
    {
        printf("\nTu segundo argumento es: %s \n", argv[1]);
        printf("\nTu tercer argumento es: %s \n", argv[2]);
    }
    else
    {
        printf("\nOlvido incluir al menos un argumento, con el nombre del programa.\n");
    }
    //Cuarta forma de control a caracter
    if (argc >= 4)
    {
        switch (argv[3][0])
            {
            case 'a':
                printf("\nEl primer caracter de tu tercer argumento es: %c \n", argv[3][0]);
                break;
            
            case 'e':
            case 'i':
                printf("\nEl primer caracter de tu tercer argumento es: %c \n", argv[3][0]);
                break;
            case 'o':
            case 'u':
                printf("\nEl primer caracter de tu tercer argumento es: %c \n", argv[3][0]);
                break;
            default:
                printf("\nEl primer caracter de tu tercer argumento no tiene vocal.\n");
                break;
            }   
    }      
    if (argc >=5)
    {
        //Cuarta forma de control a entero
        numero = atoi(argv[4]);
        switch (numero)
            {
            case 100:
                printf("\nIntrodujo un numero %d \n", numero);
                break;
            
            case 10:
            case 20:
                printf("\nIntrodujo un numero %d \n", numero);
                break;
            case -30:
            case -40:
                printf("\nIntrodujo un numero: %d \n", argv[3][0]);
                break;
            default:
                printf("\nNo agrego un valor como: 100, 10, 20, -30, -40\n");
                break;
            }
    }
    

    return 0;
}