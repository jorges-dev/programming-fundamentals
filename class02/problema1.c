/*
Programa para saber a média final
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){

	//Quais são as variáveis?
	float nota1, nota2, nota3, nota4, nnotas, resultado;

	//Quais são as entradas de dados?
	printf("Digite a nota 1: ");
	scanf("%f",&nota1);
	fflush (stdin);
	printf("Digite a nota 2: ");
	scanf("%f",&nota2);
	fflush (stdin);
	printf("Digite a nota 3: ");
	scanf("%f",&nota3);
	fflush (stdin);
	printf("Digite a nota 4: ");
	scanf("%f",&nota4);
	fflush (stdin);
	printf("Digite o número de notas: ");
	scanf("%f",&nnotas);
	fflush (stdin);


	//Quais os processamentos de dados?
	resultado=(nota1+nota2+nota3+nota4)/nnotas; 

	//Quais são as saídas dos dados?
	printf(("%f + %f + %f + %f) / %f = %f"),nota1,nota2,nota3,nota4, nnotas, resultado);

	return 0;

}
