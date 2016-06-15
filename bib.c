
#include "bib.h"

int menu() {
    int opcao;

    printf("Qual operação deseja efetuar?\n");
    printf("1) Criar Lista\n");
    printf("2) Criar Vetor\n");
    printf("3) Ordenação via Radix Sort\n");
    printf("4) Ordenação via Merge Sort\n");
    printf("5) Sair\n");
    printf("6) Visualizar lista/vetor\n");
    printf("operação: ");
    scanf("%d", &opcao);

    return opcao;
}

contato *criaLista(contato *inc, int n){
    char id[3], n1[8];
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

void getVetorAuxiliar(contatoVetor *vetor[], vetorAuxiliar *vetorAux[], int n) {
    int i;
    for (i=0; i<n; i++) {
        vetorAux[i] = (vetorAuxiliar *)malloc(sizeof(vetorAuxiliar));
        vetorAux[i]->nome = soNumeros(vetor[i]->nome);
        strcpy(vetorAux[i]->fone, vetor[i]->fone);
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


//contato *radixSort(contato *lst, int n){
//    int i, exp = 1, m = 0, bucket[n], temp[n];
//    contato *aux, *fnl;
//
//    aux=lst;
//    while(aux){
//        fnl = aux;
//        aux = aux->next;
//    }
//
//	for(aux=lst; aux!=NULL; aux = aux->next){
//		if(aux->val > m)
//			m = aux->val;
//	}
//
//	while((m/exp) > 0){
//        aux = lst;
//
//        for (i = 0; i < n; i++)
//			bucket[i] = 0;
//
//		for(i = 0; i < n; i++){
//			bucket[(aux->val / exp) % 10]++;
//                        aux = aux->next;
//		}
//
//		for(i = 1; i < n; i++)
//			bucket[i] += bucket[i-1];
//        aux = fnl;
//		for(i = (n - 1); i >= 0; i--){
//			temp[--bucket[(aux->val / exp) % 10]] = aux->val;
//            aux = aux->prev;
//		}
//
//        aux = lst;
//		for(i = 0; i < n; i++){
//			aux->val = temp[i];
//            aux = aux->next;
//        }
//
//		exp *= 10;
//	}
//
//    return lst;
//}

void mostraVetor(contatoVetor *prnt[], int n) {
    int i=0;

    printf("\n");
    for(i=0; i<n; i++){
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

char *criaFone() {
    char *numero = malloc(8), t[1];
    int i;
    for (i=0;i<8;i++) {
        sprintf(t,"%d",rand()%10);
        strcat(numero, t);
    }

    return numero;
}
