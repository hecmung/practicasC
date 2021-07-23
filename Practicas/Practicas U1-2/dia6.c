/*
Se requiere calcular para la siguiente ecuacion Y = 2X^2 + 3; se emplean
datos desde [-3, 3]
*/
#include <stdio.h>

int main(int argc, char *argv[]){
    
    int y = 0;
    int x = 0;

    //ecuacion y = 2x^2 + 3
    printf("Calcularemos el valor de una ecuacion Y = 2X^2 + 3.\nIngresa el valor de X= ");
    scanf("%d", &x);
    y = 2 * (x * x ) + 3;
    printf("Para X = %d ; Y = %d",x,y);
    
    return 0;
}