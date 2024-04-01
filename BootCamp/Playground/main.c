#include <errno.h>// for errno
#include <limits.h>// for INT_MAX, INT_MIN
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>// for strtol
#include <string.h>

void PrintBit(const long long num, const int size)
{
    printf("0b_");
    for (long long i = size - 1; i >= 0; --i) {
        printf("%lld", (num >> i) & 1);// 0011

        if (i != 0)// under bar insert, except last char
            printf("%s", i % 4 == 0 ? "_" : "");
    }
    printf(" ( %+lld ) \n", num);
}

void BitOperatorRunner()
{
    // 음수 중 가장 큰수 : -1
    // -2,147483,648 ~ 2,147,483,647

    int a = 0b1001 << 2;
    int b = 0b1001 >> 2;
    int c = 0b1001 | 2;
    int d = 0b1111 ^ 0b0000;// XOR 원래의 값
    int e = 0b1010 ^ 0b1111;// XOR 원래값의 반대값
    int f = 0b1010 ^ 0b1010;// XOR 자기 자신의 값 => 0으로 셋팅
    int g = 0b0101 & 0b1111;// & 원래의 값,
    int h = 0b10110101 >> 1;
    char be = 0b10110110;
    char ba = (char)(be >> 1);

    PrintBit(ba, 8);
    PrintBit(be, 8);
    PrintBit(h, 8);
    PrintBit(g, 32);
    PrintBit(a, 32);
    PrintBit(b, 32);
    PrintBit(c, 32);
    PrintBit(d, 32);
    PrintBit(e, 32);
    PrintBit(f, 32);
}

void ReadBit(int num, int cursor)
{
}

void StringCompress(char *text)
{
    int strLen = strlen(text);
    if (strLen < 2) return;

    char temp[strLen + 1];// 문자
    int counts[strLen + 1];// temp index 와 동일한 위치의 문자 반복횟수
    int counter = 0;// 반복횟수

    temp[counter] = text[0];
    int count = 1;

    for (int i = 1; i < strLen; i++) {
        if (text[i] == text[i - 1]) count++;
        counts[counter] = count;
        count = 1;
        temp[counter] = text[i];
        counter++;
    }
    temp[counter] = '\0';


    for (int i = 0; i < counter; i++) {
        printf("%c%d", temp[i], counts[i]);
    }
    puts("");
}

