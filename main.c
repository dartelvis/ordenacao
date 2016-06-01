#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"
#include "bib.c"
#define max 10

int main()
{
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


