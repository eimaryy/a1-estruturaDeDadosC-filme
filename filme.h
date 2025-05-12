#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme {
    int id;
    char nomeFilme[100];
    int duracaoMin;
} Filme;

typedef struct listaFilmes {
    Filme filme;
    struct listaFilmes *proximo;
    struct listaFilmes *anterior;
} ListaFilmes, *PListaFilmes;

PListaFilmes cria_no(Filme filme);
void mostrarFilmes(PListaFilmes lista);
PListaFilmes buscarFilme(PListaFilmes lista, int id);
void excluirFilme(PListaFilmes *lista, int id);
PListaFilmes inserir_ordenado(PListaFilmes *lista, Filme novoFilme);
 void cadastrar_filme(PListaFilmes *lista);
PListaFilmes alterar_filme(PListaFilmes lista, int id);

