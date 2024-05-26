#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIVISOR 3 // 제수 - 나누는 수

// int mod(int num, int power) {
//     int d = 1U << power; // so d will be 1, 2, 4, 8
//     int m;
//     m = num & (d - 1); // m will be num % d
//     return m;
// }

int mod(int a, int b)
{
    int r = a / b; // truncated division
    return (a - r * b);
}

int main(int argc, char *argv[])
{
    int apple_juice = 4500;
    int carrot_cake = 5200;
    apple_juice ^= carrot_cake;
    carrot_cake ^= apple_juice;
    apple_juice ^= carrot_cake;

    printf("apple_juice = %d, carrot_cake = %d, => %d\n\n\n", apple_juice, carrot_cake, apple_juice ^ carrot_cake);

    printf("XOR 연산을 이용한 두 변수의 값 교환 증명 (교환법칙, 결합법칙, 항등원)\n");

    // 기계어 의사코드 (Pseudo Code) 단계 요약 ..
    // (1) XOR R1, R2 # R1과 R2를 XOR연산하여 R1에 저장해라
    // (2) XOR R2, R1 # R2와 R1을 XOR연산하여 R2에 저장해라
    // (3) XOR R1, R2 # R1과 R2를 XOR연산하여 R1에 저장해라

    printf("Start: apple_juice (R1) = %d, carrot_cake (R2) = %d\n", apple_juice, carrot_cake);

    // (사전 가정)
    // apple_juice = 4500, carrot_cake = 5200
    // A = 4500 // => apple_juice
    // B = 5200 // => carrot_cake
    // R1 = A,           R2 = B

    // (1) R1 = R1 ^ R2 //=> R1 = A ^ B, R2 = B
    int _r1 = apple_juice ^ carrot_cake;
    printf("(1) R1 => (%d), R2 => (%d)\n", _r1, carrot_cake);

    // (2) R2 = R1(A ^ B) ^ R2(B)
    //=> R2 => A ^ B ^ B
    //=> R2 => A ^ (B ^ B) => A // 결합법칙, 같은 값(B ^ B)으로 XOR연산을 하면 -> 0이 나오므로 A가 나온다.
    //=> R2 => A ^ 0 = A // 0은 XOR연산의 항등원이다. (A ^ Z = A 가 되는 값 Z = 0 이 존재함.)

    int _r2 = carrot_cake ^ _r1;
    printf("(2) R2 => (%d), R1 => (%d)\n", _r2, _r1);

    // (3) R1 = R1 ^ R2
    //=> (A ^ B) ^ A = A
    //=> B ^ (A ^ A) = A
    _r1 = _r1 ^ _r2;
    printf("(3) apple_juice (R1) => (%d), carrot_cake (R2) => (%d)\n", _r1, _r2);
    /*

    x |= 0x40;       // hex
x |= 64;         // decimal
x |= 0100;       // octal*
x |= 0b01000000; // binary
x |= 1 << 6;     // expression

 */

    // return 0;
    // switch (argc) {
    // case 1:
    //     printf("하나 남았으므로 백룸을 닫습니다. 다음에 또 오세요..\n");
    //     return 444;
    // default:
    //     printf("Backroom Count = %d, last = '%s'\n", argc, argv[argc - 1]);
    //     break;
    // }

    // ///-> 문의에 대한 답
    // printf("종료하시려면 1, 계속하시려면 아무키나 누르세요! >> ");
    // int intension = getchar();

    // if (argc != 1 && intension != 1)
    //     main(argc - 1, argv);

    int input[3] = {0, 0, 0};
    int temp;

    do {
        printf("시간을 입력하세요 (HHMMSS) 1 ~ 235959 >> ");
        fflush(stdout);
        scanf("%d", &temp);
        if (temp > 235959 || temp < 0 || temp < 10000) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            continue;
        }

        for (int i = 2; i >= 0; i--) {
            input[i] = temp % 100;
            temp = temp / 100;
            if (i != 0) {
                if (input[i] > 59) {
                    printf("잘못된 입력입니다. 다시 입력하세요.\n");
                    continue;
                }
            } else {
                if (input[i] > 23) {
                    printf("잘못된 입력입니다. 다시 입력하세요.\n");
                    continue;
                }
            }
        }
        printf("%02d:%02d:%02d\n", input[0], input[1], input[2]);

    } while (temp != 0);
    // return 0;
}

/*
  == 테스트 실행 방법 (macOS) ==
  $ (1) clang BackRoom.c -o BackRoom
  $ (2) ./BackRoom 1 2 3 4 5 6 7 8 9 ...
 */
