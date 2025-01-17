#include <math.h>
#include <stdio.h>
#include <string.h>
// ANSI 색상 코드 정의
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// HSV 구조체 정의
typedef struct
{
    double h; // 색상 (Hue)
    double s; // 채도 (Saturation)
    double v; // 명도 (Value)
} HSV;

// RGB 구조체 정의
typedef struct
{
    int r; // 빨강 (Red)
    int g; // 초록 (Green)
    int b; // 파랑 (Blue)
} RGB;

// HSV를 RGB로 변환하는 함수 (h: 색상[0-360], s: 채도[0-1], v: 명도[0-1])
RGB HsvToRgb(double h, double s, double v)
{
    double r = 0, g = 0, b = 0;       // 변환된 RGB 값을 저장할 변수

    int i = (int)(h / 60) % 6;        // 색상 영역 결정 (0 ~ 5, 6개 영역으로 분할)
    double f = (h / 60) - i;          // 색상 영역 내의 상대 위치 (0.0 ~ 1.0)
    double p = v * (1 - s);           // 채도가 0일 때의 명도 감소값 (무채색)
    double q = v * (1 - f * s);       // 현재 색상 섹션에서의 보간된 RGB 값 (명도 감소 + 채도 보정)
    double t = v * (1 - (1 - f) * s); // 현재 색상 섹션에서의 보간된 RGB 값 (명도 감소 + 채도 반대 보정)

    /*
        h, s, v 즉 HSV 러 RGB로 변환하기
        (i)
        RGB로 변환된 최종 값을 반환
        Hue(색상)를 60도로 나누어 색상 섹션을 결정
        (f)
        섹션 내의 상대적인 위치로, 해당 섹션 내에서 값이 어떻게 보간되는지 명확히 서술.
        (p, q, t)
        p: 채도가 0일 때 명도만 남는 무채색 계산.
        q: 섹션 내에서 점점 감소하는 보간된 RGB 값.
        t: 섹션 내에서 점점 증가하는 보간된 RGB 값.
     */

    // 색상 영역에 따라 RGB 값 설정
    switch (i) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
            r = v;
            g = p;
            b = q;
            break;
    }

    // RGB 값을 0-255 범위로 변환
    RGB rgb = {(int)round(r * 255), (int)round(g * 255), (int)round(b * 255)};
    return rgb;
}

// 문자열을 중앙에 정렬하여 출력하는 함수
void printCentered(const char *str, int width)
{
    int len = strlen(str);
    int padding = (width - len) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s", str);
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
    if ((width - len) % 2 != 0) {
        putchar(' ');
    }
}

int main()
{
    // 색상 이름 배열
    const char *colorNames[] = {
        "BlACK",
        "WHITE",
        "RED",
        "LIME",
        "BLUE",
        "YELLOW",
        "CYAN",
        "MAGENTA"};

    // ANSI 색상 코드 배열
    const char *colorCodes[] = {
        ANSI_COLOR_BLACK,
        ANSI_COLOR_WHITE,
        ANSI_COLOR_RED,
        ANSI_COLOR_GREEN,
        ANSI_COLOR_BLUE,
        ANSI_COLOR_YELLOW,
        ANSI_COLOR_CYAN,
        ANSI_COLOR_MAGENTA};

    // HSV 값 배열
    HSV hsvValues[] = {
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 1.0, 1.0},
        {120.0, 1.0, 1.0},
        {240.0, 1.0, 1.0},
        {60.0, 1.0, 1.0},
        {180.0, 1.0, 1.0},
        {300.0, 1.0, 1.0},
        {0.0, 0.0, 0.75}};

    // 칼라 테이블 헤더
    char *line = "----------------------------------------------------------------\n";
    printf("%s", line);
    printCentered("Color", 10);
    putchar('\t');
    printCentered("HSV", 20);
    putchar('\t');
    putchar('\t');
    printCentered("RGB", 20);
    putchar('\n');
    printf("%s", line);

    char *arrow = "→"; // 화딸표 문자

    // 각 색상에 대해 HSV와 RGB 값을 출력
    for (int i = 0; i < 8; i++) {
        RGB rgb = HsvToRgb(hsvValues[i].h, hsvValues[i].s, hsvValues[i].v);
        printf("%2d. ", i + 1);
        printCentered(colorNames[i], 10);
        printf(" (%5.1f, %.1f, %.1f) \t%s\t %s(%3d, %3d, %3d)%s\n",
               hsvValues[i].h,
               hsvValues[i].s,
               hsvValues[i].v,
               arrow,
               colorCodes[i],
               rgb.r,
               rgb.g,
               rgb.b,
               ANSI_COLOR_RESET);
    }
    printf("%s", line);
    return 0;
}
