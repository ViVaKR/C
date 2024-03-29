#include "../headers/vivstd.h"

//-> 비표준라이브러리 #include <conio.h>, 비표준함수 getch();
int Factorial(int nVar);
enum { A,
       B } myEnum;

void Function() {

    /* [ 함수 ]
        - 특정한 작업을 수행하도록 작성된 독립된 코드
        - 반복적인 코드를 재사용 할 수 있도록 함
        - 역할에 따른 코드 구분이 용이함
        - 코드 가독성을 높여줌
        - 종류 : 컴파일러 제공함수 `표준함수`, 사용자 `제작함수`
            - 제작함수 : 프로그램 구조를 함수 단위로 나눔
                - 위치 : main() 상단에 원형을 정의 후 메인 하단에서 사용하거나 메인 헤더 파일에 원형을 정의
                - 초기화 관련 : InitXXXX()
                - 업데이트에 관한 코드 : UpdateXXXX();
                - 메모리 해제에 관한 코드 : ReleaseXXXX();
        - 구성 : 리턴형, 함수명, 매개변수, 함수본문
        - 함수명 : 메모리 주소를 의미
        - 헤더파일
            - 함수의 원형에 대한 정보 제공
            - 라이브러리에 관련된 정보 제공
            - `<xxx.h>`: 컴파일러 제공함수
            - `"xxx.h" : 사용자 제작함수
        - 설명서 : msdn.microsoft.com/ko-kr
    */

    printf(" 함수 ");

    char cMum = 'A';
    int  q    = 10;
    int  k    = 20;
    cMum      = tolower(cMum);

    // 함수명 자체는 메모리 주소를 의미
    printf("Function %p, %c\n", Function, cMum);

    // 입출력 함수
    char ch;
    fflush(stdin);
    printf("문자입력 (getchar) >> ");

    // getchar : 하나의 문자 입력
    ch = getchar();

    // putchar : 하나의 문자 출력
    printf("입력 받은 문자 : ");
    putchar(ch);
    fflush(stdin);
    printf("\n");

    char str[100];
    int  size = sizeof(str) / sizeof(str[0]);

    // gets : 문자열 입력 받기 (unsafe -> fgets 권장)
    printf("100자 이내의 문자를 입력하세요: ");
    gets(str);

    // puts :  문자열 출력 (unsafe -> fputs 권장)
    printf("입력받은 문자열 출력 (puts): ");
    puts(str);

    for (int i = 0; str[i] != '\0'; i++) { // 빈 배열까지만
        printf("Text %c\n", str[i]);
    }

    // fgets: 문자열 입력 받기
    char chArr[50];
    size = sizeof(chArr) / sizeof(chArr[0]);
    printf("50 자 이내의 문자를 입력: ");
    fgets(chArr, size, stdin);

    // fputs : 입력받은 문자열을 파일로 저장
    const char fileName[] = "function.txt";
    printf("입력받은 문자열 화면출력 및 파일 저장(fputs): ");
    fputs(chArr, stdout);
    FILE *file   = fopen(fileName, "a+");
    int   result = fputs(chArr, file);
    fclose(file);
    printf("파일저장완료 : (%d)", result);

    // fgets : 파일 읽기
    char lines[1000 + 1] = ""; /* initialize all to 0 ('\0') */
    size                 = sizeof(lines);
    FILE *readFile       = fopen(fileName, "r");
    if (readFile == NULL) {
        printf("파일읽기 실패");
        return;
    }
    printf("\n");
    printf("Read File Size %d\n", size);
    while (fgets(lines, size, readFile)) {
        printf("%s\n", lines);
    }

    fclose(readFile);



    // time
    time_t     timer = time(NULL);
    struct tm *t     = localtime(&timer);
    /* struct tm
        int tm_sec      // 초, 0 to 59
        int tm_min      // 분, 0 to 59
        int tm_hour     // 시간, 0 to 23
        int tm_mday     // 일, 1 to 31
        int tm_mon      // 월, 0 to 11
        int tm_year     // 1900년 부터의 년수
        int tm_wday     // 요일, range 일(0) 새 토(6)
        int tm_yday     // 1년 중 경과 일수, range o to 365
        int tm_isdst    // 섬머타임 실시여부 (양수, 0, 음수)
     */

    printf("Now : %d년 %d월 %d일 %d:%d:%d\n",
           t->tm_year + 1900, t->tm_mon + 1,
           t->tm_mday,
           t->tm_hour,
           t->tm_min,
           t->tm_sec);

    /* 재귀함수 ( Recursive Fuction ) */
    // 함수내부에서 함수 자신을 호출하는 함수
    // 조건
    // 재귀함수 안에는 종료 조건이 반드시 있어야 함

    printf("Factorial(3) = %d\n", Factorial(3));
}

int Factorial(int nVar) {

    if (nVar == 0) return 1;
    int factorial = Factorial(nVar - 1) * nVar;
    return factorial;
}
