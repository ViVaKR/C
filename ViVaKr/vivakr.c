#include <Kernel/stdbool.h> // _Bool
#include <assert.h>         // assert
#include <ctype.h>          // tolowere(int argument),
#include <float.h>
#include <limits.h>         // 정수 유형에 대한 다양한 구현 밸 제한을 정의
#include <math.h>           // 수학함수
#include <stdbool.h>        // true, false 를 정의
#include <stdio.h>          // printf, scanf 입/출력 기능 제공
#include <stdlib.h>         // 메모리 할당, 랜드 함수 및 유틸리티 기능
#include <string.h>         // strcpy, strlen 등 문자열 조작
#include <time.h>           // 날짜와 시간으로 작업한는 기능
#include <unistd.h>         // sleep(unsigned int)
/// 매크로와 상수
#define PI 3.141592

/// Global function declaration

/// (Utilities) =============================================================================
int MakeRandom(int min, int max)
{
    const int number = (rand() % (max - min + 1)) + min;
    return number;
}

/// (String Compress & DeCompress)
void compress(char *instr, char *outstr)
{
    char c = instr[0];
    int p = 0;
    int cnt = 0;             // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        if (c == instr[i])
            cnt++;           /* 이전과 같은 문자열이면 cnt 늘리기 */
        else if (cnt == 1) { /* 이전과 달라지는데 다른 문자열, 한 번이면 이전 문자열 출력하고 c에 현재 문자열 넣기 */
            outstr[p++] = c;
            c = instr[i];

        } else { /* 이전과 달라지는데 다른 문자열이 이미 여러개 쌓인 경우면 이전 숫자, 이전 문자열 출력하고 현재
                    문자열로 갱신, 그리고 다른 문자열이 한 번 나온 상태이므로 cnt =1로 초기화 */
            outstr[p++] = cnt + '0';
            outstr[p++] = c;
            c = instr[i];
            cnt = 1;
        }
    }
    /* 반복문 끝나고 NULL 나올때 출력하는 방법 */
    if (cnt == 1)
        outstr[p++] = c;
    else {
        outstr[p++] = cnt + '0';
        outstr[p++] = c;
    }
    outstr[p] = 0; /* 문자열 마지막에 NULL 입력 */
} // 1번

void compress_2(char *instr, char *outstr)
{
    _Bool tf = true;

    char c = instr[0];
    int p = 0;
    int cnt = 0; // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        if (c == instr[i])
            cnt++;
        else if (cnt == 1) {
            outstr[p++] = c;
            c = instr[i];
        } else {
            outstr[p++] = c;
            outstr[p++] = cnt + '0';
            c = instr[i];
            cnt = 1;
        }
    }
    if (cnt == 1)
        outstr[p++] = c;
    else {
        outstr[p++] = c;
        outstr[p++] = cnt + '0';
    }
    outstr[p] = 0;
} // 1-1번

void decompress(char *instr, char *outstr)
{
    int p = 0;
    int cnt = 1;                    // cnt 값이 0 or 1?
    for (int i = 0; instr[i]; i++) {
        char c = instr[i];
        if (c >= '0' && c <= '9') { /* 숫자인 경우 cnt로 횟수 저장 */
            cnt = c - '0';
        } else {                    /* 문자열인 경우 cnt만큼 문자열 출력 */
            for (int j = 0; j < cnt; j++) {
                outstr[p++] = c;
            }
            /* 문자열 출력하고 나서 cnt 1로 초기화 */
            cnt = 1;
        }
    }
    outstr[p] = 0; // output[0] = 0인가요?
} // 2번

void StringCompressStart()
{

    char *origin = "zzzzzzzzaaabbcdddeee";
    printf("[ %s ]\n", origin);
    char output[sizeof(origin)];
    compress(origin, output);
    printf("%s\n", output);

    char output_compare[10];
    compress_2("ZZZZZZZZ", output);
    printf("%s\n", output);
    char compare[] = "8z3a2Bc3d3e";
    decompress(compare, output);
    printf("%s\n", output);
}

typedef struct vnode
{
    int value;
    struct vnode *next;
} node;

node *head = NULL;

