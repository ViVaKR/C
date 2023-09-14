#include "../headers/vivstd.h"

void Calculate()
{
    /****** Calculate *****/
    char operator;
    double num1;
    double num2;
    double result;

    fflush(stdin);
    printf("Enter an operator (+ - * /): ");
    scanf("%c", &operator);

    printf("Enter number 1: ");
    scanf("%lf", &num1);

    printf("Enter number 2: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+': printf("%lf + %lf = %.2lf\n", num1, num2, num1 + num2); break;
        case '-': printf("%lf - %lf = %.2lf\n", num1, num2, num1 - num2); break;
        case '*': printf("%lf * %lf = %.2lf\n", num1, num2, num1 * num2); break;
        case '/': printf("%lf / %lf = %.2lf\n", num1, num2, num1 / num2); break;
    }
}
