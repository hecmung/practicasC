#include <stdio.h>
#include <string.h>

#include "libreriaParaArchivos.h"
//MUNGUIA AGUILERA HECTOR ADRIAN 1CV16
#define MAX_NOMBRE 60
#define MAX_BOLETA 13
#define MAX_NOMBRE_ARCHIVO 100

// hard code NO debe estar aqui
//#define MAX_GRUPO 10

// hard code NO debe estar aqui
//#define NOMBRE_ARCHIVO "alumnos.db"

// 1. Pedirle al usuario el nombre del archivo a guardar el grupo .bin
// 2. Pedirle al usuario el nombre del archivo a leer del grupo   .bin
// 3. Pedir al usuario el tamanio del grupo (cambiar MAX_GRUPO por una variable local min=30 max=36)

// 4. Va a cambiar la estructura acomodar las funciones para leer y guardar
//	(si es necesario), explicar porque cambio o porque no cambio

struct Persona {
	char nombre[MAX_NOMBRE];
	int edad;
};


struct Alumno {
	char nombre[MAX_NOMBRE];
	struct Persona *unaPersona;
	char boleta[MAX_BOLETA];
};


void limpiarBufferDeTeclado() {
	char ch;
	while( (ch=getchar())!='\n' && ch!=EOF);
}

void introducirInformacionAlumno(struct Alumno *unAlumno) {
	limpiarBufferDeTeclado();
	printf("Introducir nombre del alumno: ");
	fgets( unAlumno->nombre, MAX_NOMBRE, stdin );
	printf("Introducir la boleta del alumno: ");
	fgets( unAlumno->boleta, MAX_BOLETA, stdin );
}

void mostrarAlumno(struct Alumno unAlumno) {
	printf("Nombre: %s\n", unAlumno.nombre);
	printf("Boleta: %s\n", unAlumno.boleta);
}

void mostrarGrupo(int cuantos, struct Alumno grupo[]) {
	int contador = 0;
	for(contador=0; contador<cuantos; contador++) {
		mostrarAlumno( grupo[contador] );
		}
	printf("\n");
}

int calcularCuantos(struct Alumno grupo[], int numAlumnos) {
	int contador;
	for(contador=0; contador< numAlumnos; contador++) {
		if(strcmp(grupo[contador].nombre,"")==0 ) {
			break;
			}
		}
	return contador;
}

void enviarInformacionAlArchivo(struct Alumno grupo[], FILE *fpArchivo, char nombreArchivo[MAX_NOMBRE_ARCHIVO], int numAlumnos) {
	int contador = 0;
	fpArchivo = abrirArchivo( nombreArchivo, "wb" );
	fwrite(grupo, sizeof(struct Alumno), numAlumnos, fpArchivo);
	cerrarArchivo(fpArchivo);
	printf("%d Registros guardados.\n", numAlumnos);
}

struct Alumno * leerInformacionDelArchivo(struct Alumno *grupo, FILE *fpArchivo, char nombreArchivo[MAX_NOMBRE_ARCHIVO], int numAlumnos) {
	int contador, cuantos = 0;
	fpArchivo = abrirArchivo( nombreArchivo, "rb" );
	printf("Lectura de archivo: %d registros\n", numAlumnos);
	fread(grupo, sizeof(struct  Alumno), numAlumnos, fpArchivo );
	cerrarArchivo(fpArchivo);
	cuantos = calcularCuantos(grupo, numAlumnos);
	//mostrarGrupo(cuantos, grupo);
	return grupo;
}


int buscarAlumno(int cuantos, struct Alumno grupo[]) {
	int contador = 0, bandera = 0, auxiliarNombreABuscar = 0;
	char nombreABuscar[MAX_NOMBRE];
	char nombreAuxiliar[MAX_NOMBRE];
	limpiarBufferDeTeclado();
	printf("Introducir nombre del alumno: ");
	gets(nombreABuscar);

	for( contador=0; contador<cuantos; contador++ ) {
		strcpy(nombreAuxiliar, grupo[contador].nombre);
		//printf("%s - %s\n", nombreAuxiliar, nombreABuscar);
		//printf("Nombre: %d, %d", strlen(nombreAuxiliar), strlen(nombreABuscar));
		if(strlen(nombreABuscar) > strlen(nombreAuxiliar)-1){
			auxiliarNombreABuscar = strlen(nombreABuscar);
		}
		else{
			auxiliarNombreABuscar = strlen(nombreAuxiliar)-1;
		}
		for(int i = 0; i < auxiliarNombreABuscar; i++){
					if(nombreABuscar[i] == nombreAuxiliar[i]){
						bandera = 1;	
					}
					else {
						bandera = 0;
					}
		//			printf("%d", bandera);
		}
		//printf(" bandera: %d", bandera);
		if(bandera == 1) {
			mostrarAlumno(grupo[contador]);
			return contador;
			}
	}	
	printf("\nAlumno %s no encontrado\n", nombreABuscar);
}

// 5. Editar alumno
// Algoritmo
//	1. Buscar al alumno 
//  2. Si se encuentra entonces se edita
//     en caso contrario volver a intentar
// El usuario puede elegir si busca por nombre o busca por edad o busca por boleta
// Si es por edad entonces mostrar a todos los alumnos de esa edad y el usuario que elija uno

