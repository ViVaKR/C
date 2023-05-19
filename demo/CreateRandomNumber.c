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

    int rs = fprintf(stream, "%s\n", text);
    return fclose(stream);
}

/// @brief Start Point
void CreateRandomNumber()
{
    printf("\n***** CreateRandomNumber *****\n");
    char text[1024];
    unsigned int number = MakeNumber();
    double root = sqrt(number);
    sprintf(text, "%d의 제곱근은 %lf입니다.", number, root);
    int result = AppendText(text);
    printf("-> 파일추가 ( %s )\n",result == -1 ? "실패" : "성공");
    result = ReadText();
    printf("-> 파일읽기 ( %s )\n",result == -1 ? "실패" : "성공");
}
