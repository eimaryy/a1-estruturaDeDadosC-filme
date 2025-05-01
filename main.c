#include "filme.h"

int main(int argc, char *argv[]){
    PListaFilmes lista = NULL;
    int opcao, id;
    
    do {
        printf("Menu:\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Mostrar Filmes\n");
        printf("3. Buscar Filme\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarFilme(&lista);
                break;
            case 2:
                mostrarFilmes(lista);
                break;
            case 3:
                printf("Digite o ID do filme a ser buscado: ");
                scanf("%d", &id);
                PListaFilmes filmeEncontrado = buscarFilme(lista, id);
                if (filmeEncontrado != NULL) {
                    printf("Filme encontrado: ID: %d, Nome: %s, Duracao: %d minutos\n", filmeEncontrado->filme.id, filmeEncontrado->filme.nomeFilme, filmeEncontrado->filme.duracaoMin);
                } else {
                    printf("Filme com ID %d nao encontrado.\n", id);
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);
    
    return 0;

};