/*
Asignacion de memoria dinamica (heap, memoria del monton)
malloc () 
free()
    Prototipo de malloc()
    void malloc(int)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_MEM 20

int *crearMemoriaEntera(int cuantosEnteros){
    int *ptrInt = (int *) malloc(sizeof(int)*cuantosEnteros);
    
    return ptrInt;
}
int *duplicarMemoria(int *ptr){
    int *ptrTemporal = (int *) malloc(sizeof(ptr));
    if (ptrTemporal == NULL)
    {
        printf("No se pudo asignar la memoria de %d bytes\n", MAX_MEM*sizeof(ptr));
    }
    else
    {
        for (int i = 0; i < (sizeof(ptr)/sizeof(int)); i++)
        {
            ptrTemporal[i] = ptr[i];
        }
        ptr = (int *) malloc(sizeof(ptr)*2);
        if (ptr != NULL)
        {
            for (int i = 0; i < (sizeof(ptr)/sizeof(int)); i++)
            {
                ptr[i] = ptrTemporal[i];
            }   
        }
        
    }
    free(ptrTemporal);
    return ptr;
}

int main(int argc, char *argv[]){
    int *ptrInt = crearMemoriaEntera(MAX_MEM);
    if (ptrInt == NULL)
    {
        printf("No se pudo asignar la memoria de %d bytes\n", MAX_MEM*sizeof(int));
    }
    else
    {
        for (int i = 0; i < MAX_MEM; i++)
        {
            ptrInt[i] = i * 100;
            printf("Valor en memoria: %d\n", ptrInt[i]);
        }
    }
    ptrInt = duplicarMemoria(ptrInt);
    if (ptrInt == NULL)
    {
        printf("No se pudo asignar la memoria de %d bytes\n", MAX_MEM*sizeof(int)*2);
    }
    else
    {
        for (int i = 0; i < MAX_MEM*2; i++)
        {
            ptrInt[i] = i * 100;
            printf("Valor en memoria: %d\n", ptrInt[i]);
        }
    }
    if (ptrInt != NULL)
    {
        printf("Liberando la memoria de %d bytes.\n", MAX_MEM*sizeof(int)*2);
        free(ptrInt);
    }
    
    return 0;
}