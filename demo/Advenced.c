#include "../headers/vivstd.h"

/// @brief 비트 프린트
/// @param bits
void PrintBitsArray(char bits)
{
    for (int i = 8 - 1; i >= 0; --i) {
        char bit = (bits & (1 << i)) > 0 ? '1' : '0';
        printf("%c%c", ((i + 1) % 4 == 0 ? ' ' : '\0'), bit);
    }
}

void LoopChar()
{
    unsigned int n;
    char ch;
    bool check;
    do {// 오류 검출 (숫자 또는 알파벳 범위 내)
        fflush(stdin);
        printf("시작문자 입력하세요 : ");
        check = scanf("%c", &ch);
        fflush(stdin);
        printf("%c 부터 출력할 문자 수를 입력하세요 : ", ch);
        check = scanf("%d", &n);
        check = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    } while (!check);

    int i, k = 0;
    char cs[n];

    for (i = ch; i < INT_MAX; i++) {
        if (n == 0) break;
        if (i == 123) {
            i = 96;
            continue;
        };
        if (i == 91) {
            i = 64;
            continue;
        }
        printf("%c ", i);
        cs[k++] = i;
        n--;
    }
    printf("\n");
    for (size_t i = 0; i < sizeof(cs); i++) {
        char temp[sizeof(cs) - i];
        strncpy(temp, cs, sizeof(cs) - i);
        temp[sizeof(cs) - i] = '\0';
        printf("%s\n", temp);
    }
    for (int i = sizeof(cs) - 2; i >= 0; --i) {
        char temp[sizeof(cs) - i];
        strncpy(temp, cs, sizeof(cs) - i);
        temp[sizeof(cs) - i] = '\0';
        printf("%s\n", temp);
    }
}

void Pattern()
{

    char ch = 'A';
    unsigned int n = 5;
}

void PyramidA()
{
    char start;
    int line;
    int i, j;

    scanf("%c", &start);
    scanf("%d", &line);

    for (i = line - 1; i > -line; i--) {
        for (j = 0; j < line; j++) {
            if (i >= j || i <= -j) {
                printf("%c", start + j);
            }
        }
        printf("\n");
    }
}

//* 출력결과 *//
// 시작문자 입력하세요 :  X
// X 부터 출력할 문자 수를 입력하세요 : 10
// X Y Z A B C D E F G

// 시작문자 입력하세요 :  k
// k 부터 출력할 문자 수를 입력하세요 : 100
// k l m n o p q r s t u v w x y z a b c d e f g h i j k l m n o p q r s t u v w x y z a b c d e f g h i j k l m n o p q r s t u v w x y z a b c d e f g h i j k l m n o p q r s t u v w x y z a b c d e f

/// @brief (62) 기타
void Advenced()
{
    // LoopChar();
    PyramidA();
    printf("\n***** 시프트 연산자 *****\n");
    // 연산자 우선순위가 낮아 괄호로 사용함
    unsigned short data = 0x01;
    for (size_t i = 0; i < 8; i++) {
        printf("Left : %d\n", data << i);
    }

    printf("\n");


    unsigned short max = 0x8000;
    for (size_t i = 0; i < 8; i++) {
        printf("Right : %d\n", max >> i);
    }

    // 3 * 4 + 5 * 8
    printf("Text %d\n", (3 << 2) + (5 << 3));

    //!
    printf("Text %08d\n", 1);
    printf("Text %#x\n", 0xFF11);

    //! `sprintf` 배열에 형식 문자열 저장
    char sprn[128];
    sprintf(sprn, "%d + %d = %d", 14, 45, 14 + 45);
    printf("%s\n", sprn);

    //! `fprintf` 파일에 형식 문자열 저장

    FILE *fp = fopen("fprintf.txt", "w");
    fprintf(fp, "%d + %d = %d", 45, 83, 45 + 83);
    fclose(fp);

    //! `clock` 수행시간 채크하기
    double start, end;

    // for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;

    // for루프 100000000번 돌아보기
    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum++;
    }
    // for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end - start));

    // bit 연산
    printf("\n***** 비트 연산 *****\n");
    int bits1 = 0b10110110;
    int bits2 = 0b01101101;
    printf("\nPrint Bits1\n");
    printf("bits1\t\t");
    PrintBitsArray(bits1);
    printf("\n");
    printf("bits2\t\t");
    PrintBitsArray(bits2);
    printf("\n\n");
    printf("~bits1\t\t");
    PrintBitsArray(~bits1);
    printf("\n");
    printf("bits1 | bits2\t");
    PrintBitsArray(bits1 | bits2);
    printf("\n");
    printf("bits1 ^ bits2\t");
    PrintBitsArray(bits1 ^ bits2);
    // 1001 ^ 0100 = 1101, (9 ^ 4) = 13
    PrintBitsArray(0b1001 ^ 0b0100);
    PrintBitsArray(9 ^ 4);

    printf("\n\n");

    printf("8 | 5\t\t");
    PrintBitsArray(24 | 4);

    printf("\n");
    printf("%d", (24 | 56));
    printf("\n");
    char b1 = 0b00000001;
    char b2 = 0b00001000;
    printf("%d", b1 | b2);
    printf("\n");
    unsigned int num = 52;
    printf("%d -> 2진수 : ", num);
    for (int i = 7; i >= 0; --i) {
        printf("%d", num >> i & 1);
    }
    printf("\n");
}

/// @brief 특수사항
void Etc()
{
    //? case 1
    // int or unsigned int or unsigned long == ?; unsigned vs signed
    // 정수크기를 비교할 때 sizeof 는 부호 없는 유형을 반환함
    // 부호 없는 정수와 부호 있는 정수중에서 선택해야 함
    // -1 as an unsigned value is 0xFFFFFFFFFFFFFFFF
    // 4 > 0xFFFFFFFFFFFFFFFF 이런 결과로서 false 를 반환함
    // 동일하지 않은 데이터 유형끼리의 비교시 -1 정수인지 long 인지에 따라
    // FFFF.... 로 인식 항상 거짓이 됨
    if (sizeof(int) > -1) {
        printf("True");
    } else {
        printf("False");
    }
    printf("\n");

    //? case 2
    // C 언어는 Double 선호도에 따라
    // 0.1 은 Double data-type
    // 데이터 비교는 동일한 데이터 타입이어야 함으로
    // f 를 두배의 정밀도로 올리면서 값이 달라지게됨으로
    // 거짓을 반환함
    float f = 0.1;
    if (f == 0.1) {
        printf("True");
    } else {
        printf("False");
    }

    printf("\n");

    //? case 3
    // 런타임에서는 사이즈 추론으로
    // 타입만 보고 실제 괄호안에는 진입하지 않음으로 b, c 는 변하지 않음
    // 결과적으로 a = 4; b = 그대로 1, c 역시 1을 반환하고 끝남
    int a, b = 1, c = 1;
    a = sizeof(c = ++b + 1);// b = 2; c = 3; 을 기대하나?
    // 결과는 -> (a = 4, b = 1, c = 1;)
    printf("a= %d, b = %d, c = %d\n", a, b, c);

    //? case 4
    // Segmentation fault (core dump)
    // 메모리 0번이지 널이 아님으로 이런식으로 초기화 하면안됨
    char *p = 0;
    *p = 'A';
    printf("Value at p = %c\n", *p);

    // case 5
    int k = 1, pp = 3, t = 2;
    if (k > pp) {
        if (pp > t)
            printf("k > pp and pp > t\n");
        else
            printf("Something else\n");
    }
}
