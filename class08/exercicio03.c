/*3. Construa um programa que leia dez números inteiros e determine
qual é o maior e qual é o menor valor informado. Ao final, o programa
deve calcular e mostrar a diferença entre o maior e o menor número
do conjunto.*/


#include <stdio.h>

int main() {
    int numero, maior, menor, diferenca;

    // Entrada de dados
    for (int i = 1; i <= 10; i++) {
        printf("Digite o %do numero inteiro: ", i);
        scanf("%i", &numero);

        // Na primeira iteração, inicializamos maior e menor com o primeiro número lido
        if (i == 1) {
            maior = numero;
            menor = numero;
        } else {
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }
    }

    // Calcula a diferença
    diferenca = maior - menor;

    // Saída de dados
    printf("\n--- Resultados ---\n");
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Diferenca entre o maior e o menor: %d\n", diferenca);

    return 0;
}




