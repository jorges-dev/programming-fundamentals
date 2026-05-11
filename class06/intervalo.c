/*Construa um programaque solicite dois números inteiros ao usuário e exiba, na tela, todos os número inteiro que estão no intervalo entre eles.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int n1, n2, inicio, fim;

	printf("Digite o primeiro número inteiro: \n");
	scanf("%i", &n1);
	fflush(stdin);

	printf("Digite o segundo número inteiro: \n");
	scanf("%i", &n2);
	fflush(stdin);

	if (n1 < n2){
		inicio = n1;
		fim = n2;
	}else {
		inicio = n2;
		fim = n1;

	}


	for(int i = inicio + 1; i < fim; i++) {
		printf("%i \n", i);
	}

return 0;

}


