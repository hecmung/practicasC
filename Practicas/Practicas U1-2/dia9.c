#include <stdio.h>
/*
Crear un programa que lea 6 meses de sueldo de un trabajador (no gana lo mismo cada mes), su clave de empleado y calcule
su ingreso promedio mensual, e imprima como salida todo lo anterior y su ingreso total (utilice arreglos).
*/
#define MESES 6
#define CLAVE 9

//FUNCION LEER Y CALCULOS SOLICITADOS
void leerInformacionDelTrabajador(float ingresoMes[], char claveEmp[], float *ingresoTot, float *promedioMes){
    for (int i = 0; i < MESES; i++)
    {
        printf("\nIngresa tu sueldo mensual %d: ", (i + 1) );
        scanf("%f", &ingresoMes[i]);
        *ingresoTot += ingresoMes[i];
    }
    printf("\nIntroduzca clave del empleado: ");
    gets(claveEmp);
    gets(claveEmp);
    *promedioMes = *ingresoTot / (float)MESES;
}
//FUNCION SALIDA DE DATOS
void imprimirDatos(char claveEmp[], float ingresoMes[], float ingresoTot, float promedioMes){
    printf("----------------------");
    printf("\nClave del empleado: %s\n", claveEmp);
    for (int i = 0; i < MESES; i++)
    {
        printf("\nTu sueldo mensual %d = $  %.2f M.N.", (i+ 1), ingresoMes[i]);
    }
    printf("\n\nIngreso total = $ %.2f M.N",ingresoTot);
    printf("\nPromedio mensual = $ %.2f M.N.\n", promedioMes);
    printf("\n-------------------------------");
}

int main(int argc, char *argv[]){

    float ingresoMes[MESES];
    float ingresoTot = 0.0;
    char claveEmp[CLAVE];
    float promedioMes = 0.0;
    //PROCESO PARA 5 TRABAJADORES
    int trab = 1;
    while(trab <= 5){
        printf("\nTrabajador No: %d \n", trab);
        //LECTURA DE INFORMACION
        leerInformacionDelTrabajador(ingresoMes, claveEmp, &ingresoTot, &promedioMes);
        /*for (int i = 0; i < MESES; i++)
        {
            printf("\nIngresa tu sueldo mensual %d: ", (i + 1) );
            scanf("%f", &ingresoMes[i]);
            ingresoTot += ingresoMes[i];
        }
        printf("\nIntroduzca clave del empleado: ");
        gets(claveEmp);
        gets(claveEmp);*/
        //CALCULOS
        //promedioMes = ingresoTot / (float)MESES;
        //SALIDA DE DATOS
        imprimirDatos(claveEmp, ingresoMes, ingresoTot, promedioMes);
        /*printf("Clave del empleado: %s\n", claveEmp);
        for (int i = 0; i < MESES; i++)
        {
            printf("\nTu sueldo mensual %d = $  %.2f M.N.", (i+ 1), ingresoMes[i]);
        }
        printf("\n\nIngreso total = $ %.2f M.N",ingresoTot);
        printf("\nPromedio mensual = $ %.2f M.N.\n", promedioMes);
        printf("\n-------------------------------");*/
    /*
    1.3 Programacion y diseño integrado
        Modularidad de nuestro programas
        1. TOP-DOWN
        2. DOWN-TOP
        Creacion de procesos, metodos o funciones
    */
        trab ++;
    }
    return 0;
}