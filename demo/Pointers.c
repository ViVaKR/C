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

/// @brief
void Pointers()
{
    // Array2DPointer();

    // char *p1; 
    short **pp, *p, data = 3;
    p = &data;
    pp = &p;

    printf("%d", **pp );

}
