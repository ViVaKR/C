#include "../headers/vivstd.h"


/// @brief Decimal To Hexa
/// @param decimal 
void DecimalToHexa(int decimal)
{
    int quotient, remainder, i = 1, j;
    char hexadecimal[100];

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimal[i++] = remainder + 48;
        else
            hexadecimal[i++] = remainder + 55;

        quotient = quotient / 16;
    }

    printf("16진수로 변환한 값: ");

    for (j = i - 1; j > 0; j--)
        printf("%c", hexadecimal[j]);

    printf("\n");
}

/// @brief Hexa Convert to Decimal
/// @param hexadecimal 
void HexaToDecimal(char hexadecimal[])
{
    int length, decimal = 0, i, digit;
    length = strlen(hexadecimal);
    length--;

    for (i = 0; hexadecimal[i] != '\0'; i++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
            digit = hexadecimal[i] - '0';
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
            digit = hexadecimal[i] - 'a' + 10;
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
            digit = hexadecimal[i] - 'A' + 10;

        decimal += digit * pow(16, length);
        length--;
    }

    printf("10진수로 변환한 값: %d\n", decimal);
}

void HexerAndDecimal()
{
    int decimal;
    printf("10진수를 입력하세요: ");
    scanf("%d", &decimal);
    DecimalToHexa(decimal);

    char hexadecimal[100];
    printf("16진수를 입력하세요: ");
    scanf("%s", hexadecimal);
    HexaToDecimal(hexadecimal);
}

/// @brief Ref. Bro Code
void ArithmeticOperators()
{
    printf("\n");
    printf("***** 산술연산자 (Arithmetic Operators) *****");
    /* [ 산술연산자 (Arithmetic Operators) ]
        +   덧셈 (addition)
        -   뺄셈 (subtraction)
        *   곱셈 (multiplication)
        /   나눗셈 (division)
        %   나머지 (modulus)
        ++  증가 (increment)
        --  감소 (decrement)
     */

    /* 증감 연산자
        전위식 : ++A (A = A + 1), --A (A = A - 1)
        후위식 : A++, A-- (세미콜론이 지난후 처리)
    */
    printf("\n");

    int nVar1 = 7, nVar2 = 8, nVar3;
    nVar3 = ++nVar1 + nVar2;
    printf("++nVar1 + nVar2 =  %d\n", nVar3);// 8 + 8 = 16

    nVar3 = nVar1++ + nVar2;
    printf("nVar1++ + nVar2 = %d\n", nVar3);// 16
    nVar3 = nVar1 + nVar2;
    printf("nVar1++ + nVar2 = %d\n", nVar3);// 17

    //= 관계 (비교) 연산자 =// : 비교의 결과는 항상 0 (false)과 1 (true)이다.
    printf("nVar1(%d) == nVar2(%d) -> ( %s ), \n", nVar1, nVar2, nVar1 == nVar2 ? "true" : "false");

    //= 논리 연산자 =//
    // And : && (모두 1 일때 true)
    // Or : || (둘 중 하나가 1일 때 true)
    // Not : !
    // true (1)  : 0 이외의 값
    // false (0) : 0
    printf("0 || -1 = %d, 4 || 20 = %d, 0 || 0 = %d\n", 0 || -1, 4 || 20, 0 || 0);
    printf("!-1 = %d\n", !-1);// 0
    printf("!4 = %d\n", !4);// 0
    printf("!0 = %d\n", !0);// 1

    //= 비트 연산자 (bitwise operator, 이미지 처리에 주로 사용됨) =//
    // & : and (둘다 1일 때 1)
    // | : or (둘 중 하나만 1일 때 1)
    // ~ : not
    // xor (^): 피연산자 비트값이 같으면 0, 다르면 1
    // <<, >> : 비트이동, 7 << 2 or 7 >> 2
    printf("~2 = %08d\n", ~2);// not 0010 -> 1101
    printf("\n\nxor 같으면 0, 다르면 1\n(1 ^ 1) = %d, 1 ^ 0 = %d\n\n", 1 ^ 1, 1 ^ 0);// xor
    printf("1 << 2 = %d\n", 1 << 2);// 0000 0001 의 1을 왼쪽으로 2칸 이동 0000 0100
    printf("4 >> 1 = %d\n", 4 >> 1);// 0000 0100 을 오른쪽으로 1칸 이동 0000 0010

    //= 형변환 연산자 =//
    // (데이터형)변수/상수;
    // 메모리 크기와 데이터 허용 범위 고려하여야 함

    //= 연산사 우선순위 =//
    // 운선순위를 믿기 보다는 괄호를 사용하여 확실히 하여야 함
    int result = 2 * 6 + 4 * 9 / 3;// 12 + 12 = 24
    printf("2 * 6 + 4 * 9 / 3 = %d\n", result);

    // 라이브러리 함수는 기본 프로그램 코드와 별도로 컴파일됨
    // 컴파일러는 각 함수에 대한 기계어 코드를 별도로 생성하며
    // 함수는 주 프로그램의 컨텍스트를 인식하지 못함
    // 따라서 주 프로그램에서 변수의 메모리 위치에 대한 컴파일러 정보에 직접 액세스할 수 없음
    // 함수가 변수으 메모리 위칭 액세스하는 유일한 방법은 해당 메모리 위치를 가리키는
    // 포인터를 사용하는 것
    // 라이브러리 함수와 마찬가지로 자체 함수도 기본 프로그램 코드와 별도로 컴파일됨
    // 이는 컴파일락 각 기능에 대한 개체 코들르 개별적으로 생성한 다음
    // 이를 함께 연결하여 최종 실행 가능한 프로그램을 생성함을 의미함

    // printf 는 변수명만 사용하는데 scanf 는 변수의 주소를 전달하는 이유
    // scanf 함수는 포맷 스트링과 함께 입력 받을 데이터가 저장될 변수의 주소를 전달하는 함수입니다.이 때 포맷 스트링에는 입력할 데이터의 형식을 지정해주는 서식 지정자가 사용됩니다.
    // 따라서, printf 함수에서는 변수의 값을 출력할 뿐이기 때문에 변수명만을 사용하면 되지만,
    // scanf 함수에서는 변수의 주소를 전달해야 합니다.
    // 이를 위해서는 변수 앞에 ampersand(&) 를 붙여 변수의 주소를  전달해야 합니다.

    // int a;
    // scanf("%d", &a);

    //[철수] 101호  -> 메모리 공간의 주소
    //[영희] 201호
    //[민수] 301호
    int 철수 = 1;// 암호
    int 영희 = 2;
    int 민수 = 3;

    printf("철수네 주소 : %p, %ld, %x  암호: %d\n", &철수, &철수, &철수, 철수);
    printf("영희네 주소 : %p, %ld, %x  암호: %d\n", &영희, &영희, &영희, 영희);
    printf("민수네 주소 : %p, %ld, %x  암호: %d\n", &민수, &민수, &민수, 민수);

    int z = -25;
    // 부호화 2의 보수
    // 0001 1001 -> 1110 0111 (E7, 부호)

    printf("z = %p - %8x\n", &z, z);

    HexerAndDecimal();
}

// 0x7ffeefbff4a0

// memory read -s1 -fu -c10000 7ffeefbff4a0 --force
// me read -c4 0x7ffeefbff4a0
// 1111
