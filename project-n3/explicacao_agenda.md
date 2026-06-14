# Agenda de Contatos em C — Guia Didático

**Disciplina:** Fundamentos e Lógica de Programação  
**Trabalho:** N3 — Agenda de Contatos  
**Linguagem:** C ANSI

---

## 1. O que o programa faz

O programa é uma **agenda de contatos via console**. Ele permite:

- Incluir contatos (nome e telefone obrigatórios; e-mail opcional)
- Listar todos os contatos cadastrados
- Consultar contatos pelo nome
- Excluir um contato
- Salvar e carregar dados automaticamente em arquivo `.txt` *(bônus)*

---

## 2. Conceitos usados e onde aparecem

| Conceito | Onde no código |
|---|---|
| Variáveis | `total`, `opcao`, `indice`, `i`, `encontrou`… |
| Entrada e saída | `scanf()`, `fgets()`, `printf()`, `fprintf()` |
| Operadores aritméticos | `i < total - 1`, `total++`, `total--` |
| Estrutura condicional (`if/else`) | Verificar agenda cheia, confirmação de exclusão, campos vazios |
| Estrutura de seleção (`switch`) | Menu principal (`case 1` a `case 5`) |
| Estruturas de repetição | `do-while` no loop principal; `for` para percorrer os vetores |
| Vetores | `nomes[MAX][60]`, `telefones[MAX][20]`, `emails[MAX][60]` |
| Funções | `incluirContato()`, `listarContatos()`, `excluirContato()`… |
| Strings (vetores de char) | `busca[60]`, `fgets()`, `strcpy()`, `strcmp()`, `strlen()` |
| `string.h` *(bônus)* | `strcpy`, `strcmp`, `strlen`, `strcspn` |
| Arquivos *(bônus)* | `salvarArquivo()` e `carregarArquivo()` com `FILE *`, `fopen`, `fclose` |
| Melhorias visuais *(bônus)* | Cabeçalhos com `===` e separadores `---` em todas as telas |

---

## 3. Como o código foi construído — passo a passo

### Passo 1 — Definir os vetores globais

Ao invés de uma struct, usamos **três vetores separados** — um para cada campo do contato:

```c
#define MAX 100

char nomes[MAX][60];
char telefones[MAX][20];
char emails[MAX][60];
int total = 0;
```

**Como funciona o vetor bidimensional?**  
`nomes[MAX][60]` é um vetor de 100 posições, onde cada posição guarda uma string de até 60 caracteres.  
- `nomes[0]` → nome do primeiro contato  
- `nomes[1]` → nome do segundo contato  
- E assim por diante...

`total` controla quantos contatos existem. Funciona como um marcador da próxima posição vazia:
- Ao incluir: preenchemos `nomes[total]` e depois `total++`
- Ao excluir: movemos os elementos e depois `total--`

---

### Passo 2 — Montar o menu com `switch` dentro de `do-while`

```c
do {
    exibirMenu();
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: incluirContato();   break;
        case 2: listarContatos();   break;
        case 3: consultarContato(); break;
        case 4: excluirContato();   break;
        case 5: /* sair */          break;
    }
} while (opcao != 5);
```

**Por que `do-while` e não `while`?**  
O `do-while` executa o bloco **pelo menos uma vez** antes de checar a condição.  
Isso garante que o menu apareça na tela antes de qualquer verificação.

**Por que `scanf(" ")` antes do `fgets`?**  
O `scanf("%d", &opcao)` lê o número mas deixa o `\n` (Enter) no buffer.  
O `scanf(" ")` consome esse Enter para que o próximo `fgets` funcione corretamente.

---

### Passo 3 — Implementar `incluirContato()`

```c
void incluirContato() {
    if (total >= MAX) { /* agenda cheia */ return; }

    printf("Nome: ");
    scanf(" ");
    fgets(nomes[total], 60, stdin);
    nomes[total][strcspn(nomes[total], "\n")] = '\0';

    /* ... lê telefone e email da mesma forma ... */

    total++;
    salvarArquivo();
}
```

**Detalhe importante — remover o `\n` do `fgets`:**  
`fgets()` inclui o caractere de nova linha `\n` no fim da string.  
`strcspn(str, "\n")` retorna a posição do `\n` na string.  
Ao colocar `'\0'` nessa posição, "cortamos" o `\n` da string.

---

### Passo 4 — Excluir com deslocamento do vetor

Não existe "apagar uma posição" em um vetor C.  
A técnica correta é **mover todos os elementos seguintes uma posição para trás**:

```
Antes:  [Ana][Bruno][Carlos]   (excluindo Bruno, índice 1)
Passo:  [Ana][Carlos][Carlos]  (copia Carlos para posição 1)
Depois: [Ana][Carlos]          (total--)
```

```c
for (i = indice; i < total - 1; i++) {
    strcpy(nomes[i],     nomes[i + 1]);
    strcpy(telefones[i], telefones[i + 1]);
    strcpy(emails[i],    emails[i + 1]);
}
total--;
```

Usamos `strcpy` aqui pois strings em C não podem ser copiadas com `=` diretamente.

---

