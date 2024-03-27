#include <stdio.h>

void Print(int* arr, const int size, char* title) {
    printf("%s => ", title);
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

//=> O(N2)
// [ 버블정렬 ]
// 패스
void BubleSort(int* arr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        // 패스 (행)
        for (int j = 0; j < size - 1 - i; j++) {
            // 비교횟수 (열)

            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    Print(arr, size, "버블정렬");
}

// 선택정렬 (Selection Sort)
// 앞에서 부터 정렬을 완료해 나가는 방식
// 0번 부터 가장 작은 데이터를 두기 위하여 나머지를 모두 비교하는 방식을 반복.
// 오버 헤드 방지을 위해 작은 값을 찾기 위하여 한번에 모두 비교 검색
// 패스당 1회 교환 횟수.
void SelectionSort(int* arr, const int size) {
    // 가장 작은 값을 저장하기 위한 인덱스
    int minIdx = 0;

    for (int i = 0; i < size - 1; i++) {
        // 패스, 정렬 기준
        minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        const int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    Print(arr, size, "선택정렬");
}

// 삽입정렬 (Insertion Sort, O(N2))
// 트럼프 카드에 비교, 카드를 뽑아서(temp 변수에 할당) 위치를 찾은 후 삽입 하는 방식..
// 1번 부터 시작 하여 이전 인덱스와 비교하여 크면 대상을 한칸 오른쪽으로 미는 방식
void InsertionSort(int* arr, const int size) {
    int j;
    for (int i = 1; i < size; i++) {
        const int temp = arr[i]; // 1번 인덱스 부터 카드 뽑기.
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            // 뽑아낸 위치에서 한칸씩 왼쪽(arr[j-1])과 비교 후 `arr[j-1]` 값이 크면 오른쪽 밀기
            arr[j] = arr[j - 1]; // 앞의 것이 크면, 뒤로 밀기
        }

        arr[j] = temp;
    }

    Print(arr, size, "삽입정렬");
}

//=> O(NlogN)
// 퀵정렬 (Quick Sort) : 정렬의 꽃으로 불리는 빠른 정렬
// 편을 나누어 저 분할 정복 방법론
// (예)
// 1. 50 점을 기준으로 좌/우 그룹으로 나눔. : 2 그룹
// 2. 반복적으로 각각의 좌/우 그룹을 반 반 씩 나눔 : 4 그룹
// 3. 8 그룹... -=> 1명이 될때 까지 나눔.
void QuickSort(int * arr, int left, int right) {
    
}

// 병합정렬 (Merge Sort)

// 힙정렬 (Heap Sort)

//=> O(N)
// 버킷정렬 (Buket Sort)


int main(void) {
    // 정렬
    int target[] = {563, 72, 9432, 3, 5, 1, 4, 2, 45, 23, 99, 33};
    BubleSort(target, sizeof(target) / sizeof(int));
    SelectionSort(target, sizeof(target) / sizeof(int));
    InsertionSort(target, sizeof(target) / sizeof(int));
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
