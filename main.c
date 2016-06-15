#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bib.h"
#include "bib.c"
#define max 10

int main()
{
    int opcao;
    contatoVetor *vetor[maxVetor];
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                printf("1\n\n");
                break;
            case 2:
                criaVetor(vetor, maxVetor);
                break;
            case 3:
                radixSortVetor(vetor, maxVetor);
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
                mostraVetor(vetor, maxVetor);
                break;
            default:
                system("clear");
                printf("Opção Invalida!\n\n");
                break;
        }
    } while(opcao != 5);

    return 0;

    srand(time(NULL));
    int t;
    node *lst;
    time_t tI, tF;

    tI = time(NULL);

    lst=NULL;

    lst = criaLista(lst, max);

    mostraLista(lst);

    lst = radixSort(lst, max);

    mostraLista(lst);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}


