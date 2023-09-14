#include "../headers/vivstd.h"

void FileReadWrite()
{
    /****** FileReadWrite *****/
    printf("\n***** File Read Write *****\n");

    FILE *file = fopen("numbers.txt", "r");
    
    if (file == NULL)
    {
        printf("\nCould not locate file\n");
        exit(-1);
    }

    int number;
    int number2;

    // C File IO
    fscanf(file, "%d", &number);

    fclose(file);
    
}
