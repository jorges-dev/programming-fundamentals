/*
3.	Construa um algoritmo que solicite a temperatura em graus 
Fahrenheit (°F), converta esse valor para graus Celsius (°C) 
e mostre o resultado na tela. Utilize a fórmula: 
C = 5 * (F - 32) / 9.
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Quais são as variáveis?
	float C, F;
	
	// Quais são as entrada de dados?
	printf("Digite o valor Fahrenheit: ");
	scanf("%f",&F);
	fflush(stdin);
	
	// Qual é o processamento dos dados?
	C = 5 * (F - 32) / 9;
	
	// Quais são as saída de dados?
	printf("O valor em Celsius %f\n",C);

	return 0;
}