// 첫번째 노드삭제
node *RemoveFrontNode()
{
    if (head == NULL)
        return NULL;

    // (1) 삭제할 첫번째 노드를 => 임시 노드에 저장
    node *temp;

    temp = head;

    // (2) head를 삭제할 노드 => 다음 노드로 이동
    head = head->next;

    // (3) 첫번째 노드를 제거, free 는 temp 가 가르키는 대상이 제거됨.
    node *del = temp->next; // 제거된 노드 주소를 반환하기 위함 (temp 가 아님..)
    free(temp);
    return del;
}

/// (3) Print All Nodes
void DisplayNode()
{

    int count = 0;
    node *current;

    if (head == NULL)
        return;
    system("clear");

    printf("\n\n[ \u2665 Display LinkedList \u2665 ]\n\n");
    current = head;
    do {
        printf("(%3d) current node address: %11p, node value: %4d\n", ++count,
               current->next, current->value);
        current = current->next; // second address
    } while (current != NULL);
    // Last Node
    // printf("(%3d) current node address: %11p, node value: %4d\n", ++count,
    // current->next, current->value);
}

/// (4) 노드의 갯수 구하기
int GetNodeCount()
{

    node *current; // 방문노드의 주소를 저장하는 포인터변수 8바이트
    if (head == NULL)
        return 0;

    current = head;
    int count = 0;

    while (current != NULL) {
        ++count;
        current = current->next;
    }
    return count;
}

/// Remove All Nodes, Moemory Free
int LinkedListMemoryFree()
{

    // 링크드리스트 노드 메모리 해제 작업
    // 선두 노드를 제거하는 작업을 반복하는 알고리즘.

    node *temp;

    if (head == NULL)
        return 1;

    int count = 0;
    printf("총 노드의 수 =>\t%d \n", GetNodeCount());
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        count++;

        int remained = GetNodeCount();
        printf("남아있는 노드 =>\t%d \n", remained);
        sleep(1);
    }
    return count;
}

void LinkedListStartAtLast(int count)
{
    // TODO
}
// (2) LIFO 노드 만들기
void InsertFrontNode(int data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;

    if (head == NULL) { // 처음 연결시..
        head = newNode;
        char *address = (char *)malloc(32);
        sprintf(address, "%11p", head->next);
        printf("첫 노드 연결\t=> %s (%5d)\n",
               head->next == NULL ? "Started Head" : address, head->value);
        free(address);
        return;
    }

    newNode->next = head;
    head = newNode;
    printf("일반 노드 연결\t=> %11p (%5d)\n", head->next, head->value);

} // End InsertFrontNode

/// (2) FIFO 후미에 노드 만들기
void InsertTailNode(int data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->value = data;
    newNode->next = NULL;
    int count = 0;

    if (head == NULL) {
        head = newNode;
        char *address = (char *)malloc(32);
        sprintf(address, "%11p", head->next);
        printf("( %3d ) 첫 노드 연결\t=> %s (%5d)\n", ++count, head->next == NULL ? "Started Head" : address, head->value);
        return;
    }

    // 연결리스트 순회 하여 마지막 노드의 위치 확인
    node *current; // 방문노드의 주소를 저장하는 포인터 변수 (8바이트)
    current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    // 마지막 노드와 새노드를 연결
    current->next = newNode;
    printf("( %3d ) 일반 노드 연결 (후미)\t=> %11p (%5d)\n", GetNodeCount(), current->next, newNode->value);
}

// Linked List
void LinkedListStart(int count, bool order)
{
    srand(time(NULL));

    for (size_t i = 0; i < count; i++) {
        if (order == 1)
            InsertFrontNode(i + 1);
        else
            InsertTailNode(i + 1);
    }
}

