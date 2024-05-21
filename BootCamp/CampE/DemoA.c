#include <limits.h>
#include <math.h>
#include <stdio.h>

void SandBox();

void Array2D()
{
    int map[5][5] = {
        {1, 5, 6, 7, 8},
        {2, 4, 6, 4, 9},
        {1, 5, 7, 4, 2},
        {2, 3, 4, 5, 5},
        {5, 2, 4, 1, 1}};

    int i = 0, j = 0;
    int res = map[i][j];

    while (1) {
        if (i == 4 && j == 4) break;
        else if (i == 4) j++;
        else if (j == 4) i++;
        else if (map[i + 1][j] >= map[i][j + 1]) j++;
        else i++;

        res += map[i][j];
    }

    printf("result: %d\n", res);
}

int main(void)
{
    Array2D();
    return 0;
}

void SandBox()
{
    // int n;
    // scanf("%d", &n);

    // int array[10001] = {
    //     0,
    // };

    // for (int i = 0; i < n; i++) {
    //     int temp;
    //     scanf("%d", &temp);
    //     array[temp] += 1;
    // }

    // for (int i = 0; i < 10001; i++) {
    //     if (array[i] == 0) continue;
    //     for (int j = 0; j < array[i]; j++) {
    //         printf("%d\n", i);
    //     }
    // }

    // return 0;

    // int a = 65534;

    // int num;
    // int count;
    // printf("10만 이상의 임의의 숫자를 입력하세요\n>> ");
    // scanf("%d", &num);
    // printf("\n");

    // // 워밍업 (10진수 분해)
    // printf("\n- ( %d ) -> 10진수로 워밍업 (분해)\n", num);
    // int _10 = num;
    // while (_10 != 0) {
    //     count = _10 % 10;
    //     _10 /= 10;
    //     printf("- %5d / 10\t=\t%d\n", _10, count);
    // }

    // // 본 게임 (2진수 분해)
    // printf("\n- ( %d ) -> 2진수로 만들기\n", num);

    // _10 = num;
    // while (_10 != 0) {
    //     count = _10 % 2;
    //     _10 /= 2;
    //     printf("- %5d / 2\t=%d\t\n", _10, count);
    // }

    // 0010 1111
    // 1101 0001
    // 32 + 15
    // double t = 0.14;
    // for (int i = 1; i <= 24; i++) {
    //     int a = (int)(t * pow(2, i)) % 2;
    //     printf("%d\n", a);
    // }

    // count = num % 10;
    // num /= 10;
    // printf("- %d\t%d\n", num, count);

    // count = num % 10;
    // num /= 10;
    // printf("- %d\t%d\n", num, count);

    // count = num % 10;
    // num /= 10;
    // printf("- %d\t%d\n", num, count);

    // count = num % 10;
    // num /= 10;
    // printf("- %d\t%d\n", num, count);

    /*
    - 위 코드는 10진수를 2진수로 만드는 과정 중에
    - 10진수를 2로 계속 나눈후 역순으로 조립하는 이유를 설명하기 위한 코드입니다.
    - 즉, 왜? 2로 나눈후 꺼꾸로 조립하면?
    - 2진수가 되나요에 대한 답...
    --> 계속 나누면, 캡처 와 같은 결과가 나오는데.
    --> 꺼꾸로 조립하면 본래의 숫자가 나오는 로직으로
    --> 10 이 아닌 2로 나누면 같은 맥락으로 10진수를 2진수로 변경한 알고리즘이 증명됨.

    - 숙제 예상?..
    -> 소수점 이하를 위와 같은 방식으로 직관할 수 있는 코드를 만들어 보세요..
     */

    // int th = 0;
    // int max = INT_MIN;
    // int ar[9];
    // for (int n = 0; n < 9; n++) {
    //     scanf("%d", &ar[n]);
    // }
    // int max = ar[0];
    // for (int n = 0; n < 9; n++) {
    //     if (max < ar[n]) { max = ar[n], th = n; }
    // }
    // printf("최대값: %d\n( %d ) 번째\n", max, th);
    // return 0;

    // int target;
    // printf("과세표준을 입력하세요: ");
    // scanf("%d", &target);
    // int tax = 0;
    // if (target <= 1000) {                         // ~ 1,000
    //     tax += target * 0.08;
    // } else if (target > 1000 && target <= 4000) { // 1,001 ~ 4000
    //     tax += 1000 * 0.08;
    //     tax += (target - 1000) * 0.17;
    // } else if (target > 4000 && target <= 8000) { // 4,001 ~ 8,000
    //     tax += 1000 * 0.08;
    //     tax += 3000 * 0.17;
    //     tax += (target - 4000) * 0.26;

    // } else if (500 > target > 100) {
    // } else { // 8,001 만원 이상
    //     tax += 1000 * 0.08;
    //     tax += 3000 * 0.17;
    //     tax += 4000 * 0.26;
    //     tax += (target - 8000) * 0.35;
    // }

    // printf("소득세는 %d만원 입니다.\n", tax);
    printf("Hi Everyone=> int convert to byte array\n");
    unsigned char bytes[4];
    unsigned long n = 339319;
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;

    printf("( %lX ) => { `%X - %X - %X - %X` }\n", n, bytes[0], bytes[1], bytes[2], bytes[3]);
}

// void Demo()
// {
//     // 목표
//     int number = -47;

//     // char bit => 8비트, int size => 4바이트, 그러므로 8 * 4 => 32비트
//     // 결국, 32 자릿수로 표현하려는 것으로, 꽤 먼가 있어 보이게 만드는 가식 넘치는 코드.
//     // 당당하게 8, 16, 32, 64 이넷중 하나로 하드 코딩 권장...
//     int i = CHAR_BIT * sizeof number;

//     // 타이를'
//     printf("\n( %d ) 2진수 변환 => ", number);

//     while (i--) { // 즉, 32 에서 0으로의 여정 시작.

//         // [*** 아래 한줄 코드 해석 ***]
//         // 0x30 의 정체 => '0' 아스키 코드넘버. 즉 30 과 0 아니면 1을 더하는 로직,
//         // 메모리에 있는 비트 그 것을 고대로 꺼집어 내는 것.
//         // 즉, number binary 를 오른쪽으로 i 만큼 shift 시킨후 1과 엔드 연산을 하면
//         // 그 비트 그대로 표현됨. 즉, 0 아니면, 1이므로.. 그것을
//         // 아스키 0 에 더하기를 하면 결국 0 아니면 1이 표현되는 로직...
//         putchar(0x30 + ((number >> i) & 1));

//         // 8개 1바이트 단위로 띄여 쓰기를 통한
//         // 모양내기 신공.
//         if (i % 8 == 0) {
//             putchar(' ');
//         }
//     }
//     // 마무리
//     printf("\n");
// }
