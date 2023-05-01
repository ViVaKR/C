#include "../headers/vivstd.h"

float ByRecursive(int n, float *pSum)
{
    if (n == 1) return *pSum += n / (n + 1.0);
    *pSum = (n % 2 == 0) ? *pSum - n / (n + 1.0) : *pSum + n / (n + 1.0);
    return ByRecursive(n - 1, pSum);
}

void LValue()
{
    int a[11][11] = { 0 };
    int b = 0;
    int k = 1;
    scanf("%d", &b);

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            bool tf = (i == j) || (i + j) == (b - 1);
            if (tf) {
                a[i][j] = k;
                k++;
            }
        }
    }

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

void RecursiveForLoop()
{
    /****** RecursiveForLoop *****/
    printf("\nLoop Recursive vs For Loop Example\n");
    int i, n;
    float sum = 0;
    float *pSum = &sum;

    printf("정수 n = ");
    scanf("%d", &n);

    // 재귀함수
    printf("\n***** By Recursive *****\n");
    printf("f(%d) = %.3f", n, ByRecursive(n, pSum));
    printf("\n");

    // 맞는지 확인 용
    printf("\n***** By For Loop *****\n");
    sum = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0)
            sum -= i / (i + 1.0);
        else
            sum += i / (i + 1.0);
    }
    printf("f(%d) = %.3f", n, sum);
}
