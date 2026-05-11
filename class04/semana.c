/*Faça um programa que leia um número de 1 a 7 e exiba o dia correspondente da semana, conforme a tabela abaixo: 

1 - Domingo 

2 - Segunda-feira 

3 - Terça-feira 

4 - Quarta-feira 

5 - Quinta-feira 

6 - Sexta-feira 

7 - Sábado 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int dia;
	
	// entrada
	printf("Digite o dia da semana (1 à 7): ");
	scanf("%i",&dia);
	fflush(stdin);
	
	// processamento e saída
	switch(dia){
		case 1: 
			printf("Domingo\n");
			break;
		case 2: 
			printf("Segunda\n");
			break;

		case 3: 
			printf("Terça\n");
			break;
		case 4: 
			printf("Quarta\n");
			break;

		case 5: 
			printf("Quinta\n");
			break;

		case 6: 
			printf("Sexta\n");
			break;

		case 7: 
			printf("Sábado\n");
			break;

	}
	


	return 0;
}
