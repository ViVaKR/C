#include <Kernel/stdbool.h> // _Bool
#include <assert.h>         // assert
#include <ctype.h>          // tolowere(int argument),
#include <float.h>
#include <limits.h>         // 정수 유형에 대한 다양한 구현 밸 제한을 정의
#include <locale.h>         // 천단위 콤마.
#include <math.h>           // 수학함수
#include <stdbool.h>        // true, false 를 정의
#include <stdio.h>          // printf, scanf 입/출력 기능 제공
#include <stdlib.h>         // 메모리 할당, 랜드 함수 및 유틸리티 기능
#include <string.h>         // strcpy, strlen 등 문자열 조작
#include <time.h>           // 날짜와 시간으로 작업한는 기능
#include <unistd.h>         // sleep(unsigned int)

#define PI           3.141592
#define clear()      printf("\033[H\033[J");
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

int MakeRandom(int min, int max)
{
    const int number = (rand() % (max - min + 1)) + min;
    printf("Hello");

    return number;
}

void compress(char *instr, char *outstr)
{
    char c = instr[0];
    int p = 0;
    int cnt = 0;             // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        if (c == instr[i])
            cnt++;           /* 이전과 같은 문자열이면 cnt 늘리기 */
        else if (cnt == 1) { /* 이전과 달라지는데 다른 문자열, 한 번이면 이전 문자열 출력하고 c에 현재 문자열 넣기 */
            outstr[p++] = c;
            c = instr[i];

        } else { /* 이전과 달라지는데 다른 문자열이 이미 여러개 쌓인 경우면 이전 숫자, 이전 문자열 출력하고 현재
                    문자열로 갱신, 그리고 다른 문자열이 한 번 나온 상태이므로 cnt =1로 초기화 */
            outstr[p++] = cnt + '0';
            outstr[p++] = c;
            c = instr[i];
            cnt = 1;
        }
    }
    /* 반복문 끝나고 NULL 나올때 출력하는 방법 */
    if (cnt == 1)
        outstr[p++] = c;
    else {
        outstr[p++] = cnt + '0';
        outstr[p++] = c;
    }
    outstr[p] = 0; /* 문자열 마지막에 NULL 입력 */
} // 1번

void compress_2(char *instr, char *outstr)
{
    _Bool tf = true;

    char c = instr[0];
    int p = 0;
    int cnt = 0; // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        if (c == instr[i])
            cnt++;
        else if (cnt == 1) {
            outstr[p++] = c;
            c = instr[i];
        } else {
            outstr[p++] = c;
            outstr[p++] = cnt + '0';
            c = instr[i];
            cnt = 1;
        }
    }
    if (cnt == 1)
        outstr[p++] = c;
    else {
        outstr[p++] = c;
        outstr[p++] = cnt + '0';
    }
    outstr[p] = 0;
} // 1-1번

void decompress(char *instr, char *outstr)
{
    int p = 0;
    int cnt = 1;                    // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        char c = instr[i];
        if (c >= '0' && c <= '9') { /* 숫자인 경우 cnt로 횟수 저장 */
            cnt = c - '0';
        } else {                    /* 문자열인 경우 cnt만큼 문자열 출력 */
            for (int j = 0; j < cnt; j++) {
                outstr[p++] = c;
            }
            /* 문자열 출력하고 나서 cnt 1로 초기화 */
            cnt = 1;
        }
    }
    outstr[p] = 0; // output[0] = 0인가요?
}

void StringCompressStart()
{
    char *origin = "zzzzzzzzaaabbcdddeee";
    printf("[ %s ]\n", origin);
    char output[sizeof(origin)];
    compress(origin, output);
    printf("%s\n", output);

    char output_compare[10];
    compress_2("ZZZZZZZZ", output);
    printf("%s\n", output);
    char compare[] = "8z3a2Bc3d3e";
    decompress(compare, output);
    printf("%s\n", output);
}

/// @brief 노드 공용
typedef struct vnode
{
    int value;
    struct vnode *next;
} node;

node *head = NULL;

// 첫번째 노드삭제
node *RemoveFrontNode()
{
    if (head == NULL)
        return NULL;

    // (1) 삭제할 첫번째 노드를 => 임시 노드에 저장
    node *temp;

    temp = head;

    // (2) head를 삭제할 노드 => 다음 노드로 이동
    head = head->next;

    // (3) 첫번째 노드를 제거, free 는 temp 가 가르키는 대상이 제거됨.
    node *del = temp->next; // 제거된 노드 주소를 반환하기 위함 (temp 가 아님..)
    free(temp);
    return del;
}

/// (3) Print All Nodes
void DisplayNode()
{
    int count = 0;
    node *current;

    if (head == NULL)
        return;
    system("clear");

    printf("\n\n[ \u2665 Display LinkedList \u2665 ]\n\n");
    current = head;
    do {
        printf("(%3d) current node address: %11p, node value: %4d\n", ++count,
               current->next, current->value);
        current = current->next; // second address
    } while (current != NULL);
    // Last Node
    // printf("(%3d) current node address: %11p, node value: %4d\n", ++count,
    // current->next, current->value);
}

/// (4) 노드의 갯수 구하기
int GetNodeCount()
{

    node *current; // 방문노드의 주소를 저장하는 포인터변수 8바이트
    if (head == NULL)
        return 0;

    current = head;
    int count = 0;

    while (current != NULL) {
        ++count;
        current = current->next;
    }
    return count;
}

/// Remove All Nodes, Moemory Free
int LinkedListMemoryFree()
{
    // 링크드리스트 노드 메모리 해제 작업
    // 선두 노드를 제거하는 작업을 반복하는 알고리즘.
    node *temp;
    if (head == NULL)
        return 1;

    int count = 0;
    printf("총 노드의 수 =>\t%d \n", GetNodeCount());
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        count++;

        int remained = GetNodeCount();
        printf("남아있는 노드 =>\t%d \n", remained);
        usleep(50000);
    }
    return count;
}

void LinkedListStartAtLast(int count)
{
    // TODO
}
// (2) LIFO 노드 만들기
void InsertFrontNode(int data)
{
    node *newNode;                          // 새로운 노드 포인터 선언
    newNode = (node *)malloc(sizeof(node)); // 새로운 노드에 힙 메모리 할당. (객체 생성)
    newNode->value = data;                  // 새로운 노드에 일단 값은 할당.
    newNode->next = NULL;                   // 아직 다음 노드 연결 전...

    if (head == NULL) {                     // head 가 없을 때? 즉, 처음 연결시..
        head = newNode;
        char *address = (char *)malloc(32);
        sprintf(address, "%11p", head->next);
        printf("첫 노드 연결\t=> %s (%5d)\n",
               head->next == NULL ? "Started Head" : address, head->value);
        free(address);
        return;
    }
    // 여기 왔다는 것은 -> header 가 있고.. front 에 삽입하는 장면 ...

    // (header 와 기존 선두 node 앞에 노드 삽입할 때 장면) ... 순서가 매우 중요함.
    newNode->next = head; // head 노드 포인터가 가르키는 기존 선두 노드 주소를 새로 만든 뉴 노드 next 가 가르키게 리 매핑한후.
    head = newNode;       // 해더 즉, 루드가 가르키는 노드 시작 포인터를 -> 새로 만든 newNode 로 갱신하는 장면.

} // End InsertFrontNode

