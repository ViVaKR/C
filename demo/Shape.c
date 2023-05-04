#include "../headers/vivstd.h"

double Pythagoras(double A, double B)
{
    return sqrt(A * A + B * B);
}

void Shape()
{
    /****** Shape *****/

    // TODO
    printf("(5, 5) 빗변의 길이 = %lf\n", Pythagoras(5.0, 5.0));
}
