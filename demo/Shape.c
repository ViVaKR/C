#include "../headers/vivstd.h"

double Pythagoras(double A, double B)
{
    return sqrt(A * A + B * B);
}

/// @brief 삼각형 출력
/// @param tf true = 정삼각형,  false = 역삼각형
void DrawTriangle(bool tf)
{
    int n;
    printf("\n삼각형높이 : ");
    scanf("%d", &n);

    if (tf) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (n - i); j++) {
                printf("%c", ' ');
            }
            for (int j = 0; j < (i * 2) + 1; j++) {
                printf("%c", '*');
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                printf("%c", ' ');
            }
            for (int j = 0; j < ((n - i) * 2) - 1; j++) {
                printf("%c", '*');
            }
            printf("\n");
        }
    }
}

/// @brief 사각형 출력
void DrawRect()
{
    int n, i, j;
    printf("\n출력할 라인수 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", '*');
        }
        printf("\n");
    }
}

/// @brief (38) 모양
void Shape()
{
    system("clear");
    printf("\n***** 모양 *****\n");

    printf("(5, 5) 빗변의 길이 = %lf\n", Pythagoras(5.0, 5.0));

    DrawRect();
    DrawTriangle(true);
    DrawTriangle(false);
}
