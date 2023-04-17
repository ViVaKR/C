#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Ref. Bro Code
void ArithmeticOperators() {

    /* 산술연산자 (Arithmetic Operators)
        +   덧셈 (addition)
        -   뺄셈 (subtraction)
        *   곱셈 (multiplication)
        /   나눗셈 (division)
        %   나머지 (modulus)
        ++  증가 (increment)
        --  감소 (decrement)
     */

    /* 증감 연산자
        전위식 : ++A (A = A + 1), --A (A = A - 1)
        후위식 : A++, A-- (세미콜론이 지난후 처리)
    */

    int nVar1 = 7, nVar2 = 8, nVar3;
    nVar3 = ++nVar1 + nVar2;
    printf("++nVar1 + nVar2 =  %d\n", nVar3); // 8 + 8 = 16

    nVar3 = nVar1++ + nVar2;
    printf("nVar1++ + nVar2 = %d\n", nVar3); // 16
    nVar3 = nVar1 + nVar2;
    printf("nVar1++ + nVar2 = %d\n", nVar3); // 17

    //= 관계 (비교) 연산자 =// : 비교의 결과는 항상 0 (false)과 1 (true)이다.
    printf("nVar1(%d) == nVar2(%d) -> ( %s ), \n", nVar1, nVar2, nVar1 == nVar2 ? "true" : "false");

    //= 논리 연산자 =// 
    // And : && (모두 1 일때 true) 
    // Or : || (둘 중 하나가 1일 때 true)
    // Not : !
    // true (1)  : 0 이외의 값
    // false (0) : 0
    printf("0 || -1 = %d, 4 || 20 = %d, 0 || 0 = %d\n", 0 || -1, 4 || 20, 0 || 0);
    printf("!-1 = %d\n",!-1); // 0
    printf("!4 = %d\n",!4); // 0
    printf("!0 = %d\n",!0); // 1

    //= 비트 연산자 (bitwise operator, 이미지 처리에 주로 사용됨) =//
    // & : and (둘다 1일 때 1)
    // | : or (둘 중 하나만 1일 때 1)
    // ~ : not
    // xor (^): 피연산자 비트값이 같으면 0, 다르면 1
    // <<, >> : 비트이동, 7 << 2 or 7 >> 2
    printf("~2 = %d\n",~2); // not
    printf("1 ^ 1 = %d, 1 ^ 0 = %d : 같으면 0, 다르면 1\n",1 ^ 1, 1 ^ 0); // xor
    printf("1 << 2 = %d\n",1 << 2); // 0000 0001 의 1을 왼쪽으로 2칸 이동 0000 0100
    printf("4 >> 1 = %d\n", 4 >> 1); // 0000 0100 을 오른쪽으로 1칸 이동 0000 0010

    //= 형변환 연산자 =//
    // (데이터형)변수/상수;
    // 메모리 크기와 데이터 허용 범위 고려하여야 함


}
