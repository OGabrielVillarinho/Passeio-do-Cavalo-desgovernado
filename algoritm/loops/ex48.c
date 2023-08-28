#include <stdio.h>
#include <stdlib.h>

/* 
    Ler o conjunto de valores inteiros e positivos, calcular e escrever a média;
*/

const int QTD = 4;
int main() {
    int valor, sum = 0;

    for (int i = 0; i < QTD; i++) {
        scanf("%d", &valor);
        sum += valor;
    }

    float media = (float)sum/QTD;
    printf("MEDIA = %.2f\n", media);
    return 0;
}