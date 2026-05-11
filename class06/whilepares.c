/*
2. Construa um programa que solicite dois nÃºmeros inteiros ao 
usuÃ¡rio e exiba, na tela, apenas os nÃºmeros pares que estÃ£o no 
intervalo entre eles. 
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variÃ¡veis
	int n1, n2;
	int i;
	
	// entrada
	printf("Digite 1 numero: ");
	scanf("%i",&n1);
	fflush(stdin);
	printf("Digite 2 numero: ");
	scanf("%i",&n2);
	fflush(stdin);
	
	// processamento e saÃ­da
	if(n1<n2){
		i=n1+1;
		while(i<=n2-1){
			if(i%2 == 0) printf("%i, ",i);
			i++;
		}
	}else{
		i=n1-1;
		while(i>=n2+1){
			if(i%2 == 0) printf("%i, ",i);
			i--;
		}
	}
	
	
	return 0;
}
