#include "stdio.h"

float unFloat = 3.1254;
double unDouble = 5.6665;

int main(int argc, char *argv[]){

    float dosFloat = 6.6;
    double dosDouble = 2.102;
    float resultadoF;
    double resultadoD;

    printf("\nFLOAT");
    resultadoF = unFloat * dosFloat;
    printf("\n%f * %f = %f", unFloat, dosFloat, resultadoF);
    resultadoF = unFloat / dosFloat;
    printf("\n%f / %f = %f", unFloat, dosFloat, resultadoF);
    resultadoF = unFloat + dosFloat;
    printf("\n%f + %f = %f", unFloat, dosFloat, resultadoF);
    resultadoF = unFloat - dosFloat;
    printf("\n%f - %f = %f \n", unFloat, dosFloat, resultadoF);

    printf("\nDOUBLE");
    resultadoD = unDouble * dosDouble;
    printf("\n%f * %f = %f", unDouble, dosDouble, resultadoD);
    resultadoD = unDouble / dosDouble;
    printf("\n%f / %f = %f", unDouble, dosDouble, resultadoD);
    resultadoD = unDouble + dosDouble;
    printf("\n%f + %f = %f", unDouble, dosDouble, resultadoD);
    resultadoD = unDouble - dosDouble;
    printf("\n%f - %f = %f \n", unDouble, dosDouble, resultadoD);

    return 0;
}