/// (2) FIFO 후미에 노드 만들기
void InsertTailNode(int data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    int count = 0;

    if (head == NULL) {
        head = newNode;
        char *address = (char *)malloc(32);

        sprintf(address, "%11p", head->next);

        printf("( %3d ) 첫 노드 연결\t=> %s (%5d)\n", ++count, head->next == NULL ? "Started Head" : address, head->value);
        return;
    }

    // 연결리스트 순회 하여 마지막 노드의 위치 확인
    node *current; // 방문노드의 주소를 저장하는 포인터 변수 (8바이트)
    current = head;

    while (current->next != NULL) {
        // 이곳에 왔다는의미는 current->next 에 다음 노드 포인터인 주소값이 있다는 의미이므로.
        // 마지막 노드가 아니라는 의미이기도 하므로.. 그
        //  current-> next 에 저장된 그다음 노드 주소 를
        // 지금 현재 노드에 다시 갱신 할당하면서
        // 자연스럽게 current node를 한칸 씩 전진 시키는 장면이됨.
        // 요약 : current->next 가 null 인 마지막 노드를 찾는 여정.
        current = current->next; // current++
    }

    // 여기에 왔다는 것은
    // current->next 가 null 인 즉, current 가 마지막 노드 포인터가 됨.
    // 그래서 그, 마지막 노드와 새노드를 연결하는 장면.
    current->next = newNode;
    printf("( %3d ) 일반 노드 연결 (후미)\t=> %11p (%5d)\n", GetNodeCount(), current->next, newNode->value);
}

// (3) 중간 노드 삽입
void InsertMiddleNode(int data)
{
    /* 치장 파트 (신경 쓸 필요 없음.)*/
    printf("\n삽입할 데이터 : \033[31m( %d )\033[0m \n\u27a5 Ready... ", data);
    fflush(stdout);
    usleep(2000000);
    printf("\033[31m \nGo...\n\033[0m");

    /* Start */
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;

    if (head == NULL)   // 아직 연결리스트가 만들어 지지 않은 상태.(if true )
    {
        head = newNode; // 처음 샘플 헤드 값이 -> [ 32 ] 인 경우
        return;         // 일단 헤더 만 만들고 더이상 진행 할 필요 없으므로 함수 종료.
    }

    /*  [ 3가지 상황별 분해 ]
            1. 가장 작은 값을 선두에 삽입하는 상황
            2. 중간에 삽입하는 상황
            3. 가장 큰값을 끝에 추가하는 상황.
     */

    //--> (1) 가장 작은 값 삽입
    //        맨 앞에 넣어야 함으로 head 가 변경되어야 함으로. 조건 문으로 따로 뺌.
    // e.g. | 32 | 99 | 122 | 인 현 상태에서 -> `8번 값` 노드를 선두에 삽입하는 시나리오.

    if (head->value > newNode->value) // 물어봄?, 헤드 보다 새로운 노드의 값이 자그냐? -> 가장 작은 값이라는 의미.
    {
        //--> `head` 가 --> `32번` 주소를 가르키고 있는 상태에서
        //--> `newNode` 가 --> `8번`을 가지고 온 상태.

        /* 즉, 기존 32번 노드 앞에 추가해야 하는 상황 */

        // 진행 ...
        // 현재 탑 노드인 -> `32번 노드` 의 주소값을 알고 있는
        // `head` 값을 -> `newNode->next` 에 먼저 할당하고...
        newNode->next = head;

        // 그 다음 head 주소를 `32번 노드 주소` 값에서..
        // `8 번값 newNode` 주소로 갱신.
        // 기존에 head 가 가르키던 값 `5 노드` 주소를 `3번 노드` 주소로 변경 갱신하는 장면.
        head = newNode;
        return; //--> 가장작은 값 넣기 끝 (함수 종료, 아래 중간값 및 가장 큰값 삽입 단계 진행 안함.)
    } // (1) 끝.

    //--> (2) 일반적인 경우, 중간에 끼워넣는 경우.
    //    e.g | 8 | 32 | 99 | 122 | 인 현 상태에서 -> 50번 값 노드를 중간에 삽입하는 시나리오.
    //    진행 : 앞에서 부터 순회하여 값을 비교 하는 절차가 필요함으로
    //          임시 current 방문용 노드 를 만들어서 방문하는 노드로 하여 앞에서 부터 순회 방문 시작
    //    행위 : curent 노드가 방문하는 노드마다 더 큰 값이 있는지 확인하는 판별 절차..
    //          더 큰 값이 있으면? -> 그 값(더 큰값, 99)을 저장한 상태의 그 current node 를 똭 멈춰 버림.
    //    그다음 : 32번 노드의 next 를 -> newNode 에 연결, newNode->next 에 -> 99번 노드를 포인팅 (연결) 하면 되는데?
    //    ... but ???? ...
    //    newNode->next 에 99번을 연결하는 것은 문제없으나? (current 가 알고 있음으로...)
    //    32번 노드를 current 가 알지 못함으로, 32번을 newNode 에 연결하는 방법이 없음.
    //    왜냐하면? -> 다음 주소는 next 에 있음으로 알수 있는데, 이전 주소는 알지 못하는 단일 연결노드,즉 싱글이므로...
    //    그래서 .. 포인터를 하나 더 만들어야 함. -> 이전 주소를 저장하는 포인터 변수.
    //    이름하여 -> 두둥 -> `prev`
    //    하여 prev (한박자 뒤에 따라다니며 이전 주소 저장), current (천둥벌거숭이 노드) 두개의 임시 노드 생성. 후 진행.

    // head 값으로 초기화 하는 것으로 시작.
    // 즉, 3개의 노드 head, prev, current 가 같은 출발점에서 시작하기.
    node *prev = head;
    node *current = head;

    // 이미 첫번째 노드는 위 (1) 번에서 걸러 내었으므로 제외 함. (첫 노드 보다는 크다는 의미이므로)
    // 두번째 노드 부터 시작..
    // e.g. Saved nodes => | 8 | 32 | 99 | 122 | 인 현 상태에서
    //                            |`50`| 노드를 중간에 삽입하는 시나리오.
    while (current->next != NULL) {
        // newNode 가 값 50을 들고 온 상태 가정 시나리오...

        // current 를 한박짜 먼저 움직여주는 장면
        // 첫번째는 비교할 필요가 없으므로...바로 이동시킴..
        // 위 sample 노드 8 스킵하고 32번 부터..
        current = current->next; // 즉, 아래 비교 하기 전에 current 를 먼저 움직여 줌이 매우 중요함..

        // | (1) -> 50 이 32 보다 크냐? -> (2)로 이동
        // | (4) -> 그래 이번에 뉴 페이스 99! 냥?
        //          99 넌, 50보다 크냐?. -> (5) 로 이동 |
        if (current->value > newNode->value) {
            // (5) 큰 상황
            // (6) 현 상태 현황 중간 분석 : prev 는 `32` 에 있고 current 는 `99` 멈춰 있는 상태 (이 대목이 이해가 되어야 함.!)
            // (7, 최종)
            newNode->next = current; // 먼저 현재 잠시 대기 시킨 current 를 newNode next 에 연결하고..
            prev->next = newNode;    // (8, 끝) 직전노드의 다음 주소값을 newNode 주소로 변경한 후 최종 마무리 되는 결론. 끝...
            return;                  //--> 중간값 삽입 끝 (함수 종료, 아래 가장 큰값 삽입 단계 진행 안함)
        }
        // (2) -> 그래 나 (current) 가 크다. 왜?... -> (3)으로 이동
        // (3-1) -> 그럼 prev 노드를 다음으로 이동 시키고 돌아라..오바.. -> while 로 가서
        prev = prev->next;
        // (3-2) -> 가즈아...,
        // 이 단계에서는 prev 와 current 가 같아짐...
        // 그러서 다음..-> while(... )로 갔다. 마지막이 아닌지 확인한 후
        // -> current 를 한발짝 앞으로 전진시킨 후 -> (4) 로 이동
    } // (2)  끝

    //--> (3) 가장 큰값을 삽입하는 경우.
    // e.g. Saved nodes => | 8 | 32 | 99 | 122 | 인 현 상태에서
    //                             가장 큰 값 -> |`150`| 을 추가하는 상황.

    // 위의
    // 가장 작은 값
    // 중간 값 단계를 거치지 않고 여기까지 왔다는 것은
    // 가장 큰값이 들어 왔다는 의미이므로..
    // current->next 가 NULL 인 상태이므로..
    // 바로 newNode 를 할당하면 끝남..
    current->next = newNode;
}

