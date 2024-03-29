#include "../headers/vivstd.h"

/// @brief
typedef char NAME[14];

/// @brief 회원관리용 구조체
typedef struct Korean
{
    char name[4];
    unsigned short int age;
    float height;
    float weight;
} P;

/// @brief 배열을 통한 회원관리
void PArray()
{
    NAME name[COUNT_5];
    unsigned short int age[COUNT_5];
    float height[COUNT_5];
    float weight[COUNT_5];
    int count = 0, num;
}

/// @brief (구조체) Create
/// @param p
/// @param count
int CreateMember(P *p, int count)
{
    p = p + count;
    printf("\n1. 이름: ");
    scanf("%s", p->name);
    printf("\n2. 나이: ");
    scanf("%d", p->age);
    printf("\n3. 키: ");
    scanf("%f", p->height);
    printf("\n4. 몸무게: ");
    scanf("%f", p->weight);
}

/// @brief (구조체) Read
/// @param p
/// @param count
void ReadMember(P *p, int count)
{
    printf("\n회원 목록\n");
    for (size_t i = 0; i < count; i++) {
        printf("%s, %d, %.1f, %.1f %s\n", p->name, p->height, p->weight);
    }
}

/// @brief 노드 구조체 기본형식
typedef struct node
{
    int number;
    struct node *next;
} N;

N *H = NULL;// Head Pointer
N *L = NULL;// Last Pointer (마지막노드를 기억하는 포인터)

/// @brief (1-2) 노드추가의 새로운 방식 : Ref. 김성엽
/// @param head
/// @param tail
/// @param data
void AddNode(N **head, N **tail, int data)
{
    if (*head != NULL) {
        (*tail)->next = (N *)malloc(sizeof(N));
        *tail = (*tail)->next;// 새로 만든 노드의 주소값을 p에 저장
    } else {
        *head = (N *)malloc(sizeof(N));
        *tail = *head;// 새로 만든 노드의 주소를 p에 저장
    }
    (*tail)->number = data;// 새 노드의 number 에 data 값을 저장
    (*tail)->next = NULL;// 마지막 노드임을 명시
}

/// @brief (3-2) 메모리 해제의 새로운 방식 : Ref. 김성엽
void DeleteNode(N *head, N *tail) {

    // 이동할 다음 노드의 주소를 백업 후 노드 삭제 알고리즘
    N *temp;
    N *d;
    while (d != NULL)
    {
        temp = d->next; // 다음 노드의 주소를 백업저장
        printf("Deleted %p\n",d);
        free(d); // 노드삭제
        d = temp; // 다음노드로 이동
    }
    
    head = tail = NULL; // 연결리스트의 시작과 끝을 초기화
    
}

/// @brief (1) 노드추가
/// @param data
/// @return
int NewNode(int data)
{
    N *new = (N *)malloc(sizeof(N));
    memset(new, 0, sizeof(N));
    new->number = data;
    new->next = NULL;

    if (H == NULL) {// 시작노드가 없을 때
        L = (N *)malloc(sizeof(N));
        H = L;// 최초 시작노드 설정 (H 노드 고정됨)
        L->next = new;
        L->number = data;
        printf("\n");
        printf("F %d %p -> %p\n", L->number, L, L->next);
    } else {// 연결노드
        L->next = new;// 현재 노드의 next pointer
        L = new;// 마지막 노드를 새로운 노드로 포인터 이동
        L->next = NULL;

        printf("S %d %p -> %p\n", L->number, L, L->next);
    }

    return 1;
}

/// @brief (2) 저장된 노드 프린트 (앞에서부터)
void PrintNode()
{
    printf("\n");
    N *temp = H;
    while (temp != NULL) {
        printf("- %d\t(%p)\n", temp->number, temp);
        temp = temp->next;
    }
}

/// @brief (3) 메모리 해제
void FreeMemory()
{
    printf("\n");
    N *temp = H;
    while (temp != NULL) {
        N *delete = temp;
        temp = temp->next;
        printf("Clear %p\n", delete);
        free(delete);
    }
}

/// @brief (35) 연결리스트
void LinkedList()
{
    // system("clear");
    printf("\n***** 연결 리스트 (LinkedList) *****\n");

    // [ 연결리스트 ]
    //? 배열      : 미리 정해진 숫자만큼 자료 입력가능
    //? 동적할당   : 요청 갯수 만큼 메모리 할당하고 자료를 관리하는 방법
    //? 연결리스트 : 할당 크기가 동적으로 할당 되는 방식,  무한 자료관리 시스템
    //!-> | P1 | --> | Data(1) | P2 | --> | Data(2)| P3 | --> | Data(3) | P4 | -->...
    //                     (노드)                  (노드)                (노드)

    // (1) 헤드 포인터 (Head Pointer) : 연결리스트의 시작점, 노드는 아님
    // (2) 사용자가 데이터를 입력을 받기 위해 새로운 노드를 malloc 함수를 사용하여 동적으로 할당
    // (3) 할당된 새 노드의 주소값을 헤더 포인터에 저장
    // (4) 할당된 노드에 사용자의 데이터를 저장하고 [ *next ] 노드 필드에는 NULL 을 대입

    // Demo : 5개의 숫자 데이터로 연결리스트 작성하기
    N *head = NULL;
    N *tail = NULL;
    for (size_t i = 0; i < 5; i++) {
        AddNode(&head, &tail, (i + 1) * 100);
    }

    while (head != NULL) {
        printf("Text %d\n", head->number);
        head = head->next;
    }
    printf("\n***** Delete Memory *****\n");
    DeleteNode(head, tail);
    printf("\n***** End *****\n");

    //!-------------------------------------*//
    printf("\n***** Add New Node *****\n");
    unsigned int count = 0;
    for (size_t i = 0; i < 10; i++) {
        count += NewNode(i + 10);
    }
    printf("Data Count = %d\n\n", count);
    printf("\n***** Print *****\n");
    PrintNode();
    printf("\n***** Free Memory *****\n");
    FreeMemory();
}
