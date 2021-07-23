#include <stdio.h>
int main(int argc, char *argv[]){
    
    char ch = ' ';
    char cad[80];
    printf("Introduzca un caracter: ");
    ch = getchar();
    printf ( "Su caracter es: ");
    putchar(ch);
    printf("\nIntroduzca cadena de caracteres: ");
    scanf("%s", cad);
    printf("\nSu cadena es: %s", cad);
    printf("\nOtra cadena: ");
    gets(cad);
    gets(cad);
    printf("Cadena: ");
    puts(cad);


    return 0;

}