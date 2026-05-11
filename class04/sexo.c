/*
6) Faça um programa que leia uma letra e verifique se ela corresponde 
a: F para Feminino, M para Masculino ou caso seja digitado outro valor,
 o programa deve informar "Sexo inválido". 
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	char sexo;
	
	// entrada
	printf("Digite o sexo (f/m): ");
	scanf("%c",&sexo);
	fflush(stdin);
	
	// processamento e saída
	switch(sexo){
		case 'f': case 'F':
			printf("Feminino\n");
			break;
		case 'm':
		case 'M':
			printf("Masculino\n");
			break;
		default:
			printf("Sexo invalido\n");
	}
	
	return 0;
}
