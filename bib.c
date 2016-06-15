
#include "bib.h"

int menu() {
    int opcao;

    printf("Qual operação deseja efetuar?\n");
    printf("1) Criar Lista\n");
    printf("2) Criar Vetor\n");
    printf("3) Ordenação via Radix Sort\n");
    printf("4) Ordenação via Merge Sort\n");
    printf("5) Sair\n");
    printf("operação: ");
    scanf("%d", &opcao);

    return opcao;
}

contato *criaLista(contato *inc, int n){
    char id[3];
    int i;
    contato *fnl, *nv;

    for(i=0; i<n; i++){
        nv = (contato *)malloc(sizeof(contato));

        strcpy(nv->fone, criaFone());
        strcpy(nv->nome, name);
        sprintf(id,"%d",rand()%100);
        strcat(nv->nome, id);
        if(!inc){
            inc = nv;
            nv->prev = NULL;
        }else{
            fnl->next = nv;
            nv->prev = fnl;
        }
        nv->next = NULL;
        fnl = nv;
    }

    return inc;
}

void mostraLista(contato *lst){
    contato *prnt;

    printf("\n");
    for(prnt = lst; prnt!=NULL; prnt=prnt->next){
        printf("--------------------\n");
        printf("Nome: %s\n", prnt->nome);
        printf("Fone: %s\n", prnt->fone);
        printf("\n");
    }
    printf("\n");

    return;
}

void *criaVetor(contatoVetor *vetor[], int n){
    char id[3];
    int i;

    for(i=0; i<n; i++){
        vetor[i] = (contatoVetor *)malloc(sizeof(contatoVetor));
        strcpy(vetor[i]->fone, criaFone());
        strcpy(vetor[i]->nome, name);
        sprintf(id,"%d",rand()%100);
        strcat(vetor[i]->nome, id);
    }
}

void montaVetorOrdenado(vetorAuxiliar *vetorAux[], contatoVetor *vetorOrdenado[], int n) {
    char id[3];
    int i;

    for(i=0; i<n; i++){
        vetorOrdenado[i] = (contatoVetor *)malloc(sizeof(contatoVetor));
        strcpy(vetorOrdenado[i]->fone, vetorAux[i]->fone);
        strcpy(vetorOrdenado[i]->nome, name);
        sprintf(id,"%d",vetorAux[i]->nome);
        strcat(vetorOrdenado[i]->nome, id);
    }
}

contato *montaListaOrdenada(vetorAuxiliar *vetorAux[], contato *listaOrdenada, int n) {
    char id[3];
    int i;
    contato *fnl, *nv;

    for(i=0; i<n; i++){
        nv = (contato *)malloc(sizeof(contato));
        strcpy(nv->fone, vetorAux[i]->fone);
        strcpy(nv->nome, name);
        sprintf(id,"%d",vetorAux[i]->nome);
        strcat(nv->nome, id);
        if(!listaOrdenada){
            listaOrdenada = nv;
            nv->prev = NULL;
        }else{
            fnl->next = nv;
            nv->prev = fnl;
        }
        nv->next = NULL;
        fnl = nv;
    }
    return listaOrdenada;
}

void getVetorAuxiliar(contatoVetor *vetor[], vetorAuxiliar *vetorAux[], int n) {
    int i;
    for (i=0; i<n; i++) {
        vetorAux[i] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetorAux[i]->nome = soNumeros(vetor[i]->nome);
        strcpy(vetorAux[i]->fone, vetor[i]->fone);
    }
}

void getVetorAuxiliarLista(contato *lista, vetorAuxiliar *vetorAux[], int n) {
    int i;
    contato *listaAux = lista;
    for (i=0; i<n; i++) {
        vetorAux[i] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetorAux[i]->nome = soNumeros(listaAux->nome);
        strcpy(vetorAux[i]->fone, listaAux->fone);
        listaAux = listaAux->next;
    }
}

