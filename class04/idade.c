/* Faça um programa que leia a idade de quatro alunos, calcule a média das idades e apresente a mensagem correspondente: 


"Turma Jovem", se a média for inferior a 25 anos; 

"Turma Adulta", se a média estiver entre 25 e 40 anos; 

"Turma Idosa", se a média for superior a 40 anos. */ 

#include <stdio.h>
#include <stdlib.h>

int main(void){
	// quais são as variáveis?
	int aluno1, aluno2, aluno3, aluno4;
	float media;
	
	// quais são as entradas de dados?
	printf("Digite a idade do primeiro aluno: \n");
	scanf("%i",&aluno1);
	fflush(stdin);
	
	printf("Digite a idade do segundo aluno: \n");
	scanf("%i",&aluno2);
	fflush(stdin);

	printf("Digite a idade do terceiro aluno: \n");
	scanf("%i",&aluno3);
	fflush(stdin);

	printf("Digite a idade do quarto aluno: \n");
	scanf("%i",&aluno4);
	fflush(stdin);

	// qual é o processamento dos dados e saída dos dados?
	
	media=((aluno1 + aluno2 + aluno3 + aluno4)/4);

	if(media <= 25){
		printf("Media = %.2f = Turma Jovem\n", media);
	}else if(media > 41 ){
		printf("Media = %.2f = Turma Idosa\n", media);
	}else if(media < 40){
		printf("Media = %.2f = Turma Adulta\n", media);
	}
		
	
return 0;
}
