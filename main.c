#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 10

struct hash_node {
    int key;
    char value[100];
    struct hash_node* next;
};

int hash(char* value) {
    int index = 0;
    for (int i = 0; value[i] != '\0'; i++) {
        index += value[i];
    }
    return index % ARR_SIZE;
}

void insert(struct hash_node** hash_table, int key, char* value) {
    int index = hash(value);

    struct hash_node* newNode = malloc(sizeof(*newNode));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if(hash_table[index] == NULL) {
        hash_table[index] = newNode;
        return;
    }
    struct hash_node* cursor = hash_table[index];
    while(cursor->next != NULL) {
        cursor=cursor->next;
    }
    cursor->next = newNode;
}

int main() {
    struct hash_node* hash_table[ARR_SIZE] = {NULL};
    insert(hash_table, 3, "hello");

    return 0;
}