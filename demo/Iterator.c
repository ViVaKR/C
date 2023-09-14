#include "../headers/vivstd.h"

int Switch();
int GetGrade(int score);
void PrintScoreGrade(int score, char grade);

/// @brief For Loop
void ForLoop()
{
    printf("\n");
    printf("***** For Loop *****\n");

    int score = Switch();
    char grade = GetGrade(score);
    PrintScoreGrade(score, grade);

    // 역방향 For Loop Example
    printf("\n");
    printf("\n");
    int sum = 0;
    for (int i = 10; i >= 0; --i) { sum += i; }
    printf("1 부터 10 까지의 합계 = %d\n", sum);
}

/// @brief While Loop
// void WhileLoop()
// {
//     printf("\n");
//     printf("***** While Loop ( 1 to 100, 짝수찾기) *****\n");
//     int start = 1;
//     while (start <= 100) {
//         if (start % 2 == 0) printf("짝수 (1-100): %d\n", start);
//         start++;
//     }
// }

/// @brief Do While Loop
void DoWhileLoop()
{
    printf("\n");
    printf("***** Do While Loop *****\n");
}

int Switch()
{
    int score;
    printf("점수를 입력하세요. ");
    scanf("%d", &score);

    return score;
}

int GetGrade(int score)
{
    char grade;
    int iscore;
    iscore = score;

    switch (iscore) {
    case 9: grade = 'A';
    case 8: grade = 'B';
    case 7: grade = 'C';
    case 6: grade = 'D';
    default: grade = 'F';
    }
    return grade;
}
void PrintScoreGrade(int score, char grade)
{
    printf("당신의 성적은 %d입니다.", score);
    printf("당신의 학점은 %c입니다.", grade);
}
