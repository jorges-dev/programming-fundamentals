# Agenda de Contatos em C — Guia Didático

**Disciplina:** Fundamentos e Lógica de Programação  
**Trabalho:** N3 — Agenda de Contatos  
**Linguagem:** C ANSI

---

## 1. O que o programa faz

O programa é uma **agenda de contatos via console**. Ele permite:

- Incluir contatos (nome e telefone obrigatórios; e-mail, cidade e empresa opcionais)
- Listar todos os contatos cadastrados
- Consultar contatos pelo nome (com busca parcial — não precisa digitar o nome completo)
- Excluir um contato
- Alterar um contato já cadastrado *(bônus)*
- Ordenar alfabeticamente *(bônus)*
- Salvar e carregar dados em arquivo `.txt` *(bônus)*

---

## 2. Conceitos usados e onde aparecem

| Conceito | Onde no código |
|---|---|
| Variáveis | `totalContatos`, `opcao`, `indice`, `i`, `j`… |
| Entrada e saída | `scanf()`, `fgets()`, `printf()`, `fprintf()` |
| Operadores aritméticos | `i < totalContatos - 1`, `totalContatos++`, `totalContatos--` |
| Estrutura condicional (`if/else`) | Verificar agenda cheia, confirmação de exclusão, campos vazios |
| Estrutura de seleção (`switch`) | Menu principal (`case 1` a `case 6`) |
| Estruturas de repetição | `do-while` no loop principal; `for` para percorrer o vetor |
| Vetores | `Contato agenda[MAX_CONTATOS]` — vetor de structs |
| Funções | `incluirContato()`, `listarContatos()`, `excluirContato()`… |
| Strings (vetores de char) | `nome[60]`, `telefone[20]`, `fgets()`, `strcpy()`, `strcmp()` |
| `typedef struct` *(bônus)* | `typedef struct { ... } Contato;` |
| `string.h` *(bônus)* | `strcpy`, `strcmp`, `strlen`, `strstr`, `strcspn` |
| Arquivos *(bônus)* | `salvarArquivo()` e `carregarArquivo()` com `FILE *`, `fopen`, `fclose` |
| Ordenação Bubble Sort *(bônus)* | `ordenarContatos()` |

---

## 3. Como o código foi construído — passo a passo

### Passo 1 — Definir os dados com `typedef struct`

Antes de escrever qualquer função, definimos **qual informação cada contato vai guardar**:

```c
typedef struct {
    char nome[60];
    char telefone[20];
    char email[60];
    char cidade[40];
    char empresa[60];
} Contato;
```

**Por que `struct`?**  
Sem struct, precisaríamos de um vetor separado para cada campo:
`char nomes[100][60]`, `char telefones[100][20]`…  
Com struct, agrupamos tudo em um único tipo: `Contato agenda[100]`.

**Por que `typedef`?**  
Permite escrever `Contato` em vez de `struct Contato` em todo o código.

---

### Passo 2 — Criar o vetor global e o contador

```c
Contato agenda[MAX_CONTATOS];  /* vetor de 100 contatos */
int totalContatos = 0;         /* quantos estão cadastrados */
```

O vetor é **global** para que todas as funções consigam acessá-lo sem precisar passá-lo como parâmetro.  
`totalContatos` funciona como um "ponteiro para a próxima posição vazia":  
- Ao incluir: preenchemos `agenda[totalContatos]` e depois `totalContatos++`  
- Ao excluir: movemos os elementos e depois `totalContatos--`

---

### Passo 3 — Montar o menu com `switch` dentro de `do-while`

```c
do {
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();

    switch (opcao) {
        case 1: incluirContato();   break;
        case 2: listarContatos();   break;
        /* ... */
        case 0: /* sair */ break;
    }
} while (opcao != 0);
```

**Por que `do-while` e não `while`?**  
O `do-while` executa o bloco **pelo menos uma vez** antes de checar a condição.  
Isso garante que o menu apareça na tela antes de qualquer verificação.

**Por que `limparBuffer()` após `scanf`?**  
O `scanf("%d", &opcao)` lê o número mas deixa o `\n` (Enter) no buffer.  
Se não limparmos, o próximo `fgets()` vai "engolir" esse Enter e parecer que o usuário não digitou nada.

---

### Passo 4 — Implementar `incluirContato()`

```c
void incluirContato(void) {
    if (totalContatos >= MAX_CONTATOS) { /* agenda cheia */ return; }

    fgets(agenda[totalContatos].nome, TAM_NOME, stdin);
    agenda[totalContatos].nome[strcspn(agenda[totalContatos].nome, "\n")] = '\0';

    /* ... lê os outros campos ... */

    totalContatos++;
    salvarArquivo();
}
```

**Detalhe importante — remover o `\n` do `fgets`:**  
`fgets()` inclui o caractere de nova linha `\n` no fim da string.  
`strcspn(str, "\n")` retorna a posição do `\n` na string.  
Ao colocar `'\0'` nessa posição, "cortamos" o `\n` da string.

---

### Passo 5 — Excluir com deslocamento do vetor

Não existe "apagar uma posição" em um vetor C.  
A técnica correta é **mover todos os elementos seguintes uma posição para trás**:

```
Antes:  [Ana][Bruno][Carlos][Diana]   (excluindo Bruno, índice 1)
Passo:  [Ana][Carlos][Carlos][Diana]  (copia Carlos para posição 1)
Passo:  [Ana][Carlos][Diana][Diana]   (copia Diana para posição 2)
Depois: [Ana][Carlos][Diana]          (totalContatos--)
```

```c
for (i = indice; i < totalContatos - 1; i++)
    agenda[i] = agenda[i + 1];
totalContatos--;
```

---

### Passo 6 — Busca parcial sem diferenciar maiúsculas

