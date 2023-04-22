#include "../headers/vivstd.h"

int TestFunc(int nParam)
{
    int nData = 1;
    nData = nParam * 2;
    return nData;// EAX
}

void Rvs()
{
    int a = 2;
    int *pa = &a;

    int b = 3;
    int *pb = &b;

    int d = TestFunc(a + b);

    printf("End of Rvs()");
    // EAX -> RAX
}

/// @brief Ref. Bro Code
void Printf()
{

    printf("***** printf *****\n");
    // printf("\n");
    // printf("printf()\nint printf( const char *format[, argument])\n");

    // // [ printf() 함수의 출력형식 ]
    // // %[-][0][전체자리폭].[정밀도][변환문자]
    // // 음수, 양수 기호 표시 -> `+`
    // // 빈공간 0으로 채우기 -> `0`

    // printf("\n");

    // char message[] = "Hello World";
    // int fruitCount = 12;
    // double pi = -3.1241529234812041823;

    // long l = 345341341234234;

    // printf("Fruit Count : %d, %+010.3lf, %030s\n", fruitCount, pi, message);

    // printf("Hex %x\n", &fruitCount);
    // printf("long long : %ld\n", l);

    Rvs();
}