// (1) Linked List
void LinkedListStart(int count, bool order)
{
    srand(time(NULL));
    for (size_t i = 0; i < count; i++) {
        if (order == 1)
            InsertFrontNode(i + 1);
        else
            InsertTailNode(i + 1);
    }
}

/// (6) 값을 통한 노드 삭제
void RemoveNodeByValue()
{
    int value;
    printf("삭제할 값 입력\n>> ");
    scanf("%d", &value);
    fflush(stdin);

    node *delNode;

    if (head == NULL) {
        printf("연결 리스트가 구성되지 않아 삭제할 노드가 없습니다.");
        return;
    }
    printf("삭제할 노드의 값은 %d 입니다.\n계속하시려면 아무키나 누르세요.", value);
    getchar();
    usleep(50000);

    // 삭제할 노드가 첫번째 노드 삭제할 경우.
    if (head->value == value) {
        // 첫노드 삭제
        delNode = head;
        head = head->next; // head 를 다음으로 이동
        free(delNode);
        return;
    }

    // 중간삭제
    node *prev; // 삭제할 이전노드의 포인터

    // 첫번째 노드 부터 검색 시작
    prev = head;
    delNode = head;

    // prev 로 다음 널체크를 한 다음
    // 널이 아니면? delNode 를 먼저 움직임.

    while (prev->next != NULL) {

        delNode = prev->next;

        if (delNode->value == value) {

            // 연결
            prev->next = delNode->next;

            // (출력을 위한 임시 저장)
            node *n = delNode;
            int v = delNode->value;

            // 삭제
            free(delNode);
            printf("삭제 완료 하였습니다. ( \n%p => %d ) \n", n, v);
            free(n);
        }
        prev = delNode;
    }

    sleep(1);
    printf("계속하려면 아무키나 누르세요!");
    getchar();
}

void FPrinfEx(int a, int b)
{
    FILE *fp = fopen("fprintf.txt", "w");
    fprintf(fp, "%d + %d = %d\n", a, b, a + b);

    fclose(fp);
}

/// Min Max
void GetMax()
{
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
}

void SPrintfEx(int a, int b)
{
    char str[128];
    sprintf(str, "%d + %d = %d", a, b, a + b);

    printf("%s\n", str);
}

void ClockEx()
{

    clock_t start, end; // unsigned long
    double total;

    start = clock();
    printf("Starting of the program, Start = %ld", start);

    int sum = 0;
    for (size_t i = 0; i < 10; i++) {
        sum++;
        printf("=> ( %d )\n", sum);
        fflush(stdout);
        sleep(1);
    }
    end = clock();
    printf("End of the loop, End = %ld\n", end);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf(
        "Sum = ( %d )\n=> Total time taken by CPU: %f\n",
        sum,
        duration);
}

void AssertEx(int a, int b)
{
    assert(a == b);
}

void CTypeEx(char ch, int number)
{
    bool digit = isxdigit(number);
    printf("%d\n", digit);
}

void SScanfEx(char *str)
{

    double pi;
    char ch;
    char name[20];

    sscanf(str, "%lf %c %s", &pi, &ch, name);
    printf("%lf, %c, %s\n", pi, ch, name);
}

void BoolEx(_Bool tf)
{
    if (tf)
        printf("Hello World %d\n", tf);
    else
        printf("False %d\n", tf);
}

void SignalHandler(int sig)
{
    printf("\nCaughted Signal => ( %d )\n", sig);
}

void PointerArray()
{
    // 원본 => int x[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // => 설명을 위해 아래와 같이 변경함, x 를 => arr2d 로 이름변경,
    //    (동일한 의미의 배열, 원래 다차원 배열이라도 위와 같이 실제 메모리에는 한줄로 줄서 있는 형식임...)

    //       [행][열]
    int arr2d[4][3] = {
        {1, 2, 3},    //-> arr2d[0]
        {4, 5, 6},    //-> arr2d[1]
        {7, 8, 9},    //-> arr2d[2]
        {10, 11, 12}  //-> arr2d[3]
    };

    int(*p)[3];       // 위 원본을 3개썩 짜르니 가로 세로 4 * 3 의 매트릭스에서 1차원 배열 3개 짜리 * 4행을 지칭? 하는 가르키?는 말이됨. -> 즉, (배열 포인터)
    int *pp[3];       // 포인터로 이루어진 배열 3개 즉, -> (포인터 배열 )

    p = &arr2d[1];    // (1) == 두번째 행인 -> 배열 &{ 4, 5, 6} 의 첫번째 주소가, 저장된 변수.
    pp[0] = arr2d[2]; // (2) == &{ 7, 8, 9}, 에서 0번째 요소 즉,번-> 7번 방 주소.

    printf(
        "(*p)[0]\t\t=>\t%d\np[1][0]\t\t=>\t%d\n*pp[0]\t\t=>\t%d\n**(p = 1)\t=>\t%d\n",

        (*p)[0],  // -> 의미 : 위 (1) 을 유심히 관찰 후 -> 해석, -> {4, 5, 6} 의 0번째 인덱스의 값 (역참조 *)을 가져 -> 오라이..하여 -> 4이며,
        p[1][0],  // -> 의미 : 바로 위 가 보면 => (*p)[0] 은 => p[0][0] 과 같음, 하여 => p[1][0] 은 => (*(p + 1)[0]) 과 같음 -> 다음 행의 첫번째 값이 머냐는 것임 결론 => 위 (1) 에서 인덱스를 하나 증가 시킨 효과 때문에, 원배열에서 하나 더 추가 arr2d[2] 행의 0번째 인덱스 값이 머냐는 것임 하여 답은 => 7 이됨.
        *pp[0],   // -> 의미 : 위 (2) 번을 뚜러지개 관찰 후 -> 해석 => 배열 { 7, 8, 9 } 의 0번째 index 값을 가져 -> 다라이 하여 7이고,
        **(p + 1) // -> 의미 : 다시 위 (1) 으로 돌아가서..=> p 는 {4, 5, 6}을 가르키는 배열 포인터 이므로 => 그거에 하나 더하면  => {7, 8, 9} 를 가르키는 포인터가 됨.. 하여 => 역참조 *(p + 1)) 하나 이면? => {7,8,9} 를 가르키는 0번 인덱스 주소값이 되고 => * 을 하나 더 추가  **(p + 1)을 하니 자연스럽게  => 0번째 인덱스 주소가 아닌, 해당 값을 달라고 한 것이니 => 답은 => 7.

    );

    // 최종 답 => 1번 입니다. 다른 건 다 7인데, 1번만 독고 다이 4 임.

    char input;

    printf("문자형 입력(%%c) : ");
    scanf("%c", &input);
    printf("문자로 출력(%%c) : %c\n", input); // 'A'

    // `A` 아스키 => 65
    printf("Input Char `%c`, ASCII Code Number\t:\t%d\n", input, input);
    // `0` 아스키 => 48
    printf("ASCII Code `%c`, ASCII Code Number\t:\t%d\n", '0', '0');
    // 그러므로...
    printf("\u2234 %c - %c = %d\n", input, '0', input - '0'); // 17, (65 - 48)

    printf("\n%1$c %1$d\n", input);

    char a = 'a';
    char *abcd = "ABCDE";
    // Format Specifiers
    // %<사용할변수 순번 : 1번 부터 시작>$<정렬방향, - => left, + => right()><전체자릿수>.<소숫점이하자릿수><출력형식지정자>
    printf("\n%1$-20c\n%1$20c\n%2$-20s\n%2$20s\n", a, abcd);
}

