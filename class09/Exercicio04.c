/*
4. Construa um programa que leia 10 números inteiros e 
conte quantos deles são pares e quantos são ímpares. 
R.: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int n[10], q_impares=0, q_pares=0;
	
	// entrada
	for(int i=0;i<10;i++){
		printf("Digite %i numero: ",i+1);
		scanf("%i",&n[i]);
		fflush(stdin);
	}
	
	// processamento
	for(int i=0;i<10;i++){
		if(n[i]%2 == 0){
			q_pares++;
		}else{
			q_impares++;
		}
	}
	
	// saída
	printf("A quantidade de parese e %i\n",q_pares);
	printf("A quantidade de impares e %i\n",q_impares);
	
	return 0;
}
