#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>

int get_score();
int grade_score(int score);
void print_score_grade(int score, char grade);

void Operator() {
    printf("\n");
    printf("***** 연산자 *****");
    printf("\n");
    /* [ 연산자 종류 ]
            : 값에 변화를 주거나 비교 등의 역활을 하는 기호
            종류
            - 대입연산자 :              = (변수 = 변수 또는 상수)
            - 산술연산자 :              +, -, *, /, %
            - 산술+대입 연산자 :         +=, -=, *=, /=, %=
            - 증감연산자 :              ++, --
            - 관계연산자 :              <, >, >=, <=, ==, !=
            - 논리연산자 :              &&, ||, !
            - 부호연산자 :              +, -
            - 형(type) 변환연산자       ()

        [ 연산자 구분 ]
            피 연산자 : 연산의 대상이 되는 데이터
            단항 연산자 : 한개의 피연산자를 가지는 연산자 (+7, ++nVar, nVar--)
            이항 연산자 : 두개의 피연산자를 가지는 연상자 (1 + 2, nVar = 7; nVar % 2)
     */

    int nVar1, nVar2;
    nVar1 = 7;     // 대입연산자 (상수 할당)
    nVar2 = nVar2; // 대입연산자 (복사 할당)
    printf("\n");
    printf("nVar1 = %d, nVar2 = %d\n", nVar1, nVar2);

    int score = get_score();
    char grade = grade_score(score);
    print_score_grade(score, grade);
}

int get_score() {
    int score;
    printf("점수를 입력하세요. ");
    scanf("%d", &score);

    return score;
}

int grade_score(int score) {
    char grade;
    int iscore;
    iscore = score / 10;

    switch (iscore) {
        case 9:
            grade = 'A';
        case 8:
            grade = 'B';
        case 7:
            grade = 'C';
        case 6:
            grade = 'D';
        default:
            grade = 'F';
    }
    return grade;
}
void print_score_grade(int score, char grade) {
    printf("당신의 성적은 %d입니다.", score);
    printf("당신의 학점은 %c입니다.", grade);
}
