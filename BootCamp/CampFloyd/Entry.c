#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Floyd();
void Path();
void Print();
int Min(int a, int b);

int a[10][10];
int d[10][10];
int n;

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

void Floyd_City()
{
    const int INF = 1000000000; // 비교를 위한 비교적 큰값설정, 교체값
    const int size = 11;        // 열이름 표시를 위해 1을 더함
    char City[][8] = {"서울", "원주", "강릉", "포항", "천안", "논산", "대전", "광주", "대구", "부산"};

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
                }
            }
        }
    }
    printf("\n");

    // 최단거리 출력 표 (도시이름과 함께 출력)
    printf("\u2728 \033[33m 최단거리 출력 표 (도시이름과 함께 출력) \033[0m \u2728\n");
    // for (int i = 0; i < size; i++) {
    //     if (i == 0) {
    //         printf("\t");
    //         for (int j = 0; j < size - 1; j++) {
    //             printf("\033[32;42m %s \033[0m\t", City[j]);
    //         }
    //         printf("\n");
    //         continue;
    //     }

    //     for (int j = 0; j < size; j++) {
    //         if (j == 0) {
    //             printf("\033[32;42m %s \033[0m\t", City[i - 1]);
    //             continue;
    //         }
    //         printf("%4d\t", dist[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\n");

    // From ~ To : 최단거리 출력 (도시이름과 함께 출력)
    // printf("\u2728 \033[33m From ~ To : 최단거리 출력 (도시이름과 함께 출력) \033[0m \u2728\n");
    // for (int i = 0; i < size; i++) {
    //     if (i != 0) {
    //         printf("\u26DF ");
    //     }
    //     for (int j = 0; j < size; j++) {
    //         if (dist[i][j] == INF) {

    //             continue;
    //         }
    //         if (i == j) continue;
    //         printf("\033[31m %s\u27A0%s \u276A%2dkm\u276B,\033[0m ", City[i - 1], City[j - 1], dist[i][j]);
    //     }
    //     printf("\n");
    // }
}

void Floyd()
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

int main()
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
    Floyd();
    system("clear");
    Floyd_City();
    // Path();

    // int Digs = DECIMAL_DIG;
    // printf("DECIMAL_DIG = %.*f\n", Digs, exp(1));
    // printf("DECIMAL_DIG = %.*f\n", Digs, calculate(10));
    // printf("DECIMAL_DIG = %.*f\n", Digs, E());
    // double e = calculate(10);
    // printf("\n*** e 의 근사값 ***\n"
    //        "E() =>\t%.16f\n"
    //        "E() =>\t%.16f\n"
    //        "E() =>\t%.32llf\n",
    //        e,
    //        E(),
    //        exp(1));

    return 0;
}

int Min(int a, int b)
{
    return a < b ? a : b;
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
