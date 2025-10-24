#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
};

Node* hashTable[TABLE_SIZE];

unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    while(*key) {
        // 아스키 코드 변환
        hashValue += *key++;
    }
    return hashValue % TABLE_SIZE;
}

Node* createNode(const char* key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(const char* key, int value) {
    unsigned int index = hash(key);
    Node* newNode = createNode(key, value);

    if(hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    printf("[INSERT] (%s, %d) -> index %d\n", key, value, index);
}

int search(const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];

    while(current) {
        if(strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

void display() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);
        Node* current = hashTable[i];
        while(current) {
            printf("(%s, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert("Alice", 100);
    insert("Bob", 200);
    insert("Charlie", 300);
    insert("Eve", 400);
    insert("Mallory", 500);

    printf("\n=== 해시 테이블 상태 ===\n");
    display();

    printf("\n[SEARCH] Bob -> %d\n", search("Bob"));
    printf("[SEARCH] Mallory -> %d\n", search("Mallory"));
    return 0;
}