long long Fibonacci(int n);

long long memo[200]; // 중복된 값 처리..

long long Fibonacci_memoization(int num)
{
    if (memo[num] == -1)            // 새로운 값이면?
        memo[num] = Fibonacci(num); // 힘들게 돌고
    return memo[num];               // 그렇지 않으면? 있는 그 값을 돌려 줘라...
}

int count = 0;

long long Fibonacci(int n)
{
    count++; // 몇 번 도는 지 체크 ...
    // 재귀를 구성 자체가 2진 트리 형태이므로
    // 메모, 케쉬된 값으로 중간에 그 악?의 축을 절단하면
    // 엄청난 횟수 차감효과가 발생함.
    return n <= 1 ? n : Fibonacci_memoization(n - 1) + Fibonacci_memoization(n - 2);
}

void FibonacciStart()
{

    for (size_t i = 0; i < 100; i++) {
        memo[i] = -1;
    }
    puts("");
    int number = 80; // 그냥 돌리면, 꽤 시간이 걸림..
    // F50 = 12586269025
    //       12586269025
    // F80 = 2.3416728348468E+16
    // memoization => 23416728348467685 (81회 순회)

    long long result = Fibonacci(number);
    printf("Fibonacci %d, result = %lld, counting recurs => (%d)\n", number, result, count);
}

void StringCopy(char *university, char *school)
{
    int i = 0;
    while ((university[i] = school[i]) != '\0') i++;
    printf("\n%s, %s\n\n", university, school);
}

void CompareNumbers()
{
    long number;
    printf("3의 배수여부를 판단할 양의 정수를 하나를 입력하세요\n>> ");
    scanf("%ld", &number);
    char *result[] = {"3의 배수입니다.", "3의 배수가 아닙니다."};
    printf("%ld -> %s\n", number, result[(number % 3) & 1]);
    long a, b, c;
    printf("비교할 숫자 3개를 한칸씩 띄워서 입력하세요\n>> ");
    fflush(stdin);

    long rs[] = {};
    long input[] = {0, 0, 0};
    scanf("%ld %ld %ld", &input[0], &input[1], &input[2]);
    rs[(input[0] > input[1]) + (input[0] > input[2])] = input[0];
    rs[(input[1] > input[0]) + (input[1] > input[2])] = input[1];
    rs[(input[2] > input[0]) + (input[2] > input[1])] = input[2];
    printf("(%ld - %ld - %ld) 중 두번째로 큰수는 => (%ld) 입니다. ", input[0], input[1], input[2], rs[1]);
}

// DateTime
typedef struct
{
    int y; // 년
    int m; // 월(1~12)
    int d; // 일(1~31)
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);
/*--- 각 달의 날 수 ---*/
static int mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 평년
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 윤년
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- y년 m월 d일을 나타내는 구조체를 반환하는 DateOf 함수 ---*/
Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수 ---*/
Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if (++x.m > 12) {
            x.y++;
            x.m = 1;
        }
    }
    return x;
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);

    x.d -= n;

    while (x.d < 1) {
        if (--x.m < 1) {
            x.y--;
            x.m = 12;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }

    return x;
}

/*--- 날짜를 표시 ---*/
void Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char *ws[] = {"일", "월", "화", "수", "목", "금", "토"};
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d년%02d월%02d일(%s)", x.y, x.m, x.d,
           ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

void GetDate()
{
    int y, m, d;

    printf("날짜를 입력하세요.\n");
    printf("년: ");
    scanf("%d", &y);
    printf("월: ");
    scanf("%d", &m);
    printf("일: ");
    scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("며칠 전/후의 날짜를 원합니까?: ");
    scanf("%d", &n);

    printf("%d일 후의 날짜: ", n);
    Print(After(x, n));
    putchar('\n');

    printf("%d일 전의 날짜: ", n);
    Print(Before(x, n));
    putchar('\n');
}

void FloatToBinary(float num)
{
    int exp, sign;
    float mantissa = frexpf(num, &exp); // 가수부와 지수부 계산
    if (num < 0) {
        sign = 1;                       // 음수 처리
        mantissa = -mantissa;
    } else {
        sign = 0;                       // 양수 처리
    }

    printf("실수 값 %f의 2진수 표현: %d ", num, sign);
    for (int i = FLT_MANT_DIG - 1; i >= 0; i--) {
        mantissa *= 2;
        if (mantissa >= 1) {
            printf("1");
            mantissa -= 1;
        } else {
            printf("0");
        }
    }
    printf(" x 2^%d\n", exp - 1);
}

typedef struct p
{
    int x, y;
} PT;

void calcPoint(PT *x, PT *y, PT *z)
{
    z->x = x->x + y->x;
    z->y = x->y + y->y;
}

void BigO(int number)
{
    // 등차수열의 합의 공식
    int sum = (number + 1) * number / 2;
    printf("O(1) => %d\n", sum);
    sum = 0;
    for (size_t i = 1; i <= number; i++) {
        sum += i;
    }
    printf("O(N) => %d\n", sum);
}
void Menu();

void GetPrimeNumber(int a)
{
    int isPrime;
    printf("[ ( %d ) Prime numbers ]\n%3d\t", a, 2);
    for (int i = 3; i <= a; i++) {
        isPrime = 0;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) // substitute the 'rem' variable for an operation
            {
                isPrime = 1;
                break;
            }
        }
        if (isPrime == 0) {
            printf("%3d\t", i);
        }
    }

    printf("\n");
}

typedef int *Score;

typedef struct stack
{
    int max;
    int top;
    Score *score;
} Stack;

Stack *CreateStack(int max)
{
    Stack *s = (Stack *)malloc(sizeof(struct stack));
    s->max = max;
    s->top = -1;
    s->score = (Score *)malloc(max * sizeof(Score));
    return s;
}

int IsEmpty(Stack *s)
{
    return s->top == -1;
}

int IsFull(Stack s)
{
    return s.top == s.max - 1;
}

void Push(Score score, Stack *s)
{
    if (IsFull(*s)) {
        s->max *= 2;
        s->score = (Score *)realloc(s->score, s->max * sizeof(Score));
    }
    s->top++;
    s->score[s->top] = score;
}

Score Pop(Stack *s)
{
    if (IsEmpty(s)) {
        printf("================ Stack empty! =================\n");
        exit(1);
    }
    return s->score[s->top--];
}
void DestroyStack(Stack *s)
{
    free(s->score);
    free(s);
}

// 국가 타입별 고유번호 설정
typedef enum Nation
{
    Korea = 1,
    USA = 2,
    Venus = 3,
    Saturn = 4,
    Mars = 5,
    Andromeda = 6,
    Last = 7
} Nation;

const char *ToString(Nation n)
{
    switch (n) {
        case Korea    : return "대한민국";
        case USA      : return "미국"; break;
        case Venus    : return "금성국";
        case Saturn   : return "토성국";
        case Mars     : return "화성국"; ;
        case Andromeda: return "안드로메다제국";
        case Last     : return "--";
    }
    return "<none>";
}

void JisikIn()
{
    char *genre[] =
        {"로맨스", "판타지", "드라마", "코미디", "귀신", "스릴러", "SF",
         "판탑지", "다큐", "키즈/가족", "애니메이션",
         "한국", "미국", "금성", "토성", "화성", "안드로메다", "기타"};

    printf("\n=== 국가를 선택하세요 ===\n");

    Nation nation;

    // 국가 번호별 국각명 메뉴로 표현하기.
    for (int i = Korea; i != Last; i++)
        printf("%d. %s\n", i, ToString(i));

    printf("\u21E2 "); // 입력 모냥내기.

    scanf("%d", &nation);

    // 출력 파트 국가별 시작 인덱로 2썩 건너뛰며 추천 장르 출력하기 (문의에 대한 답별)
    printf("[ %s 추천영화목록 ]\n", ToString(nation));

    for (int i = nation; i < sizeof(genre) / sizeof(*genre); i += 2)
        printf("\u21E2 %s\n", genre[i]);
}

