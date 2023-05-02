#include "../headers/vivstd.h"

/// @brief 문자의 개수 구하기
/// @param data 
/// @return 
int GetStringLength(char data[])
{
    /****** GetStringLength *****/
    
    int count = 0;
    // while 문 내부에서 ` != 0` 불필요
    while(data[count]) count++;
    return count;

}
