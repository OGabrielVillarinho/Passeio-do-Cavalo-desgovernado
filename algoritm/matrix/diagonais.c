#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main() {
    int mat[TAM][TAM];
    //Entrada
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) 
         scanf("%d", &mat[i][j]);
    }   

    //Elementos da diagonal principal
    for (int i = 0;i < TAM; i++) 
        printf("%d ", mat[i][i]);
    printf("\n\n\n");
    //Elementos da diagonal principal
    for (int i = 0;i < TAM; i++) 
        printf("%d ", mat[i][TAM - i -1]);

}