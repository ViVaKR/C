#include "../../headers/vivstd.h"

#include <locale.h>

void Clock();
void DiffTime();

/// @brief 콜백메서드 1
/// @param p
void Abs(int *p)
{
    if (*p < 0) *p = (*p) * -1;
}

int Odd_Number(int *arr)
{

    for (int i = 0; i < sizeof(arr); i++) {
        printf("%d", arr + i);
    }
}

void Sum(int a, int b, void (*p)(int *p))
{
    if (p != NULL) {
        (*p)(&a);
        (*p)(&b);
        printf("\n%d + %d = %d\n", a, b, a + b);
    }
}

void DemoB(int (*p)(int, int))
{
    printf("%d", p);
}

void Ascii()
{
    setlocale(LC_ALL, "");

    for (int i = 0; i <= 255; i++) {
        printf("%lc\t%d\t\n", i, i);
    }

    wchar_t t = L'ㄱ';
    wchar_t *h = L"안녕하세요 반갑습니다.";

    printf("--> %lc - %ls", t, h);
    printf("\n");
    printf("%ls", L"안녕하세요");

    // Clock();
    DiffTime();

    Sum(-3, -2, Abs);
}
