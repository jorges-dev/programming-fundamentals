/*Construa um programa que leia uma matriz 4x4 e conte quantos elementos são maiores que 10. Ao final, exiba a quantidade encontrada*/

#include <stdio.h>
#include <stdlib.h>

int main () {
	int mat [4] [4];
	int contador=0;
	int i,j;
	
	//entrada de dados
	printf("Insira os elementos da matriz 4x4: \n");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			printf("Posição [%i] [%i]: ", i,j);
			scanf("%i", &mat [i] [j]);
			fflush(stdin);

		}

	}

	//processamento dos dados
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if(mat[i] [j] > 10){
				contador++;
			}
		}
	}
	
	//saída de dados
	printf("\n-- Resultado --\n");
	printf("\nA Matriz possui %i elementos maiores que 10.\n", contador);


	return 0;

}
