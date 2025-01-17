#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char City[][8] = {"서울", "원주", "강릉", "포항", "천안", "논산", "대전", "광주", "대구", "부산"};

int Min(int a, int b)
{
    return a < b ? a : b;
}

long long factorial(int num)
{
    if (num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

double calculate(int num)
{
    if (num == 1) {
        return 2;
    } else {
        return ((double)1 / factorial(num)) + calculate(num - 1);
    }
}

double E_Helper(unsigned n, double term)
{
    double next_term = term / n;
    if (next_term + 1.0 == 1.0) {
        return next_term;
    } else {
        return next_term + E_Helper(n + 1, next_term);
    }
}

double E()
{
    return 1.0 + E_Helper(1, 1.0);
}

void EulerRunner()
{
    int Digs = DECIMAL_DIG;
    printf("DECIMAL_DIG = %.*f\n", Digs, exp(1));
    printf("DECIMAL_DIG = %.*f\n", Digs, calculate(10));
    printf("DECIMAL_DIG = %.*f\n", Digs, E());
    double e = calculate(10);
    printf("\n*** e 의 근사값 ***\n"
           "E() =>\t%.16f\n"
           "E() =>\t%.16f\n"
           "E() =>\t%.32f\n",
           e,
           E(),
           exp(1));
}

/* (1) 최단 경로 */
void FloydWarshall()
{
    const int INF = 1000000000;
    const int size = 10;
    char City[][8] = {"서울", "원주", "강릉", "포항", "천안", "논산", "대전", "광주", "대구", "부산"};

    int dist[20][20];

    int adj[size][size];

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            adj[i][j] = 0;
        }
    }

    adj[1][2] = 15;
    adj[1][5] = 12;
    adj[2][1] = 15;
    adj[2][3] = 21;
    adj[2][9] = 7;

    adj[3][2] = 21;
    adj[3][4] = 25;

    adj[4][3] = 25;
    adj[4][9] = 19;
    adj[4][10] = 5;

    adj[5][1] = 12;
    adj[5][6] = 4;
    adj[5][7] = 10;

    adj[6][5] = 4;
    adj[6][7] = 3;
    adj[6][8] = 13;

    adj[7][5] = 10;
    adj[7][6] = 3;
    adj[7][9] = 10;

    adj[8][6] = 13;
    adj[8][10] = 15;

    adj[9][2] = 7;
    adj[9][4] = 19;
    adj[9][7] = 10;
    adj[9][10] = 9;

    adj[10][4] = 5;
    adj[10][8] = 15;
    adj[10][9] = 9;

    // D0
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (adj[i][j] != 0) {
                dist[i][j] = adj[i][j];
            } else {
                dist[i][j] = INF;
            }
        }
    }
    printf("\n");
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (dist[i][j] == INF) {
                printf(" %s ", "\u221E");
                continue;
            }
            printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // D1 ~ D10
    for (int k = 1; k <= size; k++) {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                int temp = dist[i][k] + dist[k][j];
                if (dist[i][j] > temp) {
                    dist[i][j] = temp;
                }
            }
        }
    }
    printf("\n");
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (dist[i][j] == INF) {
                printf(" %s ", "\u221E");
                continue;
            }
            printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (dist[i][j] == INF) continue;
            if (i == j) continue;
            printf("%s -> %s => %d\n", City[i - 1], City[j - 1], dist[i][j]);
        }
        printf("\n");
    }
}

void FloydModel()
{
    const int INF = 1000000000;
    const int N = 5;

    int adj[N][N];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = 0;
        }
    }
    adj[1][2] = 5;
    adj[1][4] = 9;
    adj[1][5] = 1;
    adj[2][1] = 5;
    adj[2][3] = 2;
    adj[3][2] = 2;
    adj[3][4] = 7;
    adj[4][1] = 9;
    adj[4][3] = 7;
    adj[4][5] = 2;
    adj[5][1] = 2;
    adj[5][4] = 2;

    int data[N + 10][N + 10];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                data[i][j] = 0;
            } else if (adj[i][j] != 0) {
                data[i][j] = adj[i][j];
            } else {
                data[i][j] = INF;
            }
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (data[i][j] == INF) {
                printf(" %s ", "\u221E");
                continue;
            }
            printf("%2d ", data[i][j]);
        }
        printf("\n");
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int temp = data[i][k] + data[k][j];
                if (data[i][j] > temp) {
                    data[i][j] = temp;
                }
            }
        }

    printf("\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (data[i][j] == INF) {
                printf(" %s ", "\u221E");
                continue;
            }
            printf("%2d ", data[i][j]);
        }
        printf("\n");
    }
}

