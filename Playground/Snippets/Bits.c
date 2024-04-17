#include "../../headers/vivstd.h"

/// @brief 비트확인 & (And 연산)
/// @param num 확인할 정수
/// @param i 시프트할 자릿수
/// @return true = 1, false = 0
int GetBits(int num, int i)
{
    return (num & (1 << i)) != 0;
}

/// @brief 프린트 비트
/// @param num
/// @param size
void PrintBits(int num, int size)
{
    for (int i = size - 1; i >= 0; --i)
        printf("%d%c", (num >> i) & 1, (i % 4 == 0) ? ' ' : '\0');
}

/// @brief 비트값변경 | (OR 연산)
/// @param num
/// @param i
/// @return
int SetBit(int num, int i)
{
    return (num | (1 << i));
}

/// @brief 특정 비트를 0으로 만들기 &, ~ (And, Not 연산)
/// @param num 변경할 숫자
/// @param i 0 으로 만들 비트
/// @return 변경된 int 정수
int ClearBits(int num, int i)
{
    return ((num & (~(1 << i))));
}

/// @brief 지정한 인덱스 왼쪽을 모두 0으로, 오른쪽은 그대로
/// @param num 원본 숫자
/// @param i 지정한 인덱스 번호
/// @return 정수 결과값
int ClearLeftBits(int num, int i)
{
    return (num & ((1 << i) - 1));
}

/// @brief 지정한 인덱스 오른쪽을 모두 0으로 변경하기, 왼쪽은 그대로
/// @param num 원본 숫자
/// @param i 인덱스 번호
/// @return 정수 결과값
int ClearRightBits(int num, int i)
{
    return (num & (-1 << (i + 1)));
}

/// @brief 해당비트만 업데이트 하기
/// @param num 원본
/// @param i 변경할 인덱스
/// @param value 변경할 값
/// @return
int UpdateBit(int num, int i, bool value)
{
    // 인덱스만 제외하고 모두 1로 설정하기
    // -> 0b11111111111111111111111111110111
    return (num & ~(1 << i)) | ((value ? 1 : 0) << i);
    // int mask = ~(1 << i);
    // int first = (num & mask);
    // return (first | ((value ? 1 : 0)) << i);
}

void ConvertToBinary(int n)
{
    printf("\n");
    printf("10진수 ( %d ) -> 2진수 변환\n", n);

    for (int i = 31; i >= 0; --i) {
        printf("%d%c", (n >> i) & 1, i % 4 == 0 ? ' ' : '\0');
    }
    printf("\n");
}

