#include "../headers/vivstd.h"
#include <stdio.h>
#include <string.h>

/// @brief Float Convert to Binary
/// @param num
void FloatToBinary(float num)
{
    int exp, sign;
    float mantissa = frexpf(num, &exp); // 가수부와 지수부 계산
    if (num < 0) {
        sign = 1;                       // 음수 처리
        mantissa = -mantissa;
    } else {
        sign = 0;                       // 양수 처리
    }
    printf("실수 값 %f의 2진수 표현: %d ", num, sign);
    for (int i = FLT_MANT_DIG - 1; i >= 0; i--) {
        mantissa *= 2;
        if (mantissa >= 1) {
            printf("1");
            mantissa -= 1;
        } else {
            printf("0");
        }
    }
    printf(" x 2^%d\n", exp - 1);
}

/// @brief Memory Bit Reverse
/// @param str
void Reverse(char *str)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
/// @brief With Pointer Print Binary
/// @param byte
void PrintBinary(char byte)
{
    for (int i = 7; i >= 0; i--) {
        putchar((byte & (1 << i)) ? '1' : '0');
    }
    // `byte & (1 << i)`는 `byte` 변수의 `i`번째 비트를 추출하는 연산입니다.
    // 이 연산은 다음과 같은 과정으로 이루어집니다.
    // `1`을 `i`번 만큼 왼쪽으로 시프트합니다.
    // 시프트 연산자 `<<` 는 이진수를 왼쪽으로 이동시키는 연산을 수행합니다.
    // 예를 들어, `1 << 3`은 이진수 `00000001`을 왼쪽으로 세 번 이동하여 `00001000`을 생성합니다.
    // `byte` 변수와 위에서 생성한 이진수를 비트단위로 논리곱 연산(`&`)을 수행합니다.
    // 논리곱 연산은 두 비트가 모두 1일 때 1을 반환합니다.
    // 즉, `byte` 변수에서 `i`번째 비트가 1인지 0인지 추출하는 것입니다.
    // 따라서, `byte & (1 << i)` 연산의 결과는 0 또는 1이 됩니다.
    // 예를 들어, `byte` 변수가 `0xA5` (이진수로 `10100101`)인 경우,
    // `byte & (1 << 2)` 연산은 `0x04` (이진수로 `00000100`)을 반환합니다.
    // 이는 `byte` 변수의 2번째 비트가 1인지 아닌지를 확인하는 것입니다.
}

/// @brief Binary Convert to Decimal
/// @param binary
void BinaryToDecimal(char *binary)
{
    // 2진수 -> 10진수 변환
    char *endptr;
    long int value = strtol(binary, &endptr, 2);
    printf("%ld\n", value);
}

