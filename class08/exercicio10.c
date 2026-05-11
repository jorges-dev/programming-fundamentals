/*
10. Construa um programa que solicite dois números inteiros, 
sendo eles a base e o expoente, e calcule o valor da potência 
correspondente. Ao final, o programa deverá mostrar o resultado
do primeiro número elevado ao segundo. 
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int base, expoente, r=1;
	
	// entrada
	printf("Digite a base: ");
	scanf("%i",&base);
	fflush(stdin);
	printf("Digite o expoente: ");
	scanf("%i",&expoente);
	fflush(stdin);
	
	// processamento
	for(int i=1;i<=expoente;i++){
		r*=base;
	}
	
	// saída
	printf("O valor e %i\n",r);
	
	return 0;
}