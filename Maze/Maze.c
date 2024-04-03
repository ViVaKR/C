#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[10];
    char major[10];
};

int main()
{
    struct student s;

    s.id = 1;
    strcpy(s.name, "Hello");
    strcpy(s.major, "World");

    struct student s2 = {.id = 1, .name = "Kim", .major = "산적부"};
    strcpy(s2.name, "설악산");

    struct student s3 = {3, "장길산", "호탕부"};

    printf("Welcom Start Maze Game %d, %s, %s\n", s.id, s.name, s.major);
    printf("Welcom Start Maze Game %d, %s, %s\n", s2.id, s2.name, s2.major);
    printf("Welcom Start Maze Game %d, %s, %s\n", s3.id, s3.name, s3.major);

    char buffer[100];
    fgets(buffer, sizeof(buffer) / sizeof(char), stdin);

    printf("%s\n", buffer);

    return 0;
}
