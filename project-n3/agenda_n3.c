/*
 * AGENDA DE CONTATOS
 * Trabalho Final N3 - Fundamentos de Programacao
 * Linguagem: C ANSI
 *
 * Bonus implementados:
 *  - Gravacao e leitura em arquivo (agenda.txt)
 *  - Uso da biblioteca string.h
 *  - Melhorias visuais na interface
 */

#include <stdio.h>
#include <string.h>   /* strcmp, strcpy, strlen, strcspn - bonus string.h */
#include <stdlib.h>

/* Limite maximo de contatos na agenda */
#define MAX 100

/* Nome do arquivo onde os contatos sao salvos */
#define ARQUIVO "agenda.txt"

/* Vetores que armazenam os dados de cada contato */
char nomes[MAX][60];
char telefones[MAX][20];
char emails[MAX][60];
int total = 0; /* quantos contatos estao cadastrados */

/* ----------------------------------------
 * FUNCAO: limparTela
 * Limpa o console
 * ---------------------------------------- */
void limparTela() {
    system("cls");
}

/* ----------------------------------------
 * FUNCAO: pausar
 * Espera o usuario pressionar Enter
 * ---------------------------------------- */
void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

/* ----------------------------------------
 * FUNCAO: salvarArquivo (bonus)
 *
 * Grava todos os contatos no arquivo "agenda.txt".
 * Sempre que incluimos ou excluimos um contato,
 * chamamos essa funcao para nao perder os dados.
 *
 * O arquivo fica assim:
 *   Ana Paula
 *   (47) 99999-1111
 *   ana@email.com
 *   ---
 *   Bruno Silva
 *   (47) 88888-2222
 *
 *   ---
 * ---------------------------------------- */
