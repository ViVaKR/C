#include "../headers/vivstd.h"

void Advenced()
{
    /****** Advenced *****/

    printf("\n");
    printf("Advenced Course");
    printf("\n");
}

void Etc()
{

    // case 1
    // int or unsigned int or unsigned long == ?; unsigned vs signed
    // 정수크기를 비교할 때 sizeof 는 부호 없는 유형을 반환함
    // 부호 없는 정수와 부호 있는 정수중에서 선택해야 함
    // -1 as an unsigned value is 0xFFFFFFFFFFFFFFFF
    // 4 > 0xFFFFFFFFFFFFFFFF 이런 결과로서 false 를 반환함
    // 동일하지 않은 데이터 유형끼리의 비교시 -1 정수인지 long 인지에 따라
    // FFFF.... 로 인식 항상 거짓이 됨
    // if (sizeof(int) > -1) {
    //     printf("True");
    // } else {
    //     printf("False");
    // }
    // printf("\n");

    // case 2
    // float f = 0.1;
    // C 언어는 Double 선호도에 따라
    // 0.1 은 Double data-type
    // 데이터 비교는 동일한 데이터 타입이어야 함으로
    // f 를 두배의 정밀도로 올리면서 값이 달라지게됨으로
    // 거짓을 반환함
    // if (f == 0.1) {
    //     printf("True");
    // } else {
    //     printf("False");
    // }

    // printf("\n");

    // case 3
    // int a, b = 1, c = 1;

    // 런타임에서는 사이즈 추론으로
    // 타입만 보고 실제 괄호안에는 진입하지 않음으로 b, c 는 변하지 않음
    // 결과적으로 a = 4; b = 그대로 1, c 역시 1을 반환하고 끝남
    // a = sizeof(c = ++b + 1);// b = 2; c = 3; 을 기대하나?
    // 결과는 -> (a = 4, b = 1, c = 1;)
    // printf("a= %d, b = %d, c = %d\n", a, b, c);

    // case 4
    // Segmentation fault (core dump)

    // 메모리 0번이지 널이 아님으로 이런식으로 초기화 하면안됨
    // char *p = 0;
    // *p = 'A';
    // printf("Value at p = %c\n", *p);

    // case 5
    // int k = 1, pp = 3, t = 2;
    // if (k > pp) {
    //     if (pp > t)
    //         printf("k > pp and pp > t\n");
    //     else
    //         printf("Something else\n");
    // }
}
