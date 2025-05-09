#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include <locale.h>

void menu(){
    PListaFilmes lista = NULL;
    int opcao, id, verifica;
    setlocale(LC_ALL, "portuguese");
    
    do {
    
        printf("Menu:\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Mostrar Filmes\n");
        printf("3. Buscar Filme\n");
        printf("4. Excluir Filme\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        
       verifica = scanf("%d", &opcao);
       
       if(verifica != 1){
       	while(getchar() != '\n');
	   }
       	system("cls");
        switch(opcao) {
            case 1:
                cadastrar_filme(&lista);
                 getch();
                break;
    
            case 2:
                if (lista == NULL) {
                    printf("Nenhum filme cadastrado.\n");
                break;
                }
                printf("Lista de Filmes:\n");
                mostrarFilmes(lista);
                getch();
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
                getch();
                break;
            }
            case 4:
		        printf("Digite o ID do filme a ser excluido: \n");
		        scanf("%d", &id);
		        excluirFilme(&lista, id);
		        getch();
		        break;                   
            case 5:
                printf("Saindo...\n");
                getch();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        system("cls");
    } while(opcao != 5);
}
