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

    int x = 5;
    int y = 2;

    int a = x + y;
    int b = x - y;
    int c = x * y;
    float d = x / (float)y; // int 형 나눗셈, float 로 변환하기
    int e = x % y;
    int f = x++;
    x--;
    int g = y--;
    y++;

    printf("%d %d (+, -, *, /, %%, ++, --) = (%d, %d, %ld, %.2f, %d, %d, %d)\n", x, y, a, b, c, d, e, f, g);
    printf("%% %d\n", e);

    /* 증강 할당 연산자 (Augmented Assignment Operators)
    Used to replace a statement where an operator takes a varialbe as one of ites arguments and
    then assigns the result back to the sam variable

    x = x + 1;
    x += 1

    x = x - 3;
    x -= 3;

    x = x * 4;
    x *= 4;

    x = x / y;
    x /= y;

    x = x % 2;
    x %= 2;

    */

    printf("5 /= 2 = %.2f\n", x /= y);
}
