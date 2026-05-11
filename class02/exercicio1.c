
#include <stdio.h>
#include <stdlib.h>

int main(void){
	// Variáveis
	//[tipo da variável] [nome da variável];
	char nome[50];
	char sexo;
	int idade;
	float altura;
	
	// Entrada
	printf("Digite seu nome: ");
	//scanf("%s",nome);
	//gets (nome);
	fgets (nome, 50, stdin);
	fflush(stdin);
	printf("Digite o sexo: ");
	scanf("%c",&sexo);
	fflush(stdin);
	printf("Digite a idade: ");
	scanf("%i",&idade);
	fflush(stdin);
	printf("Digite sua altura: ");
	scanf("%f",&altura);
	fflush(stdin);
	// scanf("[Dado formatado]",&[nome da variável]);
	
	// Saídas
	printf("Nome = %s\n",nome);
	printf("Idade = %i\n",idade);
	printf("Altura = %f\n",altura);
	printf("Sexo = %c\n",sexo);
	
	return 0;
}






