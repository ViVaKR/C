#include "../headers/vivstd.h"

/// @brief 콜백함수
/// @param a
/// @param b
/// @return
bool Callback(int a, int b)
{
    return a > b;
}

/// @brief 콜백호출
/// @param p
void CallbackCaller(bool (*p)(int, int))
{
    for (int i = 0; i < 100; i++) {
        if (p(i, 50)) {
            printf("\n%d\n", i);
        }
    }
}

void CallbackSum(int rows, int cols, int *arr)
{
    int total = 0;
    int rowSum = 0;
    for (int j = 0; j < rows * cols; j++) {
        rowSum += *(arr + j);
        total += *(arr + j);

        if ((j + 1) % rows == 0) {
            printf("(%d) 행합 = %d\n", (j + 1) / rows, rowSum);
            rowSum = 0;
        }
    }
    printf("\n");
    printf("%d", total);
}

/// @brief (2) 프린트
/// @param size 행 개수
/// @param pa 데이터 소스
/// @param p 콜백함수
void Print(int rows, int cols, int *pa, void (*p)(int, int, int *arr))
{
    p(rows, cols, pa);
}

void Array2DSum(int rows, int cols, int *arr)
{
    int total = 0;
    int subtotal = 0;
    for (int j = 0; j < rows * cols; j++) {
        total += *(arr + j);
        subtotal += *(arr + j);
        if ((j + 1) % rows == 0) {
            printf("%d\n", subtotal);
            subtotal = 0;
        }
    }
    printf("\n");
    printf("%d", total);
}

/// @brief (1) 호출
void Run()
{
    int rows = 0;
    int cols = 0;
    int check = -1;

    // 행과 열의 개수 입력 (입력확인)
    do {
        printf("행수? : ");
        fflush(stdin);
        check = scanf("%d", &rows);
        printf("열수? : ");
        fflush(stdin);
        check = scanf("%d", &cols);
    } while (check != 1);

    // 데이터 입력 (입력확인)
    int arr[rows][cols];
    check = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                printf("%d 행, %d 열 : ", i, j);
                fflush(stdin);
                check = scanf("%d", &arr[i][j]);
            } while (check != 1);
        }
    }

    // Print Call
    Array2DSum(rows, cols, *arr);
}

/// @brief (37) 호출
void CallbackEx()
{
    int rows = 0;
    int cols = 0;
    int check = -1;

    // 행과 열의 개수 입력
    do {
        printf("행수? : ");
        fflush(stdin);
        check = scanf("%d", &rows);
        printf("열수? : ");
        fflush(stdin);
        check = scanf("%d", &cols);
    } while (check != 1);

    // 데이터 입력
    int arr[rows][cols];
    check = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                printf("%d 행, %d 열 : ", i, j);
                fflush(stdin);
                check = scanf("%d", &arr[i][j]);
            } while (check != 1);
        }
    }

    // Print Call
    // Array2DSum(rows, cols, *arr);

    // void (*p)(int, int, int *arr) = CallbackSum;
    // p(rows, cols, *arr);
    Print(rows, cols, *arr, CallbackSum);
}
// CallbackCaller(Callback);
/*  = { { 4, 2, 3 },
        { 5, 2, 3 },
        { 1, 2, 3 } } */
/* ( Result )
    9
    10
    6
    25 
*/