/// (6) 값을 통한 노드 삭제
void RemoveNodeByValue()
{
    int value;
    printf("삭제할 값 입력\n>> ");
    scanf("%d", &value);
    fflush(stdin);

    node *delNode;

    if (head == NULL) {
        printf("연결 리스트가 구성되지 않아 삭제할 노드가 없습니다.");
        return;
    }
    printf("삭제할 노드의 값은 %d 입니다.\n계속하시려면 아무키나 누르세요.", value);
    getchar();
    sleep(1);

    // 삭제할 노드가 첫번째 노드 삭제할 경우.
    if (head->value == value) {
        // 첫노드 삭제
        delNode = head;
        head = head->next; // head 를 다음으로 이동
        free(delNode);
        return;
    }

    // 중간삭제
    node *prev; // 삭제할 이전노드의 포인터

    // 첫번째 노드 부터 검색 시작
    prev = head;
    delNode = head;

    // prev 로 다음 널체크를 한 다음
    // 널이 아니면? delNode 를 먼저 움직임.

    while (prev->next != NULL) {

        delNode = prev->next;

        if (delNode->value == value) {

            // 연결
            prev->next = delNode->next;

            // (출력을 위한 임시 저장)
            node *n = delNode;
            int v = delNode->value;

            // 삭제
            free(delNode);
            printf("삭제 완료 하였습니다. ( \n%p => %d ) \n", n, v);
            free(n);
        }
        prev = delNode;
    }

    sleep(1);
    printf("계속하려면 아무키나 누르세요!");
    getchar();
}

void FPrinfEx(int a, int b)
{
    FILE *fp = fopen("fprintf.txt", "w");
    fprintf(fp, "%d + %d = %d\n", a, b, a + b);

    fclose(fp);
}

/// Min Max
void GetMax()
{
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
}

void SPrintfEx(int a, int b)
{
    char str[128];
    sprintf(str, "%d + %d = %d", a, b, a + b);

    printf("%s\n", str);
}

void ClockEx()
{

    clock_t start, end; // unsigned long
    double total;

    start = clock();
    printf("Starting of the program, Start = %ld", start);

    int sum = 0;
    for (size_t i = 0; i < 10; i++) {
        sum++;
        printf("=> ( %d )\n", sum);
        fflush(stdout);
        sleep(1);
    }
    end = clock();
    printf("End of the loop, End = %ld\n", end);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf(
        "Sum = ( %d )\n=> Total time taken by CPU: %f\n",
        sum,
        duration);
}

void AssertEx(int a, int b)
{
    assert(a == b);
}

void CTypeEx(char ch, int number)
{
    bool digit = isxdigit(number);
    printf("%d\n", digit);
}

void SScanfEx(char *str)
{

    double pi;
    char ch;
    char name[20];

    sscanf(str, "%lf %c %s", &pi, &ch, name);
    printf("%lf, %c, %s\n", pi, ch, name);
}

void BoolEx(_Bool tf)
{
    if (tf)
        printf("Hello World %d\n", tf);
    else
        printf("False %d\n", tf);
}

void SignalHandler(int sig)
{
    printf("\nCaughted Signal => ( %d )\n", sig);
}

