#include "stdio.h"
/* Usaremos la funcion Scanf para la entrada de datos. */
int main(int argc, char *argv[]){
    
    char nombre[80];
    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    printf("\nTu nombre es: %s");
    return 0;
}