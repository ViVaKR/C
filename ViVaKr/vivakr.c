#include <ctype.h> // tolowere(int argument)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // sleep(unsigned int)

int MakeRandom(int min, int max)
{
    const int number = (rand() % (max - min + 1)) + min;
    return number;
}

/// @brief Node
typedef struct vnode
{
    int value;
    struct vnode *next;
} node;

node *head = NULL;

/// @brief 첫번째 노드삭제
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
        sleep(1);
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
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;

    if (head == NULL) { // 처음 연결시..
        head = newNode;
        char *address = (char *)malloc(32);
        sprintf(address, "%11p", head->next);
        printf("첫 노드 연결\t=> %s (%5d)\n",
               head->next == NULL ? "Started Head" : address, head->value);
        free(address);
        return;
    }

    newNode->next = head;
    head = newNode;
    printf("일반 노드 연결\t=> %11p (%5d)\n", head->next, head->value);

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
        current = current->next;
    }

    // 마지막 노드와 새노드를 연결
    current->next = newNode;
    printf("( %3d ) 일반 노드 연결 (후미)\t=> %11p (%5d)\n", GetNodeCount(), current->next, newNode->value);
}

/// (1) 링크드리스트 시작지점
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
    sleep(1);

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

void Menu()
{
    char *items[] = {
        "=========================",
        "  1. 노드 생성 (Front)",
        "  2. 노드 현황",
        "  3. 노드 갯수",
        "  4. 첫번째 노드삭제",
        "=========================",
        "  5. 노드 생성 (Tail)",
        "  6. 선택값 삭제",
        "  7. 모든 연결리스트 제거",
        "=========================",
        "=========================",
        "200. 프로그램 종료"};

    int count = sizeof(items) / sizeof(*items);

    printf("Menus (%d)\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("%s\n", items[i]);
    }
}

int main(void)
{
    int choice;

    while (choice != 200) {
        Menu();
        printf("\n메뉴선택\n>> ");
        scanf("%d", &choice);
        fflush(stdin);
        system("clear");
        int count;

        switch (choice) {
            case 1: { // 맨 앞에 노드 추가, 생성된 역순으로 연결. (LIFO) : 스택 (Stack)
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 1);
            } break;
            case 2: DisplayNode(); break; // 노드 출력
            case 3: printf("노드의 수 = %d\n", GetNodeCount()); break;
            case 4: {
                node *p = RemoveFrontNode();
                DisplayNode();
                sleep(1);
                printf("첫번째 노드 ( %p ) 제거가 완료되었습니다.\n", p);
            } break;
            case 5: { // 맨뒤에 노드를 추가 : 생성된 순으로 연결 (FIFO) : 큐 (Queue)
                // TODO
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 0);
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
            default: break;
        }
    }

    printf("\nProgram Exited\n");

    // 문자압축
    // StringCompressStart();
    return 0;
} /// end main

///-------------------------------------------------- Main Bottom
