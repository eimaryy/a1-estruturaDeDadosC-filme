# Gerenciador de Filmes

Este projeto é um programa em C que implementa um gerenciador de filmes utilizando uma lista duplamente encadeada. Ele permite cadastrar, listar, buscar, alterar e excluir filmes.


## Área de Negócio

🎬 **Entretenimento / Gestão de Mídia Audiovisual**

## Sobre o Projeto

Este projeto foi desenvolvido como parte da disciplina de **Estrutura de Dados** e atende aos seguintes pré-requisitos:

1. Inserir um novo elemento em ordem por meio de uma chave inteira (única).  
2. Garantir que a lista não permita repetição de chaves.  
3. Excluir um elemento com uma “chave específica”.  
4. Alterar um elemento a partir de uma “chave específica”.  
5. Listar todos os elementos cadastrados.  
6. Consultar um elemento por meio da sua chave (através de busca sequencial).  
7. Todos os procedimentos/funções foram implementados de forma recursiva.  
8. O código foi organizado como um **TAD (Tipo Abstrato de Dados)**.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- **`main.c`**: Contém o ponto de entrada do programa e chama as funções do menu.
- **`filme.h`**: Define as estruturas de dados e declara as funções utilizadas no programa.
- **`filmesFunc.c`**: Implementa as funções para manipulação da lista de filmes.

## Funcionalidades

1. **Cadastrar Filme**: Adiciona um novo filme à lista de forma ordenada.
2. **Mostrar Filmes**: Exibe todos os filmes cadastrados na lista.
3. **Buscar Filme**: Busca um filme pelo ID e exibe suas informações.
4. **Alterar Filme**: Permite alterar as informações de um filme existente.
5. **Excluir Filme**: Remove um filme da lista pelo ID.
6. **Sair**: Encerra o programa.

## Estruturas de Dados

O programa utiliza as seguintes estruturas:

- **`Filme`**: Representa um filme com os seguintes campos:
  - `id`: Identificador único do filme.
  - `nomeFilme`: Nome do filme.
  - `duracaoMin`: Duração do filme em minutos.

- **`ListaFilmes`**: Representa um nó da lista duplamente encadeada que armazena os filmes:
  - `filme`: Dados do filme.
  - `proximo`: Ponteiro para o próximo nó.
  - `anterior`: Ponteiro para o nó anterior.

## Funções Implementadas

As principais funções implementadas no programa são:

- **`cria_no(Filme filme)`**: Cria um novo nó para a lista.
- **`mostrarFilmes(PListaFilmes lista)`**: Exibe todos os filmes da lista.
- **`buscarFilme(PListaFilmes lista, int id)`**: Busca um filme pelo ID.
- **`excluirFilme(PListaFilmes *lista, int id)`**: Remove um filme da lista pelo ID.
- **`inserir_ordenado(PListaFilmes *lista, Filme novoFilme)`**: Insere um filme na lista de forma ordenada.
- **`cadastrar_filme(PListaFilmes *lista)`**: Interface para cadastrar um novo filme.
- **`alterar_filme(PListaFilmes lista, int id)`**: Altera as informações de um filme existente.

## Como Compilar e Executar

1. Certifique-se de ter um compilador C instalado, como o `gcc`.
2. Compile o programa com o seguinte comando:
   ```bash
   gcc main.c filmesFunc.c menu.c -o programa
3. Execute o programa:
    `./programa`
