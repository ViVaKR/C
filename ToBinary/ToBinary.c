#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ToBinary(int n)
{
    printf("\n");
    printf("10진수 ( %d ) -> 2진수 변환\n", n);

    for (int i = 31; i >= 0; --i) {
        printf("%d%c", (n >> i) & 1, i % 4 == 0 ? ' ' : '\0');
    }
    printf("\n");
}

// Recursive Fuction.
int sum;
void MakeBinary(int n, int i, int digit)
{
    if (i == digit) return; // base case
    MakeBinary(n, i + 1, digit);
    char c = i % 8 == 0 ? ' ' : '\0';
    int binary = (n >> i) & 1;
    sum += binary == 1 ? 1 : 0;
    printf("%d%c", binary, c);
}

typedef struct node
{
    char *name;
} Node, *NodePtr;

NodePtr create(char *message)
{
    NodePtr new_element = (NodePtr)malloc(sizeof(Node));

    if (!new_element) {
        printf("Out of memory\n");
        return NULL;
    }

    new_element->name = message;
    return new_element;
}

void destroy(NodePtr garbage_element)
{
    // free(garbage_element->name); // 할 필요 없음, name 멤버는 아래 garbage_element 에 속해 있지 별도 메모리 할당된 것이 아님으로..
    free(garbage_element);
}

int main()
{
    int decimal = -1;
    while (decimal != 0) {
        printf("2진수로 변경할 정수를 입력하세요.\n\u27AD ");
        scanf("%d", &decimal);
        printf("\n");
        int digit = 32; // 32 자리, 만일 8자리 면 8로 수정...
        sum = 0;        // 1의 합계 글로발 변수 초기화
        MakeBinary(decimal, 0, digit);
        printf(" (%d) ", decimal);
        printf("\n0의 갯수 = ( %d )개, 1의 갯수 => ( %d )개\n", digit - sum, sum);
    }

    // [ 알파벳만 추리기 ]
    // 원본 혼합된 문자열.
    char s[100] = "x!  \t@ ? za\tq h%^_-$e=l!l    o, w\no$      r\tl^d";
    char str[100]; // 알파벳만 추릴 배열
    int t = 0;
    for (int i = 0; i < 50; i++) {
        int result = isalpha(s[i]);
        if (result != 0) str[t++] = s[i];
    }
    printf("%s\n", str);
    return 0;
}
