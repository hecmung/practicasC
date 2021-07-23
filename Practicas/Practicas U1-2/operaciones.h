#include <stdio.h>
#include <math.h>
//MUNGUIA AGUILERA HECTOR ADRIAN 1CV16
#ifndef CALCULAR_POTENCIAS
#define CALCULAR_POTENCIAS

float calcularPotenciaIteracion(int exponente, float base){
    float n = base;
    for (int i = 1; i < fabs(exponente); i++)
        {
            n *= base;
        }
    if(exponente == 0){
        return 1.0;
    }
    else if(exponente > 0){
        return n;
    }
    else if(exponente < 0){
        return 1 / n;
    }
}
float calcularPotenciaRecursivo(int exponente, float base){
    if (exponente == 0)
    {
        return 1.0;
    }
    else if(exponente > 0){
        return base * calcularPotenciaRecursivo((exponente - 1), base);
    }
    else if(exponente < 0){
        return 1 / (base * calcularPotenciaRecursivo((fabs(exponente) - 1), base));
    }
}
#endif //CALCULAR_POTENCIAS

#ifndef SUMA_N_NUMEROS
#define SUMA_N_NUMEROS
int sumaDeNumerosIteracion(int numeroN){
    if(numeroN == 1){
        return 1;
    }
    else if(numeroN > 1){
        for(int i = (numeroN - 1); i > 0; i --){
            numeroN += i;
        }
        return numeroN;
    }
}
int sumaDeNumerosRecursivo(int numeroN){
    if(numeroN == 1){
        return 1;
    }
    else if(numeroN > 1){
        return (numeroN + sumaDeNumerosRecursivo((numeroN-1)));
    }
}
#endif //SUMA_N_NUMEROS

#ifndef NUMERO_PAR_O_IMPAR
#define NUMERO_PAR_O_IMPAR

int numeroParImpar(int numero){
    if(numero % 2 == 0){
        printf("El numero %d es par.", numero);
    }
    else{
        printf("El numero %d es impar.", numero);
    }
}
int esImpar(int numero);
int esPar(int numero){
    int numeroSinSigno = fabs(numero);
    if(numeroSinSigno == 0){
        return 1;
    }
    else if(numeroSinSigno > 0){
        esImpar(numeroSinSigno - 1);
    }
}
int esImpar(int numero){
    int numeroSinSigno = fabs(numero);
    if(numeroSinSigno == 0){
        return 0;
    }
    else if(numeroSinSigno > 0){
        esPar(numeroSinSigno - 1);
    }
}
#endif //NUMERO_PAR_O_IMPAR

#ifndef MULTIPLICACION_DOS_NUMEROS
#define MULTIPLICACION_DOS_NUMEROS
    int multiplicacionDosNumerosIteracion(int x, int y){
        int xSinSigno = fabs(x), ySinSigno = fabs(y), resultado = xSinSigno;
        for (int i = 1; i < ySinSigno; i++)
            {
                resultado += xSinSigno;
            }
        if(y == 0 || x == 0){
            return 0;
        }
        else if((y > 0 && x > 0) || (y < 0 && x < 0)){
            return resultado;
        }
        else if(x < 0 || y < 0){
            return (-resultado);
        }
        
    }
    int multiplicacionDosNumerosRecursivo(int x, int y){
        int ySinSigno = fabs(y);
        if(y == 0 || x == 0){
            return 0;
        }
        else if(y > 0){
            return x + multiplicacionDosNumerosRecursivo(x, (y - 1));
        }
        else if(y < 0){
            return -(x + multiplicacionDosNumerosRecursivo(x, (ySinSigno - 1)));
        }
    }
#endif //MULTIPLICACION_DOS_NUMEROS

#ifndef TORRES_DE_HANOI
#define TORRES_DE_HANOI

int torresDeHanoiIteracion(int numero){
    int resultado = 0;
    for (int i = 0; i < numero; i++)
    {
        resultado *= 2;
        resultado ++;        
    }
    if(numero == 1){
        return numero;
    }
    else if(numero > 1){
        return resultado;
    }
}
int torresDeHanoiRecursivo(int numero){
    if( numero == 1){
        return numero;
    }
    else if (numero > 1)
    {
        return (2 * torresDeHanoiRecursivo(numero-1) + 1);
    }
}
#endif //TORRES_DE_HANOI