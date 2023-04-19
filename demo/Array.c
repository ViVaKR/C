#include "../headers/vivstd.h"

void ArrayParam(char *cArray, int size);

void Array()
{
    printf("***** Array *****\n");

    /* 배열 */
    // 일반변수의 단점을 보완
    // 데이터형과 변수명이 같은 변수의 집합
    // 연속적인 메모리 할당
    // 인덱스를 통하여 배열 원소를 구분
    // 배열명은 배열의 첫번째 메모리 주소를 의미
    // int nArray[7];
    // nArray == &Array[0]; 과 같은 의미, 같은 맥락으로
    // *nArray + 1 == nArray[1] 도 같음

    // 배열 선언과 동시 초기화 방식
    int arrA[3] = { 1, 2, 3 };
    int arrB[] = { 1, 2, 3 };
    int arr[5] = {
        0,// 모두 0으로 채우기 :  0 또는 , -1, 0 만 가능
    };

    arrA[0] = 10;
    arrA[1] = 20;
    arrA[2] = 30;
    printf("\n");
    // 배열의 메모리 주소 보기 방식 2종
    printf("-- 배열의 메모리 주소 보기 방식 2종 --");
    printf("\n");
    printf("arrA = %p, &arrA[0] = %p\n",arrA, &arrA[0]);
    printf("\n");
    printf("\n");

    // 배열크기 구하기 : sizeof(배열명) / sizeof(데이터형 또는 배열의 첫번째 인덱스 요소)
    printf("size %d\n", sizeof arr / sizeof arr[0]);
    for (int i = 0; i < sizeof arrA / sizeof arrA[0]; i++) printf("Arr value %d\n", arrA[i]);

    int Grade[3], Sum;
    float Average;
    printf("성적을 입력하세요 >> C, C++, C# >> ");

    // 연속 입력시 띄여 쓰기 또는 엔터키로 구분가능
    scanf(" %d %d %d", &Grade[0], &Grade[1], &Grade[2]);
    Sum = Grade[0] + Grade[1] + Grade[2];
    Average = (double)Sum / (double)3;
    printf("C: %d, C++: %d, C#: %d, 총점: %d, 평균: %.2f\n", Grade[0], Grade[1], Grade[2], Sum, Average);

    // 배열 초기화 : memset(배열명, 0 or -1, 초기화할 크기)
    printf("문자열열초기화 : memset example, 숫자형은 이상한 값이 들어감 주의");
    char chArr[20] = "Hello World";
    memset(chArr, '0', 20 * sizeof(char));
    for (int i = 0; i < 20; i++) {

        // '0' 으로 초기화 출력
        printf("Char %d : %c\n", i, chArr[i]);
    }

    // 배열을 포인터로 전달
    ArrayParam(chArr, sizeof(chArr));

    // 배열을 포인터로 전달 된 후 값 변화 확인
    printf("배열 포인터 전달 후");
    printf("\n");
    for (size_t i = 0; i < sizeof(chArr) / sizeof(chArr[0]); i++) {

        // 숫자를 Ascii 코드 문자로 변경됨 확인
        printf("chArr %d %c\n", i, chArr[i]);
    }
}

/// @brief 배열을 포인터로 받은 값 변경, cArray[] 도 동일 결과
/// @param cArray 배열 포인터 명
/// @param size 배열 사이즈
void ArrayParam(char *cArray, int size)
{
    /* [ size_t ]
        size_t는 부호 없는 정수형(unsinged integer)으로 sizeof, alignof, offsetof의 반환 값입니다.
        이론적으로 가능한 오브젝트의 최대 크기를 저장할 수 있는 타입이며 일반적으로,
        배열 인덱싱 및 루프 계산에 사용됩니다.(문자열이나 메모리의 사이즈를 나타낼 때 사용)
        "unsigned int"를 typedef unsigned int size_t;
        이렇게 size_t 라는 이름으로 정의해 놓은 것입니다.
        size_t 는, 32비트 운영체제에서는 "부호없는 32비트 정수"이고, 64비트 운영체제에서는 "부호없는 64비트 정수"입니다.
        그러나 "unsigned int" 또는 "int"는, 64비트 OS라고 해서 꼭 64비트 정수는 아닙니다. 여전히 32비트일 수도 있습니다.
        이것이 size_t형과 "unsigned int"형의 차이입니다.
        메모리나 문자열 등의 길이를 구할 때에는 "unsigned int" 대신 size_t 라는 형으로 길이가 반환됩니다. */

    printf("함수 내부 배열 포인터");
    printf("\n");
    for (size_t i = 0; i < size; i++) {
        cArray[i] = (char)(i + 65);
        printf("nArray %d %c %c\n", i, cArray[i], *cArray + i);

    }
}
