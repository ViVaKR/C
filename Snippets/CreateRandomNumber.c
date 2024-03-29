#include "../headers/vivstd.h"

/// @brief 랜덤넘버 생성기
/// @return
unsigned int MakeNumber()
{
    srand((unsigned int)time(NULL));
    return rand() % (100 + 1 - 1) + 1;
}

/// @brief 랜덤넘버 쓰기 및 읽기 파일명
const char *SavedNumbersFile = "RandomNumberNote.txt";

/// @brief 텍스트 읽기
int ReadText()
{
    char line[1024];
    FILE *stream = fopen(SavedNumbersFile, "r");

    if (stream == NULL) {
        printf("\n파일열기 실패하였습니다.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), stream) != NULL)
        printf("%s", line);
    
    // 성공 0
    return fclose(stream);
}

/// @brief 텍스트 추가
/// @param text
int AppendText(char *text)
{
    FILE *stream = fopen(SavedNumbersFile, "a");

    if (stream == NULL) {
        printf("\n파일열기 실패하였습니다.\n");
        return -1;
    }

    // 변수의 내용을 파일에 저장 (문자열 길이 + 널문자 반환)
    int rs = fprintf(stream, "%s\n", text);
    fflush(stream);
    printf("%d === %d\n", strlen(text), rs);

    // 실제 파일에 기록하는 단계 (성공 = 0) 
    return fclose(stream);
}

/// @brief Start Point
void CreateRandomNumber()
{
    printf("\n***** CreateRandomNumber *****\n");

    char text[1024];

    unsigned int number = MakeNumber();

    double root = sqrt(number);

    // 변수에 저장 (저장한 문자의 갯수 반환)
    int len = sprintf(text, "%d의 제곱근은 %lf입니다.", number, root);
    printf("Sprintf Result %d\n",len);
    int result = AppendText(text);
    printf("-> 파일추가 ( %s )\n", result == -1 ? "실패" : "성공");
    result = ReadText();
    printf("-> 파일읽기 ( %s )\n", result == -1 ? "실패" : "성공");
}
