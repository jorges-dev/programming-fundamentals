/*Construa um programa que leia 8 números inteiros e calcule a soma de todos os elementos do vetor*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int vetor[8];
    int soma = 0;

    // Entrada de dados
       for (int i = 0; i < 8; i++) {
        printf("Digite %i numero: \n", i+1);
        scanf("%i", &vetor[i]);
	    fflush(stdin);
    }

    // Processamento dos dados
    for (int i = 0; i < 8; i++) {
        soma += vetor[i];
    }

    // Saída dos dados
    printf("\n--- Resultado ---\n");
    for(int i=0; i<=7; i++){
    printf("%i + ", vetor[i]);
    }
    printf("\nA soma de todos os elementos é: %i\n", soma);

    return 0;
}
