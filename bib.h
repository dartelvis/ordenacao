#define maxVetor 40
#define name "Fulano "

typedef struct _contato{
    char nome[40];
    char fone[30];
    struct _contato *next;
    struct _contato *prev;
} contato;

typedef struct _contatoVetor{
    char nome[40];
    char fone[30];
} contatoVetor;

typedef struct _vetorAuxiliar{
    int nome;
    char fone[30];
} vetorAuxiliar;

void montaVetorOrdenado(vetorAuxiliar *vetorAux[], contatoVetor *vetorOrdenado[], int n);

void radixSortVetor(vetorAuxiliar *vet[], int n);

void merge(vetorAuxiliar *vet[], int primeira, int meio, int ultima);

void mergeSort(vetorAuxiliar *vet[], int primeira, int ultima);

void mostraVetor(contatoVetor *prnt[], int n);

void mostraLista(contato *lst);

void getVetorAuxiliar(contatoVetor *vetor[], vetorAuxiliar *vetorAux[], int n);

void getVetorAuxiliarLista(contato *lista, vetorAuxiliar *vetorAux[], int n);

void *criaVetor(contatoVetor *vetor[], int n);

contato *criaLista(contato *inc, int n);

contato *montaListaOrdenada(vetorAuxiliar *vetorAux[], contato *listaOrdenada, int n);

int soNumeros(char * string);

int menu();

char *criaFone();



void mostraVetorAux(vetorAuxiliar *prnt[], int n);