#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

int foo(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    printf("안녕하세요! UTF-8 콘솔 테스트 \n\n");
    // argc 최소 갯수 확인
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <arguments>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("- Argument count : %d\n", argc);
    printf("- Executable path : %s\n", argv[0]);
    printf("- Arguments : \n");

    // 인수 목록 출력
    for (int i = 0; i < argc; i++)
    {
        printf(" [%d] %s\n", i, argv[i]);
    }

    // 예시 : 첫 번째 인수 숫자로 변환
    if (argc > 1)
    {
        char *endptr = NULL;
        long value = strtol(argv[0], &endptr, 10);
        if (*endptr != '\0')
        {
            fprintf(stderr, "- '%s' 는 숫자가 아닙니다.\n", argv[1]);
        }
        else
        {
            printf("- 숫자 인수 변환 성공 %ld\n", value);
        }
    }

    int a = 1;
    int b = 2;
    int sum = foo(a, b);

    for (size_t i = 0; i < 5; i++)
    {
        sum += foo(sum, i);
    }

    printf("\%d + \%d = \%d\n", a, b, sum);

    return EXIT_SUCCESS;
}

/*
--> debug
breakpoint set --name main
breakpoint set -n main

breakpoint set -file main.c --line 7
breakpoint set -f main.c -l 7

br s -n main

breakpoint set -name foo

breakpoint list

watch set var sum

process launch
run
r

next
frame variable

print &sum
p &a

memory read &sum --format x --size 4 --count 3

--format x : 16진수 (d, , f, c, s)
--format d : 10진수
--format f : 실수
--format c : 문자
--format s : 문자열
--size 4 : 4바이트
--count 3 : 3개의 값

? 단축버전 ?
x/3xw
- 3 = 3개
- x = hex
- w = word(4바이트)

frame variable --show-types

? printf 시점에서 멈추기
breakpoint set --name printf

step

continue

*/
