#ifndef PERSON_H
#define PERSON_H

/**
 * I am intentionally using different names for the tag and type name for
 * educational purposes.
 */


// Birthday

typedef struct BirthdayTag {
    int year;
    int month;
    int day;
} Birthday;

void insert_birthday(int year, int month, int day, Birthday *bd);
void print_birthday(Birthday *bd, int *indent);


// Person

typedef struct PersonTag {
    Birthday birthday;
    char name[50];
} Person;

Person * alloc_person(char name[], Birthday *bd);
void print_person(Person *person);

#endif  // PERSON_H
