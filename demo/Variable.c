#include <stdio.h>
#include <stdlib.h>

void Variable() {

    /* [ 변수 ]
        Allocated space in memory to store a value.We refer to a variable's name to access the stored value.   That variable now behaves as if it was the value it contains.But we need to declare what type of data we are storing.

        값을 저장하기 위해 메모리에 할당된 공간.저장된 값에 액세스하기 위해 변수의 이름을 참조합니다.해당 변수는 이제 포함된 값인 것처럼 동작합니다.그러나 저장하는 데이터 유형을 선언해야 합니다.
    */

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
