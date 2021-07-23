#include <stdio.h>
#define ABC_DARIO 26
#define MAX_PALABRA 120

void cifrarPalabra(char *ptrPalabraEnClaro, char letrasEnClaro[ABC_DARIO], char letrasCifrado[ABC_DARIO]){
    printf("Palabra cifrada: ");
//RECORRE LA PALABRA QUE SE INGRESO.   
    for (int i = 0; i < ptrPalabraEnClaro[i]; i++)
    {
//RECORRE EL ARRAY DEL ABECEDARIO.
        for (int j = 0; j < ABC_DARIO; j++)
        {
//COMPARA AMBAS LETRAS RECORRIDAS, SI COINCIDEN, SE IMPRIME LA LETRA DEL ABECEDARIO MODIFICADO EN EL LUGAR QUE LE CORRESPONDE.
            if (letrasEnClaro[j] == ptrPalabraEnClaro[i])
            {
                printf("%c", letrasCifrado[j]);
            }
        }
    }
    printf("\n---------------------------\n");
}
int validarPalabra(char palabra[MAX_PALABRA]){
    int mayuscula = 0;
    printf("\n---------------------------\nPalabra en claro: %s\n", palabra);
    for (int i = 0; i < palabra[MAX_PALABRA]; i++)
    {
        if (palabra[i] && palabra[i] >= 'A' && palabra[i] <= 'Z' || palabra[i] ==' ')
        {
            mayuscula = 1;
            //printf("%c", palabra[i]);
        }
        else if(!palabra[i])
        {
            break;
        }
        else
        {
            mayuscula = 0;
            break;
        }
    }
    //printf("Mayuscula desde el int: %d | ", mayuscula);
    
    return mayuscula;
}
void cifradoResultado(){
//VARIABLES NECESARIAS.
    char letrasEnClaro[ABC_DARIO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char letrasCifrado[ABC_DARIO] = {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'};
    char palabra[MAX_PALABRA];
    int mayuscula;

//SOLICITAR LA PALABRA.
    printf("Cifrado Cesar (3 posiciones).\nIngrese la palabra a cifrar (Solo mayusculas): ");    
//EL "scanf" SE DECLARA DE ESA FORMA PARA ACEPTAR ESPACIOS BLANCO, AUNQUE EN EL CIFRADO SERAN OMITIDOS.
    scanf("%120[^\n]", palabra);

//SE OBTIENE EL VALOR DE LA VALIDACION DE LA PALABRA.
    mayuscula = validarPalabra(palabra);
    //printf("Mayuscula desde el main: %d", mayuscula);

//REALIZACION DEL CIFRADO O NO, DEPENDIENDO DEL VALOR DE LA VALIDACION.
    if (mayuscula == 1)
    {
        cifrarPalabra(palabra, letrasEnClaro, letrasCifrado);
    }
    else
    {
        printf("\nIngrese solamente letras mayusculas.");
        printf("\n---------------------------\n");
    }
}
int main(int argc, char *argv[]){
    cifradoResultado();
    return 0;
}