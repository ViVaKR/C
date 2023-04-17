#include "headers/main.h"

int main() {
    int choice;
    do {
        printf("\n");
        printf("********************************\n");
        printf("*** 실행할 메뉴를 선택하세요 ***\n");
        printf("********************************\n");
        printf("\n");
        printf("1. Printf\n");
        printf("2. Variable\n");
        printf("3. DataType\n");
        printf("4. ArithmeticOperators\n");
        printf("5. Scanf\n");
        printf("6. Math\n");
        printf("7. Operator\n");
        printf("20. Pointer (Integer)\n");
        printf("100. 종료 (Exit)\n");
        //-------------------------------------------//
        fflush(stdin);        // Clear Buffer
        printf(">>> ");       // 프롬프트 (Prompt)
        scanf("%d", &choice); // 입력받기 (User Input by int)
        system("clear");
        switch (choice) {
            case 1: Printf(); break;
            case 2: Variable(); break;
            case 3: DataType(); break;
            case 4: ArithmeticOperators(); break;
            case 5: Scanf(); break;
            case 6: Math(); break;
            case 7: Operator(); break;
            case 20: PointerInt(); break;
            case 100: {
                printf("***** 종료 *****\n");
                printf("\n");
                return 0;
            };
        }
    } while (choice != 100);
    system("clear");
    return 0;
}
