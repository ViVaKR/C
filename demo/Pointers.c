#include <stdio.h>
#include <stdlib.h>

void PointerInt() {

    system("clear");

    int a, b, total;
    double avg;

    int *pa = &a;
    int *pb = &b;

    printf("a 값을 입력하세요: ");
    scanf("%d", pa);
    fflush(stdin);
    printf("b 값을 입력하세요: ");
    scanf("%d", pb);
    fflush(stdin);
    
    int *pTotal = &total;
    double *pAvg = &avg;
    *pTotal = *pa + *pb;
    *pAvg = *pTotal / 2;

    total = *pa + *pb;
    printf("Total: \%d\nAverage: \%.2f\n", *pTotal, *pAvg);
}
