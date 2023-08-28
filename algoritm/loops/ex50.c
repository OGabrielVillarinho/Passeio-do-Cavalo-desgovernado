#include <stdio.h>
#include <stdlib.h>


/* 
    Ler um valo N, calcular e escrever o valor de H;
 */

int main() {
    int n;
    float h = 0.0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        h += 1.0 / i;

    printf("%d\n", h);

    return 0;
}