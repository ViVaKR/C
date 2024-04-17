#include "../headers/vivstd.h"
void MaxAndMin();

/// @brief 자동 자릿수 계산으로 문자열을 숫자로 변환하는 함수
void ManualConvert(char *string)
{
    long long num = 0, pos;
    size_t i, count;

    count = strlen(string);
    printf("count =  %d\n", count);
    pos = pow(10, count - 1) / 10;
    printf("pos %lld\n", pos);

    for (size_t i = 0; i < count; i++) {
        num += (string[i] - '0') * pos;
        pos /= 10;
    }
    printf("%s = %ld\n", string, num);
    printf("\n");
}

/// @brief 문자 또는 문자열을 숫자로 변환하기
void StringToNumber()
{
    /****** StringToNumber *****/

    // 문자열을 정수 값으로 변환하여 사용하기
    //* 숫자 (0 ~ 9) 아스키 코드의 시작 값인 문자 '0' 의 아스키코드 값을
    //* 각 숫자 문자에서 빼면 정수형태의 숫자로 변환됨
    // '1' - '0' -> 49 - 48 -> 1 : 문자 `1` 이 숫자 1로 변환되는 원리

    printf("\n (0 ~9) 까지 문자를 숫자로 변경하기\n");
    char a = '9';
    char b = '5';
    int aa = a - '0';
    int bb = b - '0';
    printf("aa - b = %d\n", aa - bb);

    printf("\n문자열을 long 타입 숫자로 변경하기\n");
    char str[] = "347947837";
    long number = strtol(str, (char **)NULL, 10);
    printf("number = %ld\n", number);

    char src[100] = "123.45abcd";
    char *pos = NULL;
    double value = 0;
    value = strtod(src, &pos);        // 실수 부분을 추출
    printf("value is %.2f\n", value); // 추출한 값 출력
    printf("%s\n", pos);              // 나머지 부분도 출력

    char chNum[32];
    printf("\n숫자를 입력하세요 : ");
    fgets(chNum, sizeof(chNum) - 1, stdin);
    ManualConvert(chNum);

    MaxAndMin();
}
