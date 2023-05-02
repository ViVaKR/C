#include "../headers/vivstd.h"

/// @brief 전체 소스코드 프린트
void PrintCurrentFile()
{
    /****** Print Source Code *****/
    FILE *fp = NULL;
    int ch = 0;
    fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("\nError in opening the file\n");
        exit(1);
    }
    // (Read)
    do {
        ch = fgetc(fp);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(fp);
    exit(EXIT_SUCCESS);
}

/// @brief 소스코드 프린트
/// @param source __FILE__
/// @param from 시작라인 번호 - 1
/// @param to 끝 라인 번호
void PrintCurrentFileLineByLine(char *source, size_t from, size_t to)
{
    printf("\n***** ( %s ) *****\n- From:\t%d\n- To:\t%d\n\n", source, from, to);
    
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // fp = fopen(__FILE__, "r");
    fp = fopen(source, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
        
    size_t count = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if(count++ < from) continue;
        if(count > to) break;
        // printf("%zu: ", read);
        printf("%zu:%s", count, line);
    }

    fclose(fp);
    if (line)
        free(line);
    
    printf("\n*************** End Of Line ***************\n");
    exit(EXIT_SUCCESS);
}