void SelfXor()
{
    int a = 456;
    int rs = a ^ a;
    printf("%d\n", rs);
}

// Maze
#define MAX_STACK_SIZE 100
#define MAZE_SIZE      6

typedef struct
{
    short r; // 2바이트, 0과 1
    short c;
} element;   // element라는 이름의 구조체, 전역함수

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType; // 전역함수

void init_struct(StackType *s)
{
    s->top = -1; // 스택 초기화
}

int is_empty(StackType *s)
{
    return (s->top == -1); // 비었을 때
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1)); // 다 채웠을 때
}

void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n"); // 다 채운상태면 에러
        return;
    } else s->data[++(s->top)] = item;       // 1 더하고 push한 것이 top
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n"); // 빈 상태면 에러
        exit(1);                             // exit(1) = 강제종료, <stdlib.h> 필요
    } else return s->data[(s->top)--];       // pop하고 1 빼서 가장 위의 값이 top
}

element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n"); // 빈 상태면 에러
        exit(1);
    } else return s->data[s->top];           // peek = top
}

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    // = 없어도 문제 없음
    //
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

void push_loc(StackType *s, int r, int c)
{
    if (r < 0 || c < 0) return;                 // 미로를 벗어났을 경우,return; = 함수를 끝냄 -> 아무값도 저장되지 않음
    if (maze[r][c] != '1' && maze[r][c] != '.') // 행,열이 1이 아니고 .도 아닐 때만 push
    {
        element tmp;                            // push 함수에 넣기 위해 (r,c)를 tmp로 축소하고 element로 선언
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);                           // top = tmp[r][c]
    }
}

void ShowHideCursor(bool show)
{
#define CSI "\e["
    if (show) {
        fputs(CSI "?25h", stdout);
    } else {
        fputs(CSI "?25l", stdout);
    }
#undef CSI
}

void DrawMap()
{
    clear();
    ShowHideCursor(false);
    // TODO
    //<esc>[n;mH:   Move cursor to absolute coordinates. n: line (1=top), m: column (1=left). n and m defaults to 1 if absent.
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {

            char ah = maze[i][j];
            char *c = ah == '1' ? "\u274f" : (ah == 'e' ? "\u27ab" : (ah == 'x' ? "\u2766" : "\u2b58"));
            printf("%s ", c);
            fflush(stdout);
            usleep(50000);
        }
        printf("\n");
    }

    printf("\033[2;1H\u27ab");
    ShowHideCursor(true);
}

void MazeMovement()
{
    ShowHideCursor(true);
    int x = 1;
    int y = 1;
    for (int i = 1; i <= MAZE_SIZE; i++) {
        for (int j = 1; j <= MAZE_SIZE; j++) {
            //     가로 , 세로
            gotoxy(x, y);
            printf("\u27ab");
            fflush(stdout);
            usleep(500000);
            x += 2;
        }
        printf("\n");
        x = 1;
        y += 1;
    }

    // // print current location of x.
    // printf("current location of x is:%d\n", wherex());

    // // print the current location of y.
    // print("currentlocation of y is:%d", wherey());
}

void MazeRun()
{
    DrawMap();
    MazeMovement();
    getchar();
    int r, c;                           // 행,열 선언
    StackType s;                        // 지역변수 -> &s을 통해 해당 함수의 s(주소)에 main 함수의 s(주소)를 넣어 지역변수여도 해당함수에 간섭이 가능

    init_struct(&s);                    // 스택 초기화
    here = entry;                       // 현재위치 = 시작위치
    printf("(%d,%d) ", here.r, here.c); // 반복되기 전에 시작위치 출력

    while (maze[here.r][here.c] != 'x') // x 아니면 반복, 괄호 안의 maze 함수의 값도 반복을 통해 값이 변함 -> 책에 있는 maze_print 함수 필요없음
    {
        r = here.r;                     // 간편하게 축소
        c = here.c;
        maze[r][c] = '.';               // 현재위치를 .으로 표현, 굳이 .아니어도 됨

        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        push_loc(&s, r - 1, c); // 다음위치의 이동경로(4방)
        push_loc(&s, r + 1, c); // push_loc함수에서 갈 수 있는 경로만 push됨(필터링)

        if (is_empty(&s))       // 스택이 비어도 출구를 찾지 못했을 때 -> 오류 대비
        {
            printf("실패\n");
            return;
        } else here = pop(&s);              // pop을 통하여 이동, push후 pop된 것을 출력하기 때문에 시작위치 while문 전에 미리 출력해야함

        printf("(%d,%d) ", here.r, here.c); // 경로 출력
    }
    printf("성공\n");
}

// End Maze

void GreetNight()
{
    printf("Good, night!\n");
}
void GreetEvening()
{
    printf("Good evening!\n");
}

void GreetMorning()
{
    printf("Good morning!\n");
}

void Greet(void (*greeter)())
{
    greeter();
}

int PtrAdd(int a, int b, char op)
{
    int result = 0;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;

        default : result = a ^ b; break;
    }
    return result;
}

void Calulater(int (*Print)(int, int, char), int a, int b, char op)
{
    printf("%d\n", PtrAdd(a, b, op));
}

void FunctionPointer()
{

    // Function Pointer Trigger
    Greet(GreetMorning);
    Greet(GreetEvening);
    Greet(GreetNight);
    Calulater(PtrAdd, 10, 30, '*');
}

