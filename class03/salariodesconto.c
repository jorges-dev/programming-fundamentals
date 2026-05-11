//Uma empresa contrata um encanador por R$ 25,00 ao dia. Construa um programa que solicite o número de dias trabalhados e calcule a quantia líquida a ser paga, sabendo que há desconto de 8% de Imposto de Renda. 

#include <stdio.h>
#include <stdlib.h>

//Quais são as variáveis?

int main(void) {
    int D;
    float SB, SL;
    const float VD = 250.00;
    const float IR = 0.08;

//Quais são as entradas de dados?

    printf("Digite os dias trabalhados: ");
    scanf("%i", &D);
    fflush(stdin);


//Qual é o processamento de dados?

    SB = D * VD;

    SL = SB * (1.0 - IR);

//Quais são as saídas de dados?

    printf("Salário líquido a ser pago: R$ %f\n", SL);

    return 0;
}

