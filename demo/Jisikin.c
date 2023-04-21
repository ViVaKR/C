#include "../headers/vivstd.h"
void Calendar();
void ArrayAvgCaller();
float ArrayAvg(int length, int *array);

void Jisikin()
{
    printf("***** 지식인 답변 ******\n");

    int i = 1;
loop:
    printf("%d + %d = %d\n", 3, i, 3 * i);
    i++;
    if (i == 10) goto end;
    goto loop;
end:

    Calendar();
    return;
}

/// @brief 윤년찾기
void Calendar()
{

    fflush(stdin);
    printf("년도 입력 >> ");
    char xx[5];
    fgets(xx, sizeof xx, stdin);

    fflush(stdin);
    printf("월 입력 >> ");
    char dd[3];
    fgets(dd, sizeof dd, stdin);

    char datetime[12];
    datetime[0] = xx[0];
    datetime[1] = xx[1];
    datetime[2] = xx[2];
    datetime[3] = xx[3];
    datetime[4] = '-';
    datetime[5] = dd[0];
    datetime[6] = dd[1];
    datetime[7] = '-';
    datetime[8] = '0';
    datetime[9] = '1';

    struct tm utm;
    strptime(datetime, "%F", &utm);
    int yyyy = utm.tm_year + 1900;
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int *m = months;

    //--- 그레고리력 기준 ---//
    // 4로 나누어 떨어지는 해를 기준으로...
    // 100으로 나누어 떨어지되 400으로 나누어 떨어지지 않는 해는 평년으로 한다.
    // (엑셀식 =)IF(OR(MOD(A1,400)=0,AND(MOD(A1,4)=0,MOD(A1,100)<>0))

    // 1단계. 연도를 4으로 균등하게 나눌 수 있는 경우 2단계로 이동합니다.그렇지 않으면 5단계로 이동하세요.
    // 2단계. 연도를 100으로 균등하게 나눌 수 있는 경우 3단계로 이동합니다.그렇지 않으면 4단계로 이동하세요.
    // 3단계. 연도를 400으로 균등하게 나눌 수 있는 경우 4단계로 이동합니다.그렇지 않으면 5단계로 이동하세요.
    // 4단계. 해당 연도는 윤년(366일) 입니다.
    // 5단계. 해당 연도는 윤년이 아닙니다(365일)

    bool check = 0;

    // (1단계)
    check = yyyy % 4 == 0;
    if (check) {
        // (2단계)
        check = yyyy % 100 != 0;

        if (!check) {
            // (3단계)
            check = yyyy % 400 == 0;
        }
    }

    // (4단계) => check == true;
    // (5단계) => chekc == false;

    // 가장 어려운 윤년이 아닌해 -> 1900년 체크해보기
    // 윤년 (X) : 1700, 1800, 1900, 2100, 2300, 2500, 2600
    // 유년 (O) : 1600, 2000, 2400


    printf("\n");
    m[1] = check ? 29 : 28;
    char *weekday_str[] = { "일", "월", "화", "수", "목", "금", "토" };

    int wnum = utm.tm_wday;
    char *weekday = weekday_str[wnum];

    printf("%4d년 %2d월 %s 요일\n", utm.tm_year + 1900, utm.tm_mon + 1, weekday);
    for (size_t i = 0; i < 7; i++) printf("%s ", weekday_str[i]);
    printf("\n");

    int i = wnum;
    int j = m[utm.tm_mon];
    int count = 0;
    for (int i = 1 - wnum; i <= j; i++) {
        count++;
        if (i < 1) {
            printf("%2c ", ' ');
        } else {
            printf("%2d ", i);
        }
        if (count % 7 == 0) printf("\n");
    }

    /* struct tm
        int tm_sec      // 초, 0 to 59
        int tm_min      // 분, 0 to 59
        int tm_hour     // 시간, 0 to 23
        int tm_mday     // 일, 1 to 31
        int tm_mon      // 월, 0 to 11
        int tm_year     // 1900년 부터의 년수
        int tm_wday     // 요일, range 일(0) 새 토(6)
        int tm_yday     // 1년 중 경과 일수, range o to 365
        int tm_isdst    // 섬머타임 실시여부 (양수, 0, 음수)
     */
}

/// @brief 배열파라미터 (1/2)
void ArrayAvgCaller()
{
    int scores[5] = { 88, 88, 88, 88, 88 };
    printf("\n평균 = %.2f\n(`scores`)\t -> %p\n", ArrayAvg(5, scores), scores);
}

/// @brief 배열파라미터 (2/2)
/// @param length 배열의 길이
/// @param array 합계를 구할 배열
/// @return 배열 요소들의 합계
float ArrayAvg(int length, int *array)
{
    printf("\n");
    printf("//*** float average 함수 ***//\n");
    printf("(`*arrary`)\tmemory address -> %p\n", array);
    printf("\n");
    
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / (float)length;
}