void BubbleSort(int *arr, int size)
{
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool GetBit(int index)
{
    // index 비트를 제외한 나머지 모두 0으로 셋팅.
    int a = 0b1101;
    return (a & (1 << index));
}

/// @brief Start Point
/// @param
/// @param
/// @return
int main(int argc, char **argv)
{
    short originNumber = 30;
    short target = -30;
    printf("\n*** 부호를 가지고 있는 signed short (%hi) 이진표현 ***\n", target);
    // -30 은 부호있는 short 에서는 변수의 범위 벗어 나지 않으므로
    // 음수의 일반적인 표기법인 2의 보수로 표현 하면됨.
    // => +30의 이진수 는 => 0b 0000 0000 0001 1110 이므로
    // => -30의 이진수 는 => 0b 1111 1111 1110 0010 (2의 보수)

    printf("[ ( %hu )을 ( %hi )로 만들어 가는 여정 ]\n(1) 원래의 수 +30\t=>\t", originNumber, target);
    PrintBit(30, 16);// (1) 30 원래의 수
    printf("(2) +30의 1의 보수\t=>\t");
    PrintBit(~30, 16);// (2) 30에 대한 1의 보수의
    printf("(3) +30의 2의 보수\t=>\t");
    PrintBit((~30) + 0b1, 16);// (3) 30 에 대한 2의 보수
    printf("(4) -30의 비트 (답)\t=>\t");
    PrintBit(target, 16);// (재 검증) 출력 확인 파트, 위 3번과 같은 지 확인하기..


    return 0;
    printf("\n[ (2) 부호가 없는 signed short (-30) 이진표현 ]\n");
    // 부호가 없는 변수에 부호가 있으니 원래의 양의 정수로 표현하려면?
    // 사람이 알기 쉽게, 2의 보수가 아닌.. 주먹 이진화 십진수로 계산하면?.
    // -30의 short 의 최대값 65536 의 보수(65536 - 30, 2진수 2의 보수와 같은 개념..)를 구하면
    // 65506 이 나오므로.그 65506을 그대로이진수로 표현 하면 됨..
    // 그래서 ..
    unsigned short num2 = target;
    PrintBit(num2, 16);// 출력 확인 파트
    printf("\n---------------------------------------------------------------------------\n");
    // 기타 참고 사항 들 //
    printf("\n*** 이진 표현에 대한 이해를 돕기 위한 코드 조각들.. (참조 용) ***\n");
    printf("\n[ 부호를 가지고 있는 signed short (short 음수의 최소값, -32,768) 이진표현 (%hi)]\n", SHRT_MIN);

    PrintBit(SHRT_MIN, 16);
    printf("\n[ 부호를 가지고 있는 signed short (short 음수의 최대값, -1) 이진표현 (%hi) ]\n", SHRT_MAX);

    short _1 = -1;
    PrintBit(_1, 16);


    printf("\n[ 부호가 없는 unsigned short (unsigned 의 최대값 이진표현, (%hu) ]\n", USHRT_MAX);
    PrintBit(SHRT_MAX, 16);
    printf("\n");

    // [ 기타 참조 용 테스트 코드 ]
    // 변수 범위를 초가하는 숫자를 할당하여, 코드 오버플로 발생시!
    // 실제 비트가 어떻게 순회가 되는지 확인하는 파트
    printf("\n[ 부호 없는 짧은 8비트 정수의 최대값(65,535)을 넘어서는 오바플로 발생시 일어나는 비트 처리 현황 (65535 ~ + 16개 출력) ]\n");
    for (size_t i = 1; i <= 16; i++) {
        unsigned int title = USHRT_MAX + i;
        unsigned short overflow = USHRT_MAX;
        overflow += i;
        printf("(%2d) => ", title);
        PrintBit(overflow, 16);
    }

    return 0;
    printf("Hello Fine World");

    //
    if (argc > 0) {

        char *p;
        int num;
        errno = 0;
        long conv = strtol(argv[1], &p, 10);

        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv > INT_MIN) {
            // Put here the handling of the error, like exiting the program with an erro message
            return errno;
        }

        num = conv;

        printf("num => %d\n", num);
        switch (num) {
            case 1: printf("Hello, World %d\n", num); break;

            default:
                break;
        }


        // for (int i = 0; i < argc; i++) {
        //     printf("%3d =>\t%s\n", i, argv[i]);
        // }
    }

    return 0;
    // switch (argv[1])
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }
    // printf("Started..\n");
    // BitOperatorRunner();
    // GetBit(3);// 3번째 비트가 0 인지 1인지 판단하기
    // return 0;
}


/*
상수	의미	값
CHAR_BIT	비트 필드가 없는 가장 작은 변수의 비트 수입니다.	8
SCHAR_MIN	signed char 형식 변수의 최소값입니다.	-128
SCHAR_MAX	signed char 형식 변수의 최대값입니다.	127
UCHAR_MAX	unsigned char 형식 변수의 최대값입니다.	255(0Xff)
CHAR_MIN	char 형식 변수의 최소값입니다.	–128, /J 옵션이 사용된 경우 0
CHAR_MAX	char 형식 변수의 최대값입니다.	127, /J 옵션이 사용된 경우, 255
MB_LEN_MAX	멀티바이트 문자의 최대 바이트 수입니다.	5
SHRT_MIN	short 형식 변수의 최소값입니다.	-32768
SHRT_MAX	short 형식 변수의 최대값입니다.	32767
USHRT_MAX	unsigned short 형식 변수의 최대값입니다.	65535(0xffff)
INT_MIN	int 형식 변수의 최소값입니다.	-2147483647 - 1
INT_MAX	int 형식 변수의 최대값입니다.	2147483647
UINT_MAX	unsigned int 형식 변수의 최대값입니다.	4294967295(0xffffffff)
LONG_MIN	long 형식 변수의 최소값입니다.	-2147483647 - 1
LONG_MAX	long 형식 변수의 최대값입니다.	2147483647
ULONG_MAX	unsigned long 형식 변수의 최대값입니다.	4294967295(0xffffffff)
LLONG_MIN	long long 형식 변수의 최소값입니다.	-9,223,372,036,854,775,807 - 1
LLONG_MAX	long long 형식 변수의 최대값입니다.	9,223,372,036,854,775,807
ULLONG_MAX	unsigned long long 형식 변수의 최대값입니다.	18,446,744,073,709,551,615 (0xffffffffffffffff)

 */
