#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int value;
    struct Node *next;
} Node;

typedef struct hashTable
{
    Node **head;
    int size;

} HashTable;

int HashFunction(int key, int size)
{
    return key % size; // 해시 테이블의 인덱스 값. hash value;
}

/// @brief 해시 테이블 초기화.
/// @param htb
/// @param size
void HashTableInit(HashTable *htb, const int size)
{
    // calloc : 할당후 0으로 셋팅함. 2개의 인수 (갯수, 개당 크기)
    htb->head = (Node **)calloc(size, sizeof(int));
    htb->size = size;
}

/// @brief Add Hash Table
/// @param htb
/// @param size
void AddHash(HashTable *htb, int key)
{
    const int hashIndex = HashFunction(key, htb->size);
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = key;
    new->next = NULL;
    if (htb->head[hashIndex] == NULL) {
        htb->head[hashIndex] = new;
        return;
    }
    new->next = htb->head[hashIndex];
    htb->head[hashIndex] = new;
}

int HashFind(HashTable *htb, int target)
{
    int findIndex = HashFunction(target, htb->size);

    Node *current;
    current = htb->head[findIndex];

    while (current) {

        if (current->value == target) {
            printf("Key: (%d),  Value: (%d), Address: (%p)\n", findIndex, current->value, current->next);
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/// @brief Entry Point 해시 테이블, O(1)
/// @param argc
/// @param argv
/// @return
int main(int argc, const char *argv[])
{
    // 해시 테이블의 사이즈 (prime number, 중복되는 값이 작아지는 효과)
    const int size = 7;
    printf("Hash Table Start\n");
    HashTable htb;
    HashTableInit(&htb, size);

    int keys[] = {79,
                  49, 7, 35,
                  24,
                  28,
                  16, 2, 51,
                  20, 65, 58};
    for (int i = 0; i < sizeof(keys) / sizeof(int); i++) {
        AddHash(&htb, keys[i]);
    }

    int key = 16;
    if (HashFind(&htb, 16)) {
        printf("검색완료하였습니다.\n");
    } else {
        printf("키 %d 에 해당한는 값이 존재하지 않습니다.\n", key);
    }

    return 0;
}
/*

--> 해싱    (hashing)               : 데이터를 가급적 고유한 수의 값으로 표현하는 작업
--> 해시함수 (hashing function)      : 데이터로 부터 고유한 수의 값을 계산하는 함수.

* key value -> 해시함수 (키값 + 해시테이블의 사이즈, 연산 후) -> hash value.
* 버킷 : 방.
* 충돌 발생 가능성 (collision)
    -> e.g. 만약 mod 연산을 통한 해시함수일 경우 92라는 원소와 36이라는 원소를 해시 테이블 사이즈 7로 나눌 경우 동일한 값 1이 나오는 문제 방생.

* 체이닝 (chaining)
    -> 충돌 문제 해결방법 중 하나.
    -> 같은 해시값을 갖는 요소를 연결 리스트로 관리하는 방법
    -> 부하유 (load factor) = 전체 키 갯수 / 해시 테이블의 크기
    -> 부하율은 해시 함수가 키를 균일하게 분해하는지를 알수 있음.
    -> 부하율이 1보다 작으면 리스트의 노드가 비어 있는 경우로 메모리가 낭비될 수 있다.
    -> 부하율이 해시 테이블의 성능의 결정하는 유일한 지표는 될 수 없다. 1 : 1 매칭에 대한 보장이 없음 즉, 같은 방에 모두 연결된 경우.
    -> 재해싱 (rehashing) : 해시 함수를 수정하여 부하율이 1에 가까운 값이 되도록함.
    -> 예를 들어 7개의 해시테이블 구성시 7개의 node pointer 구성.

* 오픈 주소법 (open addressing)
    -> 빈 버킷을 찾을 때 까지 해싱을 반복하는 방법 (rehashing)
        + 충돌 -> 키 값에 1을 더한 값으로 재 해싱.
    -> 해시 테이블의 크기가 반드시 키 값의 크기보다 커야 함.
    -> 선형 탐사법(liner probing) : 충돌 발생시 다음 버킷이 비어 있는지 확인한 후, 비어 있다면 다음 버킷으로 상입하는 방법.

- 데이터의 범위가 큰 경우.
- 데이터가 정수가 아닌 경우
- 데이터 타입에 상관없이 원하는 범위의 정수로 매핑하는 함수를 만듦, (ex) `hello` 와 어떤 고유한 수로 매칭. `3.14` 를 어떤 고유한 정수로 매핑
 */
