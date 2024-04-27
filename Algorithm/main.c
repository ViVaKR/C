#include <_ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int MakeRandom(const int min, const int max)
{
    const int number = (rand() % (max - min + 1)) + min;
    return number;
}

void PointerSize()
{
    // ex. 2차원 배열.
    // 괄호가 없으면 => 포인터 배열, *p[3];
    // 괄호가 있으면 => 배열 포인터, (*p)[3];

    /* (괄호)로 묶어서 배열포인터로 받음으로서 배열을 가르키는 배열 포인트(8바이트)가 됨, 괄호가 없으면? 포인터 배열이 됨. */
    //      => 즉, 시스템에 따라서 int 형 포인트 배열은 포인터 변수의 크기가 4 바이트 또는 8바이트가 될 수 있음.
    //      => 포인터의 크기는 항상 8 바이트 임.
    // }
}

void Print(const int *arr, const int size, char *title)
{
    printf("%s\t=> ", title);
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
    // sleep(1);
    // usleep(1000);
}

// [ 버블정렬 ]
// O(N2)
// 인접한 데이터를 비교하면서, 정렬
// 인접한 2개를 비교해서 더 큰 데이를 뒤로 보냄.
// 맨 뒤에서 부터 정렬하는 방식
// array    [ 3 - 5 - 1 - 2 - 4 ]
// ------------------------------
// (패스 -> 인덱스)
// (1    ->   0  ) 0-1, 1-2, 2-3, 3-4  [j, 4회]
// (2    ->   1  ) 0-1, 1-2, 2-3       [j, 3회]
// (3    ->   2  ) 0-1, 1-2            [j, 2회]
// (4    ->   3  ) 0-1                 [j, 1회]
// i => 행 (횟수는 4회, 인덱스로는 3까지 이므로 i < size -1; 이 됨.
// j => 열
void BubleSort(int *arr, const int size)
{
    for (int i = 0; i < size - 1; i++) {
        // 패스 (행)
        for (int j = 0; j < size - 1 - i; j++) {
            // i 의 인덱스가 0 부터 시작하므로
            // 비교횟수 (열)

            if (arr[j] > arr[j + 1]) {
                // 현재 다음 것과 비교하므로
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    Print(arr, size, "버블정렬");
}

/* [ 선택정렬 ] (Selection Sort) */
// 앞에서 부터 정렬을 완료해 나가는 방식
// 0번 부터 가장 작은 데이터를 두기 위하여 index 0 vs 0 + 1 방식으로 이중 for 문을 이용하여 모두 비교하는 방식을 반복.
// 오버 헤드 방지을 위해 작은 값을 찾기 위하여 한번에 모두 비교 검색
void SelectionSort(int *arr, const int size)
{
    // 가장 작은 값을 저장하기 위한 임시 인덱스 변수.
    int minIdx = 0;

    // (1) 원본이 -> {5, 4, 1, 3, 2} 인배열을 오름 차순으로 정렬 하라는 시나리오로 출발
    for (int i = 0; i < size - 1; i++) {

        minIdx = i;                          // (2) 예를 들어 처음 i 가 0일 때 arr[0] 은 5가 되고, minIdx에 일단 i 와 동일하게 맞추어 줌. (맞 비교 및 교환용.)
        for (int j = i + 1; j < size; j++) { // (3) i = 0 일 때 항상 비교 대상은 한발 앞에 있는 (j = i + 1)
                                             // 즉, 5일 때는 4가 되고 위에서 i 가  size - 1 까지 이므로
                                             // 서브에서는 size 끝까지 범위 끝까지 를 설정하게 되는 이유

            if (arr[minIdx] > arr[j]) {      // (4) 그래서 아무튼 5 하고 4하고 비교하는데,
                minIdx = j;                  // (5) 5가 4보다 크다면?  minIdx 에 일단 요소 4, 값이 아닌 배열 인덱스 (j)를 저장해 두고, 아니면 (작으면 패스..)
            }
        }
        const int temp = arr[i];             // (6) arr[i] 즉, 요소 5을 임시 변수에 일단 저장해두고,
        arr[i] = arr[minIdx];                // (7) arr[i] 요소(5) 를 위에 저장해둔 minIdx 를 이용, arr[minIdx] (요소4) 의 값으로 변경하고..(즉, 5 자리에 4를 보내고..)
        arr[minIdx] = temp;                  // (8) arr[minIdx] 자리에 임시 저장해둔 (요소 5) 로 변경 즉, 5를 원래 4자리로 뒤로 보내라..하는 의미.

        // (9) 결론 하여 .. 첨부한 그림 처럼, 원본 배열의 인덱스 0번 을 시작으로 인덱스 1번 부터 끝까지 모두 정렬을 반복하라는 알고 리즘..
    }
    Print(arr, size, "선택정렬");
}

// [ 삽입정렬 ] (Insertion Sort, O(N2))
// 트럼프 카드에 비교, 카드를 뽑아서(temp 변수에 할당) 위치를 찾은 후 삽입 하는 방식..
// 1번 부터 시작 하여 이전 인덱스와 비교하여 크면 대상을 한칸 오른쪽으로 미는 방식
void InsertionSort(int *arr, const int size)
{
    int j;
    for (int i = 1; i < size; i++) {
        const int temp = arr[i]; // 1번 인덱스 부터 카드 뽑기.

        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            // 뽑아낸 위치에서 한칸씩 왼쪽(arr[j-1])과 비교 후 `arr[j-1]` 값이 크면 오른쪽 밀기
            arr[j] = arr[j - 1]; // 앞의 것이 크면, 뒤로 밀기
        }
        arr[j] = temp;
    }
}

// [ 퀵정렬 ] (Quick Sort) : 정렬의 꽃으로 불리는 빠른 정렬 => O(N logN)
// 편을 나누어 정렬, 분할 정복 방법론
// (예)
// 1. 50 점을 기준으로 좌/우 그룹으로 나눔. : 2 그룹
// 2. 반복적으로 각각의 좌/우 그룹을 반 반 씩 나눔 : 4 그룹
// 3. 8 그룹... -=> 1명이 될때 까지 나눔.
// 4. 원소가 1나 남은 상태가 정렬이 완료된 상태가 됨.
// -------------------------------------------------
// 피벗 : 기준이 되는 값.
// 피벗 뽑기가 성능이 달라짐.
// 대략 배열의 중간 값을 기준으로 함. 피벗은 좌/우 무관함.
// => Pivot : 기준이 되는 값
// => pL : 배열의 가장 작은 (인덱스) 값
// => pR : 배열의 가장 높은 (인덱스) 값
// pivot 으로 pL 먼저 비교하여 값이 (pL < pv) 일때 까지 반복 하면서 참일때 pL 인덱스를 증가 시켜줌
// pivot 으로 pR 을 비교한 후 값이 (pR > pv) 일때 까지 다시 반복 후 참일때 pR 인덱스를 증가 시켜줌
// pL 과 pR 이 크로스 되는 시점이 그룹이 나누어 진 시점
// 그룹이 나누어 지면
// pR 은 왼쪽 그룹의 Right 가 되고
// pL 은 오른쪽 그룹의 Left 가 됨
// 각각의 그룹의 시작 과 끝은 변하지 않음. 원래의 left, right
// 즉, pL 과 pR 의 인덱스가 같아 질때 원소가 1개 남았다고 판단할 수 있음.
// 재귀 호출 필요
void QuickSort(int *arr, const int left, const int right, char pos)
{
    int pL = left;                        //   (left cursor)   first index (0 부터 시작)
    int pR = right;                       //  (right cursor)    last index (size - 1 부터 시작)
    const int pivot = arr[(pL + pR) / 2]; // (middle cursor)  middle index (pL과 pR의 중간값)

    // 원칙 : 왼쪽의 값은 피벗보다 작아야 하고, 오른쪽의 값은 피벗보다 커야 함.
    //       다를 때에는 왼쪽 과 오른쪽 모두 원칙을 위반한 두값을 스왑을 반복해 주는 작업이 요점.
    ///      until -> 왼쪽과 오른 쪽이 같거나 크로스 되어 더이상 비교할 데이터가 없을 때 까지...

    // printf("(%c) pivot = %3d\n", pos, pivot);
    do {
        // pivot 보다 작은 값인지 큰값인지 체크.
        // 왼쪽 통과 기준 => ++ (인덱스)
        // 피벗보다 크면 계속 왼쪽 인덱스 계속 증가 시키기.
        while (arr[pL] < pivot) pL++; // 왼쪽에 있어도 되면 pL 을 뿔뿔..

        // 이곳에 왔다는 것은 위 pL 너 딱 걸렸어 잠시 대기해.. 하는 순간..

        // 피벗보다 작으면 계속 오른쪽 인덱스 계속 감소 시키기.
        // 오른쪽 통과 기준 => -- (인덱스)
        while (arr[pR] > pivot) pR--; // 오른쪽에 있어도 되면 pR 을 마마..

        // 역시 이곳에 왔다는 것은 위 pR 이 너도 잠시 대기 해.. 하고
        // 위 pL 과 pR 을 서로 교체 스왑 주는 작업을 아래에서 수행..하는 장면이 됨

        // [ 스왑 ]
        // (예)
        /* 아래의 배열을 기준으로 처음 시작시... 이런 장면일 때!
            배열   =>    |3|1|7|5|5|2|6|4|8|
            인덱스 =>     0 1 2 3 4 5 6 7 8

                   [값, 인덱스]
           pivot = [5, 4]
           pL    = [3, 0]
           pR    = [8, 8]

           에서 왼쪽 [7, 2]은 피벗[5, 4]보다 큼으로 넌 여기 아니야 하고.. 일단 대기 시킨 후..
           이번엔 오른쪽 [8, 8] 부터 피벗보다 작은지 여부를 점검하니?
           [4, 7]가 피벗보다 작음으로 일단 대기 시킨 후.
           왼쪽 [7, 2]과 오른 쪽 [4, 7]를 아래의 로직으로
           상호 스왑해 주는 작업을 하고.
           다음에 pL 은 => [5, 3]가 되고, pR 은 => [6,6]이 되어
           다시 재귀 호출로 범위를 좁혀 가면서...크로스 되기 전까지는 계속 반복하는 그림..

         */

        if (pL <= pR) {
            const int temp = arr[pL];
            arr[pL] = arr[pR];
            arr[pR] = temp;

            // 교환 후에도 멈추지 말고 왼쪽은 증가, 오른쪽은 감소 시킴 (인덱스라는 것을 명심보감.)
            pL++;
            pR--;
        }
    } while (pL <= pR); // pL 과 pR 배열 인덱스가 크로스 되는 그 시점 까지

    // 재귀 호출방식으로 계속 2진 트리 형태로 잘게 그룹을 나누는 그룹
    // 원소가 딱 하나 남을때 까지... 하나 남았다는 것은 정렬이 완료되었다는 의미...
    if (left < pR) QuickSort(arr, left, pR, 'L');   // 왼쪽 그룹, 원소가 하나 남을 때 까지 조건.
    if (right > pL) QuickSort(arr, pL, right, 'R'); // 오른쪽 그룹, 원소가 하나 남을 때 까지 조건.
}

// [ 2-2 병합정렬, Merge Sort ]
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
void Merge(int *arr, int *arrMerge, const int left, const int mid, const int right)
{
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
            arr[idxM++] = arrMerge[idx1++];  // 실제 arr 배열에 넣는 작업
        else
            arr[idxM++] = arrMerge[idx2++];  // arrMerge[idx2] 작을 때
    }

    while (idx1 <= mid) {
        // 나머지 채워넣기
        arr[idxM++] = arrMerge[idx1++];
    }
}

// [ 2-1 병합정렬 ]
void MergeSortUtil(int *arr, int *arrMerge, const int left, const int right)
{
    if (left < right) {
        const int mid = (left + right) / 2;
        MergeSortUtil(arr, arrMerge, left, mid);      // left
        MergeSortUtil(arr, arrMerge, mid + 1, right); // right
        Merge(arr, arrMerge, left, mid, right);
    }
}

// [ 1 병합정렬 ]
void MergeSort(int *arr, const int size)
{
    int *arrMerge = malloc(sizeof(int) * size); // 값을 비교할 배열. 공간 복잡도 O(N)
    memset(arrMerge, 0, sizeof(int) * size);
    MergeSortUtil(arr, arrMerge, 0, size - 1);
    free(arrMerge);
}

// [ 버킷정렬 ]
// (Bucket Sort) 계수정렬
// O(N)
// 범위가 정해진 경우 엄격한 조건
// 예를 들어 1 ~ 5 까지 배열일 경우, 6개의 버캣을 만듦
void BucketSort(int *arr, const int size, const int range)
{
    // 배열사이즈, 배열의 범위
    int *bucket = calloc(range, sizeof(int)); //  할당된 메모리가 모두 0으로 채워짐. ( 양동이 )

    for (int i = 0; i < size; i++) {
        // 버캣의 인덱스가 배열의 값으로 사용됨
        // 버킷 값 0은 없는 값 2 이상은 중복 된 값.
        bucket[arr[i]]++;
    } // 갯수 카운팅 완료.

    int idx = 0;
    for (int i = 1; i < range; i++) {
        for (int j = 1; j <= bucket[i]; ++j) { // 앞에서 부터 다시 서칭하여 중복된 값 처리 용.
            arr[idx++] = i;                    // 버킷의 인덱스를 배열의 값으로 재할당 하면서 정렬하기.
        }
    }

    free(bucket);
}

// [ 힙(Heap) 정렬 ] (Max Heap, Min Heap)
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
void HeapSort(int *heap, const int size)
{
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

void funPtr(int **p, const int size, int *arr)
{
    // TODO
    for (int i = 0; i < size; i++) {
        p[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", *p[i]);
    }
}

// 힙 구조체
typedef struct heap
{
    // Total Size => 16byte
    int *arr;     // 힙 메모리(배열)의 주소 저장, 8byte
    int cursor;   // 저장된 원소이 갯수, 4byte
    int capacity; // 힙(배열)의 최대 용량, 4byte
} Heap;

void CreateHeap(Heap *heap, const int capacity)
{
    heap->arr = (int *)malloc(sizeof(int) * capacity);
    heap->cursor = 0;
    heap->capacity = capacity;
}

void ShiftUp(int *arr, const int childIdx)
{
    const int parentIdx = (childIdx - 1) / 2;

    if (parentIdx >= 0 && arr[parentIdx] < arr[childIdx]) {
        const int temp = arr[parentIdx];
        arr[parentIdx] = arr[childIdx];
        arr[childIdx] = temp;
        ShiftUp(arr, parentIdx);
    }
}

void AddHeap(Heap *heap, const int value)
{
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

size_t FindIndex(const int a[], const size_t size, const int value)
{
    size_t index = 0;
    while (index < size && a[index] != value) ++index;
    return (index == size ? -1 : index);
}

// [ 힙 ]
void HeapRunner()
{
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
int ClearLeftBits(int num, int i)
{
    return (num & ((1 << i) - 1));
}

/// @brief 특정 비트를 0으로 만들기 &, ~ (And, Not 연산)
/// @param num 변경할 숫자
/// @param i 0 으로 만들 비트
/// @return 변경된 int 정수
int ClearBits(const int num, int i)
{
    return ((num & (~(1 << i))));
}

/// @brief 비트출력
/// @param num
/// @param size
void PrintBit(const long long num, const int size)
{
    printf("0b_");
    for (long long i = size - 1; i >= 0; --i) {
        printf("%lld", (num >> i) & 1); // 0011

        if (i != 0)                     // under bar insert, except last char
            printf("%s", i % 4 == 0 ? "_" : "");
    }
    printf(" (%lld)\n", num);
}

void VariableSize()
{
    /* [사전 몸풀기 */
    //
    // => 16진수 1자리는 2진수 4자리와 동일함, F == 1111, A == 1010
    // => 2진수 4자리는 각각 8 4 2 1 값의 가중치로 10진수를 만들 수 있다.
    //    2진수 1011 은 => 순서대로 8 4 2 1 에서 1일 있는 비트 즉, 8 + 2 + 1를 더하면 10진수 11이다.
    // 그래서 예를 들어 1111 -> 15가 됨으로 16진수 F 1 자릿수에 맞 대응 된다.

    //... 위 내용을 기반으로 해서 아래의 풀이 과정을 보시면 됩니다. ....//
    // (요약 ) 컴퓨터 없이 손가락으로 풀수 있는 과정

    // 즉, 16진수 1 자리는 2 진수 4자리와 동일하는 것만 알면 모두 푸실 수 있는 문제가 됨.
    // 그럼... 수기로 아래와 같이 푸실 수 있습니다.
    // 16진수를 사용하는 이유기도 한 2진수 4 자리는 정확히
    // 가중치가 8 - 4 - 2 - 1 이 됩니다.
    // 2진수 1111 은 8 + 4 + 2 + 1 이 되어 10진수로는 15가 되고 16진수로는 F라는 것 명심보감.

    // 그것으로 문의 하신 모든 문제가 해결이 됩니다.
    // 추가로 컴퓨터는 음수를 2의 보수로 표기 하는 것을 염두에 두시고
    // 아래의 설명글을 참조 하여 보세요...

    // 시작 ....
    // 8421 가중치 방식으로
    // => A 는 10 이므로 (8421) 에서 순서대로 8과 2만 있으면 되니 => 1010
    // => B 는 11 이므로 (8421) 에서 순서대로 8 2 1 이 있으면 되니 => 1011 됩니다.

    /*   [ (1) 번 풀이 ]
                 <0xAB + 0x55>
            ----------------------------
                  1010 1011 (0xAB)
                + 0101 0101 (0x55)
            ----------------------------
              1   0000 0000 (0x100, 256)
            (버림)       0   (256 - 256)  // (1) 문제의 답
            // => 버리는 이유는 1byte 는 8bit 이므로 그 이상의 비트 캐리는
            //    무시함.
     */
    const unsigned char ab = (unsigned char)0xAB;               // 0b1010
    const unsigned char _55 = (unsigned char)0x55;              // 0b1011
    const unsigned char resultAB55 = (unsigned char)(ab + _55); // ==> 0

    /*     [ (2) 번 풀이 ]
                  0xAB + 0xB8
            ----------------------------
                  1010 1011 (0xAB)
                + 1011 1000 (0xB8)
            ----------------------------
              1   0110 0011 (0x163, 355)
            (버림)   6   3   (355 - 256) // (2)번 문제의 답 : 0x63
     */
    const unsigned char b8 = (unsigned char)0xB8;              // 0b1000
    const unsigned char resultABB8 = (unsigned char)(ab + b8); // == 0x63

    /*      [ (3) 번 풀이 ]
                  0xBB - 0xA6
            ----------------------------
                  1011 1011 (0xBB) // 11 11 이므로 ...
                - 1010 0110 (0xA6) // 10 6.. 여기서 6은 가중치 (4, 2) 자리이므로 두번째 세번째가 1
            ----------------------------
                  0001 0101 (16 + 4 + 1)
                    1   5   (355 - 256) // (3)번 문제의 답 0x15
     */
    const unsigned char bb = (unsigned char)0xBB;              // 0b1010
    const unsigned char a6 = (unsigned char)0xA6;              // 0b1011
    const unsigned char resultBBA6 = (unsigned char)(bb - a6); // ==> 0x15

    // [ 2. 문제 풀이 ]...//
    // 부호 있는 1바이트 (-128 ~ 127)
    const unsigned us1 = (unsigned)0xCB; // C => 12 이므로 (8 + 4), B => 11 (8 + 2 + 1)
    //                   1100 1011 ( C B 의 2진수)
    // 그런데?
    // 8비트에서 가장 좌측이 1이므로 음수로 판정합니다.

    // 하여...
    // => 사람다운 계산 법
    //   1      1   0   0   1   0   1   1
    // -128  + 64 + 0 + 0 + 8 + 0 + 2 + 1
    // = -53 (답 1)

    // => 컴퓨터 식 2의 보수로 계산법
    // 1100 1011 ( C B )
    // 0011 0101 (2의 보수)
    //   5   3
    // = -53 (답 2)

    // [ 부호있는 1 바이트 ]
    // => CB => 1100 1011
    // => 최상위 비트 (msb, most significant bit) 1이므로 음수
    // => 사람답게 계산 => -128 + 64 + 8 + 2 + 1 ==> (답: -53)
    // => 컴퓨터식으로 2의 보수 => 0011 0100 + 1 => 00110101 => (32 + 16 + 4 + 1) => 53 => -53

    const signed char signed1Byte = 0xCB;

    // [ 부호없는 1 바이트 ]
    // 최상위 비트가 부호 비트가 아님으로 그대로 가중치를 더해줌
    // => CB => 1100 1011 => 가중치 (128 + 64 + 8 + 2 + 1) ==> 203
    const unsigned char unSigned1Byte = 0xCB;

    // 부호 있는 2바이트 (-32768 ~ 32767)
    // 사이트가 큼으로 그대로 더해주면 됨..
    const short signed2Bytes = 0xCB;

    // 부호 없는 2바이트 (0 ~ 65535)
    // 위와 동
    const unsigned short unSigned2Bytes = 0xCB; // 203

    // 맞는 지 확인 출력 해보기..
    printf(
        "(0xCB)\n"
        "0xAB + 0x55\t=>\t0x%x\n"
        "0xAB + 0xB8\t=>\t0x%x\n"
        "0xBB - 0xA6\t=>\t0x%x\n"
        "signed 1 byte\t=>\t%d\n"
        "unsigned 1 byte\t=>\t%d\n"
        "signed 2 bytes\t=>\t%d\n"
        "unsigned 2 bytes\t=>\t%d\n",
        resultAB55,
        resultABB8,
        resultBBA6,
        signed1Byte,
        unSigned1Byte,
        signed2Bytes,
        unSigned2Bytes);
}

/// @brief 중복 제거 정렬
/// @param arr
/// @param size
void ToUniqueSortedArray(int *arr, const int size)
{
    int even_numbers[32] = {};
    int odd_numbers[32] = {};
    int even = 0;
    int odd = 0;
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            while (index < size && even_numbers[index] != arr[i]) index++;
            if (index == size) // 같은 값이 없다는 의미.
                even_numbers[even++] = arr[i];
        } else {
            while (index < size && odd_numbers[index] != arr[i]) index++;
            if (index == size)
                odd_numbers[odd++] = arr[i];
        }
        index = 0;
    }

    printf("Unique Sort (Even numbers):\t");
    for (int i = 0; i < even; i++) printf("%3d ", even_numbers[i]);
    printf("\n");

    printf("Unique Sort (Odd numbers):\t");
    for (int i = 0; i < odd; i++) printf("%3d ", odd_numbers[i]);
    printf("\n");
}

void BinaryTest()
{
    const int b1 = -3; // (0011)
    PrintBit(b1, 32);
    short num1 = -30;
    unsigned short num2 = num1;
    printf("%d, %#x\n", num1, num2);
    printf("%d, %#x\n", num2, num2);
}

/// @brief CSV Splite
void StringUtils()
{
    // CSV with comma read
    char fname[50], lname[50];
    int id;
    float weight, hgnum;

    FILE *fp = fopen("hello.txt", "r");
    if (fp == NULL) {
        perror("Error: Failed to open file.");
        return;
    }

    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *tmp = strdup(line);
        const char *tok;
        for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",")) {
            printf("%s\t", tok);
        }
        printf("\n");
        free(tmp);
    }

    fclose(fp);
    char temp[] = "   \t  hi  \t  ,  \t  everyone,  \t fine  \t  , thanks , \t  and , you";
    char *t = strtok(temp, ",");
    while (t != NULL) {

        // ltrim
        while (isspace(*t)) t++;

        // rtrim
        char *b = t;
        char *back = b + strlen(b);
        while (isspace(*--back));
        *(back + 1) = '\0';
        printf("%s-%s\n", t, b);

        t = strtok(NULL, ",");
    }

    // FILE *file = fopen("../data/data.txt", "ab+");
    // if (file == NULL) {
    //     perror("Error: Failed to open file.");
    //     return 1;
    // }
    // fprintf(file, "Hi Everyone.\n");
    // // system("touch hello.txt");
    // fclose(file);
}

