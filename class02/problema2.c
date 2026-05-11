/*
Programa para calcular a área de um círculo
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Quais são as variáveis?
    float raio, area;

    // Quais são as entradas de dados?
    printf("Digite o raio: ");
    scanf("%f", &raio);

    // Quais são os processamentos de dados?
    area = 3.14159 * raio * raio;

    // Quais são as saídas dos dados?
    printf("Área do circulo = %.2f\n", area);

    return 0;
}
