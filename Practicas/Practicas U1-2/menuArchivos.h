#ifndef MENUARCHIVOS_H
#define MENUARCHIVOS_H
//MUNGUIA AGUILERA HECTOR ADRIAN 1CV16
#include <stdio.h>
#include "libreriaParaArchivos.h"
int menuArchivos(){
    int opcion, edad[1];
    long enteroLargo[1];
    float flotante[1];
    double flotanteDoble[1];
    FILE *fp;
	FILE *fp1;
	char archivoEntrada[80];
	char archivoSalida[80];
    char caracter;

    printf("\nNombre del archivo a abrir: ");
    gets(archivoEntrada);
    while(1){
        printf("\n\t1. Leer archivo.\n\t2. Escribir archivo.\n\t3. Copiar archivo.\n\t4. Escribir archivo Teclado\n\t5. Escribir y leer numeros enteros.\n\t6. Escribir y leer caracteres.\n\t7. Escribir y leer enteros largos.\n\t8. Escribir y leer flotantes.\n\t9. Escribir y leer flotantes dobles.\n\t10. Salir.\nElija una operacion a realizar: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            fp = abrirArchivo( archivoEntrada, "r" );
            if( fp!=NULL ) {
                printf("\n-Tu archivo es:\n");
                leerArchivo( fp );
                cerrarArchivo( fp );
                }
            break;
        case 2:
            fp = abrirArchivo( archivoEntrada, "a" );
            if( fp!=NULL ) {
                printf("\nLo que se incluira en tu archivo sera: 'Hola como estas, mi nombre es Hector.'");
                escribirArchivo( fp, "\nHola como estas, mi nombre es Hector." );
                //escribirDeTecladoAArchivo(fp, '-');
                cerrarArchivo( fp );
                }
            break;
        case 3:
            while(getchar() != '\n');
            printf("\nEl archivo que vas a copiar es: %s.\nEscribe el nombre del archivo copia: ", archivoEntrada);
            gets(archivoSalida);
            fp = abrirArchivo(archivoEntrada, "rb");
            fp1 = abrirArchivo(archivoSalida, "wb");
            if( fp!=NULL && fp1!=NULL ) {
                copiarArchivo(fp, archivoEntrada, fp1, archivoSalida);
                cerrarArchivo(fp);
                cerrarArchivo(fp1);
                printf("Se copio correctamente el archivo: %s.", archivoSalida);
                }
            break;
        case 4:
            fp = abrirArchivo( archivoEntrada, "a" );
            if( fp!=NULL ) {
                escribirDeTecladoAArchivo(fp, '#');
                cerrarArchivo( fp );
            }
            break;
        case 5:
            while(getchar() != '\n');
            printf("Se creara un nuevo archivo para escribir y leer entero, dejara de usar el archivo que ingreso al inicio. Ingresa el nombre del nuevo archivo: ");
            gets(archivoEntrada);
            fp = abrirArchivo(archivoEntrada, "w");
            fp1 = abrirArchivo(archivoEntrada, "r");
            printf("\n\tIngrese su edad: ");
            scanf("%d", &edad[0]);
            if(fp != NULL){
                escribirEnteroAArchivo(fp, edad);
                cerrarArchivo(fp);
                printf("\nLa edad que esta en el archivo es: %d", leerEnteroDeArchivo(fp1));
                cerrarArchivo(fp1);
            }
            break;
        case 6:
            while(getchar() != '\n');
            printf("Se creara un nuevo archivo para escribir y leer caracteres, dejara de usar el archivo que ingreso al inicio. Ingresa el nombre del nuevo archivo: ");
            gets(archivoEntrada);
            fp = abrirArchivo(archivoEntrada, "w");
            fp1 = abrirArchivo(archivoEntrada, "r");
            printf("Ingrese el caracter: ");
            scanf("%c", &caracter);
            if (fp != NULL){
                escribirCaracterAArchivo(fp, caracter);
                cerrarArchivo(fp);
                printf("El caracter que esta en el archivo es: %c", leerCaracterDeArchivo(fp1));
                cerrarArchivo(fp1);
            }
            break;
        case 7:
            while(getchar() != '\n');
            printf("Se creara un nuevo archivo para escribir y leer enteros largos, dejara de usar el archivo que ingreso al inicio. Ingresa el nombre del nuevo archivo: ");
            gets(archivoEntrada);
            fp = abrirArchivo(archivoEntrada, "w");
            fp1 = abrirArchivo(archivoEntrada, "r");
            printf("Ingrese el entero largo: ");
            scanf("%ld", &enteroLargo[0]);
            if(fp != NULL){
                escribirEnteroLargoAArchivo(fp, enteroLargo);
                cerrarArchivo(fp);
                printf(" El entero largo del archivo es: %ld", leerEnteroLargoDeArchivo(fp1));
                cerrarArchivo(fp1);
            }
            break;
        case 8:
            while(getchar() != '\n');
            printf("Se creara un nuevo archivo para escribir y leer flotante, dejara de usar el archivo que ingreso al inicio. Ingresa el nombre del nuevo archivo: ");
            gets(archivoEntrada);
            fp = abrirArchivo(archivoEntrada, "w");
            fp1 = abrirArchivo(archivoEntrada, "r");
            printf("Ingrese el flotante: ");
            scanf("%f", &flotante[0]);
            if(fp != NULL){
                escribirFlotanteAArchivo(fp, flotante);
                cerrarArchivo(fp);
                printf(" El flotante del archivo es: %f", leerFlotanteDeArchivo(fp1));
                cerrarArchivo(fp1);
            }
            break;
        case 9:
            while(getchar() != '\n');
            printf("Se creara un nuevo archivo para escribir y leer flotantes dobles, dejara de usar el archivo que ingreso al inicio. Ingresa el nombre del nuevo archivo: ");
            gets(archivoEntrada);
            fp = abrirArchivo(archivoEntrada, "w");
            fp1 = abrirArchivo(archivoEntrada, "r");
            printf("Ingrese el flotante dobles: ");
            scanf("%lf", &flotanteDoble[0]);
            if(fp != NULL){
                escribirFlotanteDobleAArchivo(fp, flotanteDoble);
                cerrarArchivo(fp);
                printf(" El flotante largo del archivo es: %lf", leerFlotanteDobleAArchivo(fp1));
                cerrarArchivo(fp1);
            }
            break;
        case 10:
            printf("Adios.");
            return 0;
            break;
        default:
            printf("Numero no valido");
            break;
        }
    }
}
#endif //MENUARCHIVOS_H