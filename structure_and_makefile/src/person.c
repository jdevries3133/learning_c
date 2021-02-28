#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person * alloc_person(char name[], Birthday *bd)
{
    Person *person = malloc(
        sizeof(struct PersonTag)
        + sizeof(char [strlen(name)])
    );

    person->birthday = *bd;
    strcpy(person->name, name);

    return person;
}

void print_person(Person *person)
{
    printf("--- PERSON ---\n");
    printf("Name: %s\n", person->name);

    int indent = 1;
    print_birthday(&person->birthday, &indent);
}

void insert_birthday(int year, int month, int day, Birthday *bd)
{
    bd->year = year;
    bd->day = day;
    bd->month = month;
}


void _indent(int num_tabs);
void print_birthday(Birthday *bd, int *indent)
{
    int indents = indent == NULL ? 0 : *indent;

    printf("--- BIRTHDAY ---\n");
    _indent(indents);

    printf("Year: %d\n", bd->year);
    _indent(indents);

    printf("Month: %d\n", bd->month);
    _indent(indents);

    printf("Day: %d\n", bd->day);
}

void _indent(int num_tabs)
{
    if (!num_tabs) return;
    for (int i = 0; i < num_tabs; i++) {
        printf("\t");
    }
}
