//Metros em CM

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Quais são as variáveis?
	float GH, HT, S;
	
	// Quais são as entrada de dados?
	printf("Digite o valor da hora de trabalho: ");
	scanf("%f",&GH);
	fflush(stdin);
	
	printf("Digite as horas trabalhadas: ");
	scanf("%f",&HT);
	fflush(stdin);

	// Qual é o processamento dos dados?
	S = HT * GH;
	
	// Quais são as saída de dados?
	printf("O valor do Salário %f\n",S);

	return 0;
}
