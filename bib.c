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

node *criaLista(node *inc, int n){
    int i;
    node *fnl, *nv;

    for(i=0; i<n; i++){
        nv = (node *)malloc(sizeof(node));
        nv->val = rand()%100;
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

void mostraLista(node *lst){
    node *prnt;

    printf("\n");
    for(prnt = lst; prnt!=NULL; prnt=prnt->next)
        printf("%d\t", prnt->val);
    printf("\n");

    return;
}

void *criaVetor(contatoVetor *vetor[], int n){
    char id[3];
    int i;

    for(i=0; i<n; i++){
        vetor[i] = (contatoVetor *)malloc(sizeof(contatoVetor));
        strcpy(vetor[i]->fone, "88144675");
        strcpy(vetor[i]->nome, name);
        sprintf(id,"%d",rand()%100);
        strcat(vetor[i]->nome, id);
    }

//    return;
}


contatoVetor *radixSortVetor(contatoVetor *vet[], int n){
    int i, exp = 1, m = 0, bucket[n], temp[n];

    for(i=0; i<n; i++){
        if(vet[i] > m)
            m = vet[i];
    }

    while((m/exp) > 0){
        for (i = 0; i < n; i++)
            bucket[i] = 0;

        for(i = 0; i < n; i++)
            bucket[(vet[i] / exp) % 10]++;

        for(i = 1; i < n; i++)
            bucket[i] += bucket[i-1];

        for(i = (n - 1); i >= 0; i--)
            temp[--bucket[(vet[i] / exp) % 10]] = vet[i];

        for(i = 0; i < n; i++)
            vet[i] = temp[i];

        exp *= 10;
    }
}


node *radixSort(node *lst, int n){
    int i, exp = 1, m = 0, bucket[n], temp[n];
    node *aux, *fnl;

    aux=lst;
    while(aux){
        fnl = aux;
        aux = aux->next;
    }

	for(aux=lst; aux!=NULL; aux = aux->next){
		if(aux->val > m)
			m = aux->val;
	}

	while((m/exp) > 0){
        aux = lst;

        for (i = 0; i < n; i++)
			bucket[i] = 0;

		for(i = 0; i < n; i++){
			bucket[(aux->val / exp) % 10]++;
                        aux = aux->next;
		}

		for(i = 1; i < n; i++)
			bucket[i] += bucket[i-1];
        aux = fnl;
		for(i = (n - 1); i >= 0; i--){
			temp[--bucket[(aux->val / exp) % 10]] = aux->val;
            aux = aux->prev;
		}

        aux = lst;
		for(i = 0; i < n; i++){
			aux->val = temp[i];
            aux = aux->next;
        }

		exp *= 10;
	}

    return lst;
}

void mostraVetor(contatoVetor *prnt[], int n) {
    int i=0;

    printf("\n");
    for(i=0; i<n; i++){
        printf("Nome: %s\n", prnt[i]->nome);
        printf("Fone: %s\n", prnt[i]->fone);

    printf("\n");
    }
    printf("\n");

    return;
}

//char *criaFone() {
//    char numero[15], t[2];
//    int i;
//    strcpy(numero, "");
//    for (i=0;i<8;i++) {
//        strcpy(t, "");
//        sprintf(t,"%d",rand()%10);
//        strcat(numero, t);
//    }
//
//    return numero;
//}
