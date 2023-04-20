#include "../headers/vivstd.h"

/// @brief 노드 구조체
typedef struct NODE
{
    // 관리될 데이터
    int nData;

    // 데이터 관리를 위한 포인터
    struct NODE *next;
} NODE;

void SingleList();

/// @brief 자료구조 (데이터베이스)
void DataStruct()
{
    printf("***** 자료구조 *****");
    printf("\n");

    int nData = 300;
    printf("\n");

    /* 선행학습 */
    // 포인터 (함수포인터 포함)
    // 구조체
    // 재귀호출

    /* 1. Single Linked List */
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

    SingleList();
}

void SingleList()
{
    /****** SingleList *****/
    NODE list[5] = { 0 };
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL;// 0 : 널포인트

    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;

    for (size_t i = 0; i < 5; i++)
        printf("list[%d]: %d\n", i, list[i].nData);

    printf("\n");
    
    NODE *pTemp = &list[0];
    while (pTemp != NULL)
    {
        printf("list %p: %d\n", pTemp, pTemp->nData);
        pTemp = pTemp->next;
    }
}
// Ref. [널널한 개발자]
