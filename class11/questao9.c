/*
Em um sistema de análise de dados, é necessário processar 
um conjunto de valores informados pelo usuário. Desenvolva 
um programa em C ANSI que leia 8 números inteiros, 
armazene os valores em um vetor, identifique o maior 
valor, o menor valor, a posição, índice, onde cada um 
foi encontrado e exiba os resultados ao final. 
R.: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int maior, menor, v[8];
	
	// entrada
	for(int i=0;i<=7;i++){
		printf("Digite %i numero: ",i+1);
		scanf("%i",&v[i]);
	}
	
	// processamento
	maior=v[0];
	menor=v[0];
	for(int i=1;i<=7;i++){
		if(v[i]>maior) maior=v[i];
		if(v[i]<menor) menor=v[i];
	}
	
	// saída
	printf("O maior e %i e o menor e %i\n",maior,menor);
	printf("Os numero estao aqui: \n");
	for(int i=0;i<=7;i++){
		if(menor==v[i]) printf("v[%i]=%i\n",i,v[i]);
		if(maior==v[i]) printf("v[%i]=%i\n",i,v[i]);
	}
	
	return 0;
}