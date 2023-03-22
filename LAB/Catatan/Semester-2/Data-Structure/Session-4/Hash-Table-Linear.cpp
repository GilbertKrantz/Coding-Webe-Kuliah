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
} *TABLE[SIZE];

int COUNT = 0;

People *createNode(char name[], int age) {
    People *curr = (People*) malloc(sizeof(People));

    strcpy(curr->name, name);
    curr->age = age;

    return curr;
}

int hash(char name[]) {
    // djb2 hash function : most popular
    return name[0] % SIZE; // Most simple way
}

void insertPeople(People *newPeople) {
    int index = hash(newPeople->name);

    if (COUNT == SIZE)
    {
        puts("Table is Full");
        return;
    }
    
    while (TABLE[index])
    {
        index = (index + 1) % SIZE; // Modulo to loop over index
    }

    TABLE[index] = newPeople;
    COUNT++;
}

int searchData(char target[]) {
    int index = hash(target);
    
    if (TABLE[index] && strcmp(TABLE[index]->name, target) == 0)
    {
        return index;
    }

    int pos = index;
    while (!TABLE[pos] || strcmp(TABLE[pos]->name, target) != 0)
    {
        pos = (pos + 1) % SIZE;

        if (pos == index) return -1;
    }

    return pos;
}

void popData(char target[]) {
    int toDel = searchData(target);
    if (toDel >= 0)
    {
        TABLE[toDel] = NULL;
        free(TABLE[toDel]);
        printf("Target {%s}, Successfuly Deleted\n", target);
    } else puts("Target not Found");
}

void printPeople() {
    for (int i = 0; i < SIZE; i++)
    {
        if (TABLE[i]) printf("%s {%d}\n", TABLE[i]->name, TABLE[i]->age);
        else puts("NULL");
    }
}

int main() {
    insertPeople(createNode("Sola", 19));
    insertPeople(createNode("Elvina", 12));
    insertPeople(createNode("Kaisar", 20));
    insertPeople(createNode("Nando", 23));
    insertPeople(createNode("Jenibelle", 19));

    printPeople();

    printf("%d\n", searchData("Sola"));
    
    popData("Meisa");
    
    popData("Sola");
    
    printPeople();
    //insertPeople(createNode("Jessica", 19)); // Table will be full

    return 0;
}