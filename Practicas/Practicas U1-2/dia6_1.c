/*
Un alumno requiere de un programa en lenguaje C que realice el siguiente
calculo.

    X(1,2) = [-b (+-) SQRT{(b^2) - 4ac}]/2a
Es decir la formula general.
*/
#include "stdio.h"
#include "math.h"

int main(int argc, char *argv[]){

    double x1 = 0, x2 = 0;
    int a, b, c, discriminante;
    printf("Resolveremos la ecuacion general.\t");
    printf("X(1,2) = [-b (+-) SQRT{(b^2) - 4ac}]/2a\n");
    printf("Ingrese los valores de a, b y c, respectivamente:\n");
    scanf("%d %d %d", &a, &b, &c);
    discriminante = (b*b) - (4*a*c);
    if(discriminante >= 0){
    x1 = (-b + sqrt(discriminante)) / (2*a);
    x2 = (-b - sqrt(discriminante)) / (2*a);
    printf("El valor de las raices son:\nX1 = %.9f \tX2 = %.9f\n", x1, x2);
    }
    else
    {
        printf("El valor de la raiz es negativo, y no podemos calcular raices negativas.");
    }
    
    return 0;
}