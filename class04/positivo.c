// Faça um programa que leia um número e informe se ele é positivo, negativo ou igual a zero.
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	int numero;
	
	// quais são as entradas de dados?
	printf("Digite um numero: ");
	scanf("%i",&numero);
	fflush(stdin);
	
	// qual é o processamento dos dados e saída dos dados?
	if(numero > 0){
		printf("O numero é positivo = %i\n",numero);
	}else{
		if(numero < 0){
			printf("O numero é negativo = %i\n",numero);
		}else{
			printf("O numero é zero\n");
		}
	}
	
	return 0;
}
