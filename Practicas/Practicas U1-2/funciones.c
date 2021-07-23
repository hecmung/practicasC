/*
2.3 Funciones
    Una unidad atomica que tiene las siguientes caracteristicas
        a. No devuelve ningun valor (void) proceso.
        b. Valor de retorno unitario, puede ser cualquier tipo (short, int, long, float, double, char, struct).
        c. Valor de retorno multiplice, devolver un apuntador, puntero.
        d. Debe tener un nombre.
            1. Debe contener y empezar con un verbo en infinitivo (ar, er, ir).
            2. Debe ser autodocumentado.
                i. imprimirAlummno(){}
                ii. introducirDatosDeEmpresa(){}
                iii. procesarInformacionDePersona(){}
                iv. El patron seria: minusculasMinusculasMinusculas(){}
        e. Despues del nombre (por sintaxis) y entre parentesis los argumentos de la Funcion.
            1. Pueden ser de cualquier tipo de dato.
            2. Tambien pueden recibir apuntadores de cualquier tipo.
            3. Separados por el operador ",".
            4. Sintaxis de los argumentos es:
                i. tipo nombreDelArgumento;
        f. Una funcion tiene cuerpo (segmento de codigo) comienza con llave de apertura "{" y termina con llave de cierra "}".
    Recomendaciones:
        1. Una funcion debe contener de 25 lineas de codigo validas para:
            i. Que sea mas comprnsible.
            2. Que sea depurable.
            3. Que sea reutilizable (libreria) por cualquier otra funcion.
            4. Que sea modular.
        2. Si la funcion main queda arriba en el codigo fuente de nuestro archivo y las demas funciones quedan debajo de ella, se deberan presentar prototipos a la funcion principal.
*/
#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 80
struct Trabajador
{
    char nombre[MAX_NOMBRE];
    double salario;
};
//Paso por referencia
void cambiarValoresDeTrabajador(struct Trabajador *ptrTrabajador){
    strcpy(ptrTrabajador->nombre,"Hector Metodo");
    ptrTrabajador->salario =5.5000;
    printf("----Desde el void----\nNombre: %s\n", ptrTrabajador->nombre);
    printf("Salario: %f\n", ptrTrabajador->salario);
}
// Se crea una copa de jose y se trabaja con la copia dentro de la funcion
void cambiarValorDeJosePorReferencia(int *pepe){
    printf("%d Jose llegando al void\n", *pepe);
    *pepe = 99;
    printf("%d Jose desde el Void\n", *pepe);

}
int main(int argc, char * argv[]){

    /*int jose = 1, *pepe = &jose;

    printf("%d Jose\n", jose);
    *pepe = 10;
    printf("%d Jose con Pepe\n", jose);
    cambiarValorDeJosePorReferencia(&jose);
    printf("%d Jose otra vez en el main.", jose);
    */
   struct Trabajador  trabajador;
   printf("Desde el main\nNombre: %s\n", trabajador.nombre);
   printf("Salario: %f\n\n", trabajador.salario);
   cambiarValoresDeTrabajador(&trabajador);
   printf("----Otra vez desde el main----\nNombre: %s\n", trabajador.nombre);
   printf("Salario: %f\n", trabajador.salario);

    return 0;
}