#include "../headers/vivstd.h"

/// @brief (14) 이차원 배열
void Array2D()
{
    printf("\n\n***** 이차원 배열 *****");

    //***** 2차원 배열 *****//
    // 행, 열 로 구성
    // 열 : 배열의 원소
    // 행 : 배열 원소의 집합
    // 메모리 차원에서는 이차원 배열은 일차원 배열의 행 연결로 볼 수 있음
    // (형식) int array[행의갯수][열의갯수];
    // int array[3][7]; 은 3행 7열, 즉 21개의 요소를 가진 변수
    //* 2차원 배열의 형식이 [행][열]의 모양인 이유 -> char[5][4]
    // 연산자 우선 순위 때문에
    // 연산자는 동일한 우선 순위를 가질 때 왼족에서 오른쪽으로 연산을 수행함
    // (1) data[5] 라는 배열을 만들겠다.
    // (2) data 배열의 각 요소는 char[4] 의 크기를 가진다는 의미



    // 선언과 동시에 초기화 방식
    int arrA[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    int arrB[][3] = { { 7, 8, 9 }, { 55, 66, 99 } };
    int arrC[2][3] = { { 11, 22, 33 } };// 첫 요소만 초기화
    printf("\n\n");

    // 행의 갯수 구하기
    // ((int 4byte * items 2 * 3 = 24) / (int 4byte * 3 = 12) = 2)
    int sizeOfRow = sizeof(arrA) / sizeof(arrA[0]);
    printf("행 갯수 :  %d\n", sizeOfRow);
    printf("\n");

    // 열의 갯수 구하기
    int sizeOfCol = sizeof(arrA[0]) / sizeof(arrA[0][0]);
    printf("열 갯수 :  %d\n", sizeOfCol);
}
