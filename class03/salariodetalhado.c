//Construa um algoritmo que solicite o salário bruto mensal de um funcionário, calcule e apresente os valores conforme o modelo abaixo.

#include <stdio.h>
#include <stdlib.h>

//Quais são as variáveis?

int main(void) {
    float SB, IR, INSS, SD, D, SL;

//Quais são as entradas de dados?

    printf("Digite o salario bruto mensal: R$ ");
    scanf("%f", &SB);
    fflush(stdin);

//Qual é o processamento de dados?

    IR = SB * 0.15;
    INSS = SB * 0.11;
    SD = SB * 0.03;
    D = IR + INSS + SD;
    SL = SB - D;

//Qual são as saídas de dados?

    printf("\nSalario Bruto  : R$ %.2f\n", SB);
    printf("(-) IR  (15%%) : R$ %.2f\n", IR);
    printf("(-) INSS(11%%) : R$ %.2f\n", INSS);
    printf("(-) Sindicato( 3%%) : R$ %.2f\n", SD);
    printf("Salario Liquido: R$ %.2f\n", SL);

    return 0;
}
