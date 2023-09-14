#include "../headers/vivstd.h"

/// @brief 샘플
void PExample()
{
    fflush(stdin);
    // 문자형 포인터 예시
    int var = 10;
    int *pVar = &var;
    char str[100];
    char *string;
    string = str;
    printf("문자입력 : ");
    scanf("%s", string);
    printf("%s\n", string);

    // 정수형 포인터 예시
    int nVar, *pPtr;
    pPtr = &nVar;
    printf("정수입력 : ");
    scanf("%d", pPtr);
    printf("nVar %d\n", *pPtr);
}

void Array2DPointer()
{
    /****** Array2DPointer *****/

    int arr[3][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    // 배열의 값을 출력합니다.
    printf("\nThe array elements are:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void CheckComputerBits()
{
    // 컴퓨터 포인터의 크기 확인
    int iData = 30;
    int *pi = &iData;
    char *pc;
    long *pl;
    float *pf;
    double *pd;

    printf("%d-(%p) ", sizeof(pi), pi);
    printf("%d-(%p) ", sizeof(pc));
    printf("%d ", sizeof(pl));
    printf("%d ", sizeof(pf));
    printf("%d ", sizeof(pd));
}

/// @brief 참조에 의한 전달
/// @param ptr
void PassValue(short *ptr)
{
    short data = 0;
    data = *ptr;
    printf("pass data %d\n", data);
    *ptr = 45;
}

/// @brief 스왑함수
/// @param a 주소 변경방지 포인터
/// @param b 주소 변경방지 포인터
void SwapWithPointer(int *const a, int *const b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// @brief (20) 포인터 데모
void Pointers()
{
    printf("\n***** 포인터 *****\n");

    // todo PrintCurrentFileLineByLine(__FILE__, 52, 58); //* 소스코드 프린트
    // todo CheckComputerBits(); //* 포인터 크기 확인
    // todo Array2DPointer(); //* 배열포인터 예시

    short data = 1234;
    printf("befor caller = %d\n", data);

    PassValue(&data);
    printf("after caller =  %d\n", data);

    // 스왑
    int a = 10;
    int b = 5;

    printf("a = %d, b = %d\n", a, b);

    if (a > b) {
        SwapWithPointer(&a, &b);
    }

    printf("a = %d, b = %d, %d\n", a, b, 1 << 3);

    char *p1 = (char*)'A';
    printf("p1 %p\n",p1 + 1);

}
