/*
10) Um sistema de análise matricial trabalha com 
matrizes quadradas 3x3. Considere que a diagonal 
principal é formada pelos elementos onde 
linha = coluna, como [0][0], [1][1] e [2][2], e 
que a diagonal secundária é formada pelos elementos 
onde linha + coluna = 2, como [0][2], [1][1] e [2][0]. 
Desenvolva um programa em C ANSI que leia os valores 
de uma matriz 3x3, calcule a soma da diagonal principal, 
calcule a soma da diagonal secundária, compare os 
resultados e informe qual diagonal possui maior soma. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int m[3][3];
	
	// entrada
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("Digite [%i,%i]: ",i,j);
			scanf("%i",&m[i][j]);
		}
	}

	// processamento
	int soma1=m[0][0]+m[1][1]+m[2][2];
	int soma2=m[0][2]+m[1][1]+m[2][1];
	
	// saída
	if(soma1>soma2){
		printf("A soma 1 e maior e o valor e %i\n",soma1);
	}else if(soma1<soma2){
		printf("A soma 2 e maior e o valor e %i\n",soma2);
	}else{
		printf("Os numeros sao iguais e e %i\n",soma1);
	}
	
	return 0;
}