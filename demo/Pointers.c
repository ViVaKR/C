#include "../headers/vivstd.h"

void Files(bool rw, char *message);
/// @brief
void PointerInt()
{
    // 데이터 자장 영역 : 1 바이트 단위
    // 메모리 주소와 데이터 형을 알면 데이터를 읽거나 저장할 수 있다.

    // fflush(stdin);

    // // 문자형 포인터 예시
    // int var = 10;
    // int *pVar = &var;
    // char str[100];
    // char *string;
    // string = str;
    // scanf("%s", string);

    // // 정수형 포인터 예시
    // printf("ch %s\n", string);
    // int nVar, *pPtr;
    // pPtr = &nVar;
    // scanf("%d", pPtr);
    // printf("nVar %d\n", *pPtr);

    int i = 0, j = 3;

    // && 연산은 둘다 참일 때만 1이므로
    // i != 0 에서 이미 거짓이기 때문에
    // 논리 적으로 절대로 1이 될 수 없으므로
    // 컴파일러는 && 뒤는 처리하지 않고 바로 거짓 0 처리함
    printf(" %d\n", i != 0 && j / i == 1);

    // 같은 맥락으로 || 연산은 둘중 하나만이라도 참이면
    // 참이므로, 역시 컴파일러는 || 뒤로 가지 않고
    // i == 0 이것만 보고 1 처리 하고 마침
    printf(" %d\n", i == 0 || j / i == 1);

    // 정수를 0으로 나누는 것은 어떤 종류의 컴파일러든
    // Eception 처리 하도록 약속이 되어 있습니다.
    // 우리가 + 기호를 보고 왜 더하기를 하느냐고 묻지 않듯
    // 0으로 나누는 것은 묻지도 따지지도 않고 오류 처리 입니다.
}

void Array2DPointer()
{
    /****** Array2DPointer *****/
    int arr[3][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    // 배열의 값을 출력합니다.
    printf("The array elements are:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *((*(arr + i)) + j));
        }
        printf("\n");
    }
}
