#include "menu.h"

void menu(){
    PListaFilmes lista = NULL;
    int opcao, id;
    
    do {
        printf("Menu:\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Mostrar Filmes\n");
        printf("3. Buscar Filme\n");
        printf("4. Excluir Filme\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarFilme(&lista);
                break;
            case 2:
                if (lista == NULL) {
                    printf("Nenhum filme cadastrado.\n");
                break;
                }
                printf("Lista de Filmes:\n");
                mostrarFilmes(lista);
                break;
            case 3: {
                printf("Digite o ID do filme a ser buscado: ");
                scanf("%d", &id);
                PListaFilmes filmeEncontrado = buscarFilme(lista, id);
                if (filmeEncontrado != NULL) {
                    printf("Filme encontrado: ID: %d, Nome: %s, Duracao: %d minutos\n", filmeEncontrado->filme.id, filmeEncontrado->filme.nomeFilme, filmeEncontrado->filme.duracaoMin);
                } else {
                    printf("Filme com ID %d nao encontrado.\n", id);
                }
                break;
            }
            case 4:
		        printf("Digite o ID do filme a ser excluido: \n");
		        scanf("%d", &id);
		        excluirFilme(&lista, id);
		        break;                   
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 5);
}