#include "stdio.h"

char resultadoChar;

int main(int argc, char *argv[]){
    
    char unoChar='H';
    char dosChar='o';

    printf("CHAR\n");
    resultadoChar = unoChar + dosChar;
    printf("%c + %c = %c \n", unoChar, dosChar, resultadoChar);
    resultadoChar = unoChar - dosChar;
    printf("%c - %c = %c \n", unoChar, dosChar, resultadoChar);
    resultadoChar = unoChar * dosChar;
    printf("%c * %c = %c \n", unoChar, dosChar, resultadoChar);
    resultadoChar = unoChar / dosChar;
    printf("%c / %c = %c", unoChar, dosChar, resultadoChar);

    return 0;
}