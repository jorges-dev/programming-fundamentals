// Exemplo 01 - Dado dois números qual é o maior?
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	int numero1, numero2;
	
	// quais são as entradas de dados?
	printf("Digite 1 numero: ");
	scanf("%i",&numero1);
	fflush(stdin);
	printf("Digite 2 numero: ");
	scanf("%i",&numero2);
	fflush(stdin);
	
	// qual é o processamento dos dados e saída dos dados?
	if(numero1 > numero2){
		printf("O numero 1 e o maior = %i\n",numero1);
	}else{
		if(numero2 > numero1){
			printf("O numero 2 e o maior = %i\n",numero2);
		}else{
			printf("Os numeros sao iguais\n");
		}
	}
	
	return 0;
}
