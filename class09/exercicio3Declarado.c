/*
3. Construa um programa que leia 10 números inteiros e 
informe qual é o maior valor armazenado no vetor.
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int n[]={77,44,32,26,51,14,88,99,29,39};
	
	// entrada
	for(int i=0;i<10;i++){
		printf("Digite %i numero: ",i+1);
		scanf("%i",&n[i]);
		fflush(stdin);
	}
	
	// processamento
	int maior=n[0];
	for(int i=1;i<=9;i++){
		if(n[i]>maior){
			maior=n[i];
		}
	}
	
	// saída
	printf("O maior e %i\n",maior);
	return 0;
}
