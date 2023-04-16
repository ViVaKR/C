#include "stdbool.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Math() {
    system("clear");
    const double EE = 2.718281828459045235; // 자연상수
    const double PI = 3.141592;

    double A = sqrt(9);     // 제곱근
    double B = pow(2, EE);  // 거듭제곱
    double C = round(PI);   // 반올림
    double D = ceil(3.14);  // 올림
    double E = floor(3.99); // 버림
    double F = fabs(-100);  // 절대값
    double G = log(10);     // log2^8 = 3 -> 2^3 = 8, 2를 몇번곱해야 8일되는가? -> 정답 : 3
    double H = sin(45);
    double I = cos(45);
    double J = tan(45);

    printf("sqrt(9) %.2lf\n", A);
    printf("pow(2, 4) %lf\n", B);
    printf("round(%lf) : %lf\n", PI, C);
    printf("floor(3.99) : %lf\n", E);
    printf("log(10) : %lf,\nsin(45) : %lf,\ncos(45) : %lf,\ntan(45) : %lf \n", G, pow(2, 4), H, I, J);

    double radius;
    double circumference;
    double area; // A = PI * r^2

    fflush(stdin);
    printf("\nEnter the radius of a circle:  ");
    scanf("%lf", &radius);
    circumference = 2 * PI * radius;
    printf("Circumference = %.2lf\n", circumference);

    printf("\n");
    
    fflush(stdin);
    printf("\nEnter the radius of a area: ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("Area =  %.2lf\n", area);
}
