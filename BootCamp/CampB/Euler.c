#include <float.h>
#include <math.h>
#include <stdio.h>

double E(unsigned n, double x)
{
    double next = x / n;
    return (next + 1.0 == 1.0) ? next : next + E(n + 1, next);
}
double Euler()
{
    return 1.0 + E(1, 1.0);
}
int main()
{
    printf("\n\n%.*f\n\n", DBL_DECIMAL_DIG - 1, Euler()); // 16자릿수 출력
    return 0;
}