void PointerArray()
{
    // 원본 => int x[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // => 설명을 위해 아래와 같이 변경함, x 를 => arr2d 로 이름변경,
    //    (동일한 의미의 배열, 원래 다차원 배열이라도 위와 같이 실제 메모리에는 한줄로 줄서 있는 형식임...)

    //       [행][열]
    int arr2d[4][3] = {
        {1, 2, 3},    //-> arr2d[0]
        {4, 5, 6},    //-> arr2d[1]
        {7, 8, 9},    //-> arr2d[2]
        {10, 11, 12}  //-> arr2d[3]
    };

    int(*p)[3];       // 위 원본을 3개썩 짜르니 가로 세로 4 * 3 의 매트릭스에서 1차원 배열 3개 짜리 * 4행을 지칭? 하는 가르키?는 말이됨. -> 즉, (배열 포인터)
    int *pp[3];       // 포인터로 이루어진 배열 3개 즉, -> (포인터 배열 )

    p = &arr2d[1];    // (1) == 두번째 행인 -> 배열 &{ 4, 5, 6} 의 첫번째 주소가, 저장된 변수.
    pp[0] = arr2d[2]; // (2) == &{ 7, 8, 9}, 에서 0번째 요소 즉,번-> 7번 방 주소.

    printf(
        "(*p)[0]\t\t=>\t%d\np[1][0]\t\t=>\t%d\n*pp[0]\t\t=>\t%d\n**(p = 1)\t=>\t%d\n",

        (*p)[0],  // -> 의미 : 위 (1) 을 유심히 관찰 후 -> 해석, -> {4, 5, 6} 의 0번째 인덱스의 값 (역참조 *)을 가져 -> 오라이..하여 -> 4이며,
        p[1][0],  // -> 의미 : 바로 위 가 보면 => (*p)[0] 은 => p[0][0] 과 같음, 하여 => p[1][0] 은 => (*(p + 1)[0]) 과 같음 -> 다음 행의 첫번째 값이 머냐는 것임 결론 => 위 (1) 에서 인덱스를 하나 증가 시킨 효과 때문에, 원배열에서 하나 더 추가 arr2d[2] 행의 0번째 인덱스 값이 머냐는 것임 하여 답은 => 7 이됨.
        *pp[0],   // -> 의미 : 위 (2) 번을 뚜러지개 관찰 후 -> 해석 => 배열 { 7, 8, 9 } 의 0번째 index 값을 가져 -> 다라이 하여 7이고,
        **(p + 1) // -> 의미 : 다시 위 (1) 으로 돌아가서..=> p 는 {4, 5, 6}을 가르키는 배열 포인터 이므로 => 그거에 하나 더하면  => {7, 8, 9} 를 가르키는 포인터가 됨.. 하여 => 역참조 *(p + 1)) 하나 이면? => {7,8,9} 를 가르키는 0번 인덱스 주소값이 되고 => * 을 하나 더 추가  **(p + 1)을 하니 자연스럽게  => 0번째 인덱스 주소가 아닌, 해당 값을 달라고 한 것이니 => 답은 => 7.

    );

    // 최종 답 => 1번 입니다. 다른 건 다 7인데, 1번만 독고 다이 4 임.

    char input;

    printf("문자형 입력(%%c) : ");
    scanf("%c", &input);
    printf("문자로 출력(%%c) : %c\n", input); // 'A'

    // `A` 아스키 => 65
    printf("Input Char `%c`, ASCII Code Number\t:\t%d\n", input, input);
    // `0` 아스키 => 48
    printf("ASCII Code `%c`, ASCII Code Number\t:\t%d\n", '0', '0');
    // 그러므로...
    printf("\u2234 %c - %c = %d\n", input, '0', input - '0'); // 17, (65 - 48)

    printf("\n%1$c %1$d\n", input);

    char a = 'a';
    char *abcd = "ABCDE";
    // Format Specifiers
    // %<사용할변수 순번 : 1번 부터 시작>$<정렬방향, - => left, + => right()><전체자릿수>.<소숫점이하자릿수><출력형식지정자>
    printf("\n%1$-20c\n%1$20c\n%2$-20s\n%2$20s\n", a, abcd);
}

long long Fibonacci(int n);

long long memo[200]; // 중복된 값 처리..

long long Fibonacci_memoization(int num)
{
    if (memo[num] == -1)            // 새로운 값이면?
        memo[num] = Fibonacci(num); // 힘들게 돌고
    return memo[num];               // 그렇지 않으면? 있는 그 값을 돌려 줘라...
}

int count = 0;

long long Fibonacci(int n)
{
    count++; // 몇 번 도는 지 체크 ...
    // 재귀를 구성 자체가 2진 트리 형태이므로
    // 메모, 케쉬된 값으로 중간에 그 악?의 축을 절단하면
    // 엄청난 횟수 차감효과가 발생함.
    return n <= 1 ? n : Fibonacci_memoization(n - 1) + Fibonacci_memoization(n - 2);
}

void FibonacciStart()
{

    for (size_t i = 0; i < 100; i++) {
        memo[i] = -1;
    }
    puts("");
    int number = 80; // 그냥 돌리면, 꽤 시간이 걸림..
    // F50 = 12586269025
    //       12586269025
    // F80 = 2.3416728348468E+16
    // memoization => 23416728348467685 (81회 순회)

    long long result = Fibonacci(number);
    printf("Fibonacci %d, result = %lld, counting recurs => (%d)\n", number, result, count);
}

void StringCopy(char *university, char *school)
{
    int i = 0;
    while ((university[i] = school[i]) != '\0') i++;
    printf("\n%s, %s\n\n", university, school);
}