void InputItemsSwap()
{
    // 배열 5개 짜리 선언
    const int arraySize = 5;
    int array[arraySize];

    // 각각 입력 받기
    printf("\n\nPlease Repeat (%d) Times For Array Itmes\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("\u27A5 ");
        scanf("%d", array + i);
    }
    printf("\n");

    // 합계내기
    int sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += *(array + i);
    }
    printf("sum of all values = %d\n", sum);
    printf("\nOriginal Array\n\u27A5 ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    // 스왑 하기 (Swap, 첫번째와 막지막 요소간 비트연산으로 교체하기)
    *(array) ^= *(array + arraySize - 1);
    *(array + arraySize - 1) ^= *(array);
    *(array) ^= *(array + arraySize - 1);
    printf("\nSwap ( array + 0 ) vs ( array + arraySize - 1 )\n\u27a5 ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void Array2D()
{
    int a1[] = {1, 2, 3};
    // *(a1 + 0) == a1[0] , *(a1 + 1) == a1[1], *(a1 + 2) == a[2]...역참조 연산자.
    // 1차원 배열은 포인터 1개로 만들어짐.
    // 배열의 인덱스 .

    int a2[] = {40, 555, 62, 12, 34, 56, 77};
    int a3[] = {71, 84, 96, 55};
    int a4[] = {121, 162};

    // 1차원이 여러개 있는 것이
    // 2차원 배열
    // 포인터 배열 선언

    int *arr[4];
    arr[0] = a1;
    arr[1] = a2;
    arr[2] = a3;
    arr[3] = a4;

    printf("%d, %d\n", *(arr[1] + 3), *(*(arr + 1) + 3)); // -> 12

    int b[3][2] = {
        {1, 2},
        {23456, 391},
        {456, 78}};

    int(*p)[2];
    p = b;

    // index [0..] : 배열의 역참조.
    printf("*(arr[1] + 1) = %d," //
           "%d, %d, %d, %d, %d\n",
           *(a2 + 1),            //
           *(arr[1] + 1),        //
           (*(p + 1)[0]),        //
           *(p[2] + 0),          //
           *(*(p + 0) + 1),
           p[0][1]);             // (p[0][1])
}

void ConstPointer()
{
    // [ 포인터 상수화 ]
    // 포인터가 변경할 수 있는 값은
    // 1. 자신의 값과 ,
    // 2. 자신이 가리키고 있는 값. 두가지.
    int t = 3;
    int k = 5;
    int temp = 12;
    const int *ptrA = &t;          // 포인터가 가리키는 메모리 값을 상수화 하는 것. -> ( *ptr = 3; 불가능함. )
    int *const ptrB = &k;          // 포인터 자신의 값 (주소)을 상수화 하는 것 -> ( ptrB = &abc; 불가능함, 일편단심 )
    const int *const ptrT = &temp; // 두가지 모두 상수화 하는 것. ( 주소와 값 두가 모두 변결 불가능 )

    printf("`const int *ptrA = &t;`          // 포인터가 가리키는 메모리 값을 상수화 하는 것. -> ( *ptr = 3; 불가능함. )\n"
           "`int *const ptrB = &k;`          // 포인터 자신의 값 (주소)을 상수화 하는 것 -> ( ptrB = &abc; 불가능함, 일편단심 )\n"
           "`const int *const ptrT = &temp;` // 두가지 모두 상수화 하는 것. ( 주소와 값 두가 모두 변결 불가능 )");
}

void VoidPointer()
{
    // void pointer
    // 타입이 없으므로 역참조가 불가능함.
    // 단지 주소값만 가지고 있음.

    int a = 5;
    void *ptr = &a;

    printf("void pointer get value \u27a5 %d\n", *((int *)ptr) = 10);
}

// ANSI
void PrintAnsiColor()
{
    printf("\n"
           "\033[30;1m Bright Black\n" // Bright ;1m
           "\033[31m Red\n"
           "\033[32m Green "
           "\033[33m Yellow "
           "\033[34m Blue "
           "\033[35m Magenta "
           "\033[36m Cyan "
           "\033[0m Reset 0m \n");

    printf("\n");
    // Background, +10
    printf("\033[41;1m Bright Red \n\033[0m");
    printf("\033[42;1m Bright Green \n\033[0m");
    printf("\n");
    printf("\033[40m A \033[41m B \033[42m C \033[43m D \033[44m E \033[45m F\n\033[0m");

    printf("\033[1m BOLD \033[4;33m Underline \033[0m \033[7m Reversed \033[0m\n");
}

void AnsiCursorNavigation()
{
    for (int i = 1; i <= 100; i++) {
        usleep(90000);
        printf("\033[1000D ( %d )", i); // which means "move cursor left by 1000 characters"
        fflush(stdout);
    }
}

void AnsiGeneral()
{
    // ESC -> \x1B
    // CSI : Control Sequence Introducer -> \x9B
    // DSC : Device Control String -> \x90
    // OSC : Operating System Command -> \x9D
    // usleep(1000000);

    printf("Hello World\v");
    printf("Fine Thanks\v");
    printf("How are you?\v");
    printf("Good Morning\v");
    printf("\033[H");      // Move Home
    printf("\033[10;20H"); // Move Cursor, 행:열H, 빈공간으로도 이동가능.
    printf("\033[2;5f");   // 위와 동일
    printf("\033[2E");     // Cursor beginning of next line, line down
    printf("\033[3F");     // Cursor previous line, line up
    printf("\033[30C");    // Cursor right
    printf("\033[1A");     // Cursor up
    printf("\033[10B");    // Cursor Down
    printf("\033[2D");     // Cursor left
    printf("\033[H");
    printf("\033[J");      // erase in display (same as ESC[OJ)
    printf("Hello World\v");
    printf("\033[2J");     // erase entrie screen
    printf("Fine Thanks\v");
    printf("How are you?\v");
    printf("Good Morning\v");
}

void CursorMovement()
{
    printf("Hello, World\n");
    usleep(1000000);
    fflush(stdout);
    printf("Hi Everyone\n");
    usleep(1000000);
    fflush(stdout);
    printf("Fine Thanks And You?");
    usleep(1000000);
    fflush(stdout);
    printf("\033[2A");  // up
    usleep(1000000);
    fflush(stdout);
    printf("\033[15D"); // Left

    printf("\033[2B");  // Down
    printf("\033[20C"); // Right
    printf("\033[3F");  // Prev Line + Begginning of line
    printf("\033[1E");  // Next Line + Beginning of line

    // [{n}G  // moves cursor to column
}

void AnsiExample()
{
    //-->  ANSI Escape Sequences
    // Unicode : \u001b
    // Hexadecimal : \x1B
    // Decimal : 27
    // Octal : \033
    //--> Sequences

    // Text Color
    // Black : 30m, Green : 32, Yellow : 33m, Blue : 34, Magenta : 35m, Cyan : 36m, White : 37m, Reset : 0m
    printf("\n\033[31mHello\033[0m World\033[0m");

    PrintAnsiColor();
    AnsiCursorNavigation();
    // printf("\n\033[0m ... End ...\n");
    // printf("\033[2J");
}

void FloatPostfix()
{
    printf("\n\n");
    float sum;
    sum = 1.23 + 45.6;

    // 접미사 없을 때?
    printf("접미사 f 없으면? ( %f vs %f ) => ", sum, 1.23 + 45.6);
    if (sum == (1.23 + 45.6))
        printf("같습니다.");
    else printf("둘은 달라요.");

    // 접미사 있을 때?

    sum = 1.23f + 45.6f;
    printf("\n\n접미사 f 있으면? ( %f vs %f ) => ", sum, 1.23f + 45.6f);
    if (sum == (1.23f + 45.6f))
        printf("같습니다.");
    else
        printf("둘은 같습니다.");

    printf("\n");
}

void UniCodeArt()
{
    char c[2] = {
        0x005C,
        0x002F};
    int size = 1;
    printf("몇개를 넣을까요? (1 ~ 8)\n\u27a5 ");
    scanf("%d", &size);
    printf("\n");
    if (size > 8) size = 8;
    int ansiColor = 31;

    while (size >= 1) {
        for (int i = 0; i < size; i++) {
            printf("\033[%dm%c", ansiColor, c[0]);
        }
        for (int i = 0; i < size; i++) {
            printf("\033[%dm%c", ansiColor, c[1]);
        }
        size--;
        ansiColor++;
        if (ansiColor > 40)
            ansiColor = 31;
    }

    printf("\033[0m\n");

    getchar();
}

void Arm64Asm()
{
    // TODO
}

void PrintSourceCodeItSelf()
{
    printf("%s\n", __FILE__);

    char c;
    FILE *fp = fopen(__FILE__, "r");
    do {
        c = fgetc(fp);
        putchar(c);
    } while (c != EOF);
    fclose(fp);

    printf("\n");
}

void StringArradWith2D()
{
    // 서로 다른 사이즈 의 열 갯수를 갖는 배열.
    char row0[] = "Hello, World!";
    char row1[] = "Hi Everyone";
    char row2[] = "Fine Thanks~~~~";
    char row3[] = "How are You???";

    // 2차원 배열 포인터.
    char *array[] = {row0, row1, row2, row3};

    // sizeof(array) : 행 4개에 대한 포인터 변수 합계 -> 32
    // sizeof(*array) : 하나의 행에 대한 포인터 변수 사이즈 -> 8
    printf("sizeof(array) = %lu, sizeof(*array) = %lu\n", sizeof(array), sizeof(*array));
    // --> 32 / 8 = 4개의 행
    for (int i = 0; i < sizeof(array) / sizeof(*array); i++) {
        printf("%s\t\t%s\n", array[i], *(array + i));
    }
}
size_t f[30];
size_t factorial(size_t n)
{
    if (n == 0 || n == 1)
        return 1;
    if (f[n] > 0)
        return f[n];
    return f[n] = factorial(n - 1) * n;
}

void PrintBitWise()
{
    printf("\n[ char 8bit test ]\n");
    unsigned char array[4] = {0b11111111, 0b00000000, 0b01010101, 0b10101010};
    for (int i = 0; i < sizeof(array) / sizeof(char); i++) {
        int j = CHAR_BIT; // 8bit
        printf("%3d => ", array[i]);
        printf("0b");     // prefix
                          // ascii '0' == 48 이므로 => 비트 연산 시 (0 == 48, 1 == 49)
        while (j--)       // 8자리 부터 0 자리 까지...
            putchar('0' + ((array[i] >> j) & 1));

        printf("\n");
    }

    printf("\n\n[ int 32bit test ]\n");
    for (int value = -1; value <= 8; value++) {
        int i = CHAR_BIT * sizeof value; // 32bit (i = 8 * 4 ==> 32bit)
        printf("%3d => ", value);
        printf("0b");
        while (i--)                      // 32 자리부터 0 자리 까지..
            putchar('0' + ((value >> i) & 1));

        printf("\n");
    }
    printf("\n");
}

void FastSize()
{
    size_t t8 = sizeof(int_fast8_t);
    size_t t16 = sizeof(int_fast16_t);
    size_t t32 = sizeof(int_fast32_t);
    size_t t64 = sizeof(int_fast64_t);
    printf("%zu %zu %zu %zu\n", t8, t16, t32, t64);
    printf("short is %d\nint is %d\nlong is %d",
           (int)sizeof(short) * CHAR_BIT,
           (int)sizeof(int) * CHAR_BIT,
           (int)sizeof(long) * CHAR_BIT);
}

/* 소수 판별기 */
bool IsPrime(int n, int i)
{
    if (n == 0 || n == 1) return false;
    if (n == i) return true;
    if (n % i == 0) return false;

    i++;
    return IsPrime(n, i);
}

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");
    int choice;
    while (choice != 200) {
        Menu();
        printf("\n메뉴선택\n>> ");
        scanf("%d", &choice);
        fflush(stdin);
        system("clear");
        int count;
        switch (choice) {
            case 0: { // 중간 노드 삽입

                for (int i = 0; i < 10; i++) {
                    int data = rand() % 1000;
                    InsertMiddleNode(data);
                    usleep(1000000);
                    DisplayNode();
                }

                getchar();
            }; break;

            case 1: { // 맨 앞에 노드 추가, 생성된 역순으로 연결. (LIFO) : 스택 (Stack)
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 1);
                getchar();

            } break;
            case 2: { // 맨뒤에 노드를 추가 : 생성된 순으로 연결 (FIFO) : 큐 (Queue)
                // TODO
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 0);
                getchar();
            } break;
            case 3: DisplayNode(); break; // 현재 전체 연결리스트 노드 출력
            case 4: printf("노드의 수 = %d\n", GetNodeCount()); break;
            case 5: {
                node *p = RemoveFrontNode();
                DisplayNode();
                sleep(1);
                printf("첫번째 노드 ( %p ) 제거가 완료되었습니다.\n", p);
            } break;
            case 6: RemoveNodeByValue(); break;
            case 7: { // Node Memory Free
                int complete = LinkedListMemoryFree();
                if (complete > 0)
                    printf("링크드리스트 ( %d ) 개 모두 제거 완료 되었습니다. \n",
                           complete);
                fflush(stdin);
                sleep(3);
                printf("계속하려면 아무키나 누르세요!");
                getchar();
            } break;
            case 8 : StringCompressStart(); break;
            case 9 : GetMax(); break;
            case 10: FPrinfEx(125, 567); break;
            case 11: ClockEx(); break;
            case 12: SPrintfEx(45, 83); break;
            case 13: AssertEx(45, 83); break;
            // case 14: CTypeEx('A', 0xFFFF); break;
            case 15: SScanfEx("3.14 A KimBumJun"); break;
            case 16: BoolEx(true); break;
            case 17: PointerArray(); break;
            case 18: FibonacciStart(); break;
            case 19: CompareNumbers(); break;
            case 20: { // String Copy
                char *s1 = malloc(20);
                char *s2 = malloc(20);
                strcpy(s1, "University");
                strcpy(s2, "School");
                StringCopy(s1, s2);
                strcpy(s1, "University");
                strcpy(s2, "School");
                StringCopy(s2, s1);
                free(s1);
                free(s2);
            } break;
            case 21: signal(SIGINT, SignalHandler); break;
            case 22: FloatToBinary(3.14); break;
            case 23: BigO(10);
            case 24: GetPrimeNumber(100);
            case 25: {
                printf("Stack Start\n");
                int size = 10;
                Stack *s = CreateStack(size);
                for (size_t i = 1; i <= size * 3; i++) {
                    Score sc = (Score)i;
                    Push(sc, s);
                }
                for (int i = 1; i <= s->max; i++) {
                    Score score = (Score)Pop(s);
                    printf("=> %p\n", score);
                }
                printf("\n");
                DestroyStack(s);
                printf("끝..");
            } break;
            case 26: JisikIn(); break;
            case 27: // TODO;
                break;
            case 28: {
                SelfXor();
                int n;
                int k;
                int j;

                printf("Enter three numbers: ");
                int rs = scanf("%d %d %d", &n, &k, &j);
                printf("first = %d, second = %d, third = %d, counts = %d\n\n", n, k, j, rs);

            } break;
            case 29: {
                MazeRun();
            } break;

            case 30: Array2D(); break;
            case 31: InputItemsSwap(); break;
            case 32: FunctionPointer(); break;
            case 33: ConstPointer(); break;
            case 34: VoidPointer(); break;
            case 35: AnsiExample(); break;
            case 36: UniCodeArt(); break;
            case 37: CursorMovement(); break;
            case 38: FloatPostfix(); break;
            case 39: Arm64Asm(); break;
            case 40: AnsiGeneral(); break;
            case 41: PrintSourceCodeItSelf(); break;
            case 42: StringArradWith2D(); break;
            case 43: {

                char a[4][5] = {"ABCK", "DEFK", "GHIK", "JKLK"};
                printf("%s\n", a[1]);
                printf("%lu, %lu\n", sizeof(a), sizeof(*a));
                for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
                    printf("%s\n", a[i]);

            } break;
            case 44: {
                for (size_t i = 1; i <= 20; i++)
                    printf("%3zu = %'30zu\n", i, factorial(i));

            } break;
            case 45: {
                PrintBitWise();
            } break;
            case 46: {
                FastSize();
            } break;
            case 47: {
                char str[][20] = {"ABC", "123", "QWE"};
                for (int i = 0; i < 3; i++) {
                    printf("%s\n", str[i]);
                }

            } break;

            case 48: {
                /* 소수 찾기 */
                printf("1 ~ 100 까지 소수\n");
                for (int i = 1; i <= 100; i++) {
                    printf("%d => %s\n", i, IsPrime(i, 2) == true ? "소수" : "-");
                }

                int input = 2;
                do {
                    printf("\u2728 임의의 수를 입력하세요(종료: 0)\n\u2761 ");
                    scanf("%d", &input);
                    bool isPrime = IsPrime(input, 2);
                    if (input < 2) {
                        printf("\u26DF\t종료합니다...\n");
                        break;
                    }
                    printf("\u2615 (%d)은 소수%s\n", input, isPrime == true ? "입니다." : "가 아닙니다.");
                } while (input > 1);

            } break;

            case 49: {
                /* 최대 연속된 번호 카운팅 */
                // int num[] = {1, 2, 4, 6, 7, 8, 10, 11, 13, 14};
                int num[] = {1, 2, 3, 9, 10, 11, 12, 13, 14, 18, 19, 20, 23, 24, 25, 27, 47, 50};
                const int size = sizeof(num) / sizeof(int);
                int count[size] = {[0 ...(size - 1)] = 1}; // 카운팅 용 배열 초기화
                int idx = 0;
                for (int k = 1; k < size - 1; k++)
                    if (num[k - 1] + 1 == num[k]) count[idx] += 1;
                    else idx++;

                int max = count[0];
                for (int i = 0; i < size; i++)
                    if (max < count[i]) max = count[i];
                printf("\n최대 일련번호 갯수 = %d\n", max);
            } break;

            default: return 123;
        }

        getchar();
    }

    printf("\n*** Program Exited ***\n");
    return 0;
} /// end main

