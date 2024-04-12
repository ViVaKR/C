#include <stdio.h>

//                           (A)       (B)       (C)
void HanoiTower(int n, char from, char temp, char to)
{
    if (n == 1) {
        printf("%c\t=>\t%c\n", from, to);
        return;
    }

    //           (출발지, 경유지, 목적지)
    HanoiTower(n - 1, from, to, temp); // A -> B
    printf("%c\t=>\t%c\n", from, to);
    HanoiTower(n - 1, temp, from, to); // B -> C
}
int main(int argc, char *argv[])
{
    int a = 123;
    int b = 456;
    printf("Hello, Hanoi Tower %d, %d\n", a, b);
    HanoiTower(3, 'A', 'B', 'C');
    return 123;
}

/*
일반화 공식

f(n) = 1 + 2 * f(n)
2^n - 1

n = 1
    A -> C

n = 2
    A -> B
    A -> C
    B -> C

n = 3
    A -> B (3회)
    A -> C (1회)
    B -> C (3회)

 */
