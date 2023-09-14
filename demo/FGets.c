#include "../headers/vivstd.h"

void StringToNumber();
int CheckInput(char *buffer, int limit);

/// @brief
void FGets()
{
    /****** FGets *****/
    
    printf("\n문자열을 입력하세요 (fgets) : ");
    char input[50];
    //! 마지막에 엔터키 `\n` 되신 널 문자 `0` 이 들어감
    //! CTRL + C 로 취소시 대비코드를 구성해야 함

    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("FGets String => %s\n", input);
    } else {
        printf("Canceled\n");
    }

    // fgets 함수로 입력 받은 숫자는 정수가 아닌 문자열로 인식됨
    StringToNumber();
}