void FloydCity()
{
    const int INF = 1000000000; // 비교를 위한 비교적 큰값설정, 교체값
    const int size = 11;        // 열이름 표시를 위해 1을 더함
    // char City[][8] = {"서울", "원주", "강릉", "포항", "천안", "논산", "대전", "광주", "대구", "부산"};

    // 거리표
    int dist[size][size];

    // 인접행렬
    int adj[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0;
        }
    }

    adj[1][2] = 15;
    adj[1][5] = 12;
    adj[2][1] = 15;
    adj[2][3] = 21;
    adj[2][9] = 7;

    adj[3][2] = 21;
    adj[3][4] = 25;

    adj[4][3] = 25;
    adj[4][9] = 19;
    adj[4][10] = 5;

    adj[5][1] = 12;
    adj[5][6] = 4;
    adj[5][7] = 10;

    adj[6][5] = 4;
    adj[6][7] = 3;
    adj[6][8] = 13;

    adj[7][5] = 10;
    adj[7][6] = 3;
    adj[7][9] = 10;

    adj[8][6] = 13;
    adj[8][10] = 15;

    adj[9][2] = 7;
    adj[9][4] = 19;
    adj[9][7] = 10;
    adj[9][10] = 9;

    adj[10][4] = 5;
    adj[10][8] = 15;
    adj[10][9] = 9;

    // 초기화 (같은도시 : 0, 연결되지 않은 도시 : 무한대, 나머지 : 거리(adj))
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (adj[i][j] != 0) {
                dist[i][j] = adj[i][j];
            } else {
                dist[i][j] = INF;
            }
        }
    }
    printf("\n");

    // 초기 거리 출력
    printf("\u2728 \033[33m 도시별 거리 출력 표 \033[0m \u2728\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] == INF) {
                printf(" %s ", "\u221E");
                continue;
            }
            printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 최단거리 계산 (플로이드 워셜 알고리즘)
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int temp = dist[i][k] + dist[k][j];
                if (dist[i][j] > temp) {
                    dist[i][j] = temp;

                    printf("\033[31m %s \u27A0 "
                           "%s \u27A0 "
                           "%s \u276A"
                           "%2dkm\u276B"
                           "\033[0m\n",
                           City[i - 1],
                           City[k - 1],
                           City[j - 1],
                           dist[i][j]);
                } else if (i == j) {
                    continue;
                }
            }
        }
    }
    printf("\n");

    // 최단거리 출력 표 (도시이름과 함께 출력)
    printf("\u2728 \033[33m 최단거리 출력 표 (도시이름과 함께 출력) \033[0m \u2728\n");
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("\t");
            for (int j = 0; j < size - 1; j++) {
                printf("\033[32;103m %s \033[0m\t", City[j]);
            }
            printf("\n");
            continue;
        }

        for (int j = 0; j < size; j++) {
            if (j == 0) {
                printf("\033[32;103m %s \033[0m\t", City[i - 1]);
                continue;
            }
            printf("%4d\t", dist[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // From ~ To : 최단거리 출력 (도시이름과 함께 출력)
    printf("\u2728 \033[33m From ~ To : 최단거리 출력 (도시이름과 함께 출력) \033[0m \u2728\n");
    for (int i = 0; i < size; i++) {
        if (i != 0) printf("\u26DF\n");

        for (int j = 0; j < size; j++) {
            if (dist[i][j] == INF) {

                continue;
            }
            if (i == j) continue;
            printf("\033[31m %s\u27A0%s \u276A%2dkm\u276B \033[0m \n", City[i - 1], City[j - 1], dist[i][j]);
        }
        printf("\n");
    }
}

/// @brief 다익스트라 알고리즘
#define NUM_VERTEXT 10

/// @brief 노드 구조체
struct node
{
    int vertext;       // 정점
    char *from_name;   // 출발지
    int weight;        // 가중치
    char *to_name;     // 도착지
    struct node *next; // 다음 노드
};

int stack[NUM_VERTEXT];
int top = -1;

/// @brief 다익스트라 구조체
struct dijkstra
{
    int found;        // 최단 거리를 찾았는지 여부 (0: 미발견, 1: 발견)
    int distance;     // 최단 거리
    int prev_vertext; // 이전 정점
};

struct dijkstra djk[NUM_VERTEXT];

struct node *graph[NUM_VERTEXT] = {0};

void Push(int item)
{
    if (top == NUM_VERTEXT - 1) return;
    stack[++top] = item;
}

int Pop()
{
    if (top == -1) return -1;
    return stack[top--];
}

void InitDijkstra()
{
    for (int i = 0; i < NUM_VERTEXT; i++) {
        djk[i].found = 0;
        djk[i].distance = 999999999;
        djk[i].prev_vertext = -1;
    }
}

int GetMinVertex()
{
    int min = 999999999;
    int min_vertex = -1;
    for (int i = 0; i < NUM_VERTEXT; i++) {
        if (djk[i].found == 0 && djk[i].distance < min) {
            min = djk[i].distance;
            min_vertex = i;
        }
    }
    return min_vertex;
}

void ShowDijkstra()
{
    for (int i = 0; i < NUM_VERTEXT; i++) {
        printf("정점 %d: ", i);
        struct node *temp = graph[i];
        while (temp != NULL) {
            printf("%d. %d -> %d %d(%d) ", i, djk[i].found, djk[i].distance, temp->vertext, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

/// @brief 다익스트라 알고리즘 업데이트
/// @param vertex
void UpdateDijkstra(int vertex)
{
    struct node *temp = graph[vertex];
    while (temp != NULL) {

        // 최단거리가 발견되지 않았고, 최단거리가 현재 최단거리보다 작을 경우
        // 최단거리를 업데이트하고 이전 정점을 저장
        if (djk[temp->vertext].found == 0 && djk[temp->vertext].distance > djk[vertex].distance + temp->weight) {
            djk[temp->vertext].distance = djk[vertex].distance + temp->weight;
            djk[temp->vertext].prev_vertext = vertex;
        }
        temp = temp->next;
    }
}

/// @brief 다익스트라 최단 경로 출력
/// @param from
/// @param to
void PrintDijkstra(int from, int to)
{
    int i = 0;
    printf("\033[033m%s \033[0m"
           "\u26DF \033[033m %s \033[0m 최단 경로\n",
           City[from],
           City[to]);
    int sum = 0;
    while ((i = Pop()) != -1) {
        int current = djk[i].distance;
        char arrow[50];
        sprintf(arrow, "\u27A0 %d \u27A0", current - sum);
        printf("%s %s ", arrow, City[i]);
        sum = current;
    }

    printf("\n\033[31m\u26DF\t%dkm\033[0m\n", sum);
    // ShowDijkstra();
}

/// @brief 다익스트라 최단 경로 찾기
/// @param from
/// @param end
void FindDijkstra(int from, int end)
{
    Push(end);
    int i = end;
    while (1) {
        int prev = djk[i].prev_vertext;
        if (prev == -1) break;
        else {
            Push(prev);
            i = prev;
        }
    }
    PrintDijkstra(from, end);
}

/// @brief 경로 추가
/// @param from 출발지
/// @param to 도착지
/// @param weight 가중치
void AddDijkstra(int from, int to, int weight)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->from_name = City[from];
    new->vertext = to;
    new->to_name = City[to];
    new->weight = weight;

    if (graph[from] == NULL) {
        graph[from] = new;
        return;
    }

    struct node *temp = graph[from];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

/// @brief 다익스트라 시작
/// @param start
void StartDijkstra(int start)
{
    int next = -1;
    djk[start].distance = 0;

    while ((next = GetMinVertex()) != -1) {
        djk[next].found = 1;
        UpdateDijkstra(next);
    }
}

void Dijkstra(int from, int to)
{
    printf("*** 다익스트라 알고리즘 ***\n");

    /*
        --> 음수 가중치가 없는 단일 출발 최단 결로 (Single Source Shortest Path) 알고리즘
        --> 하나의 출발 정점에서 다른 모든 정점까지의 최단 경로를 찾는 알고리즘
        --> Floyed Warshall 알고리즘과 비교하여 시간복잡도가 낮음
        --> 시간복잡도: O(V^2)
        --> 공간복잡도: O(V)
        --> V: 정점의 개수
        --> 자동차 네비게이션, 지도 서비스, 라우터 등에 사용
        --> Greedy 알고리즘, Dynamic Programming 알고리즘, BFS 알고리즘과 유사
        --> 동적 프로그래밍 방식을 사용하여 최단 경로를 찾음
    */

    AddDijkstra(0, 1, 15); // 서울 -> 원주
    AddDijkstra(1, 0, 15); // 원주 -> 서울
    AddDijkstra(0, 4, 12); // 서울 -> 천안
    AddDijkstra(4, 0, 12); // 천안 -> 서울

    AddDijkstra(1, 2, 21); // 원주 -> 강릉
    AddDijkstra(2, 1, 21); // 강릉 -> 원주
    AddDijkstra(1, 8, 7);  // 원주 -> 대구
    AddDijkstra(8, 1, 7);  // 대구 -> 원주

    AddDijkstra(2, 3, 25); // 강릉 -> 포항
    AddDijkstra(3, 2, 25); // 포항 -> 강릉

    AddDijkstra(3, 8, 19); // 포항 -> 대구
    AddDijkstra(8, 3, 19); // 대구 -> 포항
    AddDijkstra(3, 9, 5);  // 포항 -> 부산
    AddDijkstra(9, 3, 5);  // 부산 -> 포항

    AddDijkstra(4, 5, 4);  // 천안 -> 논산
    AddDijkstra(5, 4, 4);  // 논산 -> 천안
    AddDijkstra(4, 6, 10); // 천안 -> 대전
    AddDijkstra(6, 4, 10); // 대전 -> 천안

    AddDijkstra(5, 6, 3);  // 논산 -> 대전
    AddDijkstra(6, 5, 3);  // 대전 -> 논산
    AddDijkstra(5, 7, 13); // 논산 -> 광주
    AddDijkstra(7, 5, 13); // 광주 -> 논산

    AddDijkstra(6, 8, 10); // 대전 -> 대구
    AddDijkstra(8, 6, 10); // 대구 -> 대전

    AddDijkstra(7, 9, 15); // 광주 -> 부산
    AddDijkstra(9, 7, 15); // 부산 -> 광주

    AddDijkstra(8, 9, 9);  // 대구 -> 부산
    AddDijkstra(9, 8, 9);  // 부산 -> 대구

    InitDijkstra();
    StartDijkstra(from);
    FindDijkstra(from, to);
}

long ConcatArray(int *arr, size_t len)
{
    long result = 0;
    for (int i = len - 1; i >= 0; i--) {
        int digits = floor(log10(arr[i])) + 1;
        result *= pow(10, digits);
        result += arr[i];
    }
    return result;
}

// 그래프 구조체
typedef struct graph
{
    int vertexCount; // 정점의 갯수
    int **arr;       // 인접행렬, 동적할당된 포인터 배열
} Graph;

/// @brief 그래프 초기화
/// @param g
/// @param vertexCount
void GraphInit(Graph *g, int vertexCount)
{
    g->vertexCount = vertexCount;
    g->arr = (int **)malloc(sizeof(int *) * vertexCount);

    // 인접행렬 초기화
    for (int i = 0; i < vertexCount; i++) {
        g->arr[i] = (int *)malloc(sizeof(int) * vertexCount);
        for (int j = 0; j < vertexCount; j++) {
            g->arr[i][j] = 0;
        }
    }
}

int main()
{

    int choice = 1;
    switch (choice) {
        case 0: exit(0); break;
        case 1: FloydCity(); break;
        case 2: FloydModel(); break;
        case 3: FloydWarshall(); break;
        case 4: {
            // Dijkstra(9, 0);
            printf("서울 (0)\n");
            printf("원주 (1)\n");
            printf("강릉 (2)\n");
            printf("포항 (3)\n");
            printf("천안 (4)\n");
            printf("논산 (5)\n");
            printf("대전 (6)\n");
            printf("광주 (7)\n");
            printf("대구 (8)\n");
            printf("부산 (9)\n");

            int start = 0;
            printf("출발지를 입력하세요: ");
            scanf("%d", &start);
            int destination = 0;
            printf("도착지를 입력하세요: ");
            scanf("%d", &destination);

            // 최단 경로 찾기
            Dijkstra(start, destination);
        } break; // [ 다익스트라 ]

        case 5: EulerRunner(); break;
        case 6: {
            int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            printf("\n배열 합치기 (역순) = %ld\n", ConcatArray(arr, sizeof(arr) / sizeof(arr[0])));
        } break;
        case 7: {
            // Graph
            // 트리와 다르게 양방향으로 연결된 그래프

            // --> 노드와 간선으로 구성
            // 정점 (Vertex) : 노드
            // 간선 (Edge) : 노드와 노드를 연결하는 선

            // 각 위치 정점, 경로는 간선으로 표현
            // 인스타그램 : 노드는 사용자, 간선은 팔로우 관계
            // 항공운송망 : 노드는 공항, 간선은 항공편

            // 무방향 그래프: 간선에 방향이 없는 그래프
            // 방향 그래프: 간선에 방향이 있는 그래프
            // 가중 그래프: 간선에 가중치가 있는 그래프
            // 연결 그래프: 모든 노드가 연결된 그래프
            // 비연결 그래프: 노드가 연결되지 않은 그래프
            // 사이클 그래프: 한 노드에서 시작하여 다시 돌아오는 그래프
            // 비순환 그래프: 사이클이 없는 그래프
            // 완전 그래프: 모든 노드가 서로 연결된 그래프
            // 부분 그래프: 그래프의 일부분
            // 인접 행렬: 노드와 간선을 2차원 배열로 표현

            // 그래프의 종류
            // 1. 무방향 그래프 : 양방향 통행 길, 양방향 통신
            // 2. 방향 그래프 : 일방통행 길, 단방향 통신
            // 3. 가중 그래프 : 간선에 가중치가 있는 그래프, 거리, 시간, 비용 등 (vs 가중치 없는 그래프)
            // 4. 연결 그래프 : 모든 노드가 연결된 그래프
            // 5. 비연결 그래프 : 노드가 연결되지 않은 그래프
            // 6. 사이클 그래프 : Cyclic graph, 한 노드에서 시작하여 다시 돌아오는 그래프
            // 7. 비순환 그래프 : ACyclic 사이클이 없는 그래프
            // 8. 완전 그래프
            // 9. 부분 그래프

            // 구현방법
            // --> Adjacency Matrix : 인접행렬로 구현 (정적 배열, 2차원 배열)
            //     비 가중치 그래프의 간선의 가중치를 1로 표현
            //     무방향 그래프의 경우 대각선을 기준으로 대칭
            //     경로가 없으면 0, 경로가 있으면 1로 표현
            //     간선 쿼리하거나 추가 제가 하는데 O(1) 시간이 걸림
            //     간선 수가 적은 경우 메모리 낭비가 심함

            // --> Adjacency List : 연결리스트로 구현 (동적 배열, 연결리스트)

            // Adjacency Matrix : 인접행렬로 구현
            // 행 : 출발지, 열 : 도착지
            // 0 : 연결되지 않은 경우, 1 : 연결된 경우
            // 무방향 그래프의 경우 대각선을 기준으로 대칭

        } break;

        case 8: {
            Graph g;
            GraphInit(&g, 4);
        } break;

        default: {
            printf("Hello World");

            // double a = 3.14;
            // int b = (int)a;
            // int *p = (int *)&a; // 포인터 캐스팅
            // printf("b = %d\n %p\n", b, p);

            // int arr[5] = {1, 2, 3, 4, 5};
            // int *ptr = arr;
            // int *k = &arr[0];

            // int t = (int *)malloc(sizeof(int) * 1024); // 동적할당

            // int *s = (int *)b;

        } break;
    }
    {
        char *str = "Hello World";
    }
    return 0;
}

/*
--> Floyd Warshall Algorithm

- 그래프에서 최단 거리를 구하는 알고리즘
- 모든 정점에서 모든 정점으로의 최단 거리를 구하는 알고리즘
- 음수 가중치가 있어도 사용 가능
- 시간 복잡도: O(V^3)
- 공간 복잡도: O(V^2)
- V: 정점의 개수
 */
