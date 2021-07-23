#include <stdio.h>
#define ABC_DARIO 26
#define MAX_PALABRA 120

void cifrarPalabra(char *ptrPalabraEnClaro, char letrasEnClaro[ABC_DARIO], char letrasCifrado[ABC_DARIO]){
    printf("Palabra cifrada: ");
//RECORRE LA PALABRA QUE SE INGRESO.   
    for (int i = 0; i < ptrPalabraEnClaro[i]; i++)
    {
//RECORRE EL ARRAY DEL ABECEDARIO EN CLARO.
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
            //printf("%c-", palabra[i]);
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
void cifradoCincoPosiciones(char palabra[MAX_PALABRA], int mayuscula, char letrasEnClaro[ABC_DARIO]){
    char letrasCifradoCincoPosiciones[ABC_DARIO] = 
        {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E'};
//SOLICITAR LA PALABRA.
    printf("\nCifrado Cesar (5 posiciones).\nIngrese la palabra a cifrar (Solo mayusculas): ");    
//EL "scanf" SE DECLARA DE ESA FORMA PARA ACEPTAR ESPACIOS BLANCO, AUNQUE EN EL CIFRADO SERAN OMITIDOS.
    scanf("%120[^\n]", palabra);

//SE OBTIENE EL VALOR DE LA VALIDACION DE LA PALABRA.
    mayuscula = validarPalabra(palabra);

//REALIZACION DEL CIFRADO O NO, DEPENDIENDO DEL VALOR DE LA VALIDACION.
    if (mayuscula == 1)
    {
        cifrarPalabra(palabra, letrasEnClaro, letrasCifradoCincoPosiciones);
    }
    else
    {
        printf("\nIngrese solamente letras mayusculas.");
        printf("\n---------------------------\n");
    }
}
void cifradoSietePosiciones(char palabra[MAX_PALABRA], int mayuscula, char letrasEnClaro[ABC_DARIO]){
    char letrasCifradoSietePosiciones[ABC_DARIO] = 
        {'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
//SOLICITAR LA PALABRA.
    printf("\nCifrado Cesar (7 posiciones).\nIngrese la palabra a cifrar (Solo mayusculas): ");    
//EL "scanf" SE DECLARA DE ESA FORMA PARA ACEPTAR ESPACIOS BLANCO, AUNQUE EN EL CIFRADO SERAN OMITIDOS.
    scanf("%120[^\n]", palabra);

//SE OBTIENE EL VALOR DE LA VALIDACION DE LA PALABRA.
    mayuscula = validarPalabra(palabra);

//REALIZACION DEL CIFRADO O NO, DEPENDIENDO DEL VALOR DE LA VALIDACION.
    if (mayuscula == 1)
    {
        cifrarPalabra(palabra, letrasEnClaro, letrasCifradoSietePosiciones);
    }
    else
    {
        printf("\nIngrese solamente letras mayusculas.");
        printf("\n---------------------------\n");
    }
}
void cifradoOncePosiciones(char palabra[MAX_PALABRA], int mayuscula, char letrasEnClaro[ABC_DARIO]){
    char letrasCifradoOncePosiciones[ABC_DARIO] = 
    {'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
//SOLICITAR LA PALABRA.
    printf("\nCifrado Cesar (11 posiciones).\nIngrese la palabra a cifrar (Solo mayusculas): ");    
//EL "scanf" SE DECLARA DE ESA FORMA PARA ACEPTAR ESPACIOS BLANCO, AUNQUE EN EL CIFRADO SERAN OMITIDOS.
    scanf("%120[^\n]", palabra);

//SE OBTIENE EL VALOR DE LA VALIDACION DE LA PALABRA.
    mayuscula = validarPalabra(palabra);

//REALIZACION DEL CIFRADO O NO, DEPENDIENDO DEL VALOR DE LA VALIDACION.
    if (mayuscula == 1)
    {
        cifrarPalabra(palabra, letrasEnClaro, letrasCifradoOncePosiciones);
    }
    else
    {
        printf("\nIngrese solamente letras mayusculas.");
        printf("\n---------------------------\n");
    }
}

int main(int argc, char *argv[]){
//VARIABLES NECESARIAS.
    char letrasEnClaro[ABC_DARIO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char palabra[MAX_PALABRA];
    int mayuscula, opcion;

    while (1)
    {
        printf("\nElija el cifrado que desea realizar (Ingrese un numero del 1-4):\n\t1. Cifrado de 5 posiciones.\n\t2. Cifrado de 7 posiciones.\n\t3. Cifrado de 11 posiciones.\n\t4. Salir.\n");
        scanf("%d", &opcion);
    //VACIA EL BUFFER DEL TECLADO
        while (getchar() != '\n');
        
        switch (opcion)
        {
            case 1:
                cifradoCincoPosiciones(palabra, mayuscula, letrasEnClaro);
                break;
            case 2:
                cifradoSietePosiciones(palabra, mayuscula, letrasEnClaro);
                break;
            case 3:
                cifradoOncePosiciones(palabra, mayuscula, letrasEnClaro);
                break;
            case 4:
                printf("\nAdios.");
                return 0;
                break;
            default:
                printf("Opcion no valida");
                break;
        }
    }

    return 0;
}