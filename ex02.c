#include <stdio.h>
#include <stdlib.h>

#define START 0
#define MAX_SIZE 10

struct _lista {
    int items[MAX_SIZE];
    int primeiro, ultimo;
};

struct _lista* initLista()
{
    struct _lista* l = (struct _lista*)malloc(sizeof(struct _lista));
    l->primeiro = START;
    l->ultimo = l->primeiro;
    return l;
}

int insere(int x, struct _lista *l)
{
    int flag = 0;
    if (l->ultimo >= MAX_SIZE) {
        printf("Lista esta cheia\n");
        flag = 1;
    } else {
        l->items[l->ultimo] = x;
        l->ultimo++;
    }

    return flag;
}

void somaLista(struct _lista *l)
{
    int soma = 0;
    for (int i = 0; i < l->ultimo; i++) {
        soma += l->items[i];
    }

    printf("soma elem: %d\n", soma);
}

int main()
{
    struct _lista *l = initLista();
    int num, qtd;

    printf("Quantos elementos inserir? ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        system("clear");
        printf("Insrt elem %d: ", (i+1));
        setbuf(stdin, NULL);
        scanf("%d", &num);

       int ret = insere(num, l);
       if (ret == 1)
           break;
    }

    somaLista(l);

    free(l);
    return 0;
}
