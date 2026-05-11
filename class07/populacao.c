/*Considere que a população do país A é de 80.000 habitantes, com
crescimento anual de 3%, e que a população do país B é de 200.000
habitantes, com crescimento anual de 1,5%. Construa um programa
que calcule e mostre o número de anos necessários para que a
população do país A seja maior ou igual à população do país B,
mantendo-se essas taxas de crescimento*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Variaveis
	int pA=80000, pB=200000, anos= 0;
	float crA= 0.03, crB= 0.015;
		
	// Processamento dos dados
	while(pA < pB){
		pA += pA * crA;
		pB += pB * crB;
		anos = anos + 1;
	}
	
	system("clear");
	
	// Saida de dados
	printf("Serão necessários %i anos para que a população do país A seja maior que a população do país B\n", anos);
	
	return 0;
}



