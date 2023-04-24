#include "../headers/vivstd.h"

typedef char data;
typedef struct _Node
{

    char key;
    struct _Node *left;
    struct _Node *right;
} Node;

/// @brief 탐색
/// @param root
/// @param key
/// @return
Node *SearchBST(Node *root, char key)
{
    Node *p = root;
    while (p != NULL) {
        if (p->key == key) {
            return p;
        } else if (p->key < key) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    return NULL;
}

/// @brief 삽입
/// @param root
/// @param key
/// @return
Node *InsertBST(Node *root, char key)
{
    Node *p = root;

    // 최상위 노드가 비어있는 경우 대비로 NULL 로 초기화함
    Node *parent = NULL;

    while (p != NULL) {
        parent = p;
        if (p->key == key) {
            printf("같은 키가 있습니다.");
            return p;
        } else if (p->key < key) {
            p = p->right;
        } else {
            p = p->left;
        }
    }

    // (1) 탐색 실패 지점 에서 새노드를 준비함

    Node *new = (Node *)malloc(sizeof(Node));
    new->key = key;

    // (2) 끝(단말) 노드가 될 것이므로 NULL 을 넣으면 됨
    new->left = new->right = NULL;

    // (3) parent 의 child node 로 새노드를 붙여넣으면 됨
    // 단 루트노드가 NULL 면 한바퀴도 돌지 않고 이곳으로 오기 때문데
    // 둘다 즉 루트와 부모가 모두 널인 상태로 이곳으로 옮
    if (parent != NULL) {
        if (parent->key < new->key) {
            parent->right = new;
        } else {
            parent->left = new;
        }
    }
    return new;
}

Node *DeleteBST(Node *root, char key)
{
    Node *p = root;
    Node *parent = NULL;

    while ((p != NULL) && (p->key != key)) {
        parent = p;
        if (p->key < key) {
            p = p->right;
        } else {
            p = p->left;
        }
    }

    if (p == NULL) {
        printf("찾는 노드가 없습니다.");
        printf("\n");
        return root;
    }

    if (p->left == NULL && p->right == NULL) {// 차수가 0인 경우 (단말노드)
        if (parent == NULL)// 루트 노드 하나만 있는 경우
        {
            root = NULL;
        } else {
            // 부모의 좌우 노드에서 해당 노드 포인터 삭제하기
            if (parent->right == p) {
                parent->right = NULL;
            } else {
                parent->left = NULL;
            }
        }

    }
    // 차수가 1인 경우
    // 직계 손자의 노드를 parent 로 올림
    else if (p->left == NULL || p->right == NULL) {
        Node *child = (p->left != NULL) ? p->left : p->right;
        if (parent != NULL) {
            root = child;
        } else {
            if (parent->left == p) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
    }

    // 차수가 2인 경우
    // 최상위 루트 로드를 삭제한다고 가정할 때
    // 좌우 서브 트리노드에서 후계자를 고르는데
    // 좌측 노드의 원칙은 가장 큰값을 가진 노드를 루트로 올림
    //    -> 큰값을 선택하는 이유는 해당 노드는 절대로 오른쪽 자식이 있을 수 없음
    // 우측 노드의 원칙은 가장 작은 값을 가진 노드를 루트로 올림
    //    -> 작은값을 선택하는 이유는 해당 노드는 절대로 왼쪽 자식 노드가 있을 수 없음
    // 차수가 2인 노드에는 삭제할 노드는 실제 제거하지 않고 후계자 노드의 데이터 값만 복사해 줌
    //    -> 후계자 노드를 삭제하고 후계자의 자식 노드의 데이터만 삭제할 노드에 복사하는 개념
    // 이미 위에서 차수가 0, 1인 경우가 걸러졌으므로 별도의 조건은 불필요함
    // 데모는 오른쪽 서브 트리에서 선택 모델로 진행함
    else {
        // root -- (right) -> p = succ_parent -- (right) -> 임시 succ -> 지금 부터는 왼쪽노드로 단말 노드까지 계속 진행 -> (최종 succ)
        Node *succ_parent = p;
        Node *succ = p->right;

        while (succ->left != NULL) {
            succ_parent = succ;
            succ = succ->left;
        }

        p->key = succ->key;
        if (succ_parent->left == succ) {
            succ_parent->left = succ->right;
        } else {
            succ_parent->right = succ->right;
        }
        p = succ;
    }


    // 어떠한 경우에도 p node 는 삭제되어야 함
    free(p);
    return root;
}

/// @brief Recursive
/// @param root
void Inorder(Node *root)
{
    if (root == NULL) return;
    Inorder(root->left);
    printf("%c\n",root->key);
    Inorder(root->right);
}

/// @brief 이진탐색트리
void BinarySearchTree()
{
    /****** BinarySearchTree *****/

    // - 용어
    //   - 루트노드 (root node) : 부모가 없는 최상위 노드
    //   - 단말노드 (leaf node) : 자식이 없는 노드, 가장 아래에 있는 노드
    //   - 크기 (size) : 트리에 포함된 모든 노드의 갯수
    //   - 깊이 (depth) : 루트 노드부터의 거리, 루트노드 = 0
    //   - 높이 (heigth) : 깊이 중 최대값
    //   - 차수 (defree) : 각 노드의 (자식 방향) 간선갯수

    /* - 이진 탐색 트리 (Binary Search Tree) */
    //   - 특징 : `왼쪽` 노드 < `부모` 노드 < `오른쪽` 노드
    //       - 모든 원소는 유일한 키 값을 갖는다.
    //       - 부모노드 보다 외쪽 자식 노드가 작음
    //       - 부모노드 보다 오른쪽 자식 노드가 큼
    //       - 재귀적인 정의를 함
    //   - 데이터를 조회하는 과정
    //       1. 찾고자 하는 원소 : 37
    //       2. 루트 노드 부터 방문 탐색진행 ( 루트 노드 `30` 가정)
    //       3. 현재(루트 노드 포함) 노드와 찾는 원소 37과 비교
    //       4. 찾는 원소가 크므로 오른쪽으로 방문, 즉 반씩 줄어드는 효과 발생
    //       5. 찾으면 탐색 종료
    // - 트리 순회 (Tree Traversal)  방법
    //      - 전위 순회 (pre-order traverse)
    //      - 중위 순회 (in-order traverse)
    //        - 오름 차순의 특징을 보임
    //      - 후위 순회 (post-order traverse)

    // (1) 탐색 구현부 : 삽입하기전 먼저 탐색


    // while p != null;
    // p->data ==x; 찾았을때, return true;
    // p->data < x; 오른쪽으로 타고 내려감, p = p->right;
    // p->data > x; 왼쪽으로 타고 내려감, p = p->left;
    // 오른쪽 노드가 NULL 일때는 실패 return nullPtr;

    // (2) 삽입 구현부 : 탐색이 실패했을 때, 실패한 위치에 삽입
    // 탐색 대상 노드의 좌우 포인터 중 널 포인터인 곳에 삽입하는데
    // 리턴하기 전에 부모 노드를 임시 변수에 저장해 두고, 해당 부모의 널 포인터에 노드를 저장함
    // 노드를 움직일때 마다 직전 노드를 저장하는 알고리즘.


    // (3) 삭제 구현부
    // 단말노드의 차수가 0, 1, 2 인경우로 나눌수 있음
    // 차수가 0인 경우 : 해당 단말 노드를 프리시키고 부모노드에서 해당 노드를 삭제하기
    // 차수가 1인 경우 : parent 에 손자 노드를 붙임
    // 차수가 2인 경우

    Node *root = InsertBST(NULL, 'D');
    InsertBST(root, 'I');
    InsertBST(root, 'F');
    InsertBST(root, 'A');
    InsertBST(root, 'G');
    InsertBST(root, 'Z');
    InsertBST(root, 'Q');
    InsertBST(root, 'H');
    InsertBST(root, 'P');
    InsertBST(root, 'K');
    InsertBST(root, 'B');
    InsertBST(root, 'C');

    // 중위 운행 데모 : 알파벳순서로 정렬됨
    Inorder(root);

    // 노드삭제
    printf("***** 노드삭제 *****");
    printf("\n");
    root = DeleteBST(root, 'C');
    Inorder(root);
    printf("\n");
}
