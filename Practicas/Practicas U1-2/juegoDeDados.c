#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Algoritmo
    1. Iniciar el juego
    2. Entradas por teclado: numeroDelJugador, dado1, dado2, sumaDeLosDados.
    3. Generar el ritual del jugador
        3.1 Tomas los dados.
        3.2 Soplar los dados.
        3.3 Agitar los dados.
        3.4 Lanzar los dados.
            En las variables dado1 y dado2 se almacenan los numeros que la computadora va a generar (numeros pseudo-aleatorios) entre 1 y 6,
            estos dos numeros se suman y se asignan a sumaDeLosDados.
        4. Realizar la comprobacion de sumaDeLosDados contra numeroDelJugador, si son iguales se muestra que el jugador gano, de lo contrario 
           se indica que perdio y porque ocurrio.
        5. Fin del juego.
*/
#define caraDado 6

int numeroDelJugador, dado1, dado2, sumaDeLosDados;

void solicitarNumero(){
    printf("\nIngresa tu numero del 2 al 12: ");
    scanf("%d", &numeroDelJugador);
    
}
int tirarDado(){
    return (rand()%caraDado) + 1;
}
void tomarDados(){
    dado1 = 0;
    dado2 = 0;
    printf("\nTomando los dados");
}
void soplarDados(){
    printf("\npfffff");
}
void agitarDados(){
    printf("\nTaca-Taca...");
}
void imprimirResultadoDeJuego(){
    if (numeroDelJugador == sumaDeLosDados)
    {
        printf("\nGanaste, tu numero fue: %d", numeroDelJugador);
    }
    else
    {
        printf("\nPerdiste, tu numero fue: %d y la suma de los dados es: %d", numeroDelJugador, sumaDeLosDados);
    }
    
    
}
void jugarDados(){
    solicitarNumero();
    tomarDados();
    soplarDados();
    agitarDados();
    dado1 = tirarDado();
    printf("\nEl dado uno saco: %d", dado1);
    dado2 = tirarDado();
    printf("\nEl dado dos saco: %d", dado1);
    sumaDeLosDados = dado1 + dado2;
    imprimirResultadoDeJuego();
}
int main(int argc, char *argv[]){
    srand(time(NULL));
    jugarDados();

    return 0;
}