void Menu()
{
    char line[200];
    for (int i = 0; i < 100; i++)
        line[i] = '*';

    sprintf(line, "%.*s", 90, line);
    char *items[] = {
        "  0. 노드 생성 (Insert)"
        "  1. 노드 생성 (Front)"
        "\t2. 노드 생성 (Tail)"
        "\t3. 노드 현황",
        "  4. 노드 갯수"
        "\t\t 5. 선두 노드삭제"
        "\t6. 선택 노드삭제"
        "\t7. 모든 노드제거",
        line,
        "  8. 문자압축/해제"
        "\t9. 최대 최소값"
        "\t10. fprintf()",
        " 11. clock()"
        "\t12. sprintf()"
        "\t13. assert()",
        " 14. ctype()"
        "\t15. sscanf()"
        "\t16. _Bool()",
        " 17. PointerArray()"
        "\t18. Fibonacci()"
        "\t19. CompareNumbers()",
        " 20. StringCopy()"
        "\t21. Signal()"
        "\t22. Float Memory",
        " 23. Big(O)"
        "\t24. Prime Numbers"
        "\t25. Stack",
        " 26. Movies"
        "\t27. Matrix"
        "\t28. SelfXor",
        " 29. Maze"
        "\t30. Array 2D"
        "\t31. InputItemSwap",
        " 32. Function pointer"
        "\t33. Constant pointer"
        "\t34. Void pointer",
        " 35. Ansi"
        "\t36. Ansi Unicode Art"
        "\t37. Ansi Cursor",
        " 38. Float Postfix"
        "\t39. LLDB With ARM64 Asm"
        "\t40. AnsiGeneral",
        " 41. PrintSourceCodeItSelf",
        "200. 프로그램 종료"};

    int count = sizeof(items) / sizeof(*items);

    printf("== Menus ( %d ) ==\n", count);

    for (size_t i = 0; i < count; i++)
        printf("%s\n", items[i]);
}

