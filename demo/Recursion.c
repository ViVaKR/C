#include "../headers/vivstd.h"

void Test(int value);

/// @brief 재귀함수
void Recursion()
{
    printf("***** Recursion *****\n");
    printf("\n");

    /* 재귀호출 */
    // 논리 구조는 반복문과 같음
    // 반복을 끝내기 위한 조건을 잘 결정해야 한다.
    // Call Stack 을 활용하기 위하여 사용됨
    // Stack 의 크기는 약 1MB 정도로 제한되어 있음으로
    // 사용 전 신중히 고려하여야 함
    // 콜스택 확인방법 : 디버그 모드로 재귀함수 내부에 브레이크 설정
    Test(5);
}

/// @brief 견본 1
/// @param value : 시작할 값
void Test(int value)
{
    // 비교 참조구문
    // for (value = 5; 조건; value - 1) { 처리 }

    if (value == 0) return; // 조건에 해당
    printf("Test (%d)", value); // 처리에 해당
    return Test(value - 1); // value -1 해당
}