int soNumeros(char * string)
{
    int chars=0; //variável onde ficam armazenados os dígitos extraídos
    int i;

    for(i=0; string[i]!='\0'; i++) //percorrer todos os caracteres
    {
        if(isdigit(string[i])) //verificar se o carácter é numérico
        {
            chars += (int)(string[i])-'0'; //forma "artesanal" de converter o carácter para inteiro
            chars *= 10;
        }
    }
    chars /= 10;

    return chars;
}


void radixSortVetor(vetorAuxiliar *vet[], int n){
    int i, exp = 1, m = 0, bucket[n];
    vetorAuxiliar *temp[n];

    for(i=0; i<n; i++){
        if(vet[i]->nome > m)
            m = vet[i]->nome;
    }

    while((m/exp) > 0){
        for (i = 0; i < n; i++)
            bucket[i] = 0;

        for(i = 0; i < n; i++)
            bucket[(vet[i]->nome / exp) % 10]++;

        for(i = 1; i < n; i++)
            bucket[i] += bucket[i-1];

        for(i = (n - 1); i >= 0; i--) {
            temp[--bucket[(vet[i]->nome / exp) % 10]] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
            temp[bucket[(vet[i]->nome / exp) % 10]]->nome = vet[i]->nome;
            strcpy(temp[bucket[(vet[i]->nome / exp) % 10]]->fone, vet[i]->fone);
        }

        for(i = 0; i < n; i++) {
            vet[i]->nome = temp[i]->nome;
            strcpy(vet[i]->fone, temp[i]->fone);
        }
        exp *= 10;
    }
}

void mostraVetor(contatoVetor *prnt[], int n) {
    int i=0;

    printf("\n");
    for(i=0; i<n; i++){
        printf("--------------------\n");
        printf("Nome: %s\n", prnt[i]->nome);
        printf("Fone: %s\n", prnt[i]->fone);

    printf("\n");
    }
    printf("\n");
}

void mostraVetorAux(vetorAuxiliar *prnt[], int n) {
    int i=0;

    printf("\n");
    for(i=0; i<n; i++){
        printf("Nome: %d\n", prnt[i]->nome);
        printf("Fone: %s\n", prnt[i]->fone);

    printf("\n");
    }
    printf("\n");
}

void merge(vetorAuxiliar *vet[], int primeira, int meio, int ultima) {
    int i, j, k;
    vetorAuxiliar *vetB[ultima];

    for(i=0; i<ultima; i++) {
        vetB[i] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetB[i]->nome = vet[i]->nome;
        strcpy(vetB[i]->fone, vet[i]->fone);
    }
    i = k = primeira;
    j = meio+1;
    while(i <= meio && j <= ultima){
        if(vet[i]->nome <= vet[j]->nome) {
            vetB[k] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
            vetB[k]->nome = vet[i]->nome;
            strcpy(vetB[k++]->fone, vet[i++]->fone);
        } else {
            vetB[k] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
            vetB[k]->nome = vet[j]->nome;
            strcpy(vetB[k++]->fone, vet[j++]->fone);
        }
    }
    while(i <= meio) {
        vetB[k] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetB[k]->nome = vet[i]->nome;
        strcpy(vetB[k++]->fone, vet[i++]->fone);
    }
    while(j <= ultima) {
        vetB[k] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetB[k]->nome = vet[j]->nome;
        strcpy(vetB[k++]->fone, vet[j++]->fone);
    }
    for(i=primeira; i<=ultima; i++) {
//        vetB[i] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vet[i]->nome = vetB[i]->nome;
        strcpy(vet[i]->fone, vetB[i]->fone);
    }
//    free(vetB);
}


void mergeSort(vetorAuxiliar *vet[], int primeira, int ultima) {
    int meio;
    printf("primeira: %d\n", primeira);
    printf("ultima: %d\n", ultima);
    if(primeira<ultima){
        meio = (primeira+ultima)/2;
        mergeSort(vet, primeira, meio);
        mergeSort(vet, meio+1, ultima);
        merge(vet, primeira, meio, ultima);
    }
}

char *criaFone() {
    char *numero = malloc(8), t[1];
    int i;
    for (i=0;i<8;i++) {
        sprintf(t,"%d",rand()%10);
        strcat(numero, t);
    }

    return numero;
}
