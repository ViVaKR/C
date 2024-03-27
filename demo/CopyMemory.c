#include "../headers/vivstd.h"

void CopyMemory()
{
    // 단순 대입 연산자는 r-value 의 정보를 l-value 에 복사
    // 이 과정에서 l-value 의 기존 정보는 유실되고 새 정보로 덮어씀
    // 배열은 단순 대입으로 r-value 를 l-value 에 복사할 수 없음
    // memcpy() 함수 : 인수로 전달된 두 주소의 메모리에 담긴 정보를 복사하는 함수
    // 주소복사와 내용복사를 구분하여야 함 (Shallow Copy vs Deep Copy)

    // Deep Copy : 내용을 복사
    // 원본에서 4바이트만 대상 메모리로 복사 예시
    char szBuffer[12] = { "HelloWorld" };
    char szNewBuffer[12];
    memset(szNewBuffer, 3, sizeof(szNewBuffer));
    memcpy(szNewBuffer, szBuffer, 4);
    printf("%p %p\n", szBuffer, szNewBuffer);
    for (int i = 0; i < 12; i++) {
        printf("Text %c\n", szNewBuffer[i]);
    }

    // Shallow Copy : 주소만 복사
    char *pszData = NULL;
    pszData = szBuffer;
    printf("%p %p\n", szBuffer, pszData);

    char *demo = malloc(sizeof(char) * 12);
    printf("demo %p\n", demo);
    memcpy(demo, szBuffer, sizeof(char) * 12);
    printf("demo %s\n", demo);
    free(demo);
}
