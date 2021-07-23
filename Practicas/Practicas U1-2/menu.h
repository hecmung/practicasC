#ifndef MENU_H
#define MENU_H
//MUNGUIA AGUILERA HECTOR ADRIAN 1CV16
#include <stdio.h>
#include "operaciones.h"
int menu(){
    int opcion;
    int exponente, numeroN, x, y;
    float base;
    while(1){
        printf("\n\t1. Calcular una potencia.\n\t2. Suma de N numeros.\n\t3. Numero par o impar.\n\t4. Multilpicacion de dos numeros.\n\t5. Torres de Hanoi.\n\t6. Salir.\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese el exponente: "); scanf("%d", &exponente); while(getchar() != '\n');
            printf("Ingrese la base: "); scanf("%f", &base); while(getchar() != '\n');  
            printf("----------\nIteracion.\nLa potencia es: %f\nRecursivo.\nLa potencia es: %f", calcularPotenciaIteracion(exponente, base), calcularPotenciaRecursivo(exponente, base));
            break;
        case 2:
            printf("Ingrese el numero Natural a sumar: "); scanf("%d", &numeroN); while(getchar() != '\n');
            if(numeroN < 1 ){
                printf("Solo numeros mayores a 1."); break;
            }
            printf("----------\nIteracion.\nLa suma de los primeros %d numeros es: %d\nRecursivo.\nLa suma de los primeros %d numeros es: %d", numeroN, sumaDeNumerosIteracion(numeroN), numeroN, sumaDeNumerosRecursivo(numeroN));
            break;
        case 3:
            printf("Ingrese el numero para saber si es par o impar: "); scanf("%d", &numeroN); while(getchar() != '\n');
            printf("----------\nIteracion.");numeroParImpar(numeroN);
            printf("\nRecursivo.");
            if(esPar(numeroN) == 1){
                printf("El numero %d es par.", numeroN); break;
            }
            else {
                printf("El numero %d es impar.", numeroN); break;
            }
            break;
        case 4:
            printf("Ingrese el primer numero: "); scanf("%d", &x); while(getchar() != '\n');
            printf("Ingrese el segundo numero: "); scanf("%d", &y); while(getchar() != '\n');
            printf("----------\nIteracion.\nEl resultado de multiplicar a %d * %d = %d\nRecursivo.\nEl resultado de multiplicar a %d * %d = %d", x, y, multiplicacionDosNumerosIteracion(x, y), x, y, multiplicacionDosNumerosRecursivo(x, y)); 
            break;
        case 5:
            printf("Ingrese el numero para calcular la torre de Hanoi: "); scanf("%d", &numeroN); while(getchar() != '\n');
            if(numeroN < 1){
                printf("Solo numeros mayores a 1."); break;
            }
            else
            {
                printf("----------\nIteracion.\nEl calculo de la torre de Hanoi es %d = %d\nRecursivo.\nEl calculo de la torre de Hanoi es %d = %d", numeroN, torresDeHanoiIteracion(numeroN), numeroN, torresDeHanoiRecursivo(numeroN));
            }
            
            break;
        case 6:
            printf("Adios.");
            return 0;
            break;
        default:
            printf("Numero no valido");
            break;
        }
    }
}
#endif //MENU_H