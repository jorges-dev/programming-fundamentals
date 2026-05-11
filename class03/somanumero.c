/*Construa um programa que solicite dois números, calcule a soma entre eles e mostre o resultado na tela. 
*/

#include <stdio.h>

//Variáveis

int main() {
    float a, b, soma;

//Entrada de dados

    printf("Digite o primeiro número: ");
    scanf("%f", &a);
    fflush(stdin);

    printf("Digite o segundo número: ");
    scanf("%f", &b);
    fflush(stdin);

//Processamento de dados

    soma = a + b;

//Saída de dados

    printf("Resultado: %.2f + %.2f = %.2f\n", a, b, soma);

    return 0;
}
