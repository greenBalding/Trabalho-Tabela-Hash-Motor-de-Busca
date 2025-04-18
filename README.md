# Trabalho: Tabela Hash - Motor de Busca

## 1. Resumo
O objetivo deste trabalho é criar um motor de busca de documentos por palavras-chave, ordenados por relevância, similar aos disponibilizados em sites de busca como Google e Bing.

## 2. Detalhes

### 2.1. Índice Invertido
O motor de busca deve manter um **índice invertido**, que é uma estrutura com:
- Uma entrada para cada palavra existente em pelo menos um dos documentos da coleção.
- Cada entrada associada a uma lista de documentos onde a palavra aparece.

A partir desse índice invertido, consultas de documentos tornam-se simples consultas à tabela hash.

### 2.2. Criando o Índice Invertido
O motor de busca deve:
1. Indexar todos os arquivos de texto (`.txt`) na raiz de um diretório.
2. Utilizar obrigatoriamente uma **implementação de tabela hash** desenvolvida para este trabalho.

#### Requisitos:
- Os arquivos de texto serão fornecidos em um arquivo ZIP.
- Os nomes dos arquivos não conterão espaços ou caracteres especiais.

#### Etapas de Indexação:
1. Abrir cada arquivo e analisar seu conteúdo.
2. Indexar palavras com tamanho maior ou igual a **K** (valor inicial: `K = 4`).
3. Ignorar palavras com menos de **K** letras, tanto na indexação quanto nas consultas posteriores.

#### Considerações sobre os textos:
- Contêm apenas letras, números, espaços, hifens, quebras de linha e sinais de pontuação.
- Não possuem caracteres com marcações especiais (acentos, cedilhas, etc.).
- Não são sensíveis a maiúsculas/minúsculas (e.g., "Casa", "casa", "CASA" são tratadas como a mesma palavra).
- Apenas palavras que começam com letras são consideradas.
- Espaços, quebras de linha e sinais de pontuação são ignorados como chaves.

#### Estrutura do Índice:
- A chave é uma palavra encontrada nos arquivos.
- Cada chave está associada a uma lista de arquivos onde a palavra aparece.

### 2.3. Consultando o Índice Invertido
O motor de busca deve suportar três tipos de consultas:
1. **Busca por uma única palavra**:
   - Retorna a lista de documentos onde a palavra aparece.
2. **Busca por pelo menos uma palavra de um conjunto**:
   - Retorna a união das listas de documentos para cada palavra.
3. **Busca por todas as palavras de um conjunto**:
   - Retorna a interseção das listas de documentos para cada palavra.

#### Ordenação por Relevância:
Os documentos retornados devem ser ordenados por relevância, calculada como:

\[
r_i = \frac{1}{q_i} \sum_{j=1}^{n} p_{ij}
\]

Onde:
- \( q_i \): Quantidade de palavras distintas no arquivo \( i \).
- \( p_{ij} \): Peso da chave \( j \) no arquivo \( i \), calculado como:
  \[
  p_{ij} = f_{ij} \cdot \log_{10}\left(\frac{N}{d_j}\right)
  \]
  - \( f_{ij} \): Número de ocorrências do termo \( t_j \) no arquivo \( i \).
  - \( d_j \): Número de documentos contendo a chave \( t_j \).
  - \( N \): Número total de documentos.

Os documentos são exibidos em ordem decrescente de relevância, com:
- Nome do documento.
- Valor da relevância.

### 2.4. Considerações sobre a Implementação

#### Estrutura de Classes
Deve-se criar uma estrutura de classes que:
- Armazene todas as variáveis necessárias para o cálculo da relevância.
- Facilite a consulta posterior.

#### Tabela Hash
- O uso de uma **tabela hash** é obrigatório.
- Deve utilizar **endereçamento aberto** com tratamento de colisão por **sondagem de hash duplo**.
- Deve prever redimensionamento dinâmico para suportar um número desconhecido de registros.

#### Programa Principal
O programa deve:
1. Construir o índice invertido (usando a tabela hash) com os arquivos de texto fornecidos.
2. Disponibilizar um menu para o usuário escolher o tipo de busca:
   - **a)** Buscar documentos com ocorrência de **TODOS** os termos.
   - **b)** Buscar documentos com ocorrência de **PELO MENOS UM** dos termos.
3. Permitir que o usuário insira os termos de busca separados por espaço.
4. Realizar a busca e exibir os resultados:
   - Nome dos documentos encontrados.
   - Ordenados por relevância (do mais relevante ao menos relevante).
5. Retornar ao menu para novas buscas, sem limpar os dados anteriores.