/* Faça um programa que leia três notas de um aluno, calcule a média
e apresente uma das mensagens a seguir:*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	int nota1, nota2, nota3, media;
	
	// quais são as entradas de dados?
	printf("Digite a nota 1: ");
	scanf("%i",&nota1);
	fflush(stdin);
	
	printf("Digite a nota 2: ");
	scanf("%i",&nota2);
	fflush(stdin);

	printf("Digite a nota 3: ");
	scanf("%i",&nota3);
	fflush(stdin);

	// qual é o processamento dos dados e saída dos dados?
	
	media=((nota1 + nota2 + nota3)/3);

	if(media < 7){
		printf("Reprovado\n");
	}else if(media >= 10){
		printf("Aprovado com Distinção\n");
	}else if(media >= 7){
		printf("Aprovado\n");
	}
		
	
return 0;
}
