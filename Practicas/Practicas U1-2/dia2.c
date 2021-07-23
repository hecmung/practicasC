#include "stdio.h"

//arc: cuenta con los argumentos desde la linea de comando
//argv: almacena los argumentos
/*los argumentos para un programa desde linea de comando se 
distinguen con un espacion en blanco*/

int main(int argc, char *argv[]){

    int i = 0;
    printf("Argumentos de C\n");
    
    for(i = 0; i < argc; i++){
        // '%s' imprime una cadena de caracteres
        // '%d' imprime un numero entero
        // El orden de las variables afecta al querer imprimir
        printf("Argumento[%d]: %s", i, argv[i]);
        printf("\n");
    }
    return 0;
}