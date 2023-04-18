#include "../headers/vivstd.h"

void Variable() {

    

    int x;       // 선언 (declaration )
    x = 123;     // 초기화 (initialization)
    int y = 321; // 선언 과 동시에 초기화 (declaration + initiization)

    int age = 21;        // integer type
    float gpa = 2.05;    // floating point number
    char grade = 'C';    // single character
    char name[] = "Viv"; // array of characters

    printf("You are %d age years old\n", age);     // int
    printf("Hello \%s\n", name);                   // char[], string
    printf("Your gps \%.2f\n", gpa);               // float
    printf("Youer average grade is \%c\n", grade); // char
}
