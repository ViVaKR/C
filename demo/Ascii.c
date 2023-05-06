#include "../headers/vivstd.h"

#include <locale.h>

void Clock();
void DiffTime();

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
}
