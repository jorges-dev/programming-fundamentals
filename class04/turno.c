/*
Faça um programa que pergunte em qual turno o aluno estuda. O
programa deve receber:
M para Matutino
V para Vespertino
N para Noturno
De acordo com a opção informada, exiba a mensagem correspondente:
"Bom Dia!", "Boa Tarde!" ou "Boa Noite!". Caso seja digitado outro
valor, exiba "Valor inválido!".
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	char turno;
	
	// entrada
	printf("Qual turno você estuda? (M/V/N): ");
	scanf("%c",&turno);
	fflush(stdin);
	
	// processamento e saída
	switch(turno){
		case 'm': case 'M':
			printf("Bom dia!\n");
			break;
		
		case 'v': case 'V':
			printf("Boa Tarde!\n");
			break;
		
		case 'n':
		case 'N':
			printf("Boa Noite!\n");
			break;
		default:
			printf("Valor Inválido!\n");
	}
	
	return 0;
}
