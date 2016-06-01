typedef struct _node{
    int val;

    struct _node *next;

    struct _node *prev;
}node;

void mostraLista(node *lst);

node *criaLista(node *inc, int n);

node *radixSort(node *inc, int n);
