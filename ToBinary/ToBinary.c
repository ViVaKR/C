#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ToBinary(int n)
{
    printf("\n");
    printf("10진수 ( %d ) -> 2진수 변환\n", n);

    for (int i = 31; i >= 0; --i) {
        printf("%d%c", (n >> i) & 1, i % 4 == 0 ? ' ' : '\0');
    }
    printf("\n");
}

// Recursive Fuction.
int sum;
void MakeBinary(int n, int i, int digit)
{
    if (i == digit) return; // base case
    MakeBinary(n, i + 1, digit);
    char c = i % 8 == 0 ? ' ' : '\0';
    int binary = (n >> i) & 1;
    sum += binary == 1 ? 1 : 0;
    printf("%d%c", binary, c);
}

int main()
{
    system("clear");
    int decimal;
    while (decimal != 0) {
        printf("2진수로 변경할 정수를 입력하세요.\n\u27AD ");
        scanf("%d", &decimal);
        printf("\n");
        int digit = 32; // 32 자리, 만일 8자리 면 8로 수정...
        sum = 0;        // 1의 합계 글로발 변수 초기화
        MakeBinary(decimal, 0, digit);
        printf(" (%d) ", decimal);
        printf("\n0의 갯수 = ( %d )개, 1의 갯수 => ( %d )개\n", digit - sum, sum);
    }

    return 0;
}
