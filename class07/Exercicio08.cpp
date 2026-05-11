/*
8. Considere que a população do país A é de 80.000 habitantes, 
com crescimento anual de 3%, e que a população do país B é de 
200.000 habitantes, com crescimento anual de 1,5%. Construa um 
programa que calcule e mostre o número de anos necessários 
para que a população do país A seja maior ou igual à população 
do país B, mantendo-se essas taxas de crescimento. 
R.: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	float a=80000, b=200000;
	int anos=0;
	
	// processamento
	while(a<=b){
		a*=1.03;
		b*=1.015;
		anos++;
	}
	
	// saída
	printf("A quantidade de anos e %i\n",anos);
	
	return 0;
}