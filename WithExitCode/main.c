#include <stdio.h>
#include <Windows.h>
#include <limits.h>

// (1) 한글 포함 각종 유니코드 표현용, set console code page to utf-8
#pragma execution_character_set("utf-8")

int main()
{
    // (2) 한글 포함 각종 유니코드 표현용, set console code page to utf-8 (== 65001)
    SetConsoleOutputCP(65001);

    int a;
    printf("\u2728 임의의 숫자 입력 \u2728\n\u2230  ");
    scanf("%d", &a);

    const unsigned char u8_special[] = u8"\u2766 (한글 테스트) 하우아유? 파인땡스 엔드류?";

    printf("\u2766 %d\n%s\n", a, u8_special);

    // [ 리턴 범위 ]
    // 윈도우           -->  INT_MIN ~ INT_MAX,  윈도우는 정수범위 음수, 양수 모두 가능
    // 맥, 유닉스, 리눅스 -->  0 ~255 (8비트, 양수) 까지
    return a; // INT_MAX;
}
