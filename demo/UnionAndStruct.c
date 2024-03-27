<<<<<<< HEAD
#include "../headers/vivstd.h"

/// @brief 메모리를 공유하는 공용체
union SharedType {
    int iData;
    float fData;
};

/// @brief 구조체
struct MyData
{
    char type;
    union SharedType data;
};

/// @brief 비트 단위 정보를 다룰 수 있도록 선언된 구조체
struct BitTypes
{
    // 구조체 문법에서 비트 단위로 데이터를 사용하는 기능을 제공
    // : 비트크기;
    unsigned char bit_0 : 1;
    unsigned char bit_1 : 1;
    unsigned char bit_2 : 1;
    unsigned char bit_3 : 1;
    unsigned char bit_4 : 1;
    unsigned char bit_5 : 1;
    unsigned char bit_6 : 1;
    unsigned char bit_7 : 1; // 최상위 비트
};

/// @brief 1바이트 크기의 자료형
union BitData
{
    struct BitTypes bit_data; // 1바이트
    unsigned char byte_data; // 1바이트
};


/// @brief 공용체를 이용한 메모리 절약 데모
void
  UnionAndStruct()
{
    /****** UnionAndStruct *****/

    struct MyData a, b;
    a.type = 0;
    a.data.iData = 100;
    b.type = 1;
    b.data.fData = 3.14;

    printf("A = %d, B = %.2f\n", a.data.iData, b.data.fData);

    // 구조체와 공용체를 이용한 비트연산
    struct BitTypes data; //* 1바이트
    data.bit_0 = 1;
    data.bit_1 = 0;
    data.bit_2 = 1;
    data.bit_3 = 0;
    data.bit_4 = 0;
    data.bit_5 = 0;
    data.bit_6 = 0;
    data.bit_7 = 0;
    /* 메모리 구성
    data = 0x05
    | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 |
    bit_7                       bit_1
    */

   //* 사용예시 1
   unsigned char temp;
   memcpy(&temp, &data, 1);
   printf("temp = %x\n",temp);

    //* 사용예시 2
    union BitData bitData;
    bitData.byte_data = 0x63;
    
    /* 0x63
    |0|1|1|0|0|0|1|1|
    */
    
    printf("bitData =  %x, %x\n", bitData.bit_data, bitData.bit_data.bit_1);
    
    
}
=======
#include "../headers/vivstd.h"

/// @brief 메모리를 공유하는 공용체
union SharedType {
    int iData;
    float fData;
};

/// @brief 구조체
struct MyData
{
    char type;
    union SharedType data;
};





/// @brief 비트 단위 정보를 다룰 수 있도록 선언된 구조체
struct BitTypes
{
    // 구조체 문법에서 비트 단위로 데이터를 사용하는 기능을 제공
    // : 비트크기;
    unsigned char bit_0 : 1;
    unsigned char bit_1 : 1;
    unsigned char bit_2 : 1;
    unsigned char bit_3 : 1;
    unsigned char bit_4 : 1;
    unsigned char bit_5 : 1;
    unsigned char bit_6 : 1;
    unsigned char bit_7 : 1; // 최상위 비트
};

/// @brief 1바이트 크기의 자료형
union BitData
{
    struct BitTypes bit_data; // 1바이트
    unsigned char byte_data; // 1바이트
};


/// @brief 공용체를 이용한 메모리 절약 데모
void
  UnionAndStruct()
{
    /****** UnionAndStruct *****/

    struct MyData a, b;
    a.type = 0;
    a.data.iData = 100;
    b.type = 1;
    b.data.fData = 3.14;

    printf("A = %d, B = %.2f\n", a.data.iData, b.data.fData);

    // 구조체와 공용체를 이용한 비트연산
    struct BitTypes data; //* 1바이트
    data.bit_0 = 1;
    data.bit_1 = 0;
    data.bit_2 = 1;
    data.bit_3 = 0;
    data.bit_4 = 0;
    data.bit_5 = 0;
    data.bit_6 = 0;
    data.bit_7 = 0;
    /* 메모리 구성
    data = 0x05
    | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 |
    bit_7                       bit_1
    */

   //* 사용예시 1
   unsigned char temp;
   memcpy(&temp, &data, 1);
   printf("temp = %x\n",temp);

    //* 사용예시 2
    union BitData bitData;
    bitData.byte_data = 0x63;
    
    /* 0x63
    |0|1|1|0|0|0|1|1|
    */
    
    printf("bitData =  %x, %x\n", bitData.bit_data, bitData.bit_data.bit_1);
    
    
}
>>>>>>> 4e6914f (update dmeo/)
