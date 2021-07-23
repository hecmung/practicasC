#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 120
#define MAX_B 15
#define MAX_G 32
struct Alumno
{
    char nombreAlumno[MAX];
    int edad;
    char boleta[MAX_B];
};

struct Alumno grupo1CV16[MAX_G], *ptrGrupo, *ptrMismoGrupo;

void introducirAlumno(int i){
    while(getchar() != '\n');
    printf("Ingrese el nombre del alumno: ");
    gets(grupo1CV16[i].nombreAlumno);
    printf("Ingrese la boleta del alumno: ");
    gets(grupo1CV16[i].boleta);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &grupo1CV16[i].edad);
}

void imprimirAlumnos(int numeroAlumnos){
    printf("\n---Grupo 1CV16---\n");
    for (int i = 0; i < numeroAlumnos; i++)
    {
               printf("%d.\nAlumno: %s\n", (i+1), grupo1CV16[i].nombreAlumno);
               printf("Boleta: %s\n", grupo1CV16[i].boleta);
               printf("Edad del alumno: %d\n\n", grupo1CV16[i].edad);           
    }
}
void imprimirAlumnosPuntero(int numeroAlumnos){
    ptrGrupo = grupo1CV16;
    printf("\n---Grupo 1CV16---\n---(Con apuntador)---\n");
    for (int i = 0; i < numeroAlumnos; i++)
    {
        printf("%d.\nAlumno: %s\n", (i+1), ptrGrupo->nombreAlumno);
        printf("Boleta: %s\n", ptrGrupo->boleta);
        printf("Edad: %d\n\n", ptrGrupo->edad);
        *ptrGrupo ++;
    }
}
int eliminarAlumno(int numeroAlumnos){
    int alumno;
    imprimirAlumnos(numeroAlumnos);
    printf("----------\nIngrese el numero del alumno que desea eliminar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
       printf("Numero no valido.\n");
       return 1;
    }
    else
    {
        alumno --;
        for (int i = alumno; i < numeroAlumnos; i++)
        {
                strcpy(grupo1CV16[i].nombreAlumno, grupo1CV16[i+1].nombreAlumno);
                strcpy(grupo1CV16[i].boleta, grupo1CV16[i+1].boleta);
                grupo1CV16[i].edad = grupo1CV16[i+1].edad;        
        }
        return 0;
    }
}
int eliminarAlumnoPuntero(int numeroAlumnos){
    int alumno;
    imprimirAlumnosPuntero(numeroAlumnos);
    ptrGrupo = grupo1CV16;
    ptrMismoGrupo = grupo1CV16;
    printf("----------\nIngrese el numero del alumno que desea eliminar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
        return 1;
    }
    else
    {    
        alumno --;
        ptrGrupo += alumno;
        ptrMismoGrupo += alumno;
        ptrMismoGrupo ++;

        for (int i = alumno; i < numeroAlumnos; i++)
        {
            strcpy(ptrGrupo->nombreAlumno, ptrMismoGrupo->nombreAlumno);
            strcpy(ptrGrupo->boleta, ptrMismoGrupo->boleta);
            ptrGrupo->edad = ptrMismoGrupo->edad;
            ptrGrupo ++;
            ptrMismoGrupo ++;
        }
        return 0;
    }
}
void modificarAlumno(int numeroAlumnos){
    imprimirAlumnos(numeroAlumnos);
    int alumno;
    printf("----------\nIngrese el numero del alumno que desea modificar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
    }
    else
    {    
        alumno --;
        introducirAlumno(alumno);
    }
}
void modificarAlumnoPuntero(int numeroAlumnos){
    imprimirAlumnosPuntero(numeroAlumnos);
    int alumno;
    ptrGrupo = grupo1CV16;
    printf("----------\nIngrese el numero del alumno que desea modificar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
    }
    else
    {    
        alumno --;
        ptrGrupo += alumno;
        while(getchar() != '\n');
        printf("Nombre del alumno: ", (alumno + 1));
        gets(ptrGrupo->nombreAlumno);
        printf("Boleta: ");
        gets(ptrGrupo->boleta);
        printf("Edad: ");
        scanf("%d", &ptrGrupo->edad);
    }
}

int menu(){
    int opcion, numeroAlumnos = 0;
    while (1)
    {
        printf("Elija una accion a realizar.\n\t1. Introducir alumno.\n\t2. Imprimir alumnos (Indice).\n\t3. Imprimir alumnos (Apuntador).\n\t4. Eliminar un alumno (Indice).\n\t5. Eliminar un alumno (Apuntador).\n\t6. Modificar datos del alumno (Indice).\n\t7. Modificar datos del alumno (Apuntador).\n\t8. Salir.\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
                introducirAlumno(numeroAlumnos);
                //printf("%d ALUMNOS.", numeroAlumnos);
                numeroAlumnos++;
            break;
        case 2:
            imprimirAlumnos(numeroAlumnos);
            break;
        case 3:
            imprimirAlumnosPuntero(numeroAlumnos);
            break;
        case 4:
        printf("ALUMNOS: %d", numeroAlumnos);
            //eliminarAlumno(numeroAlumnos);
            if(eliminarAlumno(numeroAlumnos) == 0)
            {
                numeroAlumnos --;
                printf("\nAlumno eliminado.\n");

            }
            break;
        case 5:
        printf("ALUMNOS: %d", numeroAlumnos);
            //eliminarAlumnoPuntero(numeroAlumnos);
            if(eliminarAlumnoPuntero(numeroAlumnos) == 0)
            {
                numeroAlumnos --;
                printf("\nAlumno eliminado.\n");
            }
            break;
        case 6:
            modificarAlumno(numeroAlumnos);
            break;
        case 7:
            modificarAlumnoPuntero(numeroAlumnos);
            break;
        case 8:
            printf("Adios");
            return 0;
            break;
        default:
            printf("Opcion no valida!!\n");
            break;
        }
    }
}

int main(int argc, char *argv[]){
    menu();
    return 0;
}