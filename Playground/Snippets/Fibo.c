#include <curses.h>

long fibo(long num);
long count;

/// @brief
void FiboStart()
{
    /****** FiboStart *****/
    printf("\n");
    count = 0;
    long num = 0;
    printf("\n개월 수 입력 >> ");
    scanf("%ld", &num);
    printf("총 토끼 쌍: %ld\n", fibo(num));
    printf("count: %d\n", count);
}

/// @brief
/// @param num
/// @return
long fibo(long num)
{
    count++;                  // 순회 횟수 카운팅 목적
    if (num <= 1) return num; // 1 = 1, 0 = 0
    return fibo(num - 1) + fibo(num - 2);
}
