#include "../headers/vivstd.h"

typedef enum {
    C = 1,
    R = 2,
    U = 3,
    D = 4,
    X = 5
} manage;

void Create(), Read(), Update(), Delete();

struct Node
{
    int id;
    char name[20];
    int score;

    struct Node *next;
} *head, *tail, *p;

/// @brief Manager With Linked List
void Database()
{
    system("clear");
    head = NULL;
    printf("\n");
    /****** Database *****/
    int index;

    while (true) {

        printf("***** 진행할 작업을 선택하세요 *****");
        printf("\n");
        printf("(1) Create\n");
        printf("(2) Read\n");
        printf("(3) Update\n");
        printf("(4) Delete\n");
        printf("(5) Exit\n");

        printf("\n");
        printf("********************************");
        printf("\n");

        fflush(stdin);
        printf(">> ");
        scanf("%d", &index);

        manage mng = (manage)index;

        switch (mng) {
            case C: Create(); break;
            case R: Read(); break;
            case U: Update(); break;
            case D: Delete(); break;
            case X:
            default: exit(EXIT_SUCCESS); return;
        }
        printf("\n");
    }
}

void Create()
{
    printf("Create\n");

    int id;
    char name[20];
    int score;
    printf("\n");
    fflush(stdin);
    printf("id >> ");
    scanf("%d", &id);
    printf("\n");
    fflush(stdin);
    printf("name >> ");
    scanf("%s", name);
    printf("\n");
    fflush(stdin);
    printf("score >> ");
    scanf("%d", &score);

    printf("id = %d, name = %s, score = %d\n", id, name, score);
    printf("\n");

    // 새로운 노드 생성
    p = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL) {// 헤더노드가 없을 때
        head = p;
    } else {// 헤더노드가 있으면 마지막 노드에 노드 붙임
        tail->next = p;
    }

    p->id = id;
    strncpy(p->name, name, sizeof(p->name));// 주의 : p->name = name; 이 아님.
    p->score = score;
    p->next = NULL;
    tail = p;

    printf("신규추가 완료\n");

    Read();
}

void Read()
{
    //
    printf("Read");
}

void Update()
{
    //
    printf("Update");
}

void Delete()
{
    //
    printf("Delete");
}
