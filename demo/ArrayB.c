#include "../headers/vivstd.h"

int GetStringLength(char data[]);
void StringCopy();

/// @brief 배열
void ArrayB()
{
    printf("\n***** 배열의 초기화 *****\n");
    // 배열을 지역변수로 선언하면 자동 초기화가 되지 않음
    // 전역변수는 0으로 자동 초기화
    // 배열은 사용자 정의 자료형 (User-defined Data Type)

    //* 초기화 *//
    short student[5] = {
        3,
    };// {3, 0, 0 ,0 ....} 과 같음

    short data[] = { 1, 2, 3, 4, 5 };// [] 안에 요소의 개수 생략가능

    //* 배열로 문자열 표현하기 *//
    // char : C 언어에서 문자를 저장하는데 가장 적합한 자료형
    // 문자의 끝에 NULL(널) 문자 `0`을 추가하여, 배열에 저장된 정보가 배열임을 알림
    // 문자 상수 방식 : char data[6] = {'H', 'e', 'l', 'l', 'o', 0 };
    // 문자열 상수 방식 : char data[6] = "happy"; (문자열의 끝에 NULL 문자가 자동포함)
    // printf 함수로 문자열을 출력할 때는 %s 를 사용

    char str[6] = "Happy";
    char ment[] = "C# Programming";
    printf("Text %s\n", str);
    printf("Text %s\n", ment);

    //* 문자열의 길이 구하기
    // 배열에 저장된 문자열의 길이(문자의 개수)를 알기 위해서는
    // 문자열의 끝(0, EOL, End Of Line)을 찾는 코드가 필요
    // strlen (string length) 사용
    printf("Happy's String Length = %d, %d\n", GetStringLength(str), strlen(str));

    // strcpy (dest, src), strcat
    StringCopy();

    
}
