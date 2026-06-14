/*
 * ============================================================
 *  AGENDA DE CONTATOS - Trabalho Final N3
 *  Disciplina: Fundamentos e Lógica de Programação
 *  Linguagem: C ANSI
 * ============================================================
 *
 * ESTRUTURA GERAL DO PROGRAMA:
 *  - Uma struct "Contato" guarda os dados de cada pessoa.
 *  - Um vetor (array) de structs armazena ate MAX_CONTATOS contatos.
 *  - Cada funcionalidade (incluir, listar, etc.) é uma função separada.
 *  - Os dados são salvos em arquivo .txt para persistirem entre execuções.
 */

/* ============================================================
 * INCLUDES - Bibliotecas que vamos usar
 * ============================================================ */
#include <stdio.h>    /* printf, scanf, fgets - entrada e saída */
#include <string.h>   /* strcpy, strcmp, strlen, strstr - manipulação de strings */
#include <stdlib.h>   /* system() - limpar a tela */
#include <ctype.h>    /* tolower() - converter letras para minúsculo */

/* ============================================================
 * CONSTANTES - Valores fixos que usaremos no programa
 * ============================================================ */
#define MAX_CONTATOS  100   /* Capacidade máxima da agenda */
#define TAM_NOME      60    /* Tamanho máximo do nome */
#define TAM_TELEFONE  20    /* Tamanho máximo do telefone */
#define TAM_EMAIL     60    /* Tamanho máximo do e-mail */
#define TAM_CIDADE    40    /* Tamanho máximo da cidade */
#define TAM_EMPRESA   60    /* Tamanho máximo da empresa */
#define ARQUIVO       "agenda.txt" /* Nome do arquivo de dados */

/* ============================================================
 * TYPEDEF STRUCT - Definição do tipo "Contato"
 *
 * Uma struct agrupa vários dados relacionados em um único "bloco".
 * O typedef cria um apelido, permitindo escrever "Contato" em vez
 * de "struct Contato" toda vez.
 * ============================================================ */
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
    char cidade[TAM_CIDADE];
    char empresa[TAM_EMPRESA];
} Contato;

/* ============================================================
 * VARIÁVEIS GLOBAIS
 *
 * O vetor 'agenda' armazena todos os contatos.
 * 'totalContatos' controla quantos estão cadastrados.
 * São globais para que todas as funções possam acessá-las.
 * ============================================================ */
Contato agenda[MAX_CONTATOS];
int totalContatos = 0;

/* ============================================================
 * PROTÓTIPOS DAS FUNÇÕES
 *
 * Declaramos as funções antes do main() para que o compilador
 * saiba que elas existem (mesmo estando definidas depois).
 * ============================================================ */
void limparTela(void);
void pausar(void);
void limparBuffer(void);
void exibirMenu(void);
void incluirContato(void);
void listarContatos(void);
void consultarContato(void);
void excluirContato(void);
void alterarContato(void);
void ordenarContatos(void);
void salvarArquivo(void);
void carregarArquivo(void);
void exibirContato(int indice);
int  buscarPorNome(const char *nome);

/* ============================================================
 * FUNÇÕES AUXILIARES
 * ============================================================ */

