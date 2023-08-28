#include <stdio.h>
#include <stdlib.h>


/* 
    Ler um conjunto de pares de valores inteiros, calcular e escrever o 
    resultado da divisão do primeiro pelo segundo. Caso o segundo valor seja nulo,
    escrever a mensagem "DIVISÃO INVÁLIDA"
 */

const int FLAG = 4;
int main() {
    int n1, n2;

    for (int i = 0; i < FLAG; i++) {
        scanf("%d", &n1);
        scanf("%d", &n2);
        if (n2 == 0) {
            printf("Divisão inválida");
            continue;
        }
        printf("%.2f\n", (float)n1/n2);
    }


    return 0;
}