Para permitir digitar "ana" e encontrar "Ana Paula":

1. Convertemos a busca e o nome para minúsculas com `tolower()`
2. Usamos `strstr()` para verificar se a busca está **contida** no nome

```c
/* strstr(haystack, needle) retorna ponteiro se needle está em haystack */
if (strstr(nomeMin, buscaMin) != NULL) {
    /* encontrou */
}
```

---

### Passo 7 — Ordenar com Bubble Sort

O Bubble Sort compara pares adjacentes e troca os que estão fora de ordem, repetindo até o vetor estar ordenado:

```
Vetor:    [Carlos][Ana][Diana][Bruno]
Passagem 1: Carlos > Ana → troca → [Ana][Carlos][Diana][Bruno]
            Carlos < Diana → não troca
            Diana > Bruno → troca → [Ana][Carlos][Bruno][Diana]
Passagem 2: Carlos > Bruno → troca → [Ana][Bruno][Carlos][Diana]
Resultado: [Ana][Bruno][Carlos][Diana] ✓
```

```c
for (i = 0; i < totalContatos - 1; i++) {
    for (j = 0; j < totalContatos - 1 - i; j++) {
        if (strcmp(agenda[j].nome, agenda[j+1].nome) > 0) {
            temp = agenda[j];
            agenda[j] = agenda[j+1];
            agenda[j+1] = temp;
        }
    }
}
```

---

### Passo 8 — Salvar e carregar arquivo

**Salvar** — sobrescreve o arquivo com todos os contatos:

```c
FILE *arquivo = fopen("agenda.txt", "w");
for (i = 0; i < totalContatos; i++) {
    fprintf(arquivo, "%s\n", agenda[i].nome);
    fprintf(arquivo, "%s\n", agenda[i].telefone);
    /* ... outros campos ... */
    fprintf(arquivo, "---\n");  /* separador */
}
fclose(arquivo);
```

**Carregar** — lê o arquivo ao iniciar o programa:

```c
FILE *arquivo = fopen("agenda.txt", "r");
if (arquivo == NULL) return;  /* arquivo não existe ainda */

while (fgets(linha, ..., arquivo) != NULL) {
    /* lê os campos na mesma ordem que foram salvos */
    totalContatos++;
}
fclose(arquivo);
```

O arquivo `agenda.txt` fica na mesma pasta do executável e tem este formato:

```
Ana Paula
(47) 99999-1111
ana@email.com
Joinville
EMBRACO
---
Bruno Silva
(47) 88888-2222


Tech Corp
---
```

---

## 4. Como compilar e executar

### No Linux / macOS (terminal):

```bash
# Compilar (com flags que mostram todos os avisos):
gcc -ansi -Wall -Wextra -o agenda agenda_contatos.c

# Executar:
./agenda
```

### No Windows (prompt de comando com MinGW/GCC instalado):

```cmd
gcc -ansi -Wall -Wextra -o agenda.exe agenda_contatos.c
agenda.exe
```

### No Code::Blocks:

1. Crie um novo projeto **Console Application → C**
2. Substitua o conteúdo do `main.c` pelo arquivo `agenda_contatos.c`
3. Clique em **Build and Run** (F9)

---

## 5. Estrutura das funções — resumo

| Função | O que faz |
|---|---|
| `main()` | Ponto de entrada; carrega arquivo; loop do menu |
| `exibirMenu()` | Imprime o menu visual no console |
| `incluirContato()` | Lê os dados e adiciona ao vetor |
| `listarContatos()` | Percorre e exibe todos os contatos |
| `consultarContato()` | Busca parcial por nome e exibe resultados |
| `excluirContato()` | Busca, confirma e remove deslocando o vetor |
| `alterarContato()` | Busca e atualiza campos mantendo os que ficaram em branco |
| `ordenarContatos()` | Bubble Sort alfabético |
| `salvarArquivo()` | Grava todos os contatos em `agenda.txt` |
| `carregarArquivo()` | Lê `agenda.txt` ao iniciar |
| `exibirContato(i)` | Exibe os dados formatados de um contato específico |
| `buscarPorNome(s)` | Retorna o índice do primeiro contato que contém a string `s` |
| `limparTela()` | Chama `cls` ou `clear` conforme o sistema |
| `pausar()` | Espera o usuário pressionar Enter |
| `limparBuffer()` | Descarta o `\n` que fica no buffer após `scanf` |

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

| Funcionalidade | Status |
|---|---|
| Gravação e leitura em arquivo | ✅ |
| `typedef struct` | ✅ |
| `string.h` | ✅ |
| Alteração de contatos | ✅ |
| Pesquisa parcial pelo nome | ✅ |
| Ordenação alfabética | ✅ |
| Melhorias visuais (bordas no menu) | ✅ |

---

## 7. O que estudar para a apresentação (auditoria)

O professor pode perguntar sobre qualquer parte do código. Estude especialmente:

- **O que é um vetor?** — Uma sequência de elementos do mesmo tipo, acessados por índice (`agenda[0]`, `agenda[1]`…)
- **O que é uma struct?** — Um agrupamento de variáveis de tipos diferentes sob um mesmo nome
- **Por que usar funções?** — Organização, reuso de código, facilita a leitura e manutenção
- **Como funciona o `fgets` vs `scanf`?** — `scanf` para números; `fgets` para strings com espaço
- **Por que limpar o buffer?** — Para não "sujar" a próxima leitura de entrada
- **Como funciona a exclusão no vetor?** — Deslocamento dos elementos seguintes
- **O que é o `strstr`?** — Função de `string.h` que verifica se uma string está contida em outra
- **O que significa `-ansi -Wall -Wextra` no gcc?** — Compilar com padrão C89/C90 e mostrar todos os avisos

---

*Boa apresentação!*
