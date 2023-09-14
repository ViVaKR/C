#include "../headers/vivstd.h"


void CharArrayPointer()
{
    /***** CharArrayPoint *****/

    // "banana"는 -> 상수이고, 그 시작 주소를 b 저장되어 있는 형태
    char *b = "banana";

    // "apple" 은 a[0] 부터 저장된 -> 값
    char a[] = "apple";

    // 직접 대입, 포인터에서 가능 (직접 대입 전/후에 포인터 주소값이 변경됨)
    printf("b 직접대입 전: %s ( %p ) %p\n", b, b, "banana");// 직접대입 전: banana ( 0x102e20355 )
    // 또다른 상수 -> "boss" 의 시작 주소로 포인터 값, 지시하는 값이 변경됨
    b = "boss";
    printf("b 직접대입 후: %s ( %p )\n", b, b);// 직접대입 후: boss ( 0x102e20379 )

    printf("\n");
    // strcpy : 배열에서는 가능함
    // 상수 a 의 0번 주소로 부터 선언된 크기만큼 strcpy 를 이용하여
    // 저장된 요소들을 하나씩 교체하면서 값 변경이 가능함
    printf("a 직접대입 전: %s ( %p )\n", a, a);// 직접대입 전: banana ( 0x102e20355 )
    strcpy(a, "mango");
    printf("strcpy(): %s\n", a);
    printf("a 직접대입 전: %s ( %p )\n", a, a);// 직접대입 전: banana ( 0x102e20355 )
}
