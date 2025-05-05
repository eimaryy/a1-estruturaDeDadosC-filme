#include "filme.h"

int gerarID() {
    static int idAtual = 0;
    return ++idAtual;
}

void cadastrarFilme(PListaFilmes *lista) {
    PListaFilmes novoFilme = (PListaFilmes)malloc(sizeof(ListaFilmes));
    if (novoFilme == NULL) {
        printf("Erro ao alocar memória para o novo filme.\n");
        return;
    }

    novoFilme->filme.id = gerarID();
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", novoFilme->filme.nomeFilme);
    printf("Digite a duracao do filme em minutos: ");
    scanf("%d", &novoFilme->filme.duracaoMin);

    novoFilme->proximo = NULL;
    novoFilme->anterior = NULL;

    if (*lista == NULL) {
        *lista = novoFilme;
    } else {
        PListaFilmes atual = *lista;

        if (novoFilme->filme.id < atual->filme.id) {
            novoFilme->proximo = atual;
            atual->anterior = novoFilme;
            *lista = novoFilme;
        } else {
            while (atual->proximo != NULL && atual->proximo->filme.id < novoFilme->filme.id) {
                atual = atual->proximo;
            }

            novoFilme->proximo = atual->proximo;
            novoFilme->anterior = atual;

            if (atual->proximo != NULL) {
                atual->proximo->anterior = novoFilme;
            }

            atual->proximo = novoFilme;
        }
    }

    printf("Filme cadastrado com sucesso! ID: %d\n", novoFilme->filme.id);
}

void mostrarFilmes(PListaFilmes lista) {
    if (lista == NULL) {
        return;
    }

    printf("ID: %d, Nome: %s, Duracao: %d minutos\n", lista->filme.id, lista->filme.nomeFilme, lista->filme.duracaoMin);
    mostrarFilmes(lista->proximo);
}

PListaFilmes buscarFilme(PListaFilmes lista, int id) {
    if (lista == NULL || lista->filme.id == id) {
        return lista;
    }
    return buscarFilme(lista->proximo, id);
}

void excluirFilme(PListaFilmes *lista, int id) {
    if (*lista == NULL) {
        printf("Filme com ID %d nao encontrado.\n", id);
        return;
    }

    if ((*lista)->filme.id == id) {
        PListaFilmes temp = *lista;

        if (temp->anterior != NULL) {
            temp->anterior->proximo = temp->proximo;
        }

        if (temp->proximo != NULL) {
            temp->proximo->anterior = temp->anterior;
        }

        if (temp->anterior == NULL) {
            *lista = temp->proximo;
        }

        printf("Filme '%s' com ID %d excluído com sucesso.\n", temp->filme.nomeFilme, temp->filme.id);
        free(temp);
        return;
    }

    excluirFilme(&((*lista)->proximo), id);
}

