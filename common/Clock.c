#include "../headers/vivstd.h"

void Hanoi(int n, const char *src, const char *use, const char *dest);

void Clock()
{
    printf("\n***** Clock *****\n");

    clock_t st, et;

    int costs[3] = {0};
    for (int i = 0; i < 3; i++) 
    {
        st = clock();
        Hanoi(10 + i, "A", "B", "C");
        et = clock();
        costs[i] = et - st;
    }

    for (int i = 0; i < 3; i++) 
    {
        printf("\nHanoi(%d)'s 수행시간 %d clocks (1sec = %d clocks)\n",10 + i, costs[i], CLOCKS_PER_SEC);
    }
}
