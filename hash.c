#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

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
        cursor = cursor->next;
    }
    cursor->next = newNode;
}

void search(struct hash_node** hash_table, char* value) {
    int index = hash(value);
    
    struct hash_node* cursor = hash_table[index];
    
    if(cursor == NULL) {
        printf("'%s' tidak ditemukan\n", value);
        return;
    }
    
    while(cursor != NULL) {
        if(strcmp(cursor->value, value) == 0) {
            printf("Ditemukan! Key: %d, Value: %s\n", cursor->key, cursor->value);
            return;
        }
        cursor = cursor->next;
    }
    
    printf("'%s' tidak ditemukan\n", value);
}

void delete(struct hash_node** hash_table, char* value) {
    int index = hash(value);

    struct hash_node* cursor = hash_table[index];
    struct hash_node* prev = NULL;

    while(cursor != NULL) {
        if(strcmp(cursor->value, value) == 0) {
            if(prev == NULL) {
                hash_table[index] = cursor->next;
            } else {
                prev->next = cursor->next;
            }
            free(cursor);
            printf("'%s' berhasil dihapus\n", value);
            return;
        }
        prev = cursor;
        cursor = cursor->next;
    }
    printf("'%s' tidak ditemukan\n", value);
}