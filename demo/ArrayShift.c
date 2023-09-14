

void ShiftArray(int *array, int len, int direction)
{
    int i, temp;
    if (direction == 0) {
        temp = array[0];
        for (i = 0; i < len - 1; i++) {
            array[i] = array[i + 1];
        }
        array[len - 1] = temp;
    }

    // 문의에 대한 답변 파트
    // 오른 쪽 끝에서 부터 하기
    if (direction == 1) {
        temp = array[len - 1];

        for (int i = len - 1; i >= 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = temp;
    }
}

void ArrayShift()
{
    int i;

    int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int len = sizeof(array) / sizeof(int);
    printf("\n");
    printf("*******************************************");
    printf("\n");

    printf("\n*** 원본 ***\n");
    for (i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("\n");
    printf("*******************************************");
    printf("\n");
    // 순 밀기
    printf("\n*** (순) 밀기 한번 데모 ***\n");
    ShiftArray(array, len, 0);
    for (i = 0; i < len; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    printf("*******************************************");
    printf("\n");

    // 역 밀기 10번 데모
    for (int k = 0; k < 10; k++) {
        printf("\n*** %d 번 째 (역) 밀기 ***\n", k + 1);

        ShiftArray(array, len, 1);
        for (i = 0; i < len; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

// 요청사항 //
// 결과 값으로 10 9 8 7 6 54321
// 987654321 10
// 10 987654321