long DecimalConvertToBinary(long *binary)
{
    long num, i = 0;
    // binary[64]

    printf("\n");
    printf("\n2진수로 변환할 10진수를 입력하세요: ");
    scanf("%ld", &num);

    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("2진수: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    return i;
}

/// @brief 2의 보수
void ConvertToComplement()
{
    int num, comp;
    printf("\n");
    printf("2의 보수를 취할 숫자를 입력하세요: ");
    scanf("%d", &num);

    // 1의 보수 변환
    comp = ~num;

    // 2의 보수 변환
    comp = comp + 1;

    printf("%d의 2의 보수는 %d입니다.", num, comp);
}

void BinConvertToComplement(int *bin, int size)
{
    int i, carry = 1;
    int comp[size];
    // 1의 보수 계산
    for (i = size - 1; i >= 0; i--) {
        if (bin[i] == 0) {
            comp[i] = 1;
        } else {
            comp[i] = 0;
        }
    }

    // 2의 보수 계산
    for (i = size - 1; i >= 0; i--) {
        if (comp[i] == 1 && carry == 1) {
            comp[i] = 0;
        } else if (comp[i] == 0 && carry == 1) {
            comp[i] = 1;
            carry = 0;
        }
    }
    printf("\n");

    // 2의 보수 출력기
    for (size_t i = 0; i < size; i++) {
        printf("%d", comp[i]);
        printf("%d", comp[i]);
    }
}

/// @brief 각종 진수 변환기
void NumberReal()
{
    double dbl = 3.14159;
    double *ptr = &dbl;

    char *byte_ptr = (char *)ptr;
    printf("\nPrint Binary %lf\n", dbl);
    printf("\n");
    for (int i = sizeof(double) - 1; i >= 0; --i) {
        PrintBinary(byte_ptr[i]);
        putchar(' ');
    }
    printf("\n");

    float number;
    printf("2진수로 변환할 실수(float)를 입력하세요 >> ");
    fflush(stdin);
    scanf("%f", &number);
    FloatToBinary(number);
    printf("\n");

    char str[65];
    printf("10진수로 변환할 2진수 (64비트 이내)를 입력하세요 >> ");
    fflush(stdin);
    scanf("%s", str);
    BinaryToDecimal(str);

    // 비트연산 후 비트 출력
    char temp[12 + 1] = "101010101010";
    printf("temp check bits %s\nsize of temp : %d\n", temp, sizeof(temp));
    printf("\n");
    for (size_t i = 0; i < sizeof(temp) - 1; i++) {
        putchar((temp[i] & (1 << 0)) ? '1' : '0');
    }
    long binary[64];
    int i = DecimalConvertToBinary(binary);
    printf("\n");

    int c[i];
    int t = 0;
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
        c[t++] = binary[j];
    }

    BinConvertToComplement(c, i);
    // ConvertToComplement();
}

/* double ( 8byte * 8 = 64bit 메모리 기록 견본)
          4   0   8         0     00       00       00       00        00      00
    0    100 00001000     0000 00000000 00000000 00000000 000000000 00000000 00000000
    ^    ------------     ----------------------------------------------------------
    |
   sign  exponent = 2^9   mantissa with implicit high bit = 1 (normal)

e.g. 3.14159 -> 11 -> 1.1 * 2^1
1023(double bias) + 1 (exponet) = 1024(지수부, 100 0000 0000)
0 100 0000 0000   10010010000111111001 11110000 00011011 10000110 01101110
0.14159 * 2 = 0.28318  --> 0
0.28318 * 2 = 0.56636  --> 0
0.56636 * 2 = 1.13272  --> 1
0.13272 * 2 = 0.26544  --> 0
0.26544 * 2 = 0.53088  --> 0
0.53088 * 2 = 1.06176  --> 1
0.06176 * 2 = 0.12352  --> 0
0.12352 * 2 = 0.24704  --> 0
0.24704 * 2 = 0.49408  --> 0
0.49408 * 2 = 0.98816  --> 0
0.98816 * 2 = 1.97632  --> 1
0.97632 * 2 = 1.95264  --> 1
0.95264 * 2 = 1.90528  --> 1
0.90528 * 2 = 1.81056  --> 1
0.81056 * 2 = 1.62112  --> 1
0.62112 * 2 = 1.24224  --> 1
0.24224 * 2 = 0.48448  --> 0
0.48448 * 2 = 0.96896  --> 0
0.96896 * 2 = 1.93792  --> 1
0.93792 * 2 = 1.87584  --> 1
0.87584 * 2 = 1.75168  --> 1
0.75168 * 2 = 1.50336  --> 1
0.50336 * 2 = 1.00672  --> 1
0.00672 * 2 = 0.01344  --> 0
0.01344 * 2 = 0.02688  --> 0
0.02688 * 2 = 0.05376  --> 0
0.05376 * 2 = 0.10752  --> 0
0.10752 * 2 = 0.21504  --> 0
0.21504 * 2 = 0.43008  --> 0
0.43008 * 2 = 0.86016  --> 0
0.86016 * 2 = 1.72032  --> 1
0.72032 * 2 = 1.44064  --> 1
0.44064 * 2 = 0.88128  --> 0
0.88128 * 2 = 1.76256  --> 1
*/
