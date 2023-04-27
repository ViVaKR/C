#include "../headers/vivstd.h"

struct Student
{
    int number;
    char *p;
};

int TestFunc(int nParam)
{
    int nData = 1;
    nData = nParam * 2;
    return nData;// EAX
}

/// @brief 레지스터 점검용
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
    printf("\n");
    printf("***** printf *****\n");

    /*  [ printf() 함수의 출력형식 ]
        %[-][0][전체자리폭].[정밀도][변환문자]
        음수, 양수 기호 표시 -> `+`
        빈공간 0으로 채우기 -> `0`

        char message[] = "Hello World";
        int fruitCount = 12;
        double pi = -3.1241529234812041823;
        printf("Fruit Count : %d, %+010.3lf, %030s\n", fruitCount, pi, message);

        long l = 345341341234234;
        printf("Hex %x\n", &fruitCount);
        printf("long long : %ld\n", l);
     */

    Rvs();
    printf("\n");

    // 문자상수 //
    struct Student s1;
    s1.p = "Kim";
    printf("Text %s, %p, %p\n", s1.p, s1.p, "Kim");
    s1.p = "Jang";
    printf("Text %s, %p, %p\n", s1.p, s1.p, "Kim");

    // ascii 53 = (48(0) ~ 57(9))
    // 0 ~ 9 (48 ~ 57)
    // A ~ Z (65 ~ 90)
    // a ~ z (97 ~ 122)
    char a = '5';
    int b = 9;
    double c = 5.67;
    int d = 5.67;

    int rs1 = a + b;
    double rs2 = b + c;
    printf("a + b %d, b + c = %lf, %d\n", rs1, rs2, d);

    double A;
    double B;
    double C;
    printf("Enter Side A: ");
    scanf("%lf", &A);
    printf("enter Side B: ");
    scanf("%lf", &B);

    C = sqrt(A * A + B * B);

    printf("Side C:  %.2lf\n",C);
    
}
