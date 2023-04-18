#include "../headers/vivstd.h"

void DataType() {
    system("clear");
    int j = 2147483647;          // 4 bytes (-2,147,483,648 ~ 2,147,483,647)
    printf("int \%d\n", j);      //
    unsigned int k = 4294967295; // 0 ~ 4,294,967,295
    printf("int \%u\n", k);      //

    short int h = 32767;                   // 2 bytes (-32768 to +32767) %d
    printf("short int \%d\n", h);          //
    unsigned short int i = 65535;          // 2 bytes (0 to +65535) %d
    printf("unsigned short int \%d\n", i); //

    long long int l = 9223372036854775807;            // 8 bytes (-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807) %lld
    printf("long long int \%lld\n", l);               //
    unsigned long long int m = 18446744073709551615U; // 8 bytes0 ~ 18,446,744,073,709,551,615 %lld
    printf("unsigned long long int max: \%llu\n", m); //

    char a = 'C';                     // single character %c
    printf("char \%c\n", a);          //
    char f = 100;                     // 1 byte (-128 - 127) %d or %c
    printf("char \%d\n", f);          //
    unsigned char g = 255;            // 1 byte (0 to +255) %d or %c
    printf("unsigned char \%c\n", g); //

    char b[] = "Viv";          // array of characters %s
    printf("char[] \%s\n", b); //

    float c = 3.141592;           // 4 bytes (32 bits of precision) 6 - 7 digits %f
    printf("float \%f\n", c);     //
    double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf
    printf("double \%lf\n", d);   //
    bool e = true;                // 1 byte (true or false) %d, true=1, false=0 -> #include "stdbool.h"
    printf("bool \%d\n", e);      //

    // %d--> for int
    // %u--> for unsigned int
    // %ld--> for long int or long
    // %lu--> for unsigned long int or long unsigned int or unsigned long
    // %lld--> for long long int or long long
    // %llu--> for unsigned long long int or unsigned long long

    // 타입의 범위를 넘는 값은 최소값으로 초기화 됨

    /* Format Specifier % = defines and formats a type of data to be displayed
        %c : character
        %s : string (array of characters)
        %f : float
        %lf : double
        %d : integer
        %.1 : decimal precision
        %1 : minimum field width
        %- = left align
     */

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    // 8자리 고정 + 왼쪽 정렬 예시
    printf("item 1: $%-8.2f\n",item1);
    printf("Item 2: $%-8.2f\n",item2);
    printf("Item 3: $%-8.2f\n",item3);

    // 상수 (constant) = fixed value that cannot be altered by the program during its execution
    const float PI = 3.14159;
    printf("pi :  %f\n",PI);
}
