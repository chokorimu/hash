#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_node {
    int key;
    char value[100];
    struct hash_node* next;
};

int hash(int key, char value[100]) {
    int index = 0;
    int i = 0;
    while(value[i] != '\0') {
        index = 2*index;
        index += value[i]++;
        i++;
    }
    return index % 10;
}

int insert(struct hash_node hash_table, int key, char value[100]) {
    int index = hash(key, value);
    struct hash_node* newNode = malloc(sizeof(*newNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(hash_table[index] != NULL) {
        hash_table[index] = newNode;
        return;
    }
    struct hash_node* cursor = &(hash_table[index]);
    while(cursor->next != NULL) {
        cursor=cursor->next;
    }
    hash_table[index]->next = newNode;
}

int main() {
    struct hash_node hash_table[10];
    insert(hash_node, 3, "hello");

    return 0;
}