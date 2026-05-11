#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	//Variáveis
	int i;
	float media, soma;
	int vetor[5];

	//Entrada de dados
	for(i = 0; i < 5; i++){
		printf("Digite um número inteiro: \n");
		scanf("%i", &vetor[i]);
		fflush(stdin);
		soma = soma + vetor[i];
	}
	//Processamento e saída de dados
	
	media = soma / 5;
	
	system("clear");
	
	printf("%.2f\n", media);

return 0;

}
