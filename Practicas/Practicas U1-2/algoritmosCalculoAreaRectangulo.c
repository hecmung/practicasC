#include <stdio.h>
/*
MUNGUIA AGUILERA HECTOR ADRIAN 1CV16

Ejemplo
    Construya un algoritmo que calcule y muestre el valor del area de un rectangulo.

    Algoritmo (parte 3)
        1. Iniciar
        2. baseRectangulo <- ?		// double centimetros 
        alturaRectangulo <- ?	// double centimetros
        areaRectangulo <- 0		// double
        3. areaReactangulo <- baseRectangulo * alturaRectangulo // centimetros^2
        4. print baseRectangulo "*" alturaRectangulo "=" areaRetangulo " centimetros^2"
        5. Finalizar
    Tarea:
    Poner las variables baseRectangulo, alturaRectangulo y areaRectangulo como variables locales del metodo
    principal y redefinir los metodos:
        introducirBaseYAlturaDelRectangulo()
        calcularAreaDelRectangulo()
        imprimirResultadosDelCalculo()
*/
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
// 1. Iniciar
int main(int argc, char *argv[]){
    
    double baseRectangulo, alturaRectangulo, areaRectangulo = 0.0;
    // 2. Introducir datos de la base y altura del rectangulo
    solicitarBase_Y_Altura_Del_Rectangulo(&baseRectangulo, &alturaRectangulo);
    // 3. Calcular el area del rectangulo
    areaRectangulo = calcular_Area_Rectangulo(&baseRectangulo, &alturaRectangulo);
    // 4. Mostrar el resultado del calculo del area del rectangulo
    imprimir_Resultado_Area(&baseRectangulo, &alturaRectangulo, &areaRectangulo);
    // 5. Finalizar
    return 0;
}