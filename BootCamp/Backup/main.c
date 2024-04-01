#include "../Headers/main.h"

int main(int argc, char *argv[])
{
    printf("\n***** Main *****\n");

    if (argc > 0) {// 전달받은 인수 확인
        for (int i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
        }
    }

    // 로그 & 파일처리
    time_t rawtime;
    time(&rawtime);
    struct tm *info;
    info = localtime(&rawtime);
    char str[100];
    sprintf(str, "%s", asctime(info));
    Files(FALSE, str);
    Files(TRUE, NULL);

    // 메뉴선택
    printf("\n***** Press Enter To Start *****\n");
    long choice;
    char *p;
    if (argc > 1) {
        choice = strtol(argv[1], &p, 10);
        Exec(choice);
    } else {
        do {
            system("read");
            PrintMenu();
            fflush(stdin);// Clear Buffer
            printf("(번호) >>> ");// 프롬프트 (Prompt)
            scanf("%ld", &choice);// 입력받기 (User Input by int)
            Exec(choice);
        } while (choice != 100);
    }

    return 0;
}

void PrintMenu()
{
    printf("\n");
    printf("************************************\n");
    printf("***** 실행할 메뉴를 선택하세요 *****\n");
    printf("************************************\n");
    printf("\n");
    printf("(%03d) 재시작 (ReStart)\n", 0);
    printf("(%03d) Printf\t\t", 1);
    printf("(%03d) Variable\t\t", 2);
    printf("(%03d) DataType\n", 3);
    printf("(%03d) Operators\t\t", 4);
    printf("(%03d) Scanf\t\t", 5);
    printf("(%03d) Math\n", 6);
    printf("(%03d) Operator\t\t", 7);
    printf("(%03d) ForLoop\t\t", 8);
    printf("(%03d) WhileLoop\n", 9);
    printf("(%03d) DoWhile\t\t", 10);
    printf("(%03d) Jisikin\t\t", 11);
    printf("(%03d) Function\n", 12);
    printf("(%03d) Array\t\t", 13);
    printf("(%03d) Array2D\t\t", 14);
    printf("(%03d) RecursA\n", 15);
    printf("(%03d) DataStruct\t\t", 16);
    printf("(%03d) ArrayPtrA\t\t", 17);
    printf("(%03d) CopyMemory\n", 18);
    printf("(%03d) Memset\t\t", 19);
    printf("(%03d) Pointers\t\t", 20);
    printf("(%03d) ArrayPtrB\n", 21);
    printf("(%03d) CharPtr\t\t", 22);
    printf("(%03d) ArrayShift\t", 23);
    printf("(%03d) StructB\n", 24);
    printf("(%03d) Fibo\t\t", 25);
    printf("(%03d) Numbers\t\t", 26);
    printf("(%03d) FileRW\n", 27);
    printf("(%03d) RecursB\t\t", 28);
    printf("(%03d) StrConcat\t\t", 29);
    printf("(%03d) ByValue\n", 30);
    printf("(%03d) ByPtr\t\t", 31);
    printf("(%03d) ArrayB\t\t", 32);
    printf("(%03d) UnionStruct\n", 33);
    printf("(%03d) DefineTypedef\t", 34);
    printf("(%03d) LinkedList\t", 35);
    printf("(%03d) PrimeNumber\n", 36);
    printf("(%03d) Ascii\t\t", 37);
    printf("(%03d) Shape\t\t", 38);
    printf("(%03d) CallbackEx\n", 39);
    printf("(%03d) HanoiTower\n", 40);
    printf("(%03d) CreateRandomNumber\n", 41);
    printf("(%03d) Database\n", 50);
    printf("(%03d) BST\t\t", 60);
    printf("(%03d) Calculate\t\t", 61);
    printf("(%03d) Advenced\n", 62);
    printf("(%03d) Bits\n", 63);
    printf("(%03d) 종료 (Exit)\n", 100);
}

void Exec(int choice)
{
    switch (choice) {
        case 0: {
            execl("/bin/sh", "sh", "/Users/vivabm/GitProjects/C/run.sh", (char *)NULL);

            // exit(42);
        } break;
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
        case 13: Array(); break;
        case 14: Array2D(); break;
        case 15: Recursion(); break;
        case 16: DataStruct(); break;
        case 17: ArrayPointer(); break;
        case 18: CopyMemory(); break;
        case 19: MallocMemset(); break;
        case 20: Pointers(); break;
        case 21: PointerArray(); break;
        case 22: CharArrayPointer(); break;
        case 23: ArrayShift(); break;
        case 24: StructA(); break;
        case 25: FiboStart(); break;
        case 26: NumberReal(); break;
        case 27: FileReadWrite(); break;
        case 28: RecursiveForLoop(); break;
        case 29: StringConcat(); break;
        case 30: CallByValue(); break;
        case 31: CallByPointer(); break;
        case 32: ArrayB(); break;
        case 33: UnionAndStruct(); break;
        case 34: DefineTypedef(); break;
        case 35: LinkedList(); break;
        case 36: PrimeNumber(); break;
        case 37: Ascii(); break;
        case 38: Shape(); break;
        case 39: CallbackEx(); break;
        case 40: HanoiTower(); break;
        case 41: CreateRandomNumber(); break;

        case 50: Database(); break;
        case 60: BinarySearchTree(); break;

        case 61: Calculate(); break;
        case 62: Advenced(); break;
        case 63: Bits(); break;//  비트연산

        case 100: break;
    }

    printf("\n\n==> ( Press Enter View Menus ) <==\n");
}

/* Print Source Code */
//--> (전체) PrintCurrentFile();
//--> (라인) PrintCurrentFileLineByLine(__FILE__, 47, 58);
