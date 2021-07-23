#include "stdio.h"
/* Tipos de datos primitivos:Enteros (int), flotantes (float), caracter (char).
   Tipos de datos compuestos: struct, union, enum.
*/
short resultadoShort;
int resultadoInt;
long resultadoLong;
int main(int argc, char *argv[]){

    short tipoShort = 4; //2 bytes = 16 bits;
    int tipoInt = -25; //4 bytes = 32 bits;
    long tipoLong = 15; //8 bytes = 64 bits;

    /* Operadores aritmeticos
       Multiplicacion (*), Division (/), Modulo o resto (%)
       Suma (+) y Resta (-)
    */
    printf("----SHORT:\n");
    resultadoShort = 2 * tipoShort;
    printf("2 * %d = %d", tipoShort, resultadoShort);
    resultadoShort = 8 / tipoShort;
    printf("\n2 / %d = %d", tipoShort, resultadoShort);
    resultadoShort = 2 % tipoShort;
    printf("\n2 Resto %d = %d", tipoShort, resultadoShort);
    resultadoShort = 2 + tipoShort;
    printf("\n2 + %d = %d", tipoShort, resultadoShort);
    resultadoShort = 2 - tipoShort;
    printf("\n2 - %d = %d\n", tipoShort, resultadoShort);

    printf("----INT:\n");
    resultadoInt = 10 * tipoInt;
    printf("10 * %d = %d\n", tipoInt, resultadoInt);
    resultadoInt = 100 / tipoInt;
    printf("100 / %d = %d\n", tipoInt, resultadoInt);
    resultadoInt = 20 % tipoInt;
    printf("20 resto %d = %d\n", tipoInt, resultadoInt);
    resultadoInt = 60 + tipoInt;
    printf("60 + %d = %d\n", tipoInt, resultadoInt);
    resultadoInt = 90 - tipoInt;
    printf("90 - %d = %d\n", tipoInt, resultadoInt);

    printf("----LONG:\n");
    resultadoLong = 10 * tipoLong;
    printf("10 * %d = %d\n", tipoLong, resultadoLong);
    resultadoLong = 100 / tipoLong;
    printf("100 / %d = %d\n", tipoLong, resultadoLong);
    resultadoLong = 20 % tipoLong;
    printf("20 resto %d = %d\n", tipoLong, resultadoLong);
    resultadoLong = 60 + tipoLong;
    printf("60 + %d = %d\n", tipoLong, resultadoLong);
    resultadoLong = 90 - tipoLong;
    printf("90 - %d = %d\n", tipoLong, resultadoLong);
    return 0;
}