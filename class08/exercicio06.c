/*6. Construa um programa que calcule o valor total investido na compra 
de CDs e também o custo médio por unidade. O usuário deverá 
informar a quantidade de CDs adquiridos e, em seguida, o valor pago 
por cada um deles.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    //Variaveis
    int qcd;
    float valorcd, cmedio, soma=0;
	
    //Entrada de dados
    printf("Digite o número de CDs comprados: \n");
    scanf("%i", &qcd);
    fflush(stdin);

    //Processamento de dados
    for (int i = 1; i <= qcd; i++) {
        printf("Digite %i valor: ", i);
        scanf("%f", &valorcd);
	    fflush(stdin);
	    soma+=valorcd;
        }
	
    cmedio=soma/qcd;
    
    //Saída de dados
	printf("O Investimento total nos CDs é %.2f\n", soma);
	printf("A Media paga em cada CD é R$ %.2f\n", cmedio);

    return 0;
}