void CompareNumbers()
{
    long number;
    printf("3의 배수여부를 판단할 양의 정수를 하나를 입력하세요\n>> ");
    scanf("%ld", &number);
    char *result[] = {"3의 배수입니다.", "3의 배수가 아닙니다."};
    printf("%ld -> %s\n", number, result[(number % 3) && 1]);
    long a, b, c;
    printf("비교할 숫자 3개를 한칸씩 띄워서 입력하세요\n>> ");
    fflush(stdin);

    long rs[] = {};
    long input[] = {0, 0, 0};
    scanf("%ld %ld %ld", &input[0], &input[1], &input[2]);
    rs[(input[0] > input[1]) + (input[0] > input[2])] = input[0];
    rs[(input[1] > input[0]) + (input[1] > input[2])] = input[1];
    rs[(input[2] > input[0]) + (input[2] > input[1])] = input[2];
    printf("(%ld - %ld - %ld) 중 두번째로 큰수는 => (%ld) 입니다. ", input[0], input[1], input[2], rs[1]);
}

// DateTime
typedef struct
{
    int y; // 년
    int m; // 월(1~12)
    int d; // 일(1~31)
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);
/*--- 각 달의 날 수 ---*/
static int mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 평년
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 윤년
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- y년 m월 d일을 나타내는 구조체를 반환하는 DateOf 함수 ---*/
Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수 ---*/
Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if (++x.m > 12) {
            x.y++;
            x.m = 1;
        }
    }
    return x;
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);

    x.d -= n;

    while (x.d < 1) {
        if (--x.m < 1) {
            x.y--;
            x.m = 12;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }

    return x;
}

/*--- 날짜를 표시 ---*/
void Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char *ws[] = {"일", "월", "화", "수", "목", "금", "토"};
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d년%02d월%02d일(%s)", x.y, x.m, x.d,
           ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

void GetDate()
{
    int y, m, d;

    printf("날짜를 입력하세요.\n");
    printf("년: ");
    scanf("%d", &y);
    printf("월: ");
    scanf("%d", &m);
    printf("일: ");
    scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("며칠 전/후의 날짜를 원합니까?: ");
    scanf("%d", &n);

    printf("%d일 후의 날짜: ", n);
    Print(After(x, n));
    putchar('\n');

    printf("%d일 전의 날짜: ", n);
    Print(Before(x, n));
    putchar('\n');
}

void FloatToBinary(float num)
{
    int exp, sign;
    float mantissa = frexpf(num, &exp); // 가수부와 지수부 계산
    if (num < 0) {
        sign = 1;                       // 음수 처리
        mantissa = -mantissa;
    } else {
        sign = 0;                       // 양수 처리
    }
    printf("실수 값 %f의 2진수 표현: %d ", num, sign);
    for (int i = FLT_MANT_DIG - 1; i >= 0; i--) {
        mantissa *= 2;
        if (mantissa >= 1) {
            printf("1");
            mantissa -= 1;
        } else {
            printf("0");
        }
    }
    printf(" x 2^%d\n", exp - 1);
}

typedef struct p
{
    int x, y;
} PT;

void calcPoint(PT *x, PT *y, PT *z)
{
    z->x = x->x + y->x;
    z->y = x->y + y->y;
}

void BigO(int number)
{
    // 등차수열의 합의 공식
    int sum = (number + 1) * number / 2;
    printf("O(1) => %d\n", sum);
    sum = 0;
    for (size_t i = 1; i <= number; i++) {
        sum += i;
    }
    printf("O(N) => %d\n", sum);
}

void Menu()
{
    char *items[] = {
        "=========================",
        "  1. 노드 생성 (Front)",
        "  2. 노드 생성 (Tail)",
        "  3. 노드 현황",
        "  4. 노드 갯수",
        "  5. 첫번째 노드삭제",
        "  6. 선택값 삭제",
        "  7. 모든 연결리스트 제거",
        "=========================",
        "  8. 문자 압축 및 해제",
        "  9. 최대 최소값",
        " 10. fprintf()",
        " 11. clock()",
        " 12. sprintf()",
        " 13. assert()",
        " 14. ctype()",
        " 15. sscanf()",
        " 16. _Bool()",
        " 17. PointerArray()",
        " 18. Fibonacci()",
        " 19. CompareNumbers()",
        " 20. StringCopy()",
        " 21. Signal()",
        " 22. Float Memory",
        " 23. Big(O)",
        "200. 프로그램 종료"};

    int count = sizeof(items) / sizeof(*items);
    printf("== Menus (%d) ==\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("%s\n", items[i]);
    }
}

