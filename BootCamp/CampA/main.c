#include <Kernel/stdbool.h> // _Bool
#include <assert.h>         // assert
#include <ctype.h>          // tolowere(int argument),
#include <float.h>
#include <limits.h>         // 정수 유형에 대한 다양한 구현 제한을 정의
#include <locale.h>         // 천단위 콤마.
#include <math.h>           // 수학함수
#include <stdbool.h>        // true, false 를 정의
#include <stdio.h>          // printf, scanf 입/출력 기능 제공
#include <stdlib.h>         // 메모리 할당, 랜드 함수 및 유틸리티 기능
#include <string.h>         // strcpy, strlen 등 문자열 조작
#include <time.h>           // 날짜와 시간으로 작업한는 기능
#include <unistd.h>         // sleep(unsigned int)

int MakeRandom(int min, int max)
{
    const int number = (rand() % (max - min + 1)) + min;
    printf("Hello");
    return number;
}

/// @brief 노드 공용
typedef struct vnode
{
    int value;
    struct vnode *next;
} node;

node *head = NULL;

/// (5) 선두 노드삭제
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
    // system("clear");

    printf("\n\n[ \u2665 Display LinkedList \u2665 ]\n\n");
    current = head;
    do {
        printf("(%3d) current node address: %11p, node value: %4d\n", ++count,
               current->next, current->value);
        current = current->next; // second address
    } while (current != NULL);
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

/// (7) Remove All Nodes, Moemory Free
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

/// (2) LIFO 선두에 노드 만들기
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

/// (3) 중간에 노드 삽입하기
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

/// (1) Trigger --> 연결리스트 시작
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
        }
        prev = delNode;
    }

    sleep(1);
    printf("계속하려면 아무키나 누르세요!");
    getchar();
}

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

        "200. 프로그램 종료"};

    int count = sizeof(items) / sizeof(*items);

    printf("== Menus ( %d ) ==\n", count);

    for (size_t i = 0; i < count; i++)
        printf("%s\n", items[i]);
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
        // system("clear");
        int count;
        switch (choice) {
            case 0: { // 중간 노드 삽입

                for (int i = 0; i < 10; i++) {
                    int data = rand() % 1000;
                    InsertMiddleNode(data);
                    usleep(1000);
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
            case 5: {                     // 선두 노드 삭제
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
            case 200: break;
            default : return 123;
        }
    }

    printf("\n*** Program Exited ***\n");
    return 0;
} /// end main
