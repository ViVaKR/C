#include "../headers/vivstd.h"

void ScreenClear()
{
#ifdef macos
    system("clear");
#else
    system("cls")
#endif
}

