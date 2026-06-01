/*
7. Construa um programa que leia uma matriz 3x3 e 
calcule a soma de todos os elementos da matriz. 
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int m[3][3], soma=0;
	
	// entrada
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Digite [%i,%i]: ",i,j);
			scanf("%i",&m[i][j]);
			fflush(stdin);
		}
	}
	
	// processamento
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			soma+=m[i][j];
		}
	}
	
	// saída
	printf("A soma e %i\n",soma);
	return 0;
}
