#include "../headers/vivstd.h"

void SwitchStatement()
{
    /****** SwitchStatement *****/
    // switch = A more efficient alternative to using many "else if" statements
    // allows a value to be tested for equality against many cases
    char grade;
    printf("Enter a letter grade: ");
    scanf("%c", &grade);

    switch (grade) {
        case 'A': printf("Perfect!"); break;
        case 'B': printf("You did good!"); break;
        case 'C': printf("You did okay!"); break;
        case 'D': printf("At least it's not an F!!"); break;
        case 'F': printf("You Failed!"); break;
        default: printf("Please enter only valid grades!"); break;
    }
}
