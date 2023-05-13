#include "../headers/vivstd.h"

/// @brief Step #1
typedef struct NODE
{
    // 관리될 데이터
    int nData;

    // 데이터 관리를 위한 포인터
    struct NODE *next;
} NODE;

/// @brief Step #2
typedef struct NODE_B
{
    char szData[64];
    struct NODE_B *next;

} NB;

/// @brief 지식인 답변용
typedef struct
{
    char name[100];
    int age;
    double heigh;
} Profile;

typedef struct ListNode
{
    Profile pro;
    struct ListNode *list;
} NL;

NL *pnl = NULL;

int InsertNewNode(char *pszDate);
void ReleaseList();
void SingleList();
void PrintList();

void PrintNL();
void ReleaseNL();

/// @brief 자료구조 (데이터베이스)
void DataStruct()
{
    printf("***** 자료구조 *****");
    printf("\n");
    char *name[6] = {
        "Hello", "World", "Fine", "Thanks", "And", "You"
    };
    for (int i = 0; i < 6; i++) {
        NL *nl = (NL *)malloc(sizeof(NL));
        memset(nl, 0, sizeof(NL));
        Profile profile;
        profile.age = 23 + i;
        strncpy(profile.name, name[i], 100);
        profile.heigh = 170 + (double)i;

        nl->pro = profile;

        if (pnl = NULL) {
            pnl = nl;
        } else {
            nl->list = pnl;
            pnl = nl;
        }

        PrintNL();
    }
    ReleaseNL();

    // printf("\n***** 출력 *****\n");
    // PrintNL();


    //  int nData = 300;
    //  printf("\n");

    /* 선행학습 */
    // 포인터 (함수포인터 포함)
    // 구조체
    // 재귀호출

    /* 1. Single Linked List */
    // 선행 학습 내용 : 구조체, 함수, 자기참조 구조체, 동적할당 (포인터)
    // 자료 데이터를 관리하는 컨테이너의 종류
    // 연결 리스트는 여러 구조체 인스턴스를 체인처럼 줄줄이 포인터로 연결한 자료구조
    // 연결에 사용된 포인터 숫자가 한개이고 자기 다음을 가리키는 것이 특징
    // ( node | next ) -> ( node | next ) -> ( node | next ) ... -> nullptr
    // node : container
    // next : pointer
    // nullptr : 마지막 노드
    // List : 선형, 1차원 구조

    // ( 작성순서 )
    // -> 1. 구조체 배열로 테스트 : 용이함 부터 시작
    // -> 2. 연결순서를 임의로 변경 테스트 : 메모리 추적 디버깅 훈련
    // -> 3. 출력은 별도의 함수로 분리
    // -> 4. 디버거로 노드를 추적하며 메모리 위치를 확인함

    // ( 순서 )
    // 1. 전체 리스트 출력 함수 작성
    // 2. 새로운 로드의 추가 및 삭제 수정 함수 작성 (CRUD)
    // 4. 테스트 코드 실행

    // C R U D
    // Append (추가) C
    // Insert (삽입)
    // Update (수정) U
    // Delete (삭제) D
    // Search (찾기) R

    // SingleList();// Step #1

    // 데이터 삽입
    // InsertNewNode("Viv1");
    // PrintList();
    // InsertNewNode("Viv2");
    // PrintList();
    // InsertNewNode("Viv3");
    // PrintList();
    // InsertNewNode("Viv4");
    // PrintList();
    // InsertNewNode("Viv5");
    // PrintList();

    // 메모리 해제
    // ReleaseList();
}

void PrintNL()
{
    NL *temp = pnl;
    while (temp != NULL) {
        printf("\n*******************\n");
        printf("Name\t:\t%s\nAge\t:\t%d\nHeight\t:\t%.1f\n%p",
          temp->pro.name,
          temp->pro.age,
          temp->pro.heigh,
          temp);
        temp = temp->list;
        printf("\n*******************\n");
    }
}

void ReleaseNL()
{
    NL *tmp = pnl;
    while (tmp != NULL) {
        NL *delete = tmp;
        tmp = tmp->list;
        printf("Delete: [%p] %s\n", delete, delete->pro);
        free(delete);
    }
}

NB *ptr = NULL;

/// @brief NB 노드 추가하기
/// @param pszDate
/// @return
int InsertNewNode(char *pszDate)
{
    // 새 노드를 만든 후
    // 기존 노드의 포인터로 새노드 포터를 갱신 후
    // 부모 노드의 포인터에 새노드 포인터를 갱신하는 순서로 진행

    // (1) 새노드 만들기
    NB *nb = (NB *)malloc(sizeof(NB));
    memset(nb, 0, sizeof(NB));// 초기화 : 선택사항
    strncpy(nb->szData, pszDate, sizeof(nb->szData));// strcpy_s 대안

    if (ptr == NULL) {
        ptr = nb;
    } else {
        // 기존 연결을 새로운 노드로 복사 카피
        nb->next = ptr;
        ptr = nb;
    }
    return 1;
}

/// @brief Part1. 연결리스트 기본모델
void SingleList()
{
    /****** SingleList *****/

    NODE list[5] = { 0 };

    // 데이터 초기화
    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;

    // 연결 리스트 구조화
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL;// 0 : 널포인트

    for (size_t i = 0; i < 5; i++)
        printf("list[%d]: %d\n", i, list[i].nData);

    printf("\n");

    // 연결 고리가 끊어지면 문제가 발생함
    int i = 1;
    NODE *pTemp = &list[0];
    while (pTemp != NULL) {
        printf("(%d) - list %p: %d\n", i++, pTemp, pTemp->nData);
        pTemp = pTemp->next;
        // sleep(1);
    }
    printf("\n\n");
}

/// @brief Part2. 데이터 출력
void PrintList()
{
    /****** PrintList *****/

    NB *temp = ptr;
    while (temp != NULL) {
        printf("[%p] %s, next[%p]\n",
          temp,
          temp->szData,
          temp->next);
        temp = temp->next;
    }
    printf("\n");
}

void ReleaseList()
{
    NB *tmp = ptr;
    while (tmp != NULL) {
        NB *delete = tmp;
        tmp = tmp->next;
        printf("Delete: [%p] %s\n", delete, delete->szData);
        free(delete);
    }
}
// Ref. [널널한 개발자]
