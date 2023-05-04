#include "../headers/vivstd.h"

/// @brief 문자 한개 입력받기
void GetChar()
{
    printf("\n***** Get Char *****\n");

    printf("\n한개의 문자를 입력하세요! (getchar) : ");
    int input;
    //! 표준 입력 함수를 사용하여 문자 한 개 입력받기
    rewind(stdin); //* 입력버퍼 비우기
    input = getchar();
    printf("getchar %c\n",input);
    
    printf("\n한개의 문자를 입력하세요! (getchar) : ");
    rewind(stdin);
    input = getchar();
    printf("getchar %c\n", input);

    rewind(stdin);
    
    input = getc(stdin); //! getchar 의 원본 함수
    printf("getc %c\n", input);
}
