#include "../headers/vivstd.h"
#include <stdio.h>
#include <string.h>

/// @brief Float Convert to Binary
/// @param num 
void FloatToBinary(float num)
{
    int exp, sign;
    float mantissa = frexpf(num, &exp);// 가수부와 지수부 계산
    if (num < 0) {
        sign = 1;// 음수 처리
        mantissa = -mantissa;
    } else {
        sign = 0;// 양수 처리
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
}

/// @brief Binary Convert to Decimal
/// @param binary 
void BinaryToDecimal(char *binary) {
    // 2진수 -> 10진수 변환
    char *endptr;
    long int value = strtol(binary, &endptr, 2);
    printf("%ld\n", value);
}

/// @brief 각종 진수 변환기
void NumberReal()
{

    double temp = 3.14159;
    double *ptr = &temp;

    char *byte_ptr = (char *)ptr;
    printf("\nPrint Binary %lf\n", temp);
    printf("\n");
    for (int i = sizeof(double) - 1; i >= 0; --i) {
        PrintBinary(byte_ptr[i]);
        putchar(' ');
    }

    putchar('\n');
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
}

    /* double ( 8byte * 8 = 64bit 메모리 기록 견본)
              4   0   8         0     00       00       00       00        00      00
        0    100 00001000     0000 00000000 00000000 00000000 000000000 00000000 00000000
        ^    ------------     ----------------------------------------------------------
        |
       sign  exponent = 2^9   mantissa with implicit high bit = 1 (normal)

    e.g. 3.14159 -> 11 -> 1.1 * 2^1
    1023(double bias) + 1 (exponet) = 1024(지수부, 100 0000 0000)
    01000000 0000   10010010000111111001 11110000 00011011 10000110 01101110
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
