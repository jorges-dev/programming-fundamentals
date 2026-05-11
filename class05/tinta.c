/*Elabore um programa para calcular a quantidade necessária de latas de tinta para pintar uma parede com X metros de largura por H metros de altura. Considere que o consumo de latas de tinta por metro quadrado é 3 litros e a quantidade de tinta por lata é 3,6 litros. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	float altura, largura, m2, tinta= 3.6;
	
	// quais são as entradas de dados?
	printf("Digite a altura da parede em metros: \n");
	scanf("%f",&altura);
	fflush(stdin);

	printf("Digite a largura da parede em metros: \n");
	scanf("%f",&largura);
	fflush(stdin);
	
	// qual é o processamento dos dados?
	
	m2=(altura * largura);
	tinta=((m2 * 3) / tinta);

	// qual é a sáida de dados?
	
	printf("Serão necessárias %.1f 	latas de tinta\n", tinta);
	
	return 0;
}