/// @brief (63) 비트연산
void Bits()
{
    printf("\n***** 비트연산 *****\n");
    printf("\n");

    printf("\n***** 숫자 52의 비트 확인하기 (1) *****\n");
    PrintBits(52, 32);// 0011 0100
    printf("\n");

    printf("\n***** 숫자 52의 비트 확인하기 (2) *****\n");
    // And (&) + Left Shift Step 1 연산 :
    // 1 이면 1, 0 이면 0을 반환하는 속성을 이용
    //  9 = 1001
    for (int i = 31; i >= 0; --i) {
        printf("%d%c", GetBits(52, i), i % 4 == 0 ? ' ' : '\0');
    }
    printf("\n");


    printf("\n***** Set Bit비트 값 1로 변경, OR (|) 연산 %d *****\n", 0b0101);
    // 5 = 0101
    // After Change = 1101 (13)
    int t1 = SetBit(5, 3);
    PrintBits(t1, 32);
    printf("\n");
    ConvertToBinary(-8 << 3);
    // printf("(%d | 1 << 3) Change To %d\n", 5, SetBit(5, 3));

    printf("\n***** Clear Bit 해당비트를 0으로 변경, NOT (~) 연산 *****\n");
    // int num = 9, i = 3
    // 나머지는 그대로 두고, 해당 인덱스만 0으로 변경하기
    // 해당 자리는 0으로 만들고 나머지는 1로 만들어서 & 연산을 하는 알고리즘

    // 1 0 0 0 은 (1 << 3) 으로 만들수 있으나
    // 필요한 것은 0 1 1 1 이므로
    // 앞에 NOT ~ 1 0 0 0 을 붙이면 0 1 1 1 을 만들면 됨
    // 9 = 1001, 3번째 비트를 0으로 변경, result 1
    printf("(%d & ~(1 << 3)) = %d\n", 9, ClearBits(9, 3));

    //* 지정한 인덱스 왼쪽 비트를 모두 0으로 변경하기 *//
    printf("\n***** 지정한 인덱스 왼쪽 비트를 모두 0으로 변경하기 *****\n");
    // 해당 인덱스는 0으로 하고
    // 해당 인덱스 오른쪽은 모두 1로 설정한 후
    // (&) and 연산을 시행하면
    // 왼쪽은 0, 오른쪽은 원래의 값 그대로를 유지함

    // 1000 (인덱스 위치 만큼의 크기) - 1 = 0111, 즉 원본에 1을 빼면 비트가 모두 뒤바뀌는 마스크를 사용
    // 1000을 만드는 방법 (1 << 3)
    // 0111을 만드는 방법 ((1 << 3) -1)

    int num = 169;
    //  1      0   1    0    1 0 0 1
    //  128   64  32   16    8     1
    //  128 + 32 + 8 + 1 (169)
    int i = 3;
    // 169 : 10101001 -> 1
    int result = ClearLeftBits(num, i);
    printf("(%d & ((1 < %d) - 1)) = %d\n", num, i, result);

    //* 지정한 인덱스 오른쪽 비트를 모두 0으로 변경하기 *//
    printf("\n***** 지정한 인덱스 오른쪽 비트를 모두 0으로 변경하기 *****\n");
    // 마스크 : 인덱스를 포함한 오른쪽 = 0, 왼쪽은 1로 설정하고 & (AND) 연산을 수행하면됨
    // 힌트 : 모든 비트를 1로 만드는 것은 = -1
    // 인덱스 다음 부터 -1 을 Shift (-1 << (3 + 1)) 를 수행하면 : xxx(인덱스0)0000
    // 원본과 & (And) 연산을 수행
    // int num = 169, i = 3;
    num = 169, i = 3;

    // -1 << index, 마스크 테스트
    int temp = 0;// before -> 0b00000000000000000000000000000000
    temp = (-1 << (4));// after -> 0b11111111111111111111111111110000

    // before -> 0b00000000000000000000000010101001
    // mask   -> 0b11111111111111111111111111110000
    // & num  -> 0b00000000000000000000000010100000
    result = ClearRightBits(num, i);
    printf("(%d & (-1 << (%d + 1))) = %d\n", num, i, result);


    //* Update Bits 해당 비트만 값을 변경하기*//
    printf("\n***** Update Bit 해당비트만 값을 지정한 값으로 변경하기 *****\n");
    // 원본  : x x x x x x x
    // 마스크 (1) : (And) 1 1 1 0 1 1 1
    // 결과   (1) : x x x 0 x x x
    // 마스크 (2) : (Or) 0 0 0 value 0 0 0
    // 결과   (2) : x x x value x x x

    num = 169, i = 3;
    bool value = false;
    // false = 161, true = 169
    printf("Update Bit (%d | ((%d ? 1 : 0) << %d)) = %d\n", num, value, i, UpdateBit(num, i, value));
}

// 메모리에 기록된 2진수 값 출력하기
// $ p &num
// (int *) $0 = 0x00007ffeefbff4b0
// $ memory read -s4 -fb -c1 0x00007ffeefbff4b0
// result -> 0x7ffeefbff4b0: 0b00000000000000000000000010101001

/*
    1. -s는 바이트 그룹화이므로 예를 들어 uint8의 경우 1을 사용하고 int의 경우 4를 사용하십시오.
    2. -f 형식입니다. 나는 본질적으로 올바른 기호를 잊어 버립니다.
        명령문에 -f를 입력하면 모든 옵션 목록이 표시됩니다.
    3. -c는 바이트 수입니다. 1024바이트 이상 인쇄하는 경우 --force를 추가하십시오.
 */

// p &variable
// p variable

/*
'B' or "boolean"
'b' or "binary"
'y' or "bytes"
'Y' or "bytes with ASCII"
'c' or "character"
'C' or "printable character"
'F' or "complex float"
's' or "c-string"
'd' or "decimal"
'E' or "enumeration"
'x' or "hex"
'X' or "uppercase hex"
'f' or "float"
'o' or "octal"
'O' or "OSType"
'U' or "unicode16"
"unicode32"
'u' or "unsigned decimal"
'p' or "pointer"
"char[]"
"int8_t[]"
"uint8_t[]"
"int16_t[]"
"uint16_t[]"
"int32_t[]"
"uint32_t[]"
"int64_t[]"
"uint64_t[]"
"float16[]"
"float32[]"
"float64[]"
"uint128_t[]"
'I' or "complex integer"
'a' or "character array"
'A' or "address"
"hex float"
'i' or "instruction"
'v' or "void"
'u' or "unicode8"
 */
