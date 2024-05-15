#include <Kernel/stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h>
#include <time.h>

typedef struct
{
    char *names[5];
    int *id;   // 동적 메모리의 주소를 저장하는 포인터 (원하는 크기로 설정하기 위함)
    int front; // 삭제위치(배열의 첨자)
    int rear;  // 삽입위치 (배열의 첨자)
    int count; // 저장된 원소의 갯수
    int max;   // 배열의 최대 용량

} Queue;

// (0)
void InitQueue(Queue *queue, int size)
{
    queue->id = (int *)malloc(sizeof(int) * size);
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
    queue->max = size;
    for (int i = 0; i < queue->max; i++) {
        queue->names[i] = (char *)malloc(sizeof(char) * 20);
        printf("%p\n", &queue->names[i]);
    }
}

void Dispose(Queue *queue)
{

    for (int i = 0; i < queue->max; i++) {
        free(queue->names[i]);
    }
    free(queue->id);
}

// (1)
void EnQueue(Queue *queue, int data, const char *name)
{

    if (queue->count == queue->max) {
        printf("용량초과 오버플로우 발생 -> Max Capacity = %d, Current Count = %d\n", queue->max, queue->count);
        return;
    }

    queue->id[queue->rear] = data;
    strcpy(queue->names[queue->rear], name);
    printf("Current rear = %d, index = %d, name = %s", queue->rear, queue->id[queue->rear], queue->names[queue->rear]);
    queue->rear++;
    if (queue->rear == queue->max) queue->rear = 0;
    queue->rear = queue->rear < queue->max ? queue->rear++ : 0;
    queue->count++;
    printf("Data Count (%d)\n", queue->count);
}

char data[100];

// (2) DeQueue
char *DeQueue(Queue *queue)
{

    if (queue->count == 0) {
        // underflow
        printf("저장된 데이터가 없습니다.\n");
        return NULL;
    }

    int id = queue->id[queue->front];
    char *name = queue->names[queue->front];
    memset(data, '\0', 100);
    sprintf(data, "Id: %d, Name: %s", id, name);

    printf("Current front = %d, ", queue->front);
    queue->front++;
    queue->count--;
    if (queue->front == queue->max) queue->front = 0;

    return data;
}

void Print(const Queue *queue)
{
    if (queue->count == 0) {
        printf("\n큐가 비어 있는 상태입니다.\n");
        return;
    }
    for (int i = queue->front; i < queue->front + queue->count; i++) {
        int index = i % queue->max;
        printf("Queue index = %d, Id = %d, Name = %s\n", index, queue->id[index], queue->names[index]);
    }
    printf("\n");
}

int ClearQueue(Queue *queue)
{
    int count = queue->count;
    printf("\nClear Queue Start\n");
    for (int i = 0; i < count; i++) {
        char *data = DeQueue(queue);

        if (data == NULL) {
            printf("데이터가 모두 삭제 되었거나 초기화 되지 않았습니다.\n(underflow) 프로그램을 종료 합니다.\n");
            Dispose(queue);
            return 1;
        }
        printf("Data = %s, Remain Data (%d)\n", data, count);
    }
    // 논리적으로 삭제하는 원래의방식, 원래의배열의 데이터는 그대로 남아 있음.
    queue->count = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue->count;
}

int main(int argc, const char *argv[])
{

    Queue queue; // 구조체 변수.
    int size = 5;

    InitQueue(&queue, size);

    int choice;

    while (true) {

        printf("1. enqueue\t2. dequeue\t3. print\t4. clear\t0. quit\n>> ");
        scanf("%d", &choice);

        while (getchar() != '\n') {};
        switch (choice) {

            case 0: { // Exit Program
                printf("Exit Program ... \n");
                Dispose(&queue);
                exit(0);
            }

            case 1: { // EnQueue
                printf("\nEnQueue Start\n");
                time_t t;
                srand((unsigned)time(&t));
                int max = 99;
                int min = 50;

                int current = queue.count;
                if (current == size) {
                    printf("큐가 가득 찼습니다.\n");
                    return 1;
                }

                char *names[] = {
                    "Kim Bum Jun",
                    "ViVaKR",
                    "Jang Gil San",
                    "Hello, World",
                    "Fine Thanks And You",
                };
                for (int i = 0; i < size - current; i++) {

                    int number = min + rand() % (max - min + 1);
                    EnQueue(&queue, number, names[i]);
                }
            } break;

            case 2: { // DeQueue
                printf("\nDeQueue Start\n");
                char *data = DeQueue(&queue);
                if (data == NULL) {
                    printf("데이터가 모두 삭제 되었거나 초기화 되지 않았습니다.\n(underflow) 프로그램을 종료 합니다.\n");
                    Dispose(&queue);
                    return 1;
                }
                printf("Data = %s, Remain Data (%d)\n", data, queue.count);

            } break;

            case 3: { // Print
                Print(&queue);

            } break;

            case 4: { // Clear Queue
                int count = ClearQueue(&queue);
                printf("큐 삭제 완료 => 남아있는 큐의 수 %d\n", count);

            } break;

            default:
                Dispose(&queue);
                break;
        }
    }
    return 0;
}