void salvarArquivo() {
    FILE *arquivo;
    int i;

    /* "w" = abre para escrita; cria o arquivo se nao existir */
    arquivo = fopen(ARQUIVO, "w");

    if (arquivo == NULL) {
        printf("AVISO: nao foi possivel salvar o arquivo.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        fprintf(arquivo, "%s\n", nomes[i]);
        fprintf(arquivo, "%s\n", telefones[i]);
        fprintf(arquivo, "%s\n", emails[i]);
        fprintf(arquivo, "---\n"); /* separador entre contatos */
    }

    fclose(arquivo); /* IMPORTANTE: sempre fechar o arquivo! */
}

/* ----------------------------------------
 * FUNCAO: carregarArquivo (bonus)
 *
 * Le o arquivo "agenda.txt" ao iniciar o programa.
 * Se o arquivo nao existir, comeca com agenda vazia.
 * ---------------------------------------- */
void carregarArquivo() {
    FILE *arquivo;
    char linha[60];

    /* "r" = abre para leitura */
    arquivo = fopen(ARQUIVO, "r");

    /* Se o arquivo nao existe, nao ha nada para carregar */
    if (arquivo == NULL)
        return;

    total = 0;

    /*
     * Le os dados na mesma ordem em que foram salvos:
     * nome, telefone, email, separador "---"
     * fgets retorna NULL quando chega no fim do arquivo
     */
    while (total < MAX) {
        if (fgets(linha, 60, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(nomes[total], linha);

        if (fgets(linha, 20, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(telefones[total], linha);

        if (fgets(linha, 60, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(emails[total], linha);

        fgets(linha, 60, arquivo); /* pula a linha "---" */

        total++;
    }

    fclose(arquivo);
}

/* ----------------------------------------
 * FUNCAO: exibirMenu
 * Mostra o menu principal na tela
 * ---------------------------------------- */
void exibirMenu() {
    limparTela();
    printf("=====================================\n");
    printf("         AGENDA DE CONTATOS          \n");
    printf("=====================================\n");
    printf(" Contatos cadastrados: %d\n", total);
    printf("-------------------------------------\n");
    printf(" 1 - Incluir contato\n");
    printf(" 2 - Listar contatos\n");
    printf(" 3 - Consultar contato pelo nome\n");
    printf(" 4 - Excluir contato\n");
    printf(" 5 - Sair\n");
    printf("=====================================\n");
    printf(" Opcao: ");
}

/* ----------------------------------------
 * FUNCAO: incluirContato
 * Cadastra um novo contato na agenda
 * ---------------------------------------- */
void incluirContato() {
    limparTela();
    printf("=====================================\n");
    printf("         INCLUIR CONTATO             \n");
    printf("=====================================\n\n");

    if (total >= MAX) {
        printf("Agenda cheia! Limite de %d contatos.\n", MAX);
        pausar();
        return;
    }

    printf("Nome: ");
    scanf(" ");
    fgets(nomes[total], 60, stdin);
    nomes[total][strcspn(nomes[total], "\n")] = '\0';

    if (strlen(nomes[total]) == 0) {
        printf("Nome nao pode ser vazio!\n");
        pausar();
        return;
    }

    printf("Telefone: ");
    fgets(telefones[total], 20, stdin);
    telefones[total][strcspn(telefones[total], "\n")] = '\0';

    if (strlen(telefones[total]) == 0) {
        printf("Telefone nao pode ser vazio!\n");
        pausar();
        return;
    }

    printf("E-mail (opcional, Enter para pular): ");
    fgets(emails[total], 60, stdin);
    emails[total][strcspn(emails[total], "\n")] = '\0';

    total++;

    salvarArquivo(); /* salva imediatamente apos incluir */

    printf("\n-------------------------------------\n");
    printf(" Contato incluido com sucesso!\n");
    printf("-------------------------------------\n");
    pausar();
}

/* ----------------------------------------
 * FUNCAO: listarContatos
 * Exibe todos os contatos cadastrados
 * ---------------------------------------- */
void listarContatos() {
    int i;
    limparTela();
    printf("=====================================\n");
    printf("         LISTA DE CONTATOS           \n");
    printf("=====================================\n\n");

    if (total == 0) {
        printf(" Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    for (i = 0; i < total; i++) {
        printf(" [%d] Nome:     %s\n", i + 1, nomes[i]);
        printf("     Telefone: %s\n", telefones[i]);
        if (strlen(emails[i]) > 0)
            printf("     E-mail:   %s\n", emails[i]);
        printf("-------------------------------------\n");
    }

    printf(" Total: %d contato(s)\n", total);
    pausar();
}

/* ----------------------------------------
 * FUNCAO: consultarContato
 * Busca um contato pelo nome
 * ---------------------------------------- */
void consultarContato() {
    char busca[60];
    int i;
    int encontrou = 0;

    limparTela();
    printf("=====================================\n");
    printf("         CONSULTAR CONTATO           \n");
    printf("=====================================\n\n");

    if (total == 0) {
        printf(" Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    printf("Digite o nome: ");
    scanf(" ");
    fgets(busca, 60, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    printf("\nResultados para \"%s\":\n", busca);
    printf("-------------------------------------\n");

    for (i = 0; i < total; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            printf(" [%d] Nome:     %s\n", i + 1, nomes[i]);
            printf("     Telefone: %s\n", telefones[i]);
            if (strlen(emails[i]) > 0)
                printf("     E-mail:   %s\n", emails[i]);
            printf("-------------------------------------\n");
            encontrou++;
        }
    }

    if (encontrou == 0)
        printf(" Nenhum contato encontrado.\n");
    else
        printf(" %d contato(s) encontrado(s).\n", encontrou);

    pausar();
}

/* ----------------------------------------
 * FUNCAO: excluirContato
 * Remove um contato da agenda
 * ---------------------------------------- */
void excluirContato() {
    char busca[60];
    char confirmacao;
    int i;
    int indice = -1;

    limparTela();
    printf("=====================================\n");
    printf("         EXCLUIR CONTATO             \n");
    printf("=====================================\n\n");

    if (total == 0) {
        printf(" Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    printf("Digite o nome do contato: ");
    scanf(" ");
    fgets(busca, 60, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (i = 0; i < total; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Contato nao encontrado.\n");
        pausar();
        return;
    }

    printf("\nContato encontrado:\n");
    printf("-------------------------------------\n");
    printf(" Nome:     %s\n", nomes[indice]);
    printf(" Telefone: %s\n", telefones[indice]);
    printf("-------------------------------------\n");
    printf("Confirma exclusao? (s/n): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 's' || confirmacao == 'S') {
        /*
         * Desloca todos os elementos seguintes uma posicao para tras,
         * sobrescrevendo o contato que queremos remover.
         */
        for (i = indice; i < total - 1; i++) {
            strcpy(nomes[i],     nomes[i + 1]);
            strcpy(telefones[i], telefones[i + 1]);
            strcpy(emails[i],    emails[i + 1]);
        }
        total--;
        salvarArquivo(); /* atualiza o arquivo apos excluir */
        printf("\n Contato excluido com sucesso!\n");
    } else {
        printf("\n Exclusao cancelada.\n");
    }

    pausar();
}

/* ----------------------------------------
 * FUNCAO PRINCIPAL
 * ---------------------------------------- */
int main() {
    int opcao;

    carregarArquivo(); /* carrega os contatos salvos ao iniciar */

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: incluirContato();   break;
            case 2: listarContatos();   break;
            case 3: consultarContato(); break;
            case 4: excluirContato();   break;
            case 5:
                limparTela();
                printf("Encerrando. Ate logo!\n\n");
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
                getchar();
        }

    } while (opcao != 5);

    return 0;
}
