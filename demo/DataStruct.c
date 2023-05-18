#include "../headers/vivstd.h"

/// @brief 데이터 모델
typedef struct
{
    long *Id;
    char name[100];
    int age;
    double height;
    unsigned int score;
} Profile;

typedef struct ListNode
{
    Profile profile;
    struct ListNode *next;
} NL;

NL *HomeNL;// 시작 노드
NL *LastNL;// 최상위 노드

/// @brief 프린트 노드
void PrintNL()
{
    NL *temp = HomeNL;

    while (temp != NULL) {
        printf("\n*******************************\n");
        printf(
          "Id\t:\t%p\n"
          "Name\t:\t%s\n"
          "Age\t:\t%d 살\n"
          "Height\t:\t%.1f cm\n"
          "Score\t:\t%d\n"
          "[Next]\t:\t%p\n",
          temp->profile.Id,
          temp->profile.name,
          temp->profile.age,
          temp->profile.height,
          temp->profile.score,
          temp);
        temp = temp->next;
        printf("\n*******************************\n");
    }
}

/// @brief 메모리 해제
void ReleaseNL()
{
    printf("\n");
    NL *temp = HomeNL;
    while (temp != NULL) {
        NL *delete = temp;
        temp = temp->next;
        printf("Free : [%p] %s\n", delete, delete->profile.name);
        free(delete);
    }
    printf("\n*******************************\n");
}

/// @brief 데이터 작성
/// @param id 노드포인터
/// @param name 이름
/// @param age 나이
/// @param height 키
/// @return 프로파일 (Profile)
Profile MakeData(long *id, char *name, int age, double height)
{
    Profile profile;
    profile.Id = (long *)id;
    strncpy(profile.name, name, 100);
    profile.age = age;
    profile.height = height;
    profile.score = rand() % (100 + 1 - 60) + 60;
    return profile;
}

/// @brief (16) NODE Database
void DataStruct()
{
    printf("\n***** NODE Database *****\n");
    srand((unsigned int)time(NULL));
    char *name[6] = { "장길산", "임경업", "임꺽정", "한아름", "사임당", "홍영식" };

    HomeNL = NULL;
    LastNL = NULL;

    for (int i = 0; i < 6; i++) {
        NL *new = (NL *)malloc(sizeof(NL));
        memset(new, 0, sizeof(NL));
        new->profile = MakeData((long *)new, name[i], 20 + i, 165 + (i * 0.25));
        if (HomeNL == NULL) {
            HomeNL = new;
        } else {
            LastNL->next = new;
        }
        LastNL = new;// 최상위 노드
    }

    //* printf("\n***** 출력 *****\n");
    PrintNL();

    //* printf("\n***** 삭제 *****\n");
    ReleaseNL();
}
