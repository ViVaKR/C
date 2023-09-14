#include "../headers/vivstd.h"

typedef unsigned short int Vusi;

/// @brief () 전처리기 : #define, 사용자정의 자료형 : typedef
void DefineTypedef()
{
    printf("\n***** Define *****\n");
    // #define (B를 A로 치환)
    //* e.g., #define B A -> #define PSI unsinged short int *

    printf("\n***** Typedef *****\n");
    
    // typedef (A를 B로 치환)
    //* 기존 자료형 이름의 길이가 긴 경우 재정의 하여 사용하는 문법
    //* 자료형 변경 적용이 유연함 : 1바이트에서 2바이트로 변경해야 하는 경우 등등
    //* 전처리기 아님
    //* 복잡한 문법을 쉽게 표현할 수 있음
    //* e.g., typedef A B
    //* typedef unsigned int *  PSI; 
    //* PSI 라는 새로운 자료형을 정의하는 것
    
    //* unsigned short int 형을 USI 라는 새로운 이름으로 정의
    /* typedef  (기존 자료형)  (새 자료형) */

    Vusi temp; /* ==> unsigned short int temp */
    unsigned short int org = 5;
    temp = 5;

    // e.g., 배열 타입 예
    typedef int DATA[5];
    //* int DATA[5]; 와 동일
    DATA data; 
    // 또는
    // int 형 배열 5개 짜리를 가르키는 포인터배열
    // 포인터 변이가 20바이트
    int (*p)[5];
    //* int (*p)[5]; 와 같은 의미
    DATA *pp; 
}