long long memo[100];
long long Fibonacci(int n);
long long FibonacciMemoization(int sum)
{
    if (memo[sum] == -1)
        memo[sum] = Fibonacci(sum);
    return memo[sum];
}

long long Fibonacci(int n)
{
    return //     첫번째 달                       두번째
        n <= 1 ? n : FibonacciMemoization(n - 1) + FibonacciMemoization(n - 2);
}

int main(void)
{
    setlocale(LC_NUMERIC, "");

    srand(time(NULL));
    // 정렬
    int target[MakeRandom(10, 15)];
    int size = sizeof(target) / sizeof(int);
    for (int i = 0; i < size; i++)
        target[i] = MakeRandom(1, 100);

    int j = 0;
    Print(target, size, "원소스");

    BubleSort(target, size);     // 버블정렬
    SelectionSort(target, size); // 선택정렬
    MergeSort(target, size);     // 병합정렬
    Print(target, size, "병합 정렬");

    BucketSort(target, size, 100);
    Print(target, size, "버캣 정렬");

    HeapSort(target, size);
    HeapRunner();

    InsertionSort(target, size);         // 삽입정렬
    Print(target, size, "삽입 정렬");

    QuickSort(target, 0, size - 1, 'P'); // 퀵정렬
    Print(target, size, "퀵 정렬");

    VariableSize();

    // 중복제거 정렬
    printf("\n");
    int temp[] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
    ToUniqueSortedArray(temp, 16);

    // 캐시(memoization array)
    // 초기화
    for (int i = 20; i <= 50; i++) {
        for (int j = 0; j < 100; j++) memo[j] = -1;

        int month = i;                            // 3 ~ 50 개월
        long long sumOfRebbit = Fibonacci(month); // 각 개월 마다 결과

        // 출력
        printf("( \033[31m%d\033[0m ) 개월 후 토끼의 전체 개체수 합 : ( \033[32m%'20lld\033[0m )\n", month, sumOfRebbit);
    }

    float demo = 3.2f;
    printf("문의내용\t%%f\t-> %f\n", demo);
    printf("해결책(1)\t%%g\t-> %g\n", demo);
    printf("해결책(2)\t%%.2f\t-> %.1f\n", demo);
    return 0;
}

/**
 * lldb
 x -s1 -fx -c60 -l20 &str

memory read -fd -s1 -c60 -l20 &str

register read --formant binary x1

register read --format i
re r -f i
register read/d
re r -a
register read --all

memory read --size 4 --format x --count 4 0xbffff3c0
x -s4 -fx -c4 0xbffff3c0
me r -s4 -fx -c4 0xbffff3c0
memory read `argv[0]

Save to file
memory read --outfile /tmp/mem.txt --count 512 0xbffff3c0
me r -o /tmp/mem.txt -c512 0xbffff3c0
x/512bx -o /tmp/mem.txt 0xbffff3c0

starting a 0x10000 and ending a 0x2000 to a file
memory read --outfile /tmp/mem.bin --binary 0x1000 0x2000
me r -o /tmp/mem.bin -b 0x1000 0x2000

command script import lldb.macosx.heap

ptr_refs EXPR
ptr_refs str
ptr_refs &str
cstr_refs CSTRING

disassemble --frame
di -f

disassemble --name main
di -n main

disassemble --frame --bytes
di -f -b

disassemble --line
di -l

image list
image lookup --address 0x1ec4

frame variable
frame variable i

frame variable -fd &str[1]

* /
