#include <stdio.h>
#include <stdlib.h>

/* 
    Ler um valor inteiro e positivo e escrever o fatorial de N;
*/

int main() {

    int n;
    scanf("%d", &n);
    unsigned long long fat = 1;
    for (int i = 1; i <= n; i++)
        fat *= i;

    printf("%lld\n", fat);
    return 0;
}