#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

/*
  ---PASSEIO DO CAVALO DESGOVERNADO---

  GABRIEL SOARES DE BARROS VILLARINHO
  MARCELO LIMA BROMONSCHENKEL

*/

void criar_uma_linha(int tam_linha)
// Essa função complementa a função mostrar_tabuleiro
{
	printf("\n");
	for (int i = 0; i < tam_linha; i++)
		printf("-");
	printf("\n");
}

void mostrar_tabuleiro(int mat[TAM][TAM])
{

	printf("---------------------------------------\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
			(mat[i][j] < 10) ? printf("|0%d| ", mat[i][j]) : printf("|%d| ", mat[i][j]);

		criar_uma_linha(39);
	}
}

int verificar_erros(int vet[TAM])
{
	int soma = 0, result;
	for (int i = 0; i < TAM; i++)
	{
		if (vet[i] == 1)
			soma++;
	}

	result = (soma == 8) ? 1 : 0;
	return result;
}

void ler_posicao_inicial(int *linha, int *coluna, int mat[][TAM])
{
	int x, y;
	printf("Jogada Inicial: (0 / 7)\n");

	do
	{
		printf("Linha->");
		scanf("%d", &x);
		printf("Coluna-> ");
		scanf("%d", &y);
		if ((x > 7) || (x < 0) || (y > 7) || (y < 0))
		{
			system("cls");
			printf("Valores invalidos. Tente novamente!\n");
			printf("Jogada Inicial: (0 / 7)\n");
		}
	} while ((x > 7) || (x < 0) || (y > 7) || (y < 0));
	*linha = x;
	*coluna = y;
}

void passeio_do_cavalo_desgovernado(int linha, int coluna, int vet[TAM], int mat[][TAM])
{
	int passeio = 0, posicao = 2;
	system("cls");
	srand(time(NULL));
	while (!verificar_erros(vet))
	{

		passeio = rand() % 8;
		printf("Passeio escolhido -> %d\n", passeio);
		printf("Linha-> %d\n", linha);
		printf("Coluna-> %d\n", coluna);

		switch (passeio)
		{
		case 0:
			if (linha >= 0 && linha + 2 <= 7 && coluna - 1 >= 0 && coluna <= 7 && mat[linha + 2][coluna - 1] == 0)
			{
				// Duas casas para baixo e 1 para esquerda
				mat[linha + 2][coluna - 1] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha += 2;
				coluna -= 1;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 1:
			if (linha >= 0 && linha + 2 <= 7 && coluna >= 0 && coluna + 1 <= 7 && mat[linha + 2][coluna + 1] == 0)
			{
				// Duas casas para baixo e 1 para direita
				mat[linha + 2][coluna + 1] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha += 2;
				coluna += 1;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 2:
			if (linha - 2 >= 0 && linha <= 7 && coluna >= 0 && coluna + 1 <= 7 && mat[linha - 2][coluna + 1] == 0)
			{
				// duas casas para cima e uma para direita
				mat[linha - 2][coluna + 1] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha -= 2;
				coluna += 1;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 3:
			if (linha - 1 >= 0 && linha <= 7 && coluna >= 0 && coluna + 2 <= 7 && mat[linha - 1][coluna + 2] == 0)
			{
				// Uma casa para cima e duas para direita
				mat[linha - 1][coluna + 2] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha -= 1;
				coluna += 2;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 4:
			if (linha >= 0 && linha + 1 <= 7 && coluna >= 0 && coluna + 2 <= 7 && mat[linha + 1][coluna + 2] == 0)
			{
				// Uma casa para baixo e duas para direita
				mat[linha + 1][coluna + 2] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha += 1;
				coluna += 2;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 5:
			if (linha - 2 >= 0 && linha <= 7 && coluna - 1 >= 0 && coluna <= 7 && mat[linha - 2][coluna - 1] == 0)
			{
				// Duas casas para baixo e uma para esquerda
				mat[linha - 2][coluna - 1] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;

				linha -= 2;
				coluna -= 1;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 6:
			if (linha - 1 >= 0 && linha <= 7 && coluna - 2 >= 0 && coluna <= 7 && mat[linha - 1][coluna - 2] == 0)
			{
				// Uma casa para baixo e duas para esquerda
				mat[linha - 1][coluna - 2] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha -= 1;
				coluna -= 2;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		case 7:
			if (linha >= 0 && linha + 1 <= 7 && coluna - 2 >= 0 && coluna <= 7 && mat[linha + 1][coluna - 2] == 0)
			{
				// Uma casa para baixo e duas para esquerda
				mat[linha + 1][coluna - 2] = posicao;

				for (int i = 0; i < TAM; i++)
					vet[i] = 0;
				linha += 1;
				coluna -= 2;
				posicao++;
				break;
			}
			else
			{
				vet[passeio] = 1;
				break;
			}
		}
		mostrar_tabuleiro(mat);
	}
	printf("QUANTIDADE DE CASAS VISITADAS-> %d\n", posicao - 1);
	printf("QUANTIDADE DE CASAS NAO VISITADAS-> %d\n", (TAM*TAM) - posicao + 1);

}

int main()
{
	int tabuleiro[TAM][TAM] = {0};
	int linha, coluna;
	int erros[TAM] = {0};

	ler_posicao_inicial(&linha, &coluna, tabuleiro);
	tabuleiro[linha][coluna] = 1;
	mostrar_tabuleiro(tabuleiro);
	passeio_do_cavalo_desgovernado(linha, coluna, erros, tabuleiro);

	return 0;
}
