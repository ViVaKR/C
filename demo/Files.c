#include "../headers/vivstd.h"

void ReadFile();
void WriteFie();

/// @brief File Read OR Write
/// @param rw : true = Read, false = Write
void Files(bool rw, char *message)
{
    if (rw)
        ReadFile();
    else
        WriteFie(message);
}

void ReadFile()
{
    const char fileName[] = logfile;
    char chRead[100];
    FILE *stream = fopen(fileName, "r");
    sprintf(chRead, "%s", stream);
    fgets(chRead, sizeof(chRead), stream);
    fclose(stream);
    printf("%s\n",chRead);
}

void WriteFie(char *message)
{
    const char fileName[] = logfile;
    char chArr[100];
    FILE *stream = fopen(fileName, "a");
    sprintf(chArr, "%s", message);
    int rs = fputs(chArr, stream);
    fclose(stream);
}

void checker(FILE *fp) {
  if (fp == NULL){
    perror("The following error occurred");
    exit(EXIT_FAILURE);
  }
}
