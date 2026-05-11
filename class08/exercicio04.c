/*Construa um programa que calcule e mostre a média bimestral de
uma turma. O usuário deverá informar a quantidade de notas que
serão consideradas e, em seguida, digitar cada uma delas. Ao final, o
programa deverá apresentar a média calculada.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int qnotas;
    float nota, soma=0, media;
	
    printf("Digite o número de notas: \n");
    scanf("%i", &qnotas);
    fflush(stdin);

    // Inicialização
    for (int i = 1; i <= qnotas; i++) {
        printf("Digite %i nota: ", i);
        scanf("%f", &nota);
	fflush(stdin);
	soma+=nota;
    }
	media=soma/qnotas;

	printf("A Media é %.2f\n", media);

    return 0;
}

