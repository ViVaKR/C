#include<stdio.h>

int calculator(int num1, int num2) {
    const int result = num1 + num2;

    return result;
}

int main() {
    int first_num, second_num;

    printf("첫번째 숫자를 입력해 주세요 >> ");

    scanf("%d", &first_num);

    printf("두번째 숫자를 입력해 주세요 >> ");

    scanf("%d", &second_num);

    printf("%d + %d = %d\n", first_num, second_num, first_num + second_num);

    return 0;
}


// int a[50][50] = {0,};
//
// int n;
// printf("가로세로 사이즈: ");
// scanf("%d", &n);
//
// int i = 1;
// int j = n / 2 + 1;
//
// for (int k = 1; k <= n * n; k++) {
//     if ((j < 1 || j > n) && (i < 1 || i > n)) {
//         i -= 2;
//         j -= 1;
//         if (a[i][j] != 0) {
//             i -= 2;
//             j -= 1;
//         }
//     } else if (j > n) {
//         j = 1;
//     } else if (i < 1) {
//         i = n;
//     }
//     a[i][j] = k;
//     i--;
//     j++;
// }
//
// for (i = 1; i <= n; i++) {
//     for (j = 1; j <= n; j++) {
//         printf("|%03d|\t", a[i][j]);
//     }
//     printf("\n\n");
// }
// return 0;
