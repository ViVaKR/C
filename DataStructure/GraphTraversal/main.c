#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int vertexCount; // 정점의 갯수
    int **arr;       // 동적할당된 포인터 배열의 주소를 저장.

} Graph;

void GraphInit(Graph *grp, int count)
{
    grp->vertexCount = count;

    grp->arr = (int **)malloc(sizeof(int *) * count); // 출발지, 포인터 배열

    for (int i = 0; i < count; i++) {
        // calloc, 0 으로 초기화와 함께 진행.
        grp->arr[i] = (int *)calloc(count, sizeof(int)); // 도착지, 일자원배열
    }
}

// 무방향 간선 정보 (양방향)
// src : 행, dst : 열.
void UnDirectedEdge(Graph *grp, int src, int dst)
{
    // 무방향. 양방향이므로 뒤집어서 한번더 할당해줌.
    grp->arr[src][dst] = 1;
    grp->arr[dst][src] = 1;
}

void EdgeDisplay(Graph *grp)
{
    for (int i = 0; i < grp->vertexCount; i++)     // 출발지
    {
        for (int j = 0; j < grp->vertexCount; j++) // 도착지
        {
            // if (grp->arr[i][j] == 1) {
            //     printf("출발지 %d, 도착지 %d => %d \n", i, j, grp->arr[i][j]);
            // }

            printf("%d\t", grp->arr[i][j]);
        }
        printf("\n");
    }
}
void Dispose(Graph *grp)
{
    for (int i = 0; i < grp->vertexCount; i++) {
        printf("일차원 배열 -> arr[%d] 제거완료\n", i);
        free(grp->arr[i]);
    }
    printf("이차원 배열을 만든 포인터 배열 arr 제거완료\n");
    free(grp->arr);
}

void AdjacencyMatrix()
{
    Graph grp;

    GraphInit(&grp, 4);

    // 양방향.
    UnDirectedEdge(&grp, 0, 1);
    UnDirectedEdge(&grp, 0, 2);
    UnDirectedEdge(&grp, 1, 2);
    UnDirectedEdge(&grp, 2, 3);

    EdgeDisplay(&grp);
    Dispose(&grp);
}

// 노드 리스트
typedef struct node
{
    int vertext;       // 정점.
    int cost;          // 비용.
    struct Node *next; // 다음 노드 주소.
} Node;

// 노드 관리
typedef struct
{
    Node *head;      // 출발지 노드 배열의 주소
    int vertexCount; // 정점의 개수

} GraphNodeList;

void GraphListInit(GraphNodeList *grp, int count)
{
    grp->vertexCount = count; // 정점의 갯수.

    grp->head = (Node *)malloc(sizeof(Node) * count);

    for (int i = 0; i < count; i++) {
        grp->head[i].vertext = i;
        grp->head[i].cost = 1;
        grp->head[i].next = NULL;
    }
}

void AddUnDirectedEdge()
{
}

void AdjacencyList()
{
    GraphNodeList *grp;

    // GraphListInit(&grp, 4);

    AddUnDirectedEdge();
}

void ToLowerCase()
{
    char A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n = strlen(A);
    for (int i = 0; i < n; i++) {

        if (A[i] >= 'A' && A[i] <= 'Z') {
            A[i] |= 0b100000;
        }
    }
    printf("%s\n", A);
}

void Test2()
{
    char A[] = "abcdefghijklmnopqrstuvwxyz";
    int n = strlen(A);
    for (int i = 0; i < n; i++) {
        if (A[i] >= 'a' && A[i] <= 'z') {
            A[i] &= '_';
        }
    }
    printf("%s\n", A);

    n = 100;
    printf("%d = %s\n", n, n & 1 ? "odd" : "even");
    n = 33;
    printf("%d = %s\n", n, n & 1 ? "odd" : "even");
}

void ToggleCase()
{
    char A[] = "AbCdEfGhIjKlMnOpQrStUvWxYz";
    int n = strlen(A);
    for (int i = 0; i < n; i++) {
        A[i] ^= 0b00100000;
    }
    printf("%s\n", A);
}

