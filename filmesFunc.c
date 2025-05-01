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

    if (*lista == NULL) {
        novoFilme->proximo = NULL;
        novoFilme->anterior = NULL;
        *lista = novoFilme;
    } else {
        PListaFilmes temp = *lista;
    
        if (novoFilme->filme.id < temp->filme.id) {
            novoFilme->proximo = temp;
            novoFilme->anterior = NULL;
            temp->anterior = novoFilme;
            *lista = novoFilme;
        } else {
            if(temp->proximo != NULL && temp->filme.id < novoFilme->filme.id) {
                cadastrarFilme(&temp->proximo);
            }
            if (temp->proximo == NULL && temp->filme.id < novoFilme->filme.id) {
                temp->proximo = novoFilme;
                novoFilme->anterior = temp;
                novoFilme->proximo = NULL;
            } else {
                novoFilme->proximo = temp;
                novoFilme->anterior = temp->anterior;
                temp->anterior->proximo = novoFilme;
                temp->anterior = novoFilme;
            }
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