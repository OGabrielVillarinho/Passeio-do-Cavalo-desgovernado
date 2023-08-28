#include <stdio.h>
#include <stdlib.h>

/* 
    Ler um conjunto de valores inteiros e positivos, calcular e escrever a soma 
    e o produto desses valores
 */

const int N = 10;
int main() {
    int valor, sum = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &valor);
        sum += valor;
    }

    printf("Soma total = %d\n", sum);
    return 0;
}