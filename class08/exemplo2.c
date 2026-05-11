/* problema media de 10 número e mostrar os números */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	// variáveis
	int n, soma=0;
	float media;
	
	// entrada
	for(int i=1;i<=3;i++){
		printf("Digite %i numero entre 1 e 99: ",i);
		scanf("%i",&n);
		fflush(stdin);
		if(n>=1 && n<=99){
			soma+=n*pow(100,i);
			printf("soma = %i\n",soma);
		}else{
			printf("Erro! Nao esta entre 1 e 99.\n");
			i--;
		}
	}
	int n1 = (int)soma%10000/100;
	printf("n1 = %i\n",n1);
	int n2 = (int)soma%1000000/10000;
	printf("n2 = %i\n",n2);
	int n3 = (int)soma%100000000/1000000;
	printf("n3 = %i\n",n3);
	
	return 0;
}
