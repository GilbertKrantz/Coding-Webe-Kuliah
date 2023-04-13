#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define SIZE 5

struct People
{
    char name[100];
    int age;
    People *next;
    People *prev;
} *head[SIZE], *tail[SIZE];

People *createNode(char name[], int age) {
    People *curr = (People*) malloc(sizeof(People)); // Malloc is a function to allocate memory

    strcpy(curr->name, name); // strcpy is used to copy name to curr->name
    curr->age = age; // asigning age to curr->age
    curr->next = curr->prev = NULL;

    return curr; // returning the created node
}

int hash(char name[]) {
    // djb2 hash function : most popular
    return name[0] % SIZE; // Most simple way
}

void insertPeople(People *newPeople) {
    int index = hash(newPeople->name);

    if (!head[index]) 
        head[index] = tail[index] = newPeople;
    else {
        tail[index]->next = newPeople;
        newPeople->prev = tail[index];
        tail[index] = newPeople;
    }
    
}

People *searchData(char target[]) {
    int index = hash(target);
    People *curr = head[index];

    while (curr && strcmp(curr->name, target) != 0)
    {
        curr = curr->next;
    }
    
    return curr;
}

void popHead(int index) {
    if (!head[index]) return;
    else if (head[index] == tail[index])
    {
        head[index] = tail[index] = NULL;
        free(head[index]);
        return;
    }
    
    People *toDel = head[index];
    head[index] = toDel->next;
    head[index]->prev = NULL;
    toDel = NULL;
    free(toDel);
}

void popTail(int index) {
    if (!tail[index]) return;
    else if (head[index] == tail[index])
    {
        head[index] = tail[index] = NULL;
        free(tail[index]);
        return;
    }
    
    People *toDel = tail[index];
    tail[index] = toDel->prev;
    tail[index]->next = NULL;
    toDel = NULL;
    free(toDel);
}

void popData(char target[]) {
    People *toDel = searchData(target);
    int index = hash(target);

    if (!toDel) puts("Data Not Found");
    else if (toDel == head[index]) popHead(index);
    else if (toDel == tail[index]) popTail(index);
    else {
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
        toDel = NULL;
        free(toDel);
    }
}

void printPeople() {
    for (int i = 0; i < SIZE; i++)
    {
        People *curr = head[i];

        while (curr)
        {
            printf("%s {%d} -> ", curr->name, curr->age);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insertPeople(createNode("Sola", 19));
    insertPeople(createNode("Elvina", 12));
    insertPeople(createNode("Kaisar", 20));
    insertPeople(createNode("Nando", 23));
    insertPeople(createNode("Jenibelle", 19));
    insertPeople(createNode("Wenibelle", 19));

    printPeople();

    popData("Meisa");

    popData("Sola");

    printPeople();

    return 0;
}