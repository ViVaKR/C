#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];                          // 프로그램 제목을 저장할 문자열 변수
    printf("프로그램 제목을 입력하세요 : "); // 프로그램 제목을 입력받는 메시지 출력
    fgets(name, 100, stdin);                 // 프로그램 제목을 입력받음
    strtok(name, "\r\n");                    // fgets로 입력받은 문자열의 마지막에 개행문자가 들어가므로 제거
    int len = strlen(name);                  // 입력받은 문자열의 길이
    char *genre;                             // 프로그램의 장르를 저장할 포인터 변수
    // strncmp 함수를 사용하여 입력받은 문자열이 어떤 프로그램인지 판별
    if (strncmp(name, "선재 업고 튀어", len) == 0) genre = "드라마";
    else if (strncmp(name, "눈물의 여왕", len) == 0) genre = "드라마";
    else if (strncmp(name, "나 혼자 산다", len) == 0) genre = "예능";
    else if (strncmp(name, "아는 형님", len) == 0) genre = "예능";
    else if (strncmp(name, "그것이 알고 싶다", len) == 0) genre = "시사 다큐멘터리";
    else if (strncmp(name, "한국인의 밥상", len) == 0) genre = "교양 다큐멘터리";
    else genre = "알 수 없음";

    // 출력
    printf("\033[1;31m\u2620 %s\t\u27A0\t%s\n\033[0m", name, genre);
    return 0;
}