int main(void)
{
    // PT p1 = {10, 20}, p2 = {30, 40}, p3 = {0, 0};
    // calcPoint(&p1, &p2, &p3);
    // printf("(%d, %d)\n", p3.x, p3.y);
    // return 0;

    int choice;

    while (choice != 200) {
        Menu();
        printf("\n메뉴선택\n>> ");
        scanf("%d", &choice);
        fflush(stdin);
        system("clear");
        int count;

        switch (choice) {
            case 1: { // 맨 앞에 노드 추가, 생성된 역순으로 연결. (LIFO) : 스택 (Stack)
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 1);
            } break;
            case 2: { // 맨뒤에 노드를 추가 : 생성된 순으로 연결 (FIFO) : 큐 (Queue)
                // TODO
                printf("=> 생성할 노드의 수: ");
                scanf("%d", &count);
                LinkedListStart(count, 0);
            } break;
            case 3: DisplayNode(); break; // 현재 전체 연결리스트 노드 출력
            case 4: printf("노드의 수 = %d\n", GetNodeCount()); break;
            case 5: {
                node *p = RemoveFrontNode();
                DisplayNode();
                sleep(1);
                printf("첫번째 노드 ( %p ) 제거가 완료되었습니다.\n", p);
            } break;

            case 6: RemoveNodeByValue(); break;
            case 7: { // Node Memory Free
                int complete = LinkedListMemoryFree();
                if (complete > 0)
                    printf("링크드리스트 ( %d ) 개 모두 제거 완료 되었습니다. \n",
                           complete);
                fflush(stdin);
                sleep(3);
                printf("계속하려면 아무키나 누르세요!");
                getchar();
            } break;
            case 8 : StringCompressStart(); break;
            case 9 : GetMax(); break;
            case 10: FPrinfEx(125, 567); break;
            case 11: ClockEx(); break;
            case 12: SPrintfEx(45, 83); break;
            case 13: AssertEx(45, 83); break;
            // case 14: CTypeEx('A', 0xFFFF); break;
            case 15: SScanfEx("3.14 A KimBumJun"); break;
            case 16: BoolEx(true); break;
            case 17: PointerArray(); break;
            case 18: FibonacciStart(); break;
            case 19: CompareNumbers(); break;
            case 20: { // String Copy
                char *s1 = malloc(20);
                char *s2 = malloc(20);
                strcpy(s1, "University");
                strcpy(s2, "School");
                StringCopy(s1, s2);
                strcpy(s1, "University");
                strcpy(s2, "School");
                StringCopy(s2, s1);
                free(s1);
                free(s2);
            } break;
            case 21: signal(SIGINT, SignalHandler); break;
            case 22: FloatToBinary(3.14); break;
            case 23: BigO(10);

            default: break;
        }
    }

    printf("\n*** Program Exited ***\n");
    return 0;
} /// end main

