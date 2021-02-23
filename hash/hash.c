#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 100

typedef struct person {
    char name[MAX_NAME];
    int age;
    // ... maybe add more later
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash (char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = hash_value * name[i] % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL) {
        return false;
    }
    hash_table[index] = p;
    return true;
}


bool hash_table_delete(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL) {
        hash_table[index] = NULL;
        return true;
    }
    return false;
}

// find a person in the table by their name
person* hash_table_lookup(char *name) {
    int index = hash(name);
    if (
            hash_table[index] != NULL &&
            strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0
        ) {
        return hash_table[index];
    } else {
        return NULL;
    }

}

int main() {
    init_hash_table();

    person jacob = {.name="Jacob", .age=256};
    person natalie = {.name="Natalie", .age=45};
    person bobbie = {.name="Robert", .age=52};

    hash_table_insert(&jacob);
    hash_table_insert(&natalie);
    hash_table_insert(&bobbie);

    print_table();

    person *tmp = hash_table_lookup("Natalie");

    if (tmp == NULL) {
        printf("Not found");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    bool is_deleted = hash_table_delete(&jacob);
    if (is_deleted) {
        printf("Deletion successful\n");
    } else {
        printf("Deletion failed\n");
    }

    bool was_found = hash_table_lookup("Jacob");
    if (!was_found && is_deleted) {
        printf("Jacob deleted as expected\n");
    } else if (was_found && is_deleted) {
        printf("Error! Jacob deleted, then found anyway!\n");
    } else {
        printf("Jacob was deleted: %d", is_deleted);
        printf("Jacob was found: %d", was_found);

    }
    return 0;
}
