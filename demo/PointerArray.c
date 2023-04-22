#include "../headers/vivstd.h"

void PointerArray()
{
    printf("\n***** PointerArray *****\n");

    int a[3][5] = {
        { 1, 2, 3, 4, 5 },
        { 10, 20, 30, 40, 50 },
        { 100, 200, 300, 400, 500 }
    };

    // 포인터 배열 (길이가 일정하지 않은 다차원 배열)
    printf("\n*** 포인터 배열 ***\n");

    int arr1[] = { 1, 2, 3, 4, 5, 6 };
    int arr2[] = { 11, 22, 33, 44 };
    int arr3[] = { 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888 };
    int *pa[3];
    pa[0] = arr1;
    pa[1] = arr2;
    pa[2] = arr3;

    printf("pa %p, pa size = %d a %p\n", pa[0], sizeof(pa), arr1);
}
