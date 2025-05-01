#include "filme.h"

int gerarID() {
    static int idAtual = 0;
    return ++idAtual;
}

void cadastrarFilme(PListaFilmes *lista) {
    PListaFilmes novoFilme = (PListaFilmes)malloc(sizeof(ListaFilmes));
    if (novoFilme == NULL) {
        printf("Erro ao alocar memoria para o novo filme.\n");
        return;
    }

    novoFilme->filme.id = gerarID();
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", novoFilme->filme.nomeFilme);
    printf("Digite a duracao do filme em minutos: ");
    scanf("%d", &novoFilme->filme.duracaoMin);

    novoFilme->proximo = *lista;
    *lista = novoFilme;

    printf("Filme cadastrado com sucesso! ID: %d\n", novoFilme->filme.id);
}

PListaFilmes buscarFilme(PListaFilmes lista, int id) {
    while (lista != NULL) {
        if (lista->filme.id == id) {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL;
}

void mostrarFilmes(PListaFilmes lista) {
    if (lista == NULL) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }

    printf("Lista de Filmes:\n");
    while (lista != NULL) {
        printf("ID: %d, Nome: %s, Duracao: %d minutos\n", lista->filme.id, lista->filme.nomeFilme, lista->filme.duracaoMin);
        lista = lista->proximo;
    }
}
