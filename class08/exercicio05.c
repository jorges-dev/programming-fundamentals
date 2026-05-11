/*Construa um programa que calcule e mostre a média bimestral de
uma turma. O usuário deverá informar a quantidade de notas que
serão consideradas e, em seguida, digitar cada uma delas. Ao final, o
programa deverá apresentar a média calculada.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int qturma;
    int qaluno, soma=0;
    float media;
	
    printf("Digite o número de turmas: \n");
    scanf("%i", &qturma);
    fflush(stdin);

    // Inicialização
    for (int i = 1; i <= qturma; i++) {
        printf("Digite a quantidade de alunos da turma %i: ");
        scanf("%i", &qaluno);
	fflush(stdin);
	if(qaluno<=40){
	soma+=qaluno;
	}else{
		printf("Erro! Turma não pode ter mais de 40 alunos\n");
    }
	media=soma/q;

	printf("A Media é %.2f\n", media);

    return 0;
}


