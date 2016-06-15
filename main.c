#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
//#include "bib.h"
#include "bib.c"
int max;
int main()
{
    int opcao, opcaoSubMenu;
    contatoVetor *vetor[maxVetor], *vetorOrdenado[maxVetor];
    vetorAuxiliar *vetorAux[maxVetor];
    contato *lista, *listaOrdenada;
    vetor[0] = NULL;
    lista = NULL;
//    listaOrdenada = NULL;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                system("clear");
                if (lista != NULL) {
                    printf("Lista ja existe!\n\n");
                    break;
                }
                do {
                    printf("Digite o numero de contatos que deseja possui na lista\n");
                    printf("Numero de contatos: ");
                    scanf("%d", &max);

                    if (max < 0) {
                        system("clear");
                        printf("Favor digite um numero maior que zero!\n\n");
                    }
                } while(max < 0);
                lista = criaLista(lista, max);
                printf("Lista criada corretamente!\n\n");
                break;
            case 2:
                system("clear");
                if (vetor[0] == NULL) {
                    criaVetor(vetor, maxVetor);
                    printf("Vetor criado corretamente!\n\n");
                } else {
                    printf("Vetor ja existe!\n\n");
                }
                break;
            case 3:
                system("clear");
                do {
                    printf("Qual opção deseja ordenar?\n");
                    printf("1) Lista\n");
                    printf("2) Vetor\n");
                    printf("operação: ");
                    scanf("%d", &opcaoSubMenu);
                    switch(opcaoSubMenu) {
                        case 1:
                            if (lista == NULL) {
                                system("clear");
                                printf("Lista ainda nao criada!\n\n");
                                break;
                            }
                            listaOrdenada = NULL;
                            getVetorAuxiliarLista(lista, vetorAux, max);
                            radixSortVetor(vetorAux, max);
                            listaOrdenada = montaListaOrdenada(vetorAux, listaOrdenada, max);
                            system("clear");
                            printf("=== Lista Original ===\n\n");
                            mostraLista(lista);
                            printf("\n=== Lista Ordenado ===\n\n");
                            mostraLista(listaOrdenada);
                            break;
                        case 2:
                            if (vetor[0] == NULL) {
                                system("clear");
                                printf("Vetor ainda nao criado!\n\n");
                                break;
                            }
                            getVetorAuxiliar(vetor, vetorAux, maxVetor);
                            radixSortVetor(vetorAux, maxVetor);
                            montaVetorOrdenado(vetorAux, vetorOrdenado, maxVetor);
                            system("clear");
                            printf("=== Vetor Original ===\n\n");
                            mostraVetor(vetor, maxVetor);
                            printf("\n=== Vetor Ordenado ===\n\n");
                            mostraVetor(vetorOrdenado, maxVetor);
                            break;
                        default:
                            system("clear");
                            printf("Opção Invalida!\n\n");
                            break;
                    }
                } while(opcaoSubMenu > 2 || opcaoSubMenu < 1);
                break;
            case 4:
                printf("4\n\n");
                break;
            case 5:
                system("clear");
                printf("Obrigado...\n\n");
                break;
            case 6:
                system("clear");
                printf("=== Vetor Original ===\n\n");
                mostraVetor(vetor, maxVetor);
                printf("\n\n=== Vetor Ordenado ===\n\n");
                mostraVetor(vetorOrdenado, maxVetor);
                break;
            default:
                system("clear");
                printf("Opção Invalida!\n\n");
                break;
        }
    } while(opcao != 5);

    return 0;

//    srand(time(NULL));
//    int t;
//    node *lst;
//    time_t tI, tF;
//
//    tI = time(NULL);
//
//    lst=NULL;
//
//    lst = criaLista(lst, max);
//
//    mostraLista(lst);
//
//    lst = radixSort(lst, max);
//
//    mostraLista(lst);
//
//    tF = time(NULL);
//    t = difftime(tF, tI);
//    printf("\n\n%d seg", t);

    return 0;
}