// 6. Eliminar un alumno (se cambio de grupo o se dio de baja)

// 7. Poder instroducir mas alumnos en un grupo incompleto
/*void editarAlumno(int cuantos, struct Alumno grupo[], FILE *fpArchivo, char nombreArchivo[MAX_NOMBRE_ARCHIVO]){
	//limpiarBufferDeTeclado();
	fpArchivo = abrirArchivo(nombreArchivo, "r+b");
	printf("Introducir nombre del alumno: ");
	char nombreAlumno[MAX_NOMBRE];
	gets(nombreAlumno);
	leerInformacionDelArchivo(grupo, fpArchivo, nombreArchivo, cuantos);
	//limpiarBufferDeTeclado();	
	while(!feof(fpArchivo)){
			if(nombreAlumno == grupo->nombre){
				printf("Ingrese nuevo nombre:");
				gets(grupo->nombre);
				int pos = ftell(fpArchivo) -sizeof(cuantos);
				fseek(fpArchivo, pos, SEEK_SET);
				fwrite(grupo, sizeof(grupo),cuantos,fpArchivo);
				printf("Se modifico");
				break;
			}
			fread(grupo, sizeof(grupo), cuantos, fpArchivo);
	}
}*/
void imprimirSalida(void) {
	printf("Menu del programa\n");
	printf("1. Introducir Alumno\n");
	printf("2. Leer grupo\n");
	printf("3. Guardar grupo\n");
	printf("4. Mostrar grupo\n");
	printf("5. Buscar alumno\n");
	printf("6. Editar alumno\n");
	printf("7. Borrar alumno\n");
	printf("8. Salir del programa\n");
	printf("Elija uno: ");
}
int validarNumAlumnos(int numAlumnos){
    if(numAlumnos>29 && numAlumnos<37){
        return 1;
    }
    else{
        return 0;
    }
}
void ejecutarMenu(FILE *fpArchivo,char nombreArchivo[MAX_NOMBRE_ARCHIVO], int numAlumnos) {
	int selector = 0;
	int cuantos = 0;
	struct Alumno *grupo = (struct Alumno *) malloc(sizeof(struct Alumno)*numAlumnos);
	memset(grupo, 0, sizeof(struct Alumno)*numAlumnos);
	while(selector!=8) {
		imprimirSalida();
		scanf("%d", &selector);
		switch(selector) {
			case 1:
				if(cuantos<numAlumnos) {
					introducirInformacionAlumno(&grupo[cuantos]);
					cuantos++;
					}
				else {
					printf("Numero de alumnos maximo en grupo alcanzado %d.\n", numAlumnos );
					}
				break;
			case 2:
				grupo = leerInformacionDelArchivo(grupo, fpArchivo, nombreArchivo, numAlumnos);
				cuantos = calcularCuantos(grupo, numAlumnos);
				printf("Tu archivo tiene %d alumnos registrados.\n", cuantos);
				break;
			case 3:
				enviarInformacionAlArchivo(grupo, fpArchivo, nombreArchivo, numAlumnos);
				break;
			case 4:
				mostrarGrupo(cuantos, grupo);
				break;
			case 5:
				buscarAlumno(cuantos, grupo);
				break;
			case 6:
				//editarAlumno(cuantos, grupo, fpArchivo, nombreArchivo);
				printf("no funciona :((");
				break;
			case 7:
				printf("Tampoco funciona :((");
				break;
			case 8:
				break;
			default:
				printf("Introduzca un entero con valor entre 1 y 6\n");
		}
	}
	free(grupo);
}
void inicioPrograma(){
    int opcion=0;
    char nombreArchivo[MAX_NOMBRE_ARCHIVO];
    int numAlumnos=0;
    FILE *fpArchivo = NULL;
    printf("\n\t1. Abrir un archivo .bin\n\t2. Crear un archivo .bin\nSeleccione una opcion: ");
    scanf("%d", &opcion);
    limpiarBufferDeTeclado();
    switch (opcion)
    {
    case 1:
        printf("Ingrese el nombre del archivo a abrir (.bin): ");gets(nombreArchivo);
        printf("Cuantos alumnos tiene su archivo (30-36): ");scanf("%d", &numAlumnos);
        if(validarNumAlumnos(numAlumnos) == 1){
            limpiarBufferDeTeclado();
            fpArchivo = abrirArchivo(nombreArchivo, "rb");
			
            ejecutarMenu(fpArchivo, nombreArchivo, numAlumnos);

        }
        else{
            printf("Ingrese un numero de alumnos valido.\n");
        }
        break;
    case 2:
        printf("Ingrese el nombre del nuevo archivo (.bin): ");gets(nombreArchivo);
        printf("Cuantos alumnos tendra su archivo (30-36): ");scanf("%d", &numAlumnos);
        if(validarNumAlumnos(numAlumnos) == 1){
            limpiarBufferDeTeclado();
            fpArchivo =abrirArchivo(nombreArchivo, "wb");
            ejecutarMenu(fpArchivo, nombreArchivo, numAlumnos);
        }
        else{
            printf("Ingrese un numero de alumnos valido.\n");
        }
        break;
    case 3:
        break;
    default:
        printf("Ingrese una opcion valida (1-3).");
        break;
    }
}
int main(int argc, char *argv[]) {
    inicioPrograma();
}