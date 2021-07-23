#include <stdio.h>
/*
2.1 Apuntadores
    Se les conoce como puntero, es representado por el operador del lenguaje C "*" (Asterisco)
    Proporciona flexibilidad al lenguaje
    Asgina memoria dinamicamente, se utilizan las funciones:
        malloc() (Asignar memoria)
        free() (Liberar memoria)
    Estan estrechamente vinculados con los arreglos 
    Se puede realizar aritmetica de apuntadores, solamente con "+" y "-".
    Se puede utilizar con una funcion para control de flujo.

    Concepto:
        Es simple, es una "variable" que almacena una direccion de memoria, es decir, una ubicacion en ella.
        Deben respetar las reglas de tipos de datos cuando se declaran.
        Un apuntador puede ser nulo "NULL".

    Punteros y Memoria
        Estatico / Global: las variables apuntador declaradas estaticas, se asignan a este tipo de memoria. Las globales tambien utilizan esta region.
                           Se asignan cuando inicia el programa y permanecen ahi hasta que este finaliza. Y las funciones tienen acceso a ellas.
        Automatico: se declaran dentro de una funcion, se crean cuando la funcion es llamada y su tiempo de vida es hasta lo que dura la
                    ejecucion de esa funcion.
        Dinamicas: la memoria se asigna desde el monton (heap) y se puede liberar segun sea necesario. Se utiliza un puntero que hace referencia a la 
                   memoria asignada. El alcance (scope) del puntero esta limitado hasta que se asigna (malloc()) memoria y cuando se libera (free()).
    Ejemplos:
        int *punteroUno;
            punteroUno ++;
        int *punteroDos = (int *) malloc(sizeof(int) * 10); Esto quiere decir que se crea un puntero de 10 espacios en memoria.
    Prototipo de malloc es:
        void malloc(int tamanio)
        Situaciones con apuntadores (comportamiento):
            Definido por implementacion:
                Implementacion especificada y documentada. Cuando un vit de orden superior se propaga o desplaza a la derecha.
            Sin especificar:
                Se presenta alguna implementacion pero no esta documentada. Un ejemplo seria al asginar memoria con malloc(0) con un argumento 0.
            Indefinido:
                No hay requisitos y puede pasar cualquier cosa. Una funcion devuelve un apuntador.

    Declaracion de apuntadores
     tipo * nombreApuntador;
        int * ptrUno;
*/
void imprimirCaracter(char *nombres[], int a, int b){
    
    printf("%c\n", *(*(nombres + a) + b));

}
int main(int argc, char *argv[]){
    
    char *nombres[] = {"Hector", "Adrian", "Ximena"};
    
    printf("%c\n", nombres[2][0]);
    //printf("%c\n", *(*(nombres + 2) + 0));
    imprimirCaracter(nombres, 2, 1);

    int numero = 10;
    int *ptrNumero = &numero;
    printf("Valor de numero: %d \t | \t Valor de ptrNumero: %d\n", numero, *ptrNumero);

    return 0;
}