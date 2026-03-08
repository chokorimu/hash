#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 10

struct hash_node {
    int key;
    char value[100];
    struct hash_node* next;
};

int hash(char* value);
void insert(struct hash_node** hash_table, int key, char* value);
void search(struct hash_node** hash_table, char* value);
void delete(struct hash_node** hash_table, char* value);

#endif
