#include "hash.h"

int main() {
    struct hash_node* hash_table[ARR_SIZE] = {NULL};
    
    insert(hash_table, 3, "hello");
    insert(hash_table, 5, "world");
    insert(hash_table, 7, "test");
    insert(hash_table, 9, "nope");

    search(hash_table, "hello");  
    search(hash_table, "world");
    
    delete(hash_table, "nope");
    search(hash_table, "nope");
    delete(hash_table, "brave");

    return 0;
}
