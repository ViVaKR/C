#include "../headers/vivstd.h"

void Memset()
{
    /****** Memset *****/

    int arr[2][3] = {
        0,// 0으로 모두 초기화
    };
    // int형 memset 을 이용한 초기화
    memset(arr, 0, sizeof(arr));
    printf("\n");
    int size = sizeof(arr) / sizeof(arr[0][0]);
    printf("Total Size %d\n", size);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("배열 초기화 점검 :  %d -> %d\n", i, arr[i][j]);
        }
    }
}
