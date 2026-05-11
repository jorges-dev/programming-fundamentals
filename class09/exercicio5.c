/*3. Construa um programa que leia 5 números reais, armazene em um vetor e calcule a média dos valores informados*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[5], soma=0;
    float media;

    // Entrada e processamento de dados
    for (int i = 0; i < 5; i++) {
        printf("Digite o %i numero ", i+1);
        scanf("%i", &vetor[i]);
	    fflush(stdin);
	    soma+=i;
	    media=soma / 5;
    }
	
    // Saída de dados
    printf("\n--- Resultado ---\n");
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);

    return 0;
}



