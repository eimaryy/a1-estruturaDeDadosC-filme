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
} ListaFilmes, *PListaFilmes;

void cadastrarFilme(PListaFilmes *lista);
void mostrarFilmes(PListaFilmes lista);
PListaFilmes buscarFilme(PListaFilmes lista, int id);
