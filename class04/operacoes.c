/*Faça um programa que leia um número inteiro de 1 a 4 e exiba a operação correspondente: 

1 – Soma 

2 – Subtração 

3 – Multiplicação 

4 – Divisão 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int operacao;
	
	// entrada
	printf("1 - Soma\n");
	printf("2 - Subtração\n");
	printf("3 - Multiplicação)\n");
	printf("4 - Divisão\n");
	printf("Digite uma opção: ");
	scanf("%i",&operacao);
	fflush(stdin);
	
	// processamento e saída
	switch(operacao){
		case 1: 
			printf("Soma: operação de adição entre dois valores\n");
			break;
		case 2: 
			printf("Subtração: operação de redução entre dois valores\n");
			break;

		case 3: 
			printf("Multiplicação: operação multiplicar um número x vezes\n");
			break;
		case 4: 
			printf("Divisão: operação de divir um valor por outro valor\n");
			break;

	}
	
	return 0;
}