/** C
1999 - C99
2011 - C11
2018 - C17
2024 - C23, C2x

- 컴파일러 -
1. GNU Compiler Collection (GCC)
2. Clang : LLVM 프로젝트의 일부인 오픈 소스 C 컴파일러. 속도와 최적화 기능 탁월
3. 마이크로소프트 비주얼 C++
4. 터보 C : 단종

$ gcc -c hello.c -o hello.o

- 라이브러리 함수 -
확장자 .h 헤더파일로 사전 정의된 함수로 구성됨

- 유형 -
1. 라이브러리 함수
2. 사용자 정의 함수

- 프로그램 진입점 : main()

IR (.s) -> [ Assembler ] -> Binary Code (.o) -> [ Linker ] -> execute file

$ gcc main.c -o hello.out

- 토큰 -
1. 문자 : 소스코드에서 직접 하드 코딩된 변수에 할당될 값의 텍스트 표현.
    - 숫자
    - 리터럴 : 작은 따옴표
    - 탈출 시퀀스 : 문자 그대로의 한 유형..
2. 키워드 : 약 32개+, 소문자
    - 기본데이터 유형 (Primary Data Types)
        * Int
        * Long
        * Short
        * Signed
        * Double
        * Char
        * Float
        * Unsigned
        * Void
    - 사용자 정의 유형 (User defined types)
        * struct
        * typedef
        * union
        * enum
    - 저장 유형 (Storage types)
        * auto
        * Extern
        * static
        * Register
    - 조건 부 (Conditionals)
        * goto
        * if
        * else
        * case
        * Switch
        * Default
    - 루프와 루프 컨트롤 (Loop and loop controls)
        * For
        * do
        * while
        * Continue
        * break
    - 기타.. (Others)
        * const
        * sizeof
        * Volatile
    - In C99, C11, C23 version more keywords
        * _Bool
        * _Complex
        * _Imaaginary
        * inline
        * _Alginas
        * _Alignof
        * _Atomic
        * _Generic
        * _Noreturn
        * _Static_assert
        * alignas
        * alignof
        * bool
        * constexpr
        * false
        * nullprt
        * static_assert
        * thread_local
        * true
        * typeof
        * typof_unqual
        * _Decimal128
3. 식별자 : 키워드와 달리 사용자 정의 요소. 변수, 상수, 라벨, 사용자 정의 함수
4. 특별 기호 : ! " # $ % & ' ( ) * + - . : , ; ` ~ = < > { } [ ] ^ _ \ /
5. Operator :
6. Special Symbol : 쉼표, 세미콜론, 콜론, 구두점, 괄호

- Format Specifier
%c              - Character
%d              - Signed integer
%f              - Float
%i              - Unsigned integer
%l %ld, %li     - Long
%lf             - Double
%Lf             - Long Double
%lu             - Unsigned int or unsigned long
%lli or %lld    - Long Long
%llu            - Unsigned long long

- Syntax -
: 프로그램 소스코드를 작성시 규정된 규칙 세트

- 토큰 : 키워드, 식별자, 상수, 문자열, 리터럴, 기호

keyword
auto, break, case, char, const, continue, default, do, double,
else, enum, extern, float, for, goto, if, int, long, register
return, short, signed, sizeof, static, struct, switch, typedef
union, unsigned, void, volatile, while, _Packed, double

Header

Expression:
하나 이상의 값으로 표현 (reduce)될수 있는 코드
Statement  : 실행가능한 최소 독립적인 코드 조각. 컴파일러가 실행할 수 잇는 모든 구문. 한개 이상의 expression 과 키워드를 포함.

Type:
- Basic Types
    * integer types
        -> char
        -> unsigned char
        -> signed char
        -> int
        -> unsigned int
        -> unsigned int
        -> short
        -> unsigned short
        -> long
        -> unsigned long
    * floating-point types
- Enumerated types
- The type void
    * Functionreturns as void : void exit(int status);
    * Function arguments as void : int rand(void);
    * Pointers to void : (void*)malloc(size_t size);
- Derived types
    * Pointer
    * Array types
    * Structure types
    * Union types
    * Function types
- Arrays : int marks[5]; - square brackets [ ]
- Pointer : asterisk (*)
- Namming Convention : 변수의 이름은 알파벳 대문자 또는 소문자 밑줄로 시작
    * 변수 이름은 대소문자를 구분.
    * ANSI 표준으로 31자의 길이를 인식, 매우 짧은 변수 이름을 사용하지 않는다.
    * 정적인 언어이므로 데이터 유형은 이름 앞에 선언 되어야 한다.
- Lvalue : 메모리 위치를 참조하는 표현, 왼쪽 또는 오른쪽으로 나타날 수 있다.
- Rvalue : 메모리의 일부 주소에 저장된 데이터 값을 가리킴. 값을 할당 할 수 없는 표현이프로 오른쪽에 나타날 수 있지만 할당의 왼쪽에는 나타나지 못함.

- Variables
    * Data types - int, float, char or struct types
    * Scope - global or local variables
    * Storage type - automatic, static, register or extern.
    *
- ctype
   int isalnum(int c); // checks whether the passed character is alphnumeric
   int isalpha(int c); // checks alphabetic.
 */
