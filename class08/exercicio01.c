/*1. Construa um programa que leia 10 números inteiros e armazene em
um vetor. Ao final, exiba todos os valores informados.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	//Variáveis
	int i;
	int vetor[10];

	//Entrada de dados
	for(i = 0; i < 10; i++){
		printf("Digite um número inteiro: \n");
		scanf("%i", &vetor[i]);
		fflush(stdin);
	}
	//Processamento e saída de dados
	
	system("clear");

	for(i = 0; i < 10; i++) {
		printf("%i\n", vetor[i]);
	}

return 0;

}


