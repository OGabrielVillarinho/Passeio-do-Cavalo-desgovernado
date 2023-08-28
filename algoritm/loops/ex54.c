#include <stdio.h>
#include <stdlib.h>

/*
    Algoritmo para calcular o valor do desvio padrão
 */

int main() {
    int tamanho;
    printf("Digite o número de valores: ");
    scanf("%d", &tamanho);

    double soma = 0.0;
    double soma_dos_quadrados = 0.0;

    for (int i = 0; i < tamanho; ++i) {
        double valor;
        printf("Digite o valor %d: ", i + 1);
        scanf("%lf", &valor);

        soma += valor;
        soma_dos_quadrados += valor * valor;
    }

    double media = soma / tamanho;
    double variancia = (soma_dos_quadrados / tamanho) - (media * media);
    double desvio_padrao = sqrt(variancia);

    printf("O desvio padrão é: %lf\n", desvio_padrao);

    return 0;
}