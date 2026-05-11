/*3. Construa um programa que leia 10 número inteiro e informe qual é o maior valor armazenado no vetor*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor [10], maior, menor;

    // Entrada de dados
    for (int i = 0; i <= 9; i++) {
        printf("Digite o %i numero ", i+1);
        scanf("%i", &vetor[i]);
	fflush(stdin);

        // Na primeira iteração, inicializamos maior e menor com o primeiro número lido
        if (i == 1) {
            maior = vetor[i];
            menor = vetor[i];
        } else {
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
            if (vetor[i] < menor) {
                menor = vetor[i];
            }
        }
    }

    // Saída de dados
    printf("\n--- Resultados ---\n");
    printf("Maior valor: %d\n", maior);

    return 0;
}




