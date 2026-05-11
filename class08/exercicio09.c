/*
9. Construa um programa que calcule e mostre a soma de todos 
os números pares entre 100 e 200, inclusive. Após exibir o 
resultado, o programa deverá permitir que o usuário escolha 
se deseja repetir essa operação novamente. 
R.: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variáveis
	int soma=0; 
	char op;
	
	// entrada
	do{
		for(int i=100;i<=200;i++){
			if (i%2==0){
				soma+=i;
			}
		}
		printf("A soma e %i\n\n",soma);
		printf("Deseja repetir (s/n): ");
		scanf("%c",&op);
		fflush(stdin);
	}while(op=='s' || op == 'S');
	
	return 0;
}
 
