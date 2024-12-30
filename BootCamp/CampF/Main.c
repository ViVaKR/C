#include <stdio.h>
#include <string.h>

/// @brief 학생의 정보를 저장하는 구조체 (학번, 이름, 국어, 영어, 수학, 평균)
struct class
{
    int id;        // 학번
    char name[10]; // 이름
    int kor;       // 국어
    int eng;       // 영어
    int math;      // 수학
    float avg;     // 평균
};

/// @brief 학생의 정보를 출력하는 함수
void PrintStudent(struct class *student)
{
    printf("학번 : %d\n", student->id);
    printf("이름 : %s\n", student->name);
    printf("국어 : %d\n", student->kor);
    printf("영어 : %d\n", student->eng);
    printf("수학 : %d\n", student->math);
    printf("평균 : %.2f\n", student->avg);
}

/// @brief 학생의 등수를 출력하는 함수
void PrintRank(struct class *rank)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d등 : %s, 평균점수 : %.2f\n", i + 1, rank[i].name, rank[i].avg);
    }
}

/// @brief 학생의 평균을 계산하는 함수
void CalculateAvg(struct class *student)
{
    student->avg = (student->kor + student->eng + student->math) / 3.0f;
}

/// @brief 학생의 등수를 계산하는 함수
void CalculateRank(struct class *student)
{
    struct class rank[3] = {student[0], student[1], student[2]};
    struct class temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (rank[i].avg > rank[j].avg)
            {
                temp = rank[i];
                rank[i] = rank[j];
                rank[j] = temp;
            }
        }
    }

    printf("*** 등수 확인 ***\n");
    for (int i = 0; i < 3; i++)
    {
        printf("( %d등 ) %10s,\t평균: %.2f\n", i + 1, rank[i].name, rank[i].avg);
    }
}

/// @brief 학생의 정보를 수정하는 함수
void ModifyStudent(struct class *student, char *name)
{
    printf("%s의 국어 성적을 입력하세요 : ", name);
    scanf_s("%d", &student->kor);

    printf("%s의 영어 성적을 입력하세요 : ", name);
    scanf_s("%d", &student->eng);

    printf("%s의 수학 성적을 입력하세요 : ", name);
    scanf_s("%d", &student->math);
}

/// @brief 엔트리 포인트
/// @return
int main()
{
    // 학생의 정보를 저장하는 구조체 배열 선언
    struct class student[3] = {{"baek", 0, 0, 0, 0}, {"in", 0, 0, 0, 0}, {"eon", 0, 0, 0, 0}};

    // 라인 출력
    char line[50];
    memset(line, '-', sizeof(line) - 1);

    // 학생의 이름을 저장하는 배열
    char *name[3] = {"baek", "in", "eon"};

    // 학생의 성적을 입력하는 부분
    for (int i = 0; i < 3; i++)
    {
        ModifyStudent(&student[i], name[i]);
        printf("%s\n", line);
    }

    printf("성적 입력이 완료되었습니다.\n아래의 정보를 확인하신 후 수정 및 작업 완료하세요.\n%s\n", line);

    // 학생의 평균을 계산하는 부분
    for (int i = 0; i < 3; i++)
        CalculateAvg(&student[i]);

    CalculateRank(student);

    // 학생의 성적을 수정하는 부분
    for (int i = 0; i < 3; i++)
    {
        printf("*** [ %s ] 성적표 ***\n", student[i].name);
        PrintStudent(&student[i]);
        printf("%s\n", line);
        printf("%s 의 성적을 수정하시겠습니까? (1: 예, 0: 아니오) : ", student[i].name);
        int choice;
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            ModifyStudent(&student[i], student[i].name);
            CalculateAvg(&student[i]);
        }
    }

    printf("\n%s\n", line);
    printf("성적 수정이 완료되었습니다. 조정된 등수 확인하세요.\n");
    CalculateRank(student);

    return 0;
}
