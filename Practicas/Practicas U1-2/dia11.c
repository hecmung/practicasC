/*
Algoritmo
    Es una secuencia de pasos para resolver un problema y tiene las siguientes caracteristicas:
        1. Preciso: Cada pasod ebe ser claro y exacto en su construccion para que asi determine puntualmente lo que se desea hacer.
        2. Definido: Cada vez que se ejecute el algoritmo con los mismo datos de entrada debe generar el mismo resultado.
        3. Finito: Todo algoritmo debe tener un fin.
    Como se construye un algoritmo:
        -Utilizar las palabras del idioma nativo. Lo debe entender cualquier persona.
        -Se puede emplear un cuasi-codigo (pseudo-codigo), para describir lo que se tiene que hacer.
        -Los pasos deben ser traducidos a un lenguaje de programacion.
    Pasos para construir un algoritmo:
        1. Inicio.
        2. Conocer los datos que permitan resolver el problema.
        3. Realizar el procesamiento logico, calculos, resolucion de ecuaciones, etc.
        4. Mostrar los resultados, visualizar, imprimir del problema planteado.
        5. Finalizar.
Ejemplo:
    Construya un algoritmo que calcule y muestre el valor del area de un rectangulo.
Algoritmo:
    1. Iniciar.
    2. Conocer la base y la altura del rectangulo.
    3. Realizar el calculo de area del rectangulo, multiplicando la base por la altura.
    4. Mostrar el resultado del calculo del area del rectangulo.
    5. Finalizar.
*/
//Poner las variables base, altura y area como variables locales del metodo principal y redefinir los metodos.
#include <stdio.h>
/*double baseRectangulo, alturaRectangulo, areaRectangulo = 0.0;
void soliticarBaseAlturaDelRectangulo(){
    printf("Ingrese la base del rectangulo en centimetros: ");
    scanf("%lf", &baseRectangulo);
    printf("Ingrese la altura del rectangulo en centimetros: ");
    scanf("%lf", &alturaRectangulo);
}
double calcularAreaRectangulo(){
    return baseRectangulo * alturaRectangulo;
}*/
//Iniciar
void solicitarBase_Y_Altura_Del_Rectangulo(double *baseRectangulo, double *alturaRectangulo){
    printf("Ingrese la base del rectangulo: ");
    scanf("%lf", &*baseRectangulo);
    printf("Ingrese la altura del rectangulo: ");
    scanf("%lf", &*alturaRectangulo);
}
double calcular_Area_Rectangulo(double *baseRectangulo, double *alturaRectangulo){
    return *baseRectangulo * *alturaRectangulo;
}
void imprimir_Resultado_Area(double *baseRectangulo, double *alturaRectangulo, double *areaRectangulo){
    printf("El area del rectangulo es:\n %.2lf * %.2lf = %.2lf", *baseRectangulo, *alturaRectangulo, *areaRectangulo);
}
int main(int argc, char *argv[]){
   /* //2. Conocer la base y la altura del rectangulo.
    soliticarBaseAlturaDelRectangulo();
    //3. Realizar el calculo del area del rectangulo.
    areaRectangulo = calcularAreaRectangulo();
    //4. Mostrar el resultado del calculo del area del rectangulo.
    printf("El area del rectangulo es:\n%.5lf * %.5lf = %.5lf (cm)^2", baseRectangulo, alturaRectangulo, areaRectangulo);
    //Finalizar.
    */
    double baseRectangulo, alturaRectangulo, areaRectangulo = 0.0;
    solicitarBase_Y_Altura_Del_Rectangulo(&baseRectangulo, &alturaRectangulo);
    areaRectangulo = calcular_Area_Rectangulo(&baseRectangulo, &alturaRectangulo);
    imprimir_Resultado_Area(&baseRectangulo, &alturaRectangulo, &areaRectangulo);

    return 0;
}