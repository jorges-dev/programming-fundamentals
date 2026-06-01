/*
6. Construa um programa que leia os valores de uma 
matriz 3x3 e exiba todos os elementos na tela no 
formato de tabela. 
R.: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int m[3][3];
	
	// entrada
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Digite [%i,%i]: ",i,j);
			scanf("%i",&m[i][j]);
			fflush(stdin);
		}
	}
	
	// saída
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%i\t",m[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
