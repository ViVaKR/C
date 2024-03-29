#include "../headers/vivstd.h"

void TemperatureConvert()
{
    /****** TemperatureConvert *****/
    printf("\n");

    char unit;
    float temp;

    // 대문자 변환
    unit = toupper(unit);

    printf("Is the temperature in (F) or (C)? : ");
    scanf("%c", &unit);

    if (unit == 'C') {
        printf("The temp is cuttently in C\nEnter the temp in Celsius");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("The temp in Farenheit is:  %.1f\n", temp);

    } else if (unit == 'F') {
        printf("The temp is currently in F\nEnter the temp in Farenheit");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("The temp in Celsius is:  %.1f\n", temp);

    } else {
        printf("Is not a valid ni of measurement");
    }
}
