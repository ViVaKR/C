#include <stdio.h>

void demo(int (*p)[3]) {

    printf("size((*p)[])==> %ld, %d", sizeof(p), p[0][1]);
}

//=> O(N2)
// [ 버블정렬 ]
// 패스
void BubleSort(int *arr,const int size) {
    for (int i = 0; i < size - 1;i++) {         // 패스 (행)
        for (int j = 0; j < size - 1 -i; j++) {  // 비교횟수 (열)

            if(arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("버블정렬 => ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}

// 선택정렬 : (Selection Sort)

// 삽입정렬 (Insertion Sort)

//=> O(NlogN)
// 퀵정렬 (Quick Sort)

// 병합정렬 (Merge Sort)

// 힙정렬 (Heap Sort)

//=> O(N)
// 버킷정렬 (Buket Sort)


int main(void) {
    int target[] = { 3, 5, 1, 4, 2, 45, 23, 99, 33 };
    BubleSort(target, sizeof(target) / sizeof(int));
    // PrintLexicographicOrder(arr);
    // long number;
    // printf("3의 배수여부를 판단할 양의 정수를 하나를 입력하세요\n>> ");
    // scanf("%ld", &number);
    // char *result[30] = {{"3의 배수입니다."}, {"3의 배수가 아닙니다."}};
    // printf("%ld -> %s\n", number, result[(number % 3) && 1 ]);
    // long a, b, c;
    // printf("비교할 숫자 3개를 한칸씩 띄워서 입력하세요\n>> ");
    // fflush(stdin);
    // scanf("%ld %ld %ld", &a, &b, &c);
    // result[(input[0] > input[1]) + (input[0] > input[2])] = input[0];
    // result[(input[1] > input[0]) + (input[1] > input[2])] = input[1];
    // result[(input[2] > input[0]) + (input[2] > input[1])] = input[2];
    // printf("(%d - %d - %d) 중 두번째로 큰수는 => (%d) 입니다. ", input[0], input[1], input[2], result[1]);
}
