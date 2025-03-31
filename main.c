// Trabalho – Tabela Hash – Motor de Busca
// Alunos: ARTHUR CARDOSO MARQUES e MATHEUS SILVA PAINS

/*

Objetivo: Criar um motor de busca de documentos por palavras-chave ordenados por relevância, tais como os disponibilizados em sites de busca, como Google e Bing

*/

/*

 Fluxo:

 1. Programa constrói o índice invertido (usando a tabela hash) sobre os arquivos de texto existentes dentro do diretório onde estão armazenados os arquivos disponibilizados nesse trabalho.

 2. Programa disponibiliza um menu para que o usuário escolha o tipo de busca que deseja fazer:

    a) trazer registros com ocorrência de TODOS os termos de busca (palavras chave) - AND Search
    b) trazer registros com ocorrência de PELO MENOS UM dos termos de busca (palavras chave) - OR Search

 3. Usuário escolhe o tipo de busca e informa os termos de busca (palavras chave) separados por espaço (tal como em sites de busca como Google e Yahoo).

4. Programa efetua a busca conforme solicitação do usuário (ignorando os termos de busca que forem menores que K) e apresenta os nomes dos documentos (arquivos) encontrados na busca, ordenados pela relevância, do mais relevante ao menos relevante, um em cada linha.

 5. Programa volta ao passo 2, possibilitando que o usuário faça uma nova busca (não limpar a busca anterior até que o usuário faça uma nova).

*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. DEFINIÇÕES ------------------------------------------------------

#define K 3 // O valor será definido para maior ou igual a 3 para que palavras como 'mae' e 'pai' sejam consideradas na indexação

// 2. STRUCTS do motor de busca ------------------------------------------------------ 

// 2.1. struct que irá contar quantas vezes uma palavra aparece em cada arquivo texto

typedef struct {
    char *nome_arquivo; // itera nos arquivos texto
    int palavra_contagem; // será usada para o calculo de relevancia e receberá f_ij ("Número de ocorrência do termo t_j no arquivo i")
} PalavraContagem;

// 2.2. struct que será reponsável pela entradas na tabela hash (palavra_busca) e irá armazenar o endereço para a struct 'PalavraContagem'

typedef struct {
    char *palavra_busca; // será responsável por armazenar a palavra chave para busca
    int palavra_na_tabela; // será responsável por associar o número de vezes em que a palavra aparece em cada arquivo texto
    PalavraContagem *contagens; // irá servir como endereçamento para a struct 'PalavraContagem' que irá contar quantas vezes a palavra aparece em cada arquivo texto
    int status; // -1 irá indicar que está vazio, mas foi usado; 0 irá indicar que está vazio e não foi usado; 1 irá indicar que está ocupado
} EntradaHash;

// 2.3. struct da tabela hash

typedef struct {
    int tamanho_tabela; // inicializa o tamanho da tabela hash
    EntradaHash *entrada; // será responsável por armazenar, de forma dinâmica, as entradas da tabela hash tornando-a redimensionável
    int contador_tabela; // irá contar quantas entradas estão ocupadas na tabela hash
} TabelaHash;

// 3. FUNÇÕES do motor de busca ------------------------------------------------------ 

// 3.1. Função que irá inicializar a tabela hash e os valores da struct 'TabelaHash'

void init_TabelaHash (TabelaHash *tabela, int tamanho) {
    tabela->tamanho_tabela = tamanho;
    tabela->entrada = (EntradaHash *)malloc(tamanho * sizeof(EntradaHash));
    tabela->contador_tabela = 0;

    for (int i = 0; i < tamanho; i++) {
        // Como vai inicializar a TabelaHash então todos os valores serão zerados ou NULL
        tabela->entrada[i].palavra_busca = NULL;
        tabela->entrada[i].palavra_na_tabela = 0;
        tabela->entrada[i].contagens = NULL;
        tabela->entrada[i].status = 0;
    }
}

// 3.2. Função Hash 1

// 3.3. Função hash 2

// 3.4. Função que irá inserir os dados na tabela hash

// 3.5. Função será responsável pelo redimensionamento da tabela hash quando necessário

// 3.6. Função que irá converter todas as letras para minúsculas, de forma que o sistema não seja sensível ao caso

// 3.7. Função que irá buscar os dados na tabela hash

// 3.8. Função que irá fazer o cálculo de relevância 

// 3.9. Função que irá ordenar a busca de acordo com a função do cálculo de relevância

/* 

Requisitos:

2. Programa disponibiliza um menu para que o usuário escolha o tipo de busca que deseja fazer:

a) trazer registros com ocorrência de TODOS os termos de busca (palavras chave) - AND Search
b) trazer registros com ocorrência de PELO MENOS UM dos termos de busca (palavras chave) - OR Search

*/

int main() {

    int escolha = 0;

    while (true) {
        printf("Escolha o tipo de busca:\n");
        printf("1. trazer registros com ocorrencia de TODOS os termos de busca (palavras chave)\n");
        printf("2. trazer registros com ocorrencia de PELO MENOS UM dos termos de busca (palavras chave)\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Chamar função com ocorrencia de TODOS os termos de busca (palavras chave)
                break;
            case 2:
                // Chamar função com ocorrencia de PELO MENOS UM dos termos de busca (palavras chave)
                break;
            case 3:
                // Encerrar o programa
                printf("Programa Encerrado!\n");
                return 0;
            default:
                printf("Escolha inválida. Tente novamente.\n");
                break;
        }
    }
}