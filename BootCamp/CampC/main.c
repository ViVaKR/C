#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief ./runner
/// @param argc
/// @param argv <비트로 변환할 정수>
/// @return
int main(int argc, char *argv[])
{
    char *temp = "ABC";
    errno = 0;                                // 에러 필터링.
    char *p;                                  // 임시 버퍼
    int num;                                  // 2진수로 변경할 수 (실행 인수로 설정.)
    long conv = strtol(argv[1], &p, 10);      // 실행 인수를 정수로 가져오기

    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
    } else {                                  // 정상상태
        num = conv;
    }
    printf("( %d )\n\u2728 ", num);           // 원래 정수
    for (int i = 31; i >= 0; i--) {           // 32 bit scan
        int b = (num >> i) & 1;               // MSB -> LSB 비트 스캔.(1 과 and 연산하면서 비트 가져오기)
        char space = i % 4 == 0 ? ' ' : '\0'; // 4자리 띄어 놓기.
        printf("%d%c", b, space);             // 비트 프린팅.
    }

    printf(" \u2728\n");                      // 브링브링 빤짝이...

    return 123;
}

// compile and run
//--> ◯ ⭄ clang -g main.c -o runner && ./runner 191
