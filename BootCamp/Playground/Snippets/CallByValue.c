#include "../headers/vivstd.h"

int Func(int x)
{
    // 리턴값은 없거나 1개임
    // 여러개를 리턴하면 마지막 값만 유효함
    // CallByValue 의 한계임
    return x * 100, x * 50, x * 20;
}

void CallByValue()
{
    // 복사 전달 방식
    printf("복사전달방식 : %d\n",Func(50));
    Func(50);

    /****** CallByValue *****/
}
