#include <stdio.h>

//--> 하노이 타워 함수
void HanoiTower(int n, char from, char temp, char to)
{
    if (n == 1)
    { // 원판이 1개일 때
        printf("원판 %d을(를) %c에서 %c로 이동\n", n, from, to);
        return; // 재귀 호출 종료
    }

    HanoiTower(n - 1, from, to, temp);
    printf("원판 %d을(를) %c에서 %c로 이동\n", n, from, to);
    HanoiTower(n - 1, temp, from, to);
}

void HanoiTower_Simple(int n, char from, char temp, char to)
{
    if (n == 0)
        return; // 원판이 없으면 그냥 종료
    HanoiTower(n - 1, from, to, temp);
    printf("원판 %d: %c -> %c\n", n, from, to);
    HanoiTower(n - 1, temp, from, to);
}

/*
[push] H(3,A,B,C) 진입
   → ① H(2,A,C,B) 호출  [push]
       → ① H(1,A,B,C) 호출  [push]
           → n==1, print "1: A→C"
       [pop] H(1,A,B,C) 종료
       → ② print "2: A→B"
       → ③ H(1,C,A,B) 호출  [push]
           → n==1, print "1: C→B"
       [pop] H(1,C,A,B) 종료
   [pop] H(2,A,C,B) 종료          ← 여기서 H(2,...)가 완전히 끝남
   → ② print "3: A→C"
   → ③ H(2,B,A,C) 호출  [push]     ← 친구가 헷갈렸던 지점! 여기가 "바로 그자리"가 아님
       → ① H(1,B,C,A) 호출  [push]
           → n==1, print "1: B→A"
       [pop] H(1,B,C,A) 종료
       → ② print "2: B→C"
       → ③ H(1,A,B,C) 호출  [push]
           → n==1, print "1: A→C"
       [pop] H(1,A,B,C) 종료
   [pop] H(2,B,A,C) 종료
[pop] H(3,A,B,C) 종료


(lldb) br se -n hanoi
(lldb) target stop-hook add -o "disassemble -p"  // -p(pc-centric) 현재 PC(실행중인 명령어 )주변
(lldb) target stop-hook add -o "bt"              // 멈출 때 마다 콜스택 전체를 자동으로 출력
(lldb) run
*/

//--> main 함수
int main(void)
{
    int numDisks; // 원판의 개수
    do
    {
        printf("원판의 개수를 입력하세요 (1-10): ");
        scanf("%d", &numDisks);
        if (numDisks < 1 || numDisks > 10)
        {
            printf("1에서 10 사이의 숫자를 입력해주세요.\n");
            continue;
        }

        printf("\n=== 하노이 타워 시작 ===\n");
        HanoiTower(numDisks, 'A', 'B', 'C'); // 하노이 타워 함수 호출
        printf("=== 하노이 타워 완료 ===\n\n");

    } while (getYesNo()); // 사용자 입력에 따라 반복

    return 0;
}
