#include "../headers/vivstd.h"

/// @brief strcpy
void StringCopy()
{
    /****** StringCopy *****/
    
    char data[10] = "abc";
    char result[16];
    strcpy(result, data); // NULL 문자 포함하여 복사
    strcat(result, "def");

    printf("%s %s\n",data, result);
}
