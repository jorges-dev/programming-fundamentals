//Metros em CM

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Quais são as variáveis?
	float M, C;
	
	// Quais são as entrada de dados?
	printf("Digite o valor em metros: ");
	scanf("%f",&M);
	fflush(stdin);
	
	// Qual é o processamento dos dados?
	C = M * 100;
	
	// Quais são as saída de dados?
	printf("O valor em Centimetros %f\n",C);

	return 0;
}

