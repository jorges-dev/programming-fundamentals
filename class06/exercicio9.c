/*
9) FaÃ§a um programa que implemente uma calculadora simples. 
O programa deve solicitar dois valores e, em seguida, apresentar 
o menu abaixo para o usuÃ¡rio escolher a operaÃ§Ã£o desejada:
[1] AdiÃ§Ã£o
[2] SubtraÃ§Ã£o
[3] MultiplicaÃ§Ã£o
[4] DivisÃ£o
[5] Fim
O programa deve exibir o resultado da operaÃ§Ã£o escolhida. 
Caso o usuÃ¡rio escolha divisÃ£o, deve verificar se o segundo 
valor Ã© diferente de zero. Caso a opÃ§Ã£o informada seja invÃ¡lida, 
o programa deve exibir uma mensagem de erro.
R.:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// variÃ¡veis
	float n1, n2, r;
	int op;
	
	// entrada
	do{
		system("cls");
		system("color 1f");
		printf("[1] Adicao\n");
		printf("[2] Subtracao\n");
		printf("[3] Multiplicacao\n");
		printf("[4] Divisao\n");
		printf("[5] Fim\n\n");
		printf("Digite uma opcao: ");
		scanf("%i",&op);
		fflush(stdin);
		
		system("cls");
		if(op>=1 && op<=4){
			printf("Digite 1 numero: ");
			scanf("%f",&n1);
			fflush(stdin);
			printf("Digite 2 numero: ");
			scanf("%f",&n2);
			fflush(stdin);
		}
	
		// processamento e saÃ­da
		system("cls");
		system("color 02");
		
		switch(op){
			case 1:
				r=n1+n2;
				printf("%f + %f = %f\n",n1,n2,r);
				break;
			case 2:
				r=n1-n2;
				printf("%f - %f = %f\n",n1,n2,r);
				break;
			case 3:
				r=n1*n2;
				printf("%f * %f = %f\n",n1,n2,r);
				break;
			case 4:
				if(n2!=0){
					r=n1/n2;
					printf("%f / %f = %f\n",n1,n2,r);
				}else{
					system("color 4f");
					printf("Erro! Divisao por zero\n");
				}
				break;
			case 5:
				break;
			default:
				system("color 4f");
				printf("Erro! Nao tem esta opcao\n");
		}
		if(op!=5) system("pause");
	}while(op!=5);
	return 0;
}