/** C
1999 - C99
2011 - C11
2018 - C17
2024 - C23, C2x

- 컴파일러 -
1. GNU Compiler Collection (GCC)
2. Clang : LLVM 프로젝트의 일부인 오픈 소스 C 컴파일러. 속도와 최적화 기능 탁월
3. 마이크로소프트 비주얼 C++
4. 터보 C : 단종

$ gcc -c hello.c -o hello.o

- 라이브러리 함수 -
확장자 .h 헤더파일로 사전 정의된 함수로 구성됨

- 유형 -
1. 라이브러리 함수
2. 사용자 정의 함수

- 프로그램 진입점 : main()

IR (.s) -> [ Assembler ] -> Binary Code (.o) -> [ Linker ] -> execute file

$ gcc main.c -o hello.out

- 토큰 -
1. 문자 : 소스코드에서 직접 하드 코딩된 변수에 할당될 값의 텍스트 표현.
    - 숫자
    - 리터럴 : 작은 따옴표
    - 탈출 시퀀스 : 문자 그대로의 한 유형..
2. 키워드 : 약 32개+, 소문자
    - 기본데이터 유형 (Primary Data Types)
        * Int
        * Long
        * Short
        * Signed
        * Double
        * Char
        * Float
        * Unsigned
        * Void
    - 사용자 정의 유형 (User defined types)
        * struct
        * typedef
        * union
        * enum
    - 저장 유형 (Storage types)
        * auto
        * Extern
        * static
        * Register
    - 조건 부 (Conditionals)
        * goto
        * if
        * else
        * case
        * Switch
        * Default
    - 루프와 루프 컨트롤 (Loop and loop controls)
        * For
        * do
        * while
        * Continue
        * break
    - 기타.. (Others)
        * const
        * sizeof
        * Volatile
    - In C99, C11, C23 version more keywords
        * _Bool
        * _Complex
        * _Imaaginary
        * inline
        * _Alginas
        * _Alignof
        * _Atomic
        * _Generic
        * _Noreturn
        * _Static_assert
        * alignas
        * alignof
        * bool
        * constexpr
        * false
        * nullprt
        * static_assert
        * thread_local
        * true
        * typeof
        * typof_unqual
        * _Decimal128
3. 식별자 : 키워드와 달리 사용자 정의 요소. 변수, 상수, 라벨, 사용자 정의 함수
4. 특별 기호 : ! " # $ % & ' ( ) * + - . : , ; ` ~ = < > { } [ ] ^ _ \ /
5. Operator :
6. Special Symbol : 쉼표, 세미콜론, 콜론, 구두점, 괄호

- Format Specifier
%c              - Character
%d              - Signed integer
%f              - Float
%i              - Unsigned integer
%l %ld, %li     - Long
%lf             - Double
%Lf             - Long Double
%lu             - Unsigned int or unsigned long
%lli or %lld    - Long Long
%llu            - Unsigned long long

- Syntax -
: 프로그램 소스코드를 작성시 규정된 규칙 세트

- 토큰 : 키워드, 식별자, 상수, 문자열, 리터럴, 기호

keyword
auto, break, case, char, const, continue, default, do, double,
else, enum, extern, float, for, goto, if, int, long, register
return, short, signed, sizeof, static, struct, switch, typedef
union, unsigned, void, volatile, while, _Packed, double

Header

Expression:
하나 이상의 값으로 표현 (reduce)될수 있는 코드
Statement  : 실행가능한 최소 독립적인 코드 조각. 컴파일러가 실행할 수 잇는 모든 구문. 한개 이상의 expression 과 키워드를 포함.

Type:
- Basic Types
    * integer types
        -> char
        -> unsigned char
        -> signed char
        -> int
        -> unsigned int
        -> unsigned int
        -> short
        -> unsigned short
        -> long
        -> unsigned long
    * floating-point types
- Enumerated types
- The type void
    * Functionreturns as void : void exit(int status);
    * Function arguments as void : int rand(void);
    * Pointers to void : (void*)malloc(size_t size);
- Derived types
    * Pointer
    * Array types
    * Structure types
    * Union types
    * Function types
- Arrays : int marks[5]; - square brackets [ ]
- Pointer : asterisk (*)
- Namming Convention : 변수의 이름은 알파벳 대문자 또는 소문자 밑줄로 시작
    * 변수 이름은 대소문자를 구분.
    * ANSI 표준으로 31자의 길이를 인식, 매우 짧은 변수 이름을 사용하지 않는다.
    * 정적인 언어이므로 데이터 유형은 이름 앞에 선언 되어야 한다.
- Lvalue : 메모리 위치를 참조하는 표현, 왼쪽 또는 오른쪽으로 나타날 수 있다.
- Rvalue : 메모리의 일부 주소에 저장된 데이터 값을 가리킴. 값을 할당 할 수 없는 표현이프로 오른쪽에 나타날 수 있지만 할당의 왼쪽에는 나타나지 못함.

- Variables
    * Data types - int, float, char or struct types
    * Scope - global or local variables
    * Storage type - automatic, static, register or extern.
    *
- ctype
   int isalnum(int c); // checks whether the passed character is alphnumeric
   int isalpha(int c); // checks alphabetic.
 */