void Print(const int *arr, const int size, char *title)
{
    printf("%s\t=> ", title);
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
    // sleep(1);
    // usleep(1000);
}
void BubleSort(int *arr, const int size)
{
    for (int i = 0; i < size - 1; i++) {
        // 패스 (행)
        for (int j = 0; j < size - 1 - i; j++) {
            // i 의 인덱스가 0 부터 시작하므로
            // 비교횟수 (열)

            if (arr[j] > arr[j + 1]) {
                // 현재 다음 것과 비교하므로
                // const int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
    }
    Print(arr, size, "버블정렬");
}

void SwapTwoNumberWithoutTemp()
{
    int x = 12, y = 20;
    printf("%d %d\n", x, y);
    x ^= y; // x=x^y
    y ^= x; // y=x^y
    x ^= y; // x=x^y
    printf("%d %d\n", x, y);

    /*
        x=12 y=20
        now for x=x^y
        12 = b01100
        ^20 = b10100
        -------------
        x = b11000

        now for y=x^y
        x = b11000
        ^20 = b10100
        -------------
        y = b01100 =12 (swapped)

        now for y=x^y
        x = b11000
        ^y = b01100
        -------------
        x = b10100 =20 (swapped)
     */
}

void Multiply()
{
    int n = 3;
    int b = 4 << n;
    printf("%d\n", b); // 4 x 2 ^3;
}

void Divide()
{
    int n = 3;
    int b = 32 >> n;
    printf("%d\n", b); // 32 / 2^3 = 4
}

void ToLowerSolution()
{
    char text[100];
    printf("문장을 입력해 보세요 영문으로..>> ");
    scanf("%[^\n]s", text);
    printf("문장 입력 : %s\n", text);
    int n = strlen(text);
    int changesCount = 0;
    for (int i = 0; i < n; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] |= 0b100000;
            changesCount++;
        }
    }
    printf("바뀐 문장 : %s\n바뀐 문자수 = %d\n", text, changesCount);
}
int main(int argc, const char *argv[])
{
    // Matrix
    AdjacencyMatrix();

    // Node List
    AdjacencyList();

    Test2();
    ToggleCase();
    SwapTwoNumberWithoutTemp();
    Multiply();
    ToLowerSolution();

    int arr[] = {7, 23, 9, 1, 95, 2, 8, 4};
    BubleSort(arr, 8);

    // int ta = 10;
    // int tb = 5;
    // ta = (ta * tb) / (tb = ta);

    // printf("%d %d\n", ta, tb);
}

/*
--> Graph
* 정점 (vertex) : 노드의 집합, 트리의 노드.
* 간선 (edge) : 정점 쌍의 집합
- 그래프는 정점과 간선 데이터 모두 저장해야 함.
- 정점과 간선의 예
    + 구글지도 : 각 위치는 정점으로 경로는 간선으로 표시
    + 인스타그램 친구 : 각 사용자는 정점으로 친구 관계는 간선으로 표시.
    + 항공 운송망 : 각 공항은 정점으로 항로는 간선으로 표시, 가장 빠르거나 가장 저렴한 경로를 계산.
- 방향이 없는 간선을 갖는 그래프.
- 간선의 방향이 존재, 간선 (x, y) 와 간선 (y, x)는 서로 다름.
- 간선이 가중치를 갖음.
- 가중치가 없는 그래프는 비 가중치 그래프
- 비 가중치 그래프릐 간선의 가중치는 1임.
- cyclic graph : 하나 이상의 사이클을 갖는 그래프.
- acyclic graph : 사이클이 없는 그래프는 비순환 그래프.
- 그래프 구현 방식
    1. 2차원 배열로 구현. : adjacency matrix (인접행렬), 희소한 경우 자원낭비가 발생함. O(1)
    2. 연결 리스트로 구현 : adjacency list (인접행렬)

--> 그래프 순회 (Graph Traversal) : 모든 정점과 간선을 검사해서 그래프를 탐색하는 과정.
- DFS (Depth First Search, 깊이우선 탐색)
    1. 스택과 재귀 호출로 다음 방문할 정점을 얻어냄
    2. 같은 정점을 재 방문하는 것을 막기 위해 boolean type 방문 배열(Boolean Visited Array) 을 사용.
    3. 출발 정점 선정.-> 스택에 푸쉬 하는 작업
    4. 스택이 비어 있는지 확인.
    5. 0번을 팝하면서 방문했다는 것으로.
    6. 꺼내면서 푸시
- BFS (Breadth First Search, 너비우선 탐색)
 */

/**
 * scanf("%c", &c1);
 * 1. 버퍼를 읽어봄.
 * 2. 버퍼가 비어있으면? 키보드로 부터 입력을 대기함.
 * 3. 키보드로 입력을 하면, 데이터는 버퍼로 들어감.
 * 4. 키보드로 엔터 키를 입력하면? 그때 비로서 scacnf 는 버퍼에서 문자 하나를 읽어 들임.
 *
 */
