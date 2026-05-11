/*Construa um algoritmo que calcule a área de um quadrado, em seguida mostre o dobro desta área para o usuário.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	float medida, area;
	
	// quais são as entradas de dados?
	printf("Digite a medida de um dos lados do quadrado (cm): \n");
	scanf("%f",&medida);
	fflush(stdin);
	
	// qual é o processamento dos dados?
	
	area=(medida * medida);

	// qual é a sáida de dados?
	
	printf("A área do quadrado é %.2fcm \n", area);
	
	return 0;
}
