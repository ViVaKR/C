#include "../headers/vivstd.h"

/// @brief 지식인 답변용
typedef struct
{
    char name[100];
    int age;
    double height;
} Profile;

typedef struct ListNode
{
    Profile profile;
    struct ListNode *next;
} NL;

NL *HomeNL;
NL *LastNL;

/// @brief 프린트 노드
void PrintNL()
{
    NL *temp = HomeNL;

    while (temp != NULL) {
        printf("\n*******************************\n");
        printf(
          "Name\t:\t%s\n"
          "Age\t:\t%d 살\n"
          "Height\t:\t%.1f cm\n"
          "[Next]\t:\t%p",
          temp->profile.name,
          temp->profile.age,
          temp->profile.height,
          temp);
        temp = temp->next;
        printf("\n*******************************\n");
    }
}

/// @brief 메모리 해제
void ReleaseNL()
{
    NL *temp = HomeNL;
    while (temp != NULL) {
        NL *delete = temp;
        temp = temp->next;
        printf("Free : [%p] %s\n", delete, delete->profile.name);
        free(delete);
    }
}

/// @brief 자료구조 (데이터베이스)
void DataStruct()
{
    printf("\n***** 자료구조 *****\n");

    char *name[6] = {
        "Hello", "World", "Fine", "Thanks", "And", "You"
    };

    HomeNL = NULL;
    LastNL = NULL;

    for (int i = 0; i < 6; i++) {

        NL *new = (NL *)malloc(sizeof(NL));
        memset(new, 0, sizeof(NL));

        Profile profile;
        profile.age = 23 + i;
        strncpy(profile.name, name[i], 100);
        profile.height = 170 + (double)i;
        new->profile = profile;

        if (HomeNL == NULL) {
            HomeNL = new;
        } else {
            LastNL->next = new; // 현재 노드
        }
        LastNL = new; // 최상위 노드
    }

    //? printf("\n***** 출력 *****\n");
    PrintNL();

    //? printf("\n***** 삭제 *****\n");
    ReleaseNL();
}
