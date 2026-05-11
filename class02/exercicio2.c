/*
Exemplo 04 - Dado dois números, some eles.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){

	//Quais são as variáveis?
	float numero1, numero2, resultado;

	//Quais são as entradas de dados?
	printf("Digite 1 número: ");
	scanf("%f",&numero1);
	fflush (stdin);
	printf("Digite 2 número: ");
	scanf("%f" ,&numero2);
	fflush (stdin);

	//Quais os processamentos de dados?
	resultado=numero1+numero2;

	//Quais são as saídas dos dados?
	printf("%f + %f = %f",numero1,numero2,resultado);

	return 0;

}
