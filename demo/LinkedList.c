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

/// @brief 연결리스트
void LinkedList()
{
    system("clear");
    printf("\n***** 연결 리스트 (LinkedList) *****\n");

    // [ 구조체 ]
    // TODO 친구의 이름, 나이 키, 체중을 관리하는 프로그램, 최대인원 5명
    P p[COUNT_5];
    int count = 0, num;
}
