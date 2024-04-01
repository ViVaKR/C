#include "../Headers/vivstd.h"

/// @brief 시간차이 구하기
void DiffTime() {
    /****** DiffTime *****/

    struct tm *gmt, *localt;

    time_t now, gm_time;

    char buf[256];

    time(&now); // 현재 초 단위 시간

    localt = localtime(&now);
    gmt = localtime(&gm_time);

    printf("%d", localt->tm_hour);
}
