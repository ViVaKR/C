#include "../headers/vivstd.h"

/// @brief 하노이타워
/// @param n 
/// @param src 
/// @param use 
/// @param dest 
void Hanoi(int n, const char *src, const char *use, const char *dest)
{
    if (n <= 0) return;
    Hanoi(n - 1, src, dest, use);
    printf("(%lld), %s -> %s\n", N_0++, src, dest);
    Hanoi(n - 1, use, src, dest);
}
