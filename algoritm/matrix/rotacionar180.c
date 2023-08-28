#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void rotacionar_matriz180(int mat[TAM][TAM]);
float calcular_media(int mat[TAM][TAM]);

int main() {
    int mat[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            scanf("%d ", &mat[i][j]);
        }
    }

    rotacionar_matriz180(mat);
    float medial_secundaria = calcular_media(mat);

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Media da diagonal secundaria => %.2f\n", medial_secundaria);
    return 0;
}

void rotacionar_matriz180(int mat[TAM][TAM]) {
    int i, j, temp;

    for (i = 0; i < TAM / 2; i++) {
        for (j = 0; j < TAM; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[TAM - 1 - i][TAM - 1 - j];
            mat[TAM - 1 - i][TAM - 1 - j] = temp;
        }
    }

}

float calcular_media(int mat[TAM][TAM]) {
    int soma = 0;
    for (int i = 0; i < TAM ; i++)
        soma += mat[i][TAM - i - 1];
    float media = (float)soma/TAM;

    return media;
}