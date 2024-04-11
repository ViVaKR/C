#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Menu();
void Clear(bool tf);

enum Demo
{
    one,
    two,
    three
};

/// @brief 노드
typedef struct treenode
{
    // 트리노드는 -> 루트부터 시작, 일반 노드는 헤더와 동일 개념.

    int data;           // 값
    struct node *left;  // 좌측 자식노드 포인터
    struct node *right; // 오른쪽 자식노드 포인터

} TreeNode;

// head : 첫 노드의 주소를 저장하고 있는 포인터

TreeNode *AddNode(TreeNode *node, int data)
{
    if (node == NULL) { // 부모가 있다는 의미
        node = (TreeNode *)malloc(sizeof(TreeNode));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    // 1. 값이 작은지 크지 판단 : 왼쪽 (작은값), 오른쪽(큰값) 노드결정
    else if (node->data > data) { // 삽입할 정수가 더 작은 경우
        // 왼쪽, 재귀호출
        // (left 3)       (left 1)
        node->left = AddNode(node->left, data);

    } else { // 더 큰 경우
        // 오른쪽
        node->right = AddNode(node->right, data);
    }

    return node; // (left 2) 재귀호출을 한 곳으로 리턴 되는 노드. 즉, 3번 node 와는 다른 시점의 node.
}

/// @brief 노드출력
/// @param node
void DisplayAsc(TreeNode *node)
{
    if (node != NULL) {
        DisplayAsc(node->left);
        printf("%d ", node->data);
        DisplayAsc(node->right);
    }
}

// 노드검색
TreeNode *SearchNode(TreeNode *find, int target)
{
    if (find == NULL) return NULL;
    if (find->data == target) return find;

    if (find->data > target)
        return SearchNode(find->left, target);
    else
        return SearchNode(find->right, target);
}

// 최대값
TreeNode *GetMaxValue(TreeNode *maxData)
{
    if (maxData == NULL) return NULL;
    if (maxData->right != NULL)
        return GetMaxValue(maxData->right); // (final)
    return maxData;                         // 위 final 로 돌아감.
}

// 최소값
TreeNode *GetMinValue(TreeNode *minData)
{

    if (minData == NULL) return NULL;
    if (minData->left != NULL)
        return GetMinValue(minData->left);

    return minData;
}

// 노드 삭제

TreeNode *RemoveNode(TreeNode *remove, int target)
{
    TreeNode *temp; // 제거용 임시 노드 포인터 변수.

    if (remove->data == target) {
        // 노드 삭제
        // case 1. 자식노드가 없는 경우, 삭제 후 부모에게 -> NULL
        if (remove->left == NULL && remove->right == NULL) {
            free(remove);
            return NULL;

        }
        // case 2 - 오른쪽 자식 노드 하나만 있는 경우.
        else if (remove->left == NULL) {
            temp = remove->right; // 제거 (remove->right) 하기전에 임시변수에 복사할당.
            free(remove);
            return temp;          // 오른쪽 자식 노드의 값을 리턴, 부모 에겐 왼쪽 오른쪽 모두 해당함.
        }
        // case 2 - 왼쪽 자식 노드 하나만 있는 경우
        else if (remove->right == NULL) {
            temp = remove->left;
            free(remove);
            return temp; // 왼쪽 자식 노드의 값을 리턴
        }
        // case 3 - 왼쪽/오른쪽 자식 노드 둘다 있는 경우
        else { //  (remove->left != NULL && remove->right != NULL)
            // (1-left) 왼쪽 : 최대값 찾기 -> GetMax();
            temp = GetMaxValue(remove->left);
            // (2) 최대값을 삭제할 노드에 대입하기
            remove->data = temp->data; // 왼쪽 자식 중 최댓삽을 삭제한 노드 대입.
            // (3) 부모로 이동한 자식노드 삭제하기 재귀.
            remove->left = RemoveNode(remove->left, temp->data);
        }

    } else if (remove->data > target) { // 왼쪽
        // 재귀호출 (with left)
        remove->left = RemoveNode(remove->left, target);

    } else { // 오른쪽
        // 재귀호출 (with right)
        remove->right = RemoveNode(remove->right, target);
    }
    return remove;
}

/// @brief main (BST, 이진검색트리)
/// @param argc
/// @param argv
/// @return
int main(int argc, const char *argv[])
{
    srand((unsigned int)time(NULL));

    // 루트 (최상위 노드) 의주소, 포인터
    TreeNode *root = NULL;

    // 검색 노드
    TreeNode *find = NULL;

    int *origin;

    int data;
    int choice;
    while (true) {
        // Clear(false);
        Menu();

        scanf("%d", &choice);
        switch (choice) {
            case 1: {

                printf("\n\n\u2766 노드 삽입중\n\u27AD ");

                while (getchar() != '\n');
                for (int i = 0; i < 20; i++) {
                    int rnd = (rand() % 51) + 10;

                    printf("%d ", rnd);
                    fflush(stdout);
                    usleep(100000);
                    root = AddNode(root, rnd);
                }
                printf("\n");

            } break;
            case 2: {
                // 노드 제거
                // 사전 검토 사항
                // 1. 자식노드가 없는 경우 -> 제거후 널 값을 리턴
                // 2. 왼쪽 또는 오른쪽 자식 노드만 있는 경우줌
                //     -> 자식노드를 임시변수에 저장 -> 삭제 -> 자식노드의 값을 부모와 연결
                // 3. 자식노드가 둘다 있는 경우 -> 왼쪽 트리의 가장 큰값을 부모에게 연결, 오른쪽은 볼필요 없음.

                printf("\n\u27AD 삭제할 노드 입력\n\u27AD ");
                scanf("%d", &data);
                root = RemoveNode(root, data);

            } break;

            // 노드 검색
            case 3: {
                printf("\n\n검색할 데이터 입력 (정수)\n\u27Ad ");

                scanf("%d", &data);

                find = SearchNode(root, data);

                if (find == NULL) {
                    printf("\n\n검색한 값은 존재하지 않습니다.\n\n");

                } else {
                    printf("\n\n검색한 데이터 ( %d ) 를 찾았습니다.\n", find->data);
                }

            } break;

            case 4: {
                // Get Max Value
                find = GetMaxValue(root);
                if (find != NULL)
                    printf("\n\n\u27AD 최대값은 \u27AD ( %d )\n", find->data);
            } break;
            case 5: {
                // Get Min Value
                find = GetMinValue(root);
                if (find != NULL)
                    printf("\n\n\u27AD 최소값은 \u27AD ( %d )\n", find->data);
            } break;
            case 6: {
                // 출력
                // 중위 순회 (오름차순): 윈쪽 -> 부모 -> 오른쪽
                printf("\u27AD 중위순회 출력 \n");
                DisplayAsc(root);

            } break;
            case 0 : return 257;

            default: break;
        }
    }
    // Clear(true);
    return 35;
}

void Menu()
{
    printf("\n\n*** [ Binary Search Tree(BST) ] ***\n");
    printf("1. 노드 삽입\n");
    printf("2. 노드 삭제\n");
    printf("3. 노드 검색\n");
    printf("4. 최댓값 구하기\n");
    printf("5. 최소값 구하기\n");
    printf("6. 이진검색트리 출력 (중위순회)\n");
    printf("0. 프로그램 종료\n");
    printf("\n\u2766 메뉴선택\n\u27A5 ");
}
void Clear(bool tf)
{

#ifdef __APPLE__
    if (tf) {
        printf("\n\n\u2766 계속하시려면 엔터키를 누르세요...\n\u27AD ");
        system("read");
    }
    system("clear");
#elif __WIN64__
    printf("\n\n\u2766 계속하시려면 엔터키를 누르세요... \u2766\n\n");
    system("pause");
#elif __linux__
    printf("\n\n\u2766 계속하시려면 엔터키를 누르세요... \u2766\n\n");
    system("read");
#elif __unix__
    printf("\n\n\u2766 계속하시려면 엔터키를 누르세요... \u2766\n\n");
    system("read");
#endif
}

/*
    - 루트 좌측 : 루트보다 작은 값,
    - 루트 우측 : 루트보다 큰값

    1. 원소 검색
    2. 최댓값 : 오른쪽 끝으로
    3. 최소값 : 왼쪽 끝
    4. 원소 삽입
    5. 원소 삭제
        - 자식노드가 없는 경우 : 삭제후 부모에게 NULL 을 넘겨줌.
        - 왼쪽 자식노드만 있는 경우 :
        - 오른쪽 자식 노드만 있는 경우
        - 자식노드가 둘다 있는 경우
            - 왼쪽 : 왼쪽 자식 노드 중에 최대값을 삭제 자리에 올리고 올린 자식노드를 부모노드에 연결하여 줌.
 */

/*
    process launch
    run
    r
    frame variable
    memory read -fx -c4 -s4 &a
    memory read -fx -c4 -s4 &b
    display variable-name
    b 10 (breakpoint)
    breakpoint set --file main.c --line 6
    breakpoint set --method foo
    br s --file main.c --line 13
    c (continue)
    clang CalculateApp.c -o ./Bin/Calculate

    register read
    reg r

    f
    list main
    up
    down
    step (s)
    next(n)
    finish
    quit

    b (pos)
    tbreak (pos)
    breakpoint delete (or br del) : delete all breakpoints
    breakpoint delete (number) : delete the breakpoint indicated by (number)


    print (var)
    p  (var) : 주어진 변수의 값을 인쇄
    print *(ptr) : 포인터의 목적지를 인쇄
    x/(format) (var/address) :
    display (var) : 프로그램이 일시 중지될 때마다 항상 (var) 값을 표시.
    display
    undisplay (num) : 변수 표시 취소.
    expr (var) = (value) : 변수 (var) 를 값으로 설정 expr foo = 5
    up and down : 충돌하거나 일시 중지된 프로그램의 백트레이스 (bt)에서 프레임으르 위로 이동하거나 아래로 이동.




 */
