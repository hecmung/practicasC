#include <stdio.h>

int calcularFacotrialIterado(int n){
    int factorial = n;
    int i;
    for (i = n - 1; i > 0; i--)
    {
        factorial *= i;
    }
    return factorial;
}
int calcularFactorialRecursivo(int n){
    if (n == 0){
        return 1;
    }
    return n*calcularFacotrialIterado(n-1);
}
int calcularFibonacciIterado(int n){
    return 0;
}
int calcularFibonacciRecursivo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    //printf("%d,",n);
    return calcularFibonacciRecursivo(n-2)+calcularFibonacciRecursivo(n-1);
}
int calcularHanoiRecursivo(int n){
    if( n == 1){
        return n;
    }
    else if (n > 1)
    {
        return 2*calcularHanoiRecursivo(n-1) + 1;
    }
}
int main(int argc, char *argv[]){
    int numero = 3;
    printf("Factorial Iterado\n");
    printf("%d! = %d\n", numero, calcularFacotrialIterado(numero));
    printf("Factorial Recursivo\n%d! = %d\n", numero, calcularFactorialRecursivo(numero));
    printf("Fibonacci Recursivo\n%d = %d\n", numero, calcularFibonacciRecursivo(numero));
    printf("Hanoi Recursivo\n%d = %d\n", numero, calcularHanoiRecursivo(numero));
    return 0;
}