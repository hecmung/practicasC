#include <stdio.h>
//MUNGUIA AGUILERA HECTOR ADRIAN
#define CALIFICACION 10
    //FUNCION QUE SOLICITA CALIFICACIONES
void solcitarCalificiones(float arrayCalificaciones[]){
    for (int i = 0; i < CALIFICACION; i++)
        {
            printf("Ingrese la calificacion %d: ",(i+1));
            scanf("%f", &arrayCalificaciones[i]);
        }
}
    //FUNCION PARA CALCULAR PROMEDIO
void calcularPromedio(float arrayCalificaciones[], float *sumaCalificaciones, float *promedio){
    for (int i = 0; i < CALIFICACION; i++)
        {
            *sumaCalificaciones += arrayCalificaciones[i];
        }
    *promedio = *sumaCalificaciones / (float)CALIFICACION;
    printf("\nEl promedio de las calificaciones es: %.2f", *promedio);
}
    //FUNCION PARA ENCONTRAR LA CALIFICACION MENOR
void menorCalificacion(float arrayCalificaciones[]){
    float menor = arrayCalificaciones[0];
    for (int i = 0; i < CALIFICACION; i++)
    {
        if(menor > arrayCalificaciones[i]){
            menor = arrayCalificaciones[i];
        }        
    }
    printf("La calificacion menor es: %.2f", menor);
}
    //FUNCION PARA ENCONTRAR LA CALIFICACION MAYOR
void mayorCalificacion(float arrayCalificaciones[]){
    float mayor = arrayCalificaciones[0];
    for (int i = 0; i < CALIFICACION; i++)
    {
        if(mayor < arrayCalificaciones[i]){
            mayor = arrayCalificaciones[i];
        }
    }
    printf("La calificacion mayor es: %.2f", mayor);
}
    //FUNCION PARA CONTAR EL NUMERO DE REPROBADOS
int contador = 0;
void reprobados(float arrayCalificaciones[]){
    for (int i = 0; i < CALIFICACION; i++)
    {
        if(arrayCalificaciones[i] < 6){
            contador ++;
        }
    }
    printf("El numero de personas reprobadas es: %d", contador);
}
    //FUNCION PARA CONTAR EL NUMERO DE APROBADOS
void aprobados(float arrayCalificaciones[]){
    for (int i = 0; i < CALIFICACION; i++)
    {
        if (arrayCalificaciones[i] >= 6){
            contador ++;
        }
    }
    printf("El numero de persona aprobadas es: %d", contador);
}
int main(int argc, char *argv[]){
    float arrayCalificaciones[CALIFICACION];
    float sumaCalificaciones = 0.0, promedio = 0.0;
    int opcion;
    
    printf("\n\tAntes de elegir la operacion a realizar debera ingresar las calificiones. (0-10)");
    printf("\n\n");
    solcitarCalificiones(arrayCalificaciones);

    printf("\nElija la operacion a realizar:\n");
    printf("\t1. Mostrar la calificacion menor.\n\t2. Mostrar la calificacion mayor.\n\t3. Numero de reprobados.\n\t4. Numero de aprobados.\n\t5. Promedio.\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        menorCalificacion(arrayCalificaciones);
        break;
    case 2:
        mayorCalificacion(arrayCalificaciones);
        break;
    case 3:
        reprobados(arrayCalificaciones);
        break;
    case 4:
        aprobados(arrayCalificaciones);
        break;
    case 5:
        calcularPromedio(arrayCalificaciones, &sumaCalificaciones, &promedio);
        break;
    default:
        printf("\nOpcion no valida.");
        break;
    }

    return 0;
}