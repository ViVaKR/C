#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>

int Switch();
int GetGrade(int score);
void PrintScoreGrade(int score, char grade);

/// @brief For Loop
void ForLoop() {
    printf("\n");
    printf("***** For Loop *****\n");

    int score = Switch();
    char grade = GetGrade(score);
    PrintScoreGrade(score, grade);
}

/// @brief While Loop
void WhileLoop() {
    printf("\n");
    printf("***** While Loop *****\n");
}

/// @brief Do While Loop
void DoWhileLoop() {
    printf("\n");
    printf("***** Do While Loop *****\n");
}

int Switch() {
    int score;
    printf("점수를 입력하세요. ");
    scanf("%d", &score);

    return score;
}

int GetGrade(int score) {
    char grade;
    int iscore;
    iscore = score / 10;

    switch (iscore) {
        case 9: grade = 'A';
        case 8: grade = 'B';
        case 7: grade = 'C';
        case 6: grade = 'D';
        default: grade = 'F';
    }
    return grade;
}
void PrintScoreGrade(int score, char grade) {
    printf("당신의 성적은 %d입니다.", score);
    printf("당신의 학점은 %c입니다.", grade);
}
