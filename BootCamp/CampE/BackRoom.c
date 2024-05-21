#include <stdio.h>
#define DIVISOR 3 // 제수 - 나누는 수

// int mod(int num, int power) {
//     int d = 1U << power; // so d will be 1, 2, 4, 8
//     int m;
//     m = num & (d - 1); // m will be num % d
//     return m;
// }

int mod(int a, int b) {
    int r = a / b; // truncated division
    return (a - r * b);
}

int main(int argc, char *argv[]) {

    printf("%d\n", mod(8, 3));

    /*

    x |= 0x40;       // hex
x |= 64;         // decimal
x |= 0100;       // octal*
x |= 0b01000000; // binary
x |= 1 << 6;     // expression

 */

    return 0;
    switch (argc) {
    case 1:
        printf("하나 남았으므로 백룸을 닫습니다. 다음에 또 오세요..\n");
        return 444;
    default:
        printf("Backroom Count = %d, last = '%s'\n", argc, argv[argc - 1]);
        break;
    }

    ///-> 문의에 대한 답
    printf("종료하시려면 1, 계속하시려면 아무키나 누르세요! >> ");
    int intension = getchar();

    if (argc != 1 && intension != 1)
        main(argc - 1, argv);

    return 0;
}

/*
  == 테스트 실행 방법 (macOS) ==
  $ (1) clang BackRoom.c -o BackRoom
  $ (2) ./BackRoom 1 2 3 4 5 6 7 8 9 ...
 */
