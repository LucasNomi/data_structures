#include <stdio.h>

#define MAX 5

int main()
{
    int lista[MAX], soma = 0;

    for (int i = 0; i < MAX; i++) {
        printf("Insrt elem: ");
        setbuf(stdin, NULL);
        scanf("%d", &(*lista)+i);
        soma += lista[i];
    }

    printf("soma elem: %d\n", soma);
    return 0;
}
