#include "../headers/vivstd.h"


void IfStatement()
{
    /****** IfStatement *****/

    int age;

    printf("Enter Your Age: ");

    scanf("%d", &age);

    if (age >= 18) {
        printf("You are now singed up!");
    } else if (age == 0) {
        printf("You can't sign up! You are just born");
    }
    else if (age < 0) {
        printf("You haven't been born yet!");
    } else {
        printf("You are too young to sign up!");
    }
}
