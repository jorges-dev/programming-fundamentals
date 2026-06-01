#include <stdio.h>
#include <stdlib.h>

// prototipo das funções
void limpa(void);		// sem saída / sem entrada
int soma(int a, int b);	// com entrada / com saída
int leia(void);			// com saída / sem entrada
void escreva(int a);	// sem saída / com entrada

int main(void){
	limpa();
	escreva(soma(leia(),leia()));
	
	return 0;
}

// função limpa
void limpa(void){
	system("cls");
}

// função soma
int soma(int a, int b){
	int r;
	r=a+b;
	return r;
}

// função leia
int leia(void){
	int a;
	printf("Digite um numero:");
	scanf("%i",&a);
	return a;
}

// função escreva
void escreva(int a){
	printf("A soma e %i\n",a);
}