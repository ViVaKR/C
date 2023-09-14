#include "../headers/vivstd.h"

void MallocMemset()
{
    int *pList = NULL;
    pList = malloc(sizeof(int) * 5);

    memset(pList, 0, sizeof(int) * 3);

    printf("Tests %p, Hello World\n", MallocMemset);
    printf("pList %p\n", pList);

    free(pList);
    printf("Tests %p\n", MallocMemset);
}
