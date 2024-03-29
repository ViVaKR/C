#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <_ctype.h>

int usleep(useconds_t useconds);

int MakeRandom(const int min, const int max) {
    const int number = (rand() % (max - min + 1)) + min;
    return number;
}

void PointerSize() {
    // ex. 2차원 배열.
    // 괄호가 없으면 => 포인터 배열, *p[3];
    // 괄호가 있으면 => 배열 포인터, (*p)[3];

    /* (괄호)로 묶어서 배열포인터로 받음으로서 배열을 가르키는 배열 포인트(8바이트)가 됨, 괄호가 없으면? 포인터 배열이 됨. */
    //      => 즉, 시스템에 따라서 int 형 포인트 배열은 포인터 변수의 크기가 4 바이트 또는 8바이트가 될 수 있음.
    //      => 포인터의 크기는 항상 8 바이트 임.
    // }
}

void Print(const int* arr, const int size, char* title) {
    printf("%s\t=>\t", title);
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
    // sleep(1);
    // usleep(1000);
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
// 4. 원소가 1나 남은 상태가 정렬이 완료된 상태가 됨.
// -------------------------------------------------
// 피벗 : 기준이 되는 값.
// 피벗을 뽑기가 성능이 달라짐.
// 대략 배열의 중간 값을 기준으로 함. 피벗은 좌/우 무관함.
// => Pivot : 기준이 되는 값
// => pL : 배열의 가장 작은 인덱스 값
// => pR : 배열의 가장 높은 인덱스 값
// pivot 으로 pL 먼저 비교하여 값이 (pL < pv) 일때 까지 반복 하면서 참일때 pL 인덱스를 증가 시켜줌
// pivot 으로 pR 을 비교한 후 값이 (pR > pv) 일때 까지 다시 반복 후 참일때 pR 인덱스를 증가 시켜줌
// pL 과 pR 이 크로스 되는 시점이 그룹이 나누어 진 시점
// 그룹이 나누어 지면
// pR 은 왼쪽 그룹의 Right 가 되고
// pL 은 오른쪽 그룹의 Left 가 됨
// 각각의 그룹의 시작 과 끝은 변하지 않음. 원래의 left, right
// 즉, pL 과 pR 의 인덱스가 같아 질때 원소가 1개 남았다고 판달할 수 있음.
// 재귀 호출 필요
void QuickSort(int* arr, const int left, const int right) {
    int pL = left; // 0 에서 시작
    int pR = right; // 배열의 마지막 인덱스 (size - 1)
    const int pv = arr[(pL + pR) / 2]; // 중간값 ->arr[pL + pR] / 2

    do {
        // 왼쪽 통과 기준 => ++ (인덱스)
        while (arr[pL] < pv) pL++;

        // 오른쪽 통과 기준 => -- (인덱스)
        while (arr[pR] > pv) pR--;

        if (pL <= pR) {
            // 크로스 되는 순간, 각각의 값을 변경해줌
            const int temp = arr[pL];
            arr[pL] = arr[pR];
            arr[pR] = temp;

            pL++;
            pR--;
        }
    } while (pL <= pR);

    if (left < pR) QuickSort(arr, left, pR);
    if (right > pL) QuickSort(arr, pL, right);
}

// [ 병합정렬, Merge Sort ]
// 3개의 배열을 사용 (배열1, 배열2, 병합된 배열)
// 3개의 인덱스 변수 필요 (3개의 배열의 현재 비교 대상 인덱스 저장)
// => 원소를 반으로 나누어서 정렬하는 방식 : 나눈다 => 병합
// 1. 어떠한 작업 없이 반씩 나누는 작업 부터..
// 2. 원소가 하나 남을 때 까지..나눈 후.
// 3. 병합 2의 거듭제곱으로 병합..하는데
// 4. 작은 것을 먼저 넣고, 비교 하고 나머지 넣고 를 반복.
// 배열을 나눌 때 별도의 배열을 생성하지 않음이 중요함. (left - middle - right)
// middle 중간값을 이용함. (left to middle) (middle + 1 to right)
// left 와 right 가 같아지는 시점이 원소가 하나 남았다는 판단.
// 재귀 호출
// -> int ex[] = {7, 5, 2, 4, 1, 3, 8, 6};
// [ 7, 5, 2, 4 ] [ 1, 3, 8, 6 ]

// [ 7, 5 ] [ 2, 4, ] [ 1, 3 ] [ 8, 6 ]
// [7] [5] [2] [4] [1] [3] [8] [6]
// => 병합 개시
// (3)
void Merge(int* arr, int* arrMerge, const int left, const int mid, const int right) {
    // 비교는 arrMerge
    // 병합은 arr
    int idx1 = left;
    int idx2 = mid + 1;
    int idxM = left; // arrMerge's left

    for (int i = 0; i <= right; i++) {
        // 일반 복사
        arrMerge[i] = arr[i]; // copy to arrMerge
    }

    while (idx1 <= mid && idx2 <= right) {
        if (arrMerge[idx1] < arrMerge[idx2]) // 임시 배열의 값을 비교해서, arrMerge[idx1] 이 작을 때
            arr[idxM++] = arrMerge[idx1++]; // 실제 arr 배열에 넣는 작업
        else
            arr[idxM++] = arrMerge[idx2++]; // arrMerge[idx2] 작을 때
    }

    while (idx1 <= mid) {
        // 나머지 채워넣기
        arr[idxM++] = arrMerge[idx1++];
    }
}

// (2)
void MergeSortUtil(int* arr, int* arrMerge, const int left, const int right) {
    if (left < right) {
        const int mid = (left + right) / 2;
        MergeSortUtil(arr, arrMerge, left, mid); // left
        MergeSortUtil(arr, arrMerge, mid + 1, right); // right
        Merge(arr, arrMerge, left, mid, right);
    }
}

// (1)
void MergeSort(int* arr, const int size) {
    int* arrMerge = malloc(sizeof(int) * size); // 값을 비교할 배열. 공간 복잡도 O(N)
    memset(arrMerge, 0, sizeof(int) * size);
    MergeSortUtil(arr, arrMerge, 0, size - 1);
    free(arrMerge);
}

//=> O(N)
// 버킷정렬 (Buket Sort), 계수정렬
// 범위가 정해진 경우 엄격한 조건
// 예를 들어 1 ~ 5 까지 배열일 경우, 6개의 버캣을 만듦
void BucketSort(int* arr, const int size, const int range) {
    // 배열사이즈, 배열의 범위
    int* bucket = calloc(range, sizeof(int)); //  할당된 메모리가 모두 0으로 채워짐. ( 양동이 )

    for (int i = 0; i < size; i++) {
        // 버캣의 인덱스가 배열의 값으로 사용됨
        bucket[arr[i]]++;
    } // 갯수 카운팅 완료.

    int idx = 0;
    for (int i = 1; i < range; i++) {
        for (int j = 1; j <= bucket[i]; ++j) {
            arr[idx++] = i;
        }
    }

    free(bucket);
}

// 힙(Heap) 자료구조 (Max Heap, Min Heap)
// 유의미한 값 => root value, 0 번째 값 구성.
// Complete binary tree : 말단 노드를 제외한 모든 노드가 꽉 채워진 상태
// Max Heap : 부모노드의 값은 자식노드의 값보다 크거나 같아야 함.
// Min Heap : 부모노드의 값은 자식노드이 값보다 작거나 같아야 함.
// heapify : 자료구조를 힙 형태로 만드는 것. 자식 노드가 있는 노드만 힙히 파이를 함.
// 자식 노드 끼리 먼저 비교 후, 해당 자식 노드값과 부모 노드값과 비교 작업을 함.
// 원소 추가 : 항상 가장 마지막 끝에 추가하고, 자식 노드 입장에서 부모노드와 비교를 시작함.
// 원소 삭제 : 힙에서 삭제는 루트만 함 (유의미한 값이 루트이므로), 가장 마지막을 루트로 옮기고 마지막 노드를 삭제함.

// 힙정렬 (Heap Sort)
// O(log N) : 2^n, ((n/2) * log N) -> O(N)
// 예를 들어 데이터의 갯수가 1024개 라면 약 10 개의 깊이가 됨.
// 병합정렬, 퀵 정렬 만큼 빠른 정렬 알고리즘.
// 힙 트리구조 를 이용한 정렬방식.
// 이진 트리 : 데이터를 표현할 때 데이터를 각 노드에 담은 뒤에 각 노드를 2개씩 연결하는 구조.
// 부모노드에서 자식 노드로 가지가 뻗어나가는데, 이진트리는 모든 노드의 자식 노드가 2개 이하인 노드를 말함.
// Root,  Leaf
// 완전 이진 트리 : 모든 자료가 구성됨. 왼쪽 부터.
// 힙 (Heap) : 최대값 또는 최소값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리
// 최대힙 : 부모노드가 자식 노드 보다 큰 힙을 말함.
// Heapify
// 힙 정렬 : 최상 노드와 최 하단 노드를 교체 후 -> Heapify 작업을 반복. (O(N * log N))

// (ex, max-heap)
// 자식노드의 수 = 원소의 갯수 / 2, 100 / 2 = 50개의 자식노드.
// 부모 : 자식보다 크거나 같음
void HeapSort(int* heap, const int size) {
    // (1) 전체 트리 구조를 최대 힙 구조로 바꾸는 작업
    for (int i = 1; i < size; ++i) {
        int c = i;
        do {
            // 부모가 자식 보다 작은 경우 교체하여 주는 작업
            const int root = (c - 1) / 2;

            if (heap[root] < heap[c]) {
                const int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            c = root;
        } while (c != 0);
    }

    // (2) 크기를 줄여 가면서 반복적으로 힙을 구성 (N 번 반복)
    // 0 번째 인덱가 가장 큰값이므로 그것을 가장 마지막으로 보내는 작업을 반복
    // 가장 큰값을 계속해서 뒤로 보내는 작업
    for (int i = size - 1; i >= 0; i--) {
        // 가장 큰 값을 맨 뒤로 보내는 작업
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        // 힙 재구성
        int root = 0;
        int c = 1;

        do {
            // 힙구조를 만드는 작업
            c = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기
            // left right 비교  && 범위를 벗어나지 않도록 함.
            if (heap[c] < heap[c + 1] && c < i - 1) {
                c++; // right value 가 더 크다면? 이동.
            }

            // 루트보다 자식이 더 크면 교환하고 && 범위를 벗어나지 않도록 함.
            if (heap[root] < heap[c] && c < i) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            root = c;
        } while (c < i);
    }
    Print(heap, size, "힙 정렬");
}

void funPtr(int** p, const int size, int* arr) {
    //TODO
    for (int i = 0; i < size; i++) {
        p[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", *p[i]);
    }
}

// 힙 구조체
typedef struct heap {
    // Total Size => 16byte
    int* arr; // 힙 메모리(배열)의 주소 저장, 8byte
    int cursor; // 저장된 원소이 갯수, 4byte
    int capacity; // 힙(배열)의 최대 용량, 4byte
} Heap;

void CreateHeap(Heap* heap, const int capacity) {
    heap->arr = (int *) malloc(sizeof(int) * capacity);
    heap->cursor = 0;
    heap->capacity = capacity;
}

void ShiftUp(int* arr, const int childIdx) {
    const int parentIdx = (childIdx - 1) / 2;

    if (parentIdx >= 0 && arr[parentIdx] < arr[childIdx]) {
        const int temp = arr[parentIdx];
        arr[parentIdx] = arr[childIdx];
        arr[childIdx] = temp;
        ShiftUp(arr, parentIdx);
    }
}

void AddHeap(Heap* heap, const int value) {
    if (heap->capacity == heap->cursor) // 최대저장 용량
    {
        printf("저장할 공간이 부족합니다.");
        return;
    }
    heap->arr[heap->cursor] = value;
    // Shift-up : 추가된 자식 노드 입장에서 부모 노드와 비교하는 작업
    // 부모노드 구하는 공식
    //=> (구하고자하는 노드의 부모인덱스 - 1) / 2, 소수점은 right, 정수는 left
    ShiftUp(heap->arr, heap->cursor);
    heap->cursor++;
}

size_t FindIndex(const int a[], size_t size, int value) {
    size_t index = 0;
    while (index < size && a[index] != value) ++index;

    return (index == size ? -1 : index);
}

void HeapRunner() {
    Heap heap; // 힙 구조체 변수
    heap.cursor = 0;
    CreateHeap(&heap, 14);

    // const int values[] = {57, 32, 48, 10, 15, 25, 20, 9, 60};
    const int values[] = {6, 8, 9, 10, 15, 19, 20, 28, 30, 45, 50};
    const int size = sizeof(values) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        AddHeap(&heap, values[i]);
    }
    // 60 의 부모 노드 구하는 법
    // (60의 인덱스의 부모 인덱스 - 1 ) / 2, 소숫점은 오른 쪽, 정수는 왼쪽,
    // printf("현재 저장된 힙 요소 => %d, %d, %d\n", capacity, heap.cursor, heap.capacity);
    // Print(heap.arr, size, "Heap Sorting");
    printf("힙 정렬(Max)\t=>\t");
    for (int i = 0; i < size; ++i) {
        printf("%d", heap.arr[i]);
        printf(" %c ", i < size - 1 ? '-' : ' ');
    }

    puts("");

    const size_t myIndex = FindIndex(heap.arr, size, 19);
    const int left = heap.arr[2 * myIndex + 1];
    const int right = heap.arr[2 * myIndex + 2];

    printf("node (%d)'s : left => %d, right => %d\n", heap.arr[myIndex], left, right);
}

/// @brief 지정한 인덱스 왼쪽을 모두 0으로, 오른쪽은 그대로
/// @param num 원본 숫자
/// @param i 지정한 인덱스 번호
/// @return 정수 결과값
int ClearLeftBits(int num, int i) {
    return (num & ((1 << i) - 1));
}


/// @brief 특정 비트를 0으로 만들기 &, ~ (And, Not 연산)
/// @param num 변경할 숫자
/// @param i 0 으로 만들 비트
/// @return 변경된 int 정수
int ClearBits(const int num, int i) {
    return ((num & (~(1 << i))));
}

void PrintBit(const long long num, const int size) {
    printf("0b_");
    for (long long i = size - 1; i >= 0; --i) {
        printf("%lld\n", (num >> i) & 1); // 0011

        if (i != 0) // under bar insert, except last char
            printf("%s", i % 4 == 0 ? "_" : "");
    }
    printf(" (%lld)\n", num);
}


int main(void) {
    srand(time(NULL));
    // 정렬
    int target[MakeRandom(30, 50)];
    const int size = sizeof(target) / sizeof(int);
    for (int i = 0; i < size; i++) {
        target[i] = MakeRandom(1, 100);
    }
    Print(target, size, "원 소스");
    BubleSort(target, size); // 버블정렬
    SelectionSort(target, size); // 선택정렬
    MergeSort(target, size); // 병합정렬
    Print(target, size, "병합 정렬");

    BucketSort(target, size, 100);
    Print(target, size, "버캣 정렬");

    HeapSort(target, size);

    HeapRunner();

    const int b1 = -3; // (0011)
    PrintBit(b1, 32);

    return 0;
}
