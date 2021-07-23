#include <stdio.h>
/*
Arreglos
*/
//UNO
#define MAX 10
//DOS
#define MAX_Y 4
#define MAX_X 10
//TRES
#define MAX_Z 3
//CUATRO
#define MAX_W 2

int miArray[MAX];
long miArray2D[MAX_Y][MAX_X];
float miArray3D[MAX_Z][MAX_Y][MAX_X];
long miArray4D[MAX_W][MAX_Z][MAX_Y][MAX_X];

int main(int argc, char *argv[]){

    //UNA DIMENSION
    printf("\n  Celda  |  Memoria   |   Valor en memoria\n");
    for (int i = 0; i < MAX; i++)
    {
        miArray[i] = i;
        printf("\nmiArray[%d] : %x = %d\n", i, &miArray[i], miArray[i]);
    }              //Contador - Direccion de memoria - Valor del arreglo
    
    //DOS DIMENSIONES
    printf("----------------------------------\n  Celda\t  |\t  Memoria   |\t   Valor en memoria\n");
    for (int y = 0; y < MAX_Y; y++)
    {
        for (int x = 0; x < MAX_X; x++)
        {
            miArray2D[y][x] = y * x;
            printf("\nmiArray2D[%d][%d] : %d = %d\t", y, x, &miArray2D[y][x], miArray2D[y][x]);
        }
        printf("\n-----------------------------------\n");
        
    }
    
    //TRES DIMENSIONES
    printf("----------------------------------\n  Celda\t  |\t  Memoria   |\t   Valor en memoria\n");
    for (int z = 0; z < MAX_Z; z++)
    {
        for (int y = 0; y < MAX_Y; y++)
        {
            for (int x = 0; x < MAX_X; x++)
            {
                miArray3D[z][y][x] = z * y * x;
                printf("\nmiArray3D[%d][%d][%d] : %d = %f", z, y, x, &miArray3D[z][y][x], miArray3D[z][y][x]);
            }
            printf("\n-----------------------------------\n");
        }
        printf("\n-----------------------------------\n");
    }
    
    //CUATRO DIMENSIONES
    printf("CUATRO DIMENSIONES\n----------------------------------\n  Celda\t  |\t  Memoria   |\t   Valor en memoria\n");
    for (int w = 0; w < MAX_W; w++)
    {    
        for (int z = 0; z < MAX_Z; z++)
        {
            for (int y = 0; y < MAX_Y; y++)
            {
                for (int x = 0; x < MAX_X; x++)
                {
                    miArray4D[w][z][y][x] = w * z * y * x;
                    printf("\nmiArray4D[%d][%d][%d][%d] : %d = %d", w, z, y, x, &miArray4D[w][z][y][x], miArray4D[w][z][y][x]);
                }
                printf("\n-----------------------------------\n");
            }
            printf("\n-----------------------------------\n");
        }
    }
    return 0;
}