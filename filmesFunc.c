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

    if(*lista == NULL) {
        novoFilme->proximo = *lista;
        novoFilme->anterior = novoFilme->proximo;
        *lista = novoFilme;
    } else {
        PListaFilmes temp = *lista;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoFilme;
        novoFilme->anterior = temp;
        novoFilme->proximo = NULL;
    }

    printf("Filme cadastrado com sucesso! ID: %d\n", novoFilme->filme.id);
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
