// Trabalho – Tabela Hash – Motor de Busca
// Alunos: ARTHUR CARDOSO MARQUES e MATHEUS SILVA PAINS

/*

Objetivo: Criar um motor de busca de documentos por palavras-chave ordenados por relevância, tais como os 
disponibilizados em sites de busca, como Google e Bing

*/

/*

 Fluxo:

 1. Programa constrói o índice invertido (usando a tabela hash) sobre os arquivos de texto existentes dentro 
do diretório onde estão armazenados os arquivos disponibilizados nesse trabalho.

 2. Programa disponibiliza um menu para que o usuário escolha o tipo de busca que deseja fazer:

    a) trazer registros com ocorrência de TODOS os termos de busca (palavras chave) - AND Search
    b) trazer registros com ocorrência de PELO MENOS UM dos termos de busca (palavras chave) - OR Search

 3. Usuário escolhe o tipo de busca e informa os termos de busca (palavras chave) separados por espaço (tal 
como em sites de busca como Google e Yahoo).

4. Programa efetua a busca conforme solicitação do usuário (ignorando os termos de busca que forem 
menores que K) e apresenta os nomes dos documentos (arquivos) encontrados na busca, ordenados pela 
relevância, do mais relevante ao menos relevante, um em cada linha.

 5. Programa volta ao passo 2, possibilitando que o usuário faça uma nova busca (não limpar a busca 
anterior até que o usuário faça uma nova).

*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Componentes do motor de busca

// Index invertido (tabela hash)

/* 

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