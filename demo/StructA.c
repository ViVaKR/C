#include "../headers/vivstd.h"


struct IT
{
    char company[50];
    int employee;
};

typedef struct IT It;

/// @brief (24) 구조체 A 형
void StructA()
{
    printf("\n***** (16) 구조체 *****\n");

    /* 비슷한 형태의 데이터를 관리 */
    //* 다수의 사람들의 나이, 키 그리고 몸무게를 관리하는 프로그램
    //* 

    // 선언
    It t1 = { "google", 55000 };
    It t2 = { "facebook", 43000 };
    printf("t1 address (before) %p\n", &t1);
    printf("t2 address (before) %p\n", &t2);
    t1.company;//->  dot 의미 ( `.` ) : 맴버 접근 연산자

    // 맴버 값 변경
    strcpy(t1.company, "Google");
    strcpy(t2.company, "Apple");// 문자열 맴버 값 변경은 `strcpy`
    t1.employee = 54500;
    t2.employee = 45500;

    // 구조체 맞 교환 :
    // 메모리 복사 형식 정수 교환과 동일, 맞 교환 후 구조체 주소는 바뀌지 않음

    It tmp;
    printf("tmp address (before) %p\n", &tmp);
    tmp = t2;
    t2 = t1;
    t1 = tmp;
    printf("tmp address (after) %p\n", &tmp);
    printf("\n");
    printf("t1: %s %d\n", t1.company, t1.employee);
    printf("t2: %s %d\n", t2.company, t2.employee);
    printf("t1 address (after) %p\n", &t1);
    printf("t2 address (after) %p\n", &t2);

    printf("\n");

    // 구조체 포인터
    // 포함 구조체
    // 비트 필드
    // 함수의 인수
}
