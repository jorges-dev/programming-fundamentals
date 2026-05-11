/*
Faça um programa que peça um número e informe se o número é inteiro ou quebrado.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Quais são as variáveis?
    float numero;

    // Quais são as entradas de dados?
    printf("Digite um número: ");
    scanf("%f", &numero);
    fflush(stdin);

    // Quais são os processamentos de dados?

    if(numero == (int)numero){
	    printf("Número Inteiro!\n");
    }else{
	printf("Numero Quebrado!\n");

}

    return 0;
}
