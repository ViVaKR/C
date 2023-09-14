#include "../headers/vivstd.h"

/// @brief 구조체 샘플 1 : 타입설정
typedef struct Member
{
    char Name[12];
    unsigned short int Age;
} Member;

/// @brief 구조체 샘플 2 : 구조체명 생략형
typedef struct
{
    unsigned long id;        // 고유번호 : 8바이트
    char name[12];           // 이름 :    12바이트
    unsigned short int age;  // 나이 :    2바이트
    float height;            // 키 :      4바이트
    float weight;            // 몸무게 :   4바이트
} People;

/// @brief 구조체 샘플 3 : 구조체 변수선언
struct Score
{
    unsigned short 국어;
    unsigned short 영어;
    unsigned short 수학;
} Score;

/// @brief (24) 구조체 A 형
void StructA()
{
    printf("\n***** (16) 구조체 *****\n");
    //* 비슷한 형태의 데이터를 관리
    //* 다수의 사람들의 나이, 키 그리고 몸무게를 관리하는 프로그램등에 사용
    //* 구조체의 크기 : 내부의 데이터 타입 크기의 총합 (가장큰 사이즈에 규격을 맞춤)
    //* 초기화는 구조체의 요소(변수)의 순서와 초기값 순서가 동일해야 함.

    /* 구조체 멤버 정렬 기준 */
    //* 구조체의 요소를 일정한 크기로 정렬하여 실행속도를 높이기 위해
    //* C 컴파일러가 구조체 멤버 정렬(Struct Member Algnment) 기능을 제공
    //* 1, 2, 4, 8 바이트 단위로 정렬 (기본 : 8)
    //* 정렬 기준에 따라 기준 배수로 주소로 할당됨
    //* 작은 바이트 부터 큰 바이트 순으로 정렬하는 것을 권장


    // 선언 예시 //
    People P;
    People *p;
    p = (People *)malloc(sizeof(People));
    People pList[64];
    p->id = 1;
    char nm[12] = "장길산";
    strcpy(p->name, nm);
    p->height = 188;
    p->weight = 72;

    // 선언후 초기화 방법
    Member m1;
    Member m2  = { "장길산", 34 };

    Member *pm;
    pm = &m1;

    (*pm).Age = 27;
    strcpy((*pm).Name, "임꺽정");

    printf(
      "[ Size ]\n"
      "id = %d, name = %s height = %.1f, weight = %.1f\n"
      "Name = %s\n"
      "Name = %s, Age = %u",
      p->id, p->name, p->height, p->weight,
      pm->Name,
      m2.Name, m2.Age);// pm->Name 과 (*pm).Name 동일

    printf("\n");
    Score.국어 = 98;
    Score.영어 = 78;
    Score.수학 = 88;
    printf("[ Member Size ] = %d 바이트, 국어 = %d, 영어 = %d, 수학 = %d\n",
      sizeof(Score),
      Score.국어,
      Score.영어,
      Score.수학);

    free(p);
}
