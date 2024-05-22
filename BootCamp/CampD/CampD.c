
#include <float.h>
#include <math.h>
#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    printf("%.*f\n", DBL_DECIMAL_DIG - 1, exp(1));
    puts("2.71828182845904523536028747135266249775724709369995...");
    return 0;
}
