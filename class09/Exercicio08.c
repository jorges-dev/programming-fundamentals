/*
8. Construa um programa que leia uma matriz 3x3 e 
exiba apenas os elementos da diagonal principal. 
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
			if(i==j){
				printf("%i\t",m[i][j]);
			}else{
				printf("\t");
			}
		}
		printf("\n");
	}
	
	return 0;
}
