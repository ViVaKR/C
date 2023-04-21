#include "../headers/vivstd.h"

/// @brief 두값을 포인터를 통하여 교체하기
/// @param x 
/// @param y 
void Swap(int *x, int *y)
{
    /****** Swap *****/
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// @brief 포인터를 통한 두값을 스왑 변경
void CallByPointer()
{
    /****** CallByPointer *****/
    int a = 100, b = 200;
    Swap(&a, &b);
    printf("***** Call By Pointer *****\n");
    printf("a = %d\nb = %d\n", a, b);
}
