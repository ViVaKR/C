#include "../headers/vivstd.h"

/// @brief 소수 판별기
/// @param num 
/// @return 
bool IsPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

/// @brief (3) 소수의 합 구하기
/// @param number 
void IsSumOfPrimeNumbers(int number)
{
    printf("\n***** (%d) 소수의 합 구하기 *****\n", number);
    int count = 0;
    int j;
    for (int i = 2; i <= number / 2; i++) {
        if (IsPrime(i)) {
            j = i;
            if (IsPrime(number - j)) {
                count++;
                printf("%d = %d + %d\n", number, j, (number - j));
            }
        }
    }

    if (count == 0) {
        printf("\n%d 은 소수의 합으로 표현할 수 없습니다.\n", number);
    } else {
        printf("\n%d 은 %d개의 소수합으로 표현 가능합니다.\n", number, count);
    }
}

/// @brief (2) 전체 소수 구하기
/// @param number 
void CheckIsPrimeNumber(int number)
{
    printf("\n***** 2 부터 %d 까지 소수 목록 *****\n", number);
    int count = 0;// 갯수
    bool tf = true;// 줄바꿈
    int j;

    for (int i = 2; i <= number; i++) {

        if (IsPrime(i)) {
            count++;
            tf = false;
            printf("%3d\t", i);
        }

        if (!tf && count % 4 == 0) {
            printf("\n");
            tf = true;
        }
    }
    printf("\n( %d )의 총 소수 갯수 = %d\n", number, count);
}

/// @brief (1) 소수 및 소수의 합 구하기 Caller
void PrimeNumber()
{
    bool check = false;
    int number;
    do {
        printf("소수의 합을 구할 정수입력 : ");
        fflush(stdin);
        check = scanf("%d", &number);

    } while (!check);

    CheckIsPrimeNumber(number);
    IsSumOfPrimeNumbers(number);
}
