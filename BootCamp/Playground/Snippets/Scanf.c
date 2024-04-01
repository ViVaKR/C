#include "../../headers/vivstd.h"
#include <cstdio>
#include <stdio.h>


void Scanf()
{

    char name[25];// bytes
    int age;

    fflush(stdin);
    printf("What's your name? : ");

    // 문자열을 입력 받을 시에는
    // scanf 는 뛰어 쓰기 (WhiteSpace) 가 있는 문자열이 짤림으로
    // fgets 를 사용함
    // scanf("%s", &name);
    fgets(name, sizeof name, stdin);// 배열 사이즈와 동일하게 맞춤

    // 줄바꿈 제거,
    // name 의 끝(엔터키)을 널문자로 치환
    name[strlen(name) - 1] = '\0';

    fflush(stdin);
    printf("How old are you? : ");
    scanf("%d", &age);

    printf("\nHello %s, how are you?\n", name);
    printf("You are %d years old\n", age);
}
