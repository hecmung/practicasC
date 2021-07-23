#include <stdio.h>
#include <stdlib.h>
#define MAX_NOMBRE 80
#define MAX_FECHA 11
#define MAX_BOLETA 11
#define MAX_ALUMNOS 33


struct SerHumano { 
	char fechaNacimiento[MAX_FECHA]; // formato :: aaaa/mm/dd\0 :: si mm<10 mm=08 :: si dd<10 dd=05
};

struct Persona {
	struct SerHumano *ptrhumano;		// Apuntador a la Estructura anidada
	char nombre[MAX_NOMBRE];
};

struct Alumno {
	struct Persona *ptralguien;			// Apuntador a la Estructura anidada
	char boleta[MAX_BOLETA]; 		// 10 digitos numericos aaaaxxxxxx\0
};

struct Alumno grupoDeFundamentos[MAX_ALUMNOS]; // instancia de Alumno
int contador = 0;

void limpiarBufferDeTeclado() {
	char ch;
	while( (ch=getchar())!='\n' && ch!=EOF);
}
void ptrMemorias(){
    for (int i = 0; i < MAX_ALUMNOS; i++)
    {
        grupoDeFundamentos[i].ptralguien = malloc(sizeof(struct Persona));
        grupoDeFundamentos[i].ptralguien->ptrhumano=malloc(sizeof(struct SerHumano));
    }
    
}
void introducirAlumno() {
    while(getchar() != '\n');
	printf( "Alumno (%d):\n", contador+1 );
	printf( "Fecha de nacimiento (aaaa/mm/dd): " );
	gets(grupoDeFundamentos[contador].ptralguien->ptrhumano->fechaNacimiento);
	printf( "Nombre completo                 : " );
	gets(grupoDeFundamentos[contador].ptralguien->nombre);
	printf( "Boleta                          : " );
	gets(grupoDeFundamentos[contador].boleta);
	contador++;
}

void visualizarAlumno(int indice, int alumnos) {
	if(indice<=0 || indice> alumnos) {
		printf( "Error: indice fuera de rango.\n" );
		return;
		}
    else
	{
	indice --;
	printf( "Alumno (%d):\n", (indice+1) );
	printf( "Fecha de nacimiento : %s\n", grupoDeFundamentos[indice].ptralguien->ptrhumano->fechaNacimiento);
	printf( "Nombre completo     : %s\n", grupoDeFundamentos[indice].ptralguien->nombre);
	printf( "Boleta              : %s\n", grupoDeFundamentos[indice].boleta);
	}
}

void visualizarATodosLosAlumnos(int alumnos) {
	int numeroDeAlumno;
	for(numeroDeAlumno=1; numeroDeAlumno<(alumnos + 1); numeroDeAlumno++) {
		visualizarAlumno(numeroDeAlumno, alumnos);
		}
}

int ejecutarMenu() {
	int opcion = -500;
	int indice = 0, alumnos = 0;
	while(1) {
		printf( "Menu de la aplicacion.\n" );
		printf( "1. Introducir alumno.\n" );
		printf( "2. Visualizar alumno.\n" );
		printf( "3. Visualizar al grupo.\n" );
		printf( "4. Salir del programa.\n" );
		printf( "Elija una opcion: " );
		scanf( "%d", &opcion );
		switch( opcion ) {
			case 1: // introducir un alumno
				introducirAlumno();
                alumnos ++;
				break;
			case 2:
				printf( "Dame el numero del alumno: " );
				scanf( "%d", &indice );
				visualizarAlumno(indice, alumnos);
				break;
			case 3:
				visualizarATodosLosAlumnos(alumnos);
				break;
			case 4:
				return 0;
				printf( "Hasta luego, buen dia.\n" );
				break;
			default:
				printf( "Elija una opcion entre 1 y 4.\n" );
			}
		}
}

int main(int argc, char *argv[]) {
    ptrMemorias();
	ejecutarMenu();
	return 0;
}