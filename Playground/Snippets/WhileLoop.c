#include "../headers/vivstd.h"

void WhileLoop()
{
    int input;
    char *alert;
    do {
        printf("%s 4 이상 정수를 입력하세요 >> ", alert == NULL ? "- " : alert);
        scanf("%d", &input);
        alert = "따시 ~~ ";
    } while (input < 4);

    printf("*** 1 부터 %d 까지 4의 배수를 찾기... ***\n", input);

    int count = 0;
    while (input >= 4) {
        if (input % 4 == 0) {
            printf("%d\n", input);
            count++;
        }
        input--;
    }

    printf("1 부터 %d 까지 4의 배수는 총 %d 개입니다.\n", input, count);
}