### Passo 5 — Salvar e carregar arquivo *(bônus)*

**Salvar** — chamado após incluir e excluir. Sobrescreve o arquivo com todos os contatos:

```c
void salvarArquivo() {
    FILE *arquivo;
    int i;

    arquivo = fopen("agenda.txt", "w"); /* "w" = escrita */
    if (arquivo == NULL) return;

    for (i = 0; i < total; i++) {
        fprintf(arquivo, "%s\n", nomes[i]);
        fprintf(arquivo, "%s\n", telefones[i]);
        fprintf(arquivo, "%s\n", emails[i]);
        fprintf(arquivo, "---\n"); /* separador */
    }

    fclose(arquivo); /* sempre fechar! */
}
```

**Carregar** — chamado no início do `main()`. Lê os dados salvos:

```c
void carregarArquivo() {
    FILE *arquivo;
    char linha[60];

    arquivo = fopen("agenda.txt", "r"); /* "r" = leitura */
    if (arquivo == NULL) return; /* arquivo não existe ainda, tudo bem */

    while (total < MAX) {
        if (fgets(linha, 60, arquivo) == NULL) break;
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(nomes[total], linha);

        /* ... lê telefone e email da mesma forma ... */

        fgets(linha, 60, arquivo); /* pula a linha "---" */
        total++;
    }

    fclose(arquivo);
}
```

O arquivo `agenda.txt` fica na mesma pasta do executável e tem este formato:

```
Ana Paula
(47) 99999-1111
ana@email.com
---
Bruno Silva
(47) 88888-2222

---
```

**O que saber explicar sobre arquivos na auditoria:**
- `fopen` abre o arquivo; `fclose` fecha — **sempre fechar**
- `"w"` sobrescreve tudo; `"r"` só lê
- `fprintf` é igual ao `printf` mas escreve no arquivo
- `fgets` retorna `NULL` quando chega no fim do arquivo — por isso usamos no `while`

---

## 4. Como compilar e executar

### No Windows (MinGW/GCC):

```cmd
gcc -Wall -Wextra -o agenda.exe agenda_bonus.c
agenda.exe
```

### No Code::Blocks:

1. Crie um novo projeto **Console Application → C**
2. Substitua o conteúdo do `main.c` pelo arquivo `agenda_bonus.c`
3. Clique em **Build and Run** (F9)

---

## 5. Estrutura das funções — resumo

| Função | O que faz |
|---|---|
| `main()` | Ponto de entrada; carrega arquivo; loop do menu |
| `exibirMenu()` | Imprime o menu visual no console |
| `incluirContato()` | Lê os dados e adiciona aos vetores |
| `listarContatos()` | Percorre e exibe todos os contatos |
| `consultarContato()` | Busca por nome exato e exibe resultados |
| `excluirContato()` | Busca, confirma e remove deslocando os vetores |
| `salvarArquivo()` | Grava todos os contatos em `agenda.txt` |
| `carregarArquivo()` | Lê `agenda.txt` ao iniciar o programa |
| `limparTela()` | Chama `cls` para limpar o console |
| `pausar()` | Espera o usuário pressionar Enter |

---

## 6. Pontuação esperada

### Base (7,0 pontos):

| Critério | Status |
|---|---|
| Compilando e executando | ✅ |
| Menu funcionando | ✅ |
| Inclusão de contatos | ✅ |
| Listagem | ✅ |
| Consulta pelo nome | ✅ |
| Exclusão | ✅ |

### Bônus implementados (até +3,0 pontos):

| Funcionalidade | Pontos | Status |
|---|---|---|
| Gravação e leitura em arquivo | até 2,0 | ✅ |
| Uso da biblioteca `string.h` | até 0,5 | ✅ |
| Melhorias visuais na interface | até 0,5 | ✅ |

---

## 7. O que estudar para a apresentação (auditoria)

O professor pode perguntar sobre qualquer parte do código. Estude especialmente:

- **O que é um vetor?** — Uma sequência de elementos do mesmo tipo, acessados por índice (`nomes[0]`, `nomes[1]`…)
- **O que é um vetor bidimensional?** — Um vetor onde cada posição guarda outro vetor; no caso, cada posição guarda uma string (`nomes[100][60]`)
- **Por que usar funções?** — Organização, cada função faz uma coisa só, facilita encontrar erros
- **Como funciona o `fgets` vs `scanf`?** — `scanf` para números; `fgets` para strings que podem ter espaço
- **Por que o `scanf(" ")` antes do `fgets`?** — Para consumir o Enter que sobrou do `scanf` anterior
- **Como funciona a exclusão no vetor?** — Não apagamos; deslocamos os elementos seguintes uma posição para trás
- **O que é `strcpy`?** — Copia uma string para outra (não podemos usar `=` com strings em C)
- **O que é `strcmp`?** — Compara duas strings; retorna 0 se forem iguais
- **O que é `FILE *`?** — Um tipo que representa um arquivo aberto no programa
- **Por que sempre fechar o arquivo com `fclose`?** — Para garantir que os dados foram gravados e liberar o arquivo para outros programas usarem

---

*Boa apresentação!*
