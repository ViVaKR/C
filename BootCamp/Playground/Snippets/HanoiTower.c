#include "../headers/vivstd.h"

void Hanoi(int n, const char *src, const char *use, const char *dest);

int StartPeg = 0;
int TempPeg = 0;
int EndPeg = 0;
char a = 'A', b = 'B', c = 'C';

/// @brief Printing
/// @param left 빼내는 판
/// @param right 넣는 판
void PrintStatus(const char left, const char right)
{
    if (left == 'A') StartPeg--;
    if (right == 'A') StartPeg++;
    if (left == 'B') TempPeg--;
    if (right == 'B') TempPeg++;
    if (left == 'C') EndPeg--;
    if (right == 'C') EndPeg++;
    printf("H ( %d - %d - %d )\n", StartPeg, TempPeg, EndPeg);
    printf("P ( %d\t%c -> %c )\n\n", StartPeg, left, right);
}

/// @brief 하노이 타워
/// @param n 판 갯수
/// @param start 출발지
/// @param end 목적지
/// @param temp 임시
void Move(int n, const char start, const char end, const char temp)
{
    if (n <= 0) return;
    Move(n - 1, start, temp, end);
    printf("Before(H)\t( %c - %c - %c )\nNow(H)\t\t( %c - %c - %c )\n", a, b, c , start, end, temp);
    a = start; b = end; c = temp;
    PrintStatus(start, end);
    Move(n - 1, temp, end, start);
}
void HanoiTower()
{
    printf("\n***** 하노이 타워 *****\n");
    int pegs = 4;
    StartPeg = pegs;

    char A = 'A';
    char B = 'B';
    char C = 'C';

    // 시작 (판 4개 기준)
    // 2 ^ n - 1 => 2 ^ 4 - 1 = 15;
    Move(pegs, A, C, B);

    // printf("\n");
    // Hanoi(4, "A", "B", "C");
}
