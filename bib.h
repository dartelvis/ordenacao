#define maxVetor 40
#define name "Fulano "

typedef struct _node{
    int val;
    struct _node *next;
    struct _node *prev;
} node;

typedef struct _contatoVetor{
    char nome[40];
    char fone[30];
} contatoVetor;


int menu();

void mostraLista(node *lst);

node *criaLista(node *inc, int n);

node *radixSort(node *inc, int n);

contatoVetor *radixSortVetor(contatoVetor *vet[], int n);

void mostraVetor(contatoVetor *prnt[], int n);

//char *criaFone();

void *criaVetor(contatoVetor *vetor[], int n);