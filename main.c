#include "headers/main.h"

int main() {
    int choice;
    do {
        PrintMenu();
        //-------------------------------------------//
        fflush(stdin);        // Clear Buffer
        printf(">>> ");       // 프롬프트 (Prompt)
        scanf("%d", &choice); // 입력받기 (User Input by int)
        system("clear");
        Exec(choice);
    } while (choice != 100);
    system("clear");
    // return 0;
    exit(EXIT_SUCCESS);
}

void PrintMenu() {
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
    printf("8. For Loop\n");
    printf("9. While Loop\n");
    printf("10. Do While Loop\n");
    printf("11. Jisikin\n");
    printf("12. Function\n");
    printf("20. Pointer (Integer)\n");
    printf("100. 종료 (Exit)\n");
}

void Exec(int choice) {
    switch (choice) {
        case 1: Printf(); break;
        case 2: Variable(); break;
        case 3: DataType(); break;
        case 4: ArithmeticOperators(); break;
        case 5: Scanf(); break;
        case 6: Math(); break;
        case 7: Operator(); break;
        case 8: ForLoop(); break;
        case 9: WhileLoop(); break;
        case 10: DoWhileLoop(); break;
        case 11: Jisikin(); break;
        case 12: Function(); break;
        case 20: PointerInt(); break;
        case 100:; break;
    }
}
