#include "../headers/vivstd.h"

char *ConcatStr(char *s1, char *s2, char *s3, char *s4)
{
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + 1);// 널종결자 + 1
    strcat(strcat(strcat(strcpy(result, s1), s2), s3), s4);
    free(result);
    return result;
}

/// @brief String Concat
void StringConcat()
{
    /****** StringConcat *****/
    char myString[30] = "ABCDEFG";
    char ch[30] = "abcd";
    char *ps = "12";
    char *string = ConcatStr(myString, "M", ps, ch);
    printf("%s\n", string);
}