/* Limpa a tela do console (funciona em Windows e Linux) */
void limparTela(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* Pausa o programa esperando o usuário pressionar Enter */
void pausar(void) {
    printf("\n  Pressione Enter para continuar...");
    limparBuffer();
    getchar();
}

/*
 * limparBuffer: descarta caracteres que sobram no buffer de entrada.
 *
 * Problema comum: após ler um número com scanf(), o '\n' (Enter)
 * fica no buffer. Se não limparmos, o próximo fgets() vai ler
 * esse '\n' como se fosse uma linha vazia.
 */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ============================================================
 * EXIBIR MENU PRINCIPAL
 * ============================================================ */
void exibirMenu(void) {
    limparTela();
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║        AGENDA DE CONTATOS            ║\n");
    printf("  ╠══════════════════════════════════════╣\n");
    printf("  ║  Contatos cadastrados: %-3d           ║\n", totalContatos);
    printf("  ╠══════════════════════════════════════╣\n");
    printf("  ║  1 - Incluir contato                 ║\n");
    printf("  ║  2 - Listar contatos                 ║\n");
    printf("  ║  3 - Consultar contato pelo nome     ║\n");
    printf("  ║  4 - Excluir contato                 ║\n");
    printf("  ║  5 - Alterar contato                 ║\n");
    printf("  ║  6 - Ordenar contatos (A-Z)          ║\n");
    printf("  ║  0 - Sair                            ║\n");
    printf("  ╚══════════════════════════════════════╝\n");
    printf("  Opcao: ");
}

/* ============================================================
 * EXIBIR UM CONTATO FORMATADO
 *
 * Recebe o índice do contato no vetor e exibe seus dados.
 * Separar em função evita repetir o mesmo código em vários lugares.
 * ============================================================ */
void exibirContato(int i) {
    printf("  ┌─────────────────────────────────────┐\n");
    printf("  │ #%-3d  %-30s  │\n", i + 1, agenda[i].nome);
    printf("  ├─────────────────────────────────────┤\n");
    printf("  │ Telefone: %-27s│\n", agenda[i].telefone);

    /* Só exibe os campos opcionais se não estiverem vazios */
    if (strlen(agenda[i].email) > 0)
        printf("  │ E-mail:   %-27s│\n", agenda[i].email);
    if (strlen(agenda[i].cidade) > 0)
        printf("  │ Cidade:   %-27s│\n", agenda[i].cidade);
    if (strlen(agenda[i].empresa) > 0)
        printf("  │ Empresa:  %-27s│\n", agenda[i].empresa);

    printf("  └─────────────────────────────────────┘\n");
}

/* ============================================================
 * BUSCAR CONTATO POR NOME (pesquisa parcial)
 *
 * Recebe uma string de busca e retorna o índice do primeiro
 * contato cujo nome a contenha (busca parcial, sem diferenciar
 * maiúsculas/minúsculas).
 *
 * Retorna -1 se não encontrar nenhum.
 *
 * COMO FUNCIONA A BUSCA PARCIAL:
 *  1. Converte a busca e o nome do contato para minúsculas.
 *  2. Usa strstr() para verificar se a busca está contida no nome.
 * ============================================================ */
int buscarPorNome(const char *busca) {
    char buscaMin[TAM_NOME];   /* busca em minúsculas */
    char nomeMin[TAM_NOME];    /* nome do contato em minúsculas */
    int i, j;

    /* Copia a busca convertendo cada letra para minúscula */
    for (i = 0; busca[i] != '\0' && i < TAM_NOME - 1; i++)
        buscaMin[i] = (char)tolower((unsigned char)busca[i]);
    buscaMin[i] = '\0'; /* Termina a string com '\0' */

    /* Percorre todos os contatos cadastrados */
    for (i = 0; i < totalContatos; i++) {
        /* Converte o nome do contato para minúscula */
        for (j = 0; agenda[i].nome[j] != '\0' && j < TAM_NOME - 1; j++)
            nomeMin[j] = (char)tolower((unsigned char)agenda[i].nome[j]);
        nomeMin[j] = '\0';

        /* strstr retorna não-nulo se encontrar a substring */
        if (strstr(nomeMin, buscaMin) != NULL)
            return i; /* Encontrou: retorna o índice */
    }
    return -1; /* Não encontrou */
}

/* ============================================================
 * INCLUIR CONTATO
 * ============================================================ */
void incluirContato(void) {
    limparTela();
    printf("  === INCLUIR CONTATO ===\n\n");

    /* Verifica se ainda há espaço no vetor */
    if (totalContatos >= MAX_CONTATOS) {
        printf("  Agenda cheia! Limite de %d contatos atingido.\n", MAX_CONTATOS);
        pausar();
        return; /* Sai da função sem fazer nada */
    }

    /* Lê o nome (campo obrigatório) */
    printf("  Nome: ");
    fgets(agenda[totalContatos].nome, TAM_NOME, stdin);
    /* fgets inclui o '\n' na string; removemos aqui */
    agenda[totalContatos].nome[strcspn(agenda[totalContatos].nome, "\n")] = '\0';

    /* Verifica se o nome não ficou vazio */
    if (strlen(agenda[totalContatos].nome) == 0) {
        printf("  Nome nao pode ser vazio!\n");
        pausar();
        return;
    }

    /* Lê o telefone (campo obrigatório) */
    printf("  Telefone: ");
    fgets(agenda[totalContatos].telefone, TAM_TELEFONE, stdin);
    agenda[totalContatos].telefone[strcspn(agenda[totalContatos].telefone, "\n")] = '\0';

    if (strlen(agenda[totalContatos].telefone) == 0) {
        printf("  Telefone nao pode ser vazio!\n");
        pausar();
        return;
    }

    /* Campos opcionais - podem ficar em branco */
    printf("  E-mail (opcional, Enter para pular): ");
    fgets(agenda[totalContatos].email, TAM_EMAIL, stdin);
    agenda[totalContatos].email[strcspn(agenda[totalContatos].email, "\n")] = '\0';

    printf("  Cidade (opcional, Enter para pular): ");
    fgets(agenda[totalContatos].cidade, TAM_CIDADE, stdin);
    agenda[totalContatos].cidade[strcspn(agenda[totalContatos].cidade, "\n")] = '\0';

    printf("  Empresa (opcional, Enter para pular): ");
    fgets(agenda[totalContatos].empresa, TAM_EMPRESA, stdin);
    agenda[totalContatos].empresa[strcspn(agenda[totalContatos].empresa, "\n")] = '\0';

    /*
     * Só incrementamos totalContatos DEPOIS de preencher todos os campos.
     * Assim, se algo der errado antes, o contato "meio preenchido"
     * não é considerado válido.
     */
    totalContatos++;

    salvarArquivo(); /* Salva imediatamente após incluir */
    printf("\n  Contato incluido com sucesso!\n");
    pausar();
}

/* ============================================================
 * LISTAR CONTATOS
 * ============================================================ */
void listarContatos(void) {
    int i;
    limparTela();
    printf("  === LISTA DE CONTATOS ===\n\n");

    /* Verifica se há algum contato antes de tentar listar */
    if (totalContatos == 0) {
        printf("  Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    /* Estrutura de repetição: percorre todos os contatos */
    for (i = 0; i < totalContatos; i++) {
        exibirContato(i);
        printf("\n");
    }

    printf("  Total: %d contato(s)\n", totalContatos);
    pausar();
}

/* ============================================================
 * CONSULTAR CONTATO PELO NOME
 * ============================================================ */
void consultarContato(void) {
    char busca[TAM_NOME];
    int encontrou = 0; /* Contador de resultados */
    int i;
    char nomeMin[TAM_NOME];
    char buscaMin[TAM_NOME];
    int j;

    limparTela();
    printf("  === CONSULTAR CONTATO ===\n\n");

    if (totalContatos == 0) {
        printf("  Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    printf("  Digite o nome (ou parte do nome): ");
    fgets(busca, TAM_NOME, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    if (strlen(busca) == 0) {
        printf("  Busca vazia!\n");
        pausar();
        return;
    }

    printf("\n  Resultados para \"%s\":\n\n", busca);

    /*
     * Busca parcial: em vez de usar a função buscarPorNome()
     * que retorna apenas o PRIMEIRO resultado, aqui percorremos
     * TODOS os contatos para exibir todos que correspondam à busca.
     */

    /* Converte a busca para minúsculas */
    for (i = 0; busca[i] != '\0' && i < TAM_NOME - 1; i++)
        buscaMin[i] = (char)tolower((unsigned char)busca[i]);
    buscaMin[i] = '\0';

    for (i = 0; i < totalContatos; i++) {
        /* Converte o nome do contato para minúsculas */
        for (j = 0; agenda[i].nome[j] != '\0' && j < TAM_NOME - 1; j++)
            nomeMin[j] = (char)tolower((unsigned char)agenda[i].nome[j]);
        nomeMin[j] = '\0';

        /* Se a busca estiver contida no nome, exibe o contato */
        if (strstr(nomeMin, buscaMin) != NULL) {
            exibirContato(i);
            printf("\n");
            encontrou++;
        }
    }

    if (encontrou == 0)
        printf("  Nenhum contato encontrado.\n");
    else
        printf("  %d contato(s) encontrado(s).\n", encontrou);

    pausar();
}

/* ============================================================
 * EXCLUIR CONTATO
 * ============================================================ */
void excluirContato(void) {
    char busca[TAM_NOME];
    char confirmacao;
    int indice;
    int i;

    limparTela();
    printf("  === EXCLUIR CONTATO ===\n\n");

    if (totalContatos == 0) {
        printf("  Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    printf("  Digite o nome do contato a excluir: ");
    fgets(busca, TAM_NOME, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    /* Reutilizamos a função de busca */
    indice = buscarPorNome(busca);

    if (indice == -1) {
        printf("\n  Contato nao encontrado.\n");
        pausar();
        return;
    }

    /* Exibe o contato antes de confirmar a exclusão */
    printf("\n  Contato encontrado:\n\n");
    exibirContato(indice);

    printf("\n  Confirma exclusao? (s/n): ");
    scanf(" %c", &confirmacao); /* O espaço antes de %c pula espaços/Enter */
    limparBuffer();

    /* Estrutura condicional: verifica se o usuário confirmou */
    if (confirmacao == 's' || confirmacao == 'S') {
        /*
         * TÉCNICA DE EXCLUSÃO EM VETOR:
         * Não podemos "apagar" uma posição no meio do vetor.
         * A solução é mover todos os elementos seguintes uma
         * posição para trás, sobrescrevendo o elemento removido.
         *
         * Antes: [A][B][C][D][E]  (excluindo C, índice 2)
         * Passo 1: [A][B][D][D][E]  (copiamos D para posição 2)
         * Passo 2: [A][B][D][E][E]  (copiamos E para posição 3)
         * Depois:  [A][B][D][E][_]  (decrementamos totalContatos)
         */
        for (i = indice; i < totalContatos - 1; i++)
            agenda[i] = agenda[i + 1]; /* Copia a struct inteira */

        totalContatos--; /* Reduz o contador */
        salvarArquivo();
        printf("\n  Contato excluido com sucesso!\n");
    } else {
        printf("\n  Exclusao cancelada.\n");
    }

    pausar();
}

/* ============================================================
 * ALTERAR CONTATO (funcionalidade bônus)
 * ============================================================ */
void alterarContato(void) {
    char busca[TAM_NOME];
    char temp[TAM_NOME];
    int indice;

    limparTela();
    printf("  === ALTERAR CONTATO ===\n\n");

    if (totalContatos == 0) {
        printf("  Nenhum contato cadastrado.\n");
        pausar();
        return;
    }

    printf("  Digite o nome do contato a alterar: ");
    fgets(busca, TAM_NOME, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    indice = buscarPorNome(busca);

    if (indice == -1) {
        printf("\n  Contato nao encontrado.\n");
        pausar();
        return;
    }

    printf("\n  Contato encontrado:\n\n");
    exibirContato(indice);

    printf("\n  Preencha os novos dados (Enter para manter o atual):\n\n");

    /*
     * Para cada campo, mostramos o valor atual entre colchetes.
     * Se o usuário pressionar Enter sem digitar nada,
     * mantemos o valor original.
     */
    printf("  Nome [%s]: ", agenda[indice].nome);
    fgets(temp, TAM_NOME, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0)
        strcpy(agenda[indice].nome, temp);

    printf("  Telefone [%s]: ", agenda[indice].telefone);
    fgets(temp, TAM_TELEFONE, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0)
        strcpy(agenda[indice].telefone, temp);

    printf("  E-mail [%s]: ", agenda[indice].email);
    fgets(temp, TAM_EMAIL, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0)
        strcpy(agenda[indice].email, temp);

    printf("  Cidade [%s]: ", agenda[indice].cidade);
    fgets(temp, TAM_CIDADE, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0)
        strcpy(agenda[indice].cidade, temp);

    printf("  Empresa [%s]: ", agenda[indice].empresa);
    fgets(temp, TAM_EMPRESA, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0)
        strcpy(agenda[indice].empresa, temp);

    salvarArquivo();
    printf("\n  Contato alterado com sucesso!\n");
    pausar();
}

/* ============================================================
 * ORDENAR CONTATOS - Algoritmo Bubble Sort (bônus)
 *
 * Bubble Sort ("ordenação por bolha") funciona assim:
 * - Percorre o vetor comparando pares de elementos adjacentes.
 * - Se estiverem fora de ordem, troca-os de lugar.
 * - Repete até nenhuma troca ser necessária.
 *
 * É um dos algoritmos mais simples de entender, ideal para
 * aprender o conceito de ordenação.
 * ============================================================ */
void ordenarContatos(void) {
    int i, j;
    Contato temp;      /* Variável auxiliar para a troca */
    int trocou;

    if (totalContatos <= 1) {
        printf("\n  Nenhuma ordenacao necessaria.\n");
        pausar();
        return;
    }

    /* Passagens pelo vetor (no máximo totalContatos - 1) */
    for (i = 0; i < totalContatos - 1; i++) {
        trocou = 0;

        /* Compara pares adjacentes */
        for (j = 0; j < totalContatos - 1 - i; j++) {
            /*
             * strcmp compara strings lexicograficamente (como dicionário).
             * Retorna > 0 se a primeira string vem depois da segunda.
             */
            if (strcmp(agenda[j].nome, agenda[j + 1].nome) > 0) {
                /* Troca os dois contatos de lugar */
                temp        = agenda[j];
                agenda[j]   = agenda[j + 1];
                agenda[j + 1] = temp;
                trocou = 1;
            }
        }

        /* Se não houve nenhuma troca, o vetor já está ordenado */
        if (!trocou)
            break;
    }

    salvarArquivo();
    printf("\n  Contatos ordenados alfabeticamente!\n");
    pausar();
}

/* ============================================================
 * SALVAR EM ARQUIVO (bônus)
 *
 * Grava todos os contatos no arquivo texto "agenda.txt".
 * Usamos um separador "---" entre contatos para facilitar a leitura.
 * ============================================================ */
void salvarArquivo(void) {
    FILE *arquivo;
    int i;

    /* Abre o arquivo para escrita ("w" = write, cria ou sobrescreve) */
    arquivo = fopen(ARQUIVO, "w");
    if (arquivo == NULL) {
        printf("  AVISO: Nao foi possivel salvar o arquivo.\n");
        return;
    }

    /* Escreve cada contato no arquivo */
    for (i = 0; i < totalContatos; i++) {
        fprintf(arquivo, "%s\n", agenda[i].nome);
        fprintf(arquivo, "%s\n", agenda[i].telefone);
        fprintf(arquivo, "%s\n", agenda[i].email);
        fprintf(arquivo, "%s\n", agenda[i].cidade);
        fprintf(arquivo, "%s\n", agenda[i].empresa);
        fprintf(arquivo, "---\n"); /* Separador entre contatos */
    }

    fclose(arquivo); /* Sempre fechar o arquivo após usar! */
}

/* ============================================================
 * CARREGAR DO ARQUIVO (bônus)
 *
 * Lê os contatos do arquivo "agenda.txt" ao iniciar o programa.
 * Se o arquivo não existir, começa com a agenda vazia.
 * ============================================================ */
void carregarArquivo(void) {
    FILE *arquivo;
    char linha[100];

    /* Abre o arquivo para leitura ("r" = read) */
    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL)
        return; /* Arquivo não existe ainda - começa vazio, tudo bem */

    totalContatos = 0;

    /*
     * Lê 5 linhas de dados + 1 linha separador ("---") por contato.
     * A função fgets retorna NULL quando chega ao fim do arquivo.
     */
    while (totalContatos < MAX_CONTATOS) {
        /* Lê cada campo; se não conseguir, saiu do arquivo */
        if (fgets(linha, TAM_NOME, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(agenda[totalContatos].nome, linha);

        if (fgets(linha, TAM_TELEFONE, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(agenda[totalContatos].telefone, linha);

        if (fgets(linha, TAM_EMAIL, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(agenda[totalContatos].email, linha);

        if (fgets(linha, TAM_CIDADE, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(agenda[totalContatos].cidade, linha);

        if (fgets(linha, TAM_EMPRESA, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(agenda[totalContatos].empresa, linha);

        fgets(linha, sizeof(linha), arquivo); /* Pula a linha "---" */

        totalContatos++;
    }

    fclose(arquivo);
}

/* ============================================================
 * FUNÇÃO PRINCIPAL - main()
 *
 * O programa começa aqui.
 * ============================================================ */
int main(void) {
    int opcao; /* Armazena a opção escolhida pelo usuário */

    carregarArquivo(); /* Carrega dados salvos (se existirem) */

    /*
     * LOOP PRINCIPAL DO PROGRAMA:
     * O do-while executa o bloco pelo menos uma vez e repete
     * enquanto a condição for verdadeira (opcao != 0).
     */
    do {
        exibirMenu();
        scanf("%d", &opcao); /* Lê a opção do menu */
        limparBuffer();      /* Limpa o Enter que ficou no buffer */

        /*
         * SWITCH-CASE: direciona para a função correta
         * conforme a opção escolhida.
         */
        switch (opcao) {
            case 1: incluirContato();   break;
            case 2: listarContatos();   break;
            case 3: consultarContato(); break;
            case 4: excluirContato();   break;
            case 5: alterarContato();   break;
            case 6: ordenarContatos();  break;
            case 0:
                limparTela();
                printf("  Encerrando o programa. Ate logo!\n\n");
                break;
            default:
                printf("  Opcao invalida! Tente novamente.\n");
                pausar();
        }

    } while (opcao != 0); /* Repete até o usuário escolher sair */

    return 0; /* Retorna 0 indicando que o programa terminou sem erros */
}
