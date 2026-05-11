/*
3.	Construa um algoritmo que solicite a temperatura em graus 
Celsius (°C), converta esse valor para graus Fahrenheit (°F) 
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
	printf("Digite o valor Celsius: ");
	scanf("%f",&C);
	fflush(stdin);
	
	// Qual é o processamento dos dados?
	F = C * 9 / 5 + 32;
	
	// Quais são as saída de dados?
	printf("O valor em Fahrenheit %f\n",F);

	return 0;
}

