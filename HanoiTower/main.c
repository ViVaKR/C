#include <stdio.h>

//--> 하노이 타워 함수
void HanoiTower(int n, char from, char temp, char to)
{
    if (n == 1) {                      // 원판이 1개일 때
        printf("원판 %d을(를) %c에서 %c로 이동\n", n, from, to);
        return;                        // 재귀 호출 종료
    }

    HanoiTower(n - 1, from, to, temp); // n-1개 원판을 A에서 B로 이동
    printf("원판 %d을(를) %c에서 %c로 이동\n", n, from, to);
    HanoiTower(n - 1, temp, from, to); // n-1개 원판을 B에서 C로 이동
}

//--> 권장되는 함수
// int getYesNo(void)
// {
//     char ch;
//     while (1) {
//         printf("프로그램을 다시 실행하겠습니까? (Y/N): ");
//         scanf(" %c", &ch);

//         // 대소문자 Y,N 검사
//         if (ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n') {
//             return (ch == 'Y' || ch == 'y');
//         }

//         printf("잘못된 입력입니다. Y 또는 N을 입력해주세요.\n");
//         while (getchar() != '\n'); // 입력 버퍼 비우기
//     }
// }

//--> goto문을 사용한 권장되지 않는 함수 (다만 요청에 의하여 goto문 사용 예시)
int getYesNo(void)
{
    char ch; // 사용자 입력

retry:       // 레이블
    printf("프로그램을 다시 실행하겠습니까? (Y/N): ");
    scanf(" %c", &ch);

    switch (ch) {
        case 'Y':
        case 'y':
            return 1;

        case 'N':
        case 'n':
            return 0;

        default:
            printf("잘못된 입력입니다. Y 또는 N을 입력해주세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            goto retry;                // 레이블로 이동
    }
}

//--> main 함수
int main(void)
{
    unsigned int branch_address = 0x256A;                        // 분기 주소
    int displacement = -0x75;                                    // 분기 주소로부터의 상대 주소
    unsigned int target_address = branch_address + displacement; // 목표 주소
    printf("분기 주소: %XH\n", target_address);                  // 분기 주소 출력

    int x = 1, y = 1, z = 0;
    z = x-- + ++y;
    printf("x=%d, y=%d, z=%d\n", x, y, z);

    int numDisks; // 원판의 개수
    do {
        printf("원판의 개수를 입력하세요 (1-10): ");
        scanf("%d", &numDisks);
        if (numDisks < 1 || numDisks > 10) {
            printf("1에서 10 사이의 숫자를 입력해주세요.\n");
            continue;
        }

        printf("\n=== 하노이 타워 시작 ===\n");
        HanoiTower(numDisks, 'A', 'B', 'C'); // 하노이 타워 함수 호출
        printf("=== 하노이 타워 완료 ===\n\n");

    } while (getYesNo()); // 사용자 입력에 따라 반복

    return 0;
}
