#include "filme.h"


int gerarID() {
     int idAtual = rand();
    return idAtual;
}


PListaFilmes cria_no(Filme filme){
	PListaFilmes novoFilme = (PListaFilmes)malloc(sizeof(ListaFilmes));
	novoFilme->filme = filme;
	novoFilme->proximo = NULL;
    novoFilme->anterior = NULL;
    return novoFilme;
}



PListaFilmes inserir_ordenado(PListaFilmes *lista, Filme novoFilme) {
	PListaFilmes novo = cria_no(novoFilme);
    if (*lista == NULL) {
    	*lista = novo;
		 return novo;
        
    } 
	else {
        PListaFilmes temp = *lista;

        if (novo->filme.id < temp->filme.id) {
            novo->proximo = temp;
            temp->anterior = novo;
            return novo;
        } 
        
        temp->proximo = inserir_ordenado(&temp->proximo, novoFilme);
		
		if(temp->proximo != NULL){
			temp->proximo->anterior = temp;
		}
		
		return *lista;
		}
    }
    
    void cadastrar_filme(PListaFilmes *lista) {
    Filme f;
    f.id = gerarID();
    printf("Digite o nome do filme: ");
    scanf(" %[^\n]", f.nomeFilme);
    printf("Digite a duração em minutos: ");
    scanf("%d", &f.duracaoMin);

    inserir_ordenado(lista, f);
    printf("Filme cadastrado com sucesso! ID: %d\n", f.id);
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


