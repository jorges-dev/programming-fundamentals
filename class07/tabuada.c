/*Construa um programa que gere a tabuada de 1 a 10 de qualquer
número informado pelo usuário. Ao final, o programa deverá exibir
todos os resultados correspondentes à multiplicação desse número
pelos valores de 1 até 10.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	//Variáveis
	int n;

	//Entrada de dados
	printf("Digite um número inteiro: \n");
	scanf("%i", &n);
	fflush(stdin);

	system("clear");
	
	//Processamento e saída de dados
	printf("Tabuada de 1 à 10\n");

	for(int i = 1; i <= 10; i++) {
		printf("%i x %i = %i\n", n, i, n * i);
	}

return 0;

}

