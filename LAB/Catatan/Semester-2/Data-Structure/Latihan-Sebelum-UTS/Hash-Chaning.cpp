#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 5

// Creating a Hash Table with the Hashkey being the string and the value being the integer

struct People {
    char name[20];
    int age;
    People *next, *prev;
} *head[SIZE], *tail[SIZE];

// Creating a Hash Function

int hash(char *name) {
    int sum = 0;
    for (int i = 0; i < strlen(name); i++) {
        sum += name[i];
    }
    return sum % SIZE;
}

// Function to create a new node

People *createNode(char *name, int age) {
    People *newNode = (People *) malloc(sizeof(People));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node from the front/head

void pushHead(char *name, int age) {
    People *temp = createNode(name, age);
    int idx = hash(name);

    if (!head[idx]) {
        head[idx] = tail[idx] = temp;
    } else {
        temp->next = head[idx];
        head[idx]->prev = temp;
        head[idx] = temp;
    }
}

// Function to insert a new node from the back/tail

void pushTail(char *name, int age) {
    People *temp = createNode(name, age);
    int idx = hash(name);

    if (!head[idx]) {
        head[idx] = tail[idx] = temp;
    } else {
        temp->prev = tail[idx];
        tail[idx]->next = temp;
        tail[idx] = temp;
    }
}

// Function to insert a new node based on the given name

void push(char *name, int age) {
    int idx = hash(name);
    People *curr = head[idx];

    while (curr)
    {
        if (strcmp(curr->name, name) <= 0)
        {
            curr = curr->next;
        } else break;
    }
    
    if (curr == head[idx]) pushHead(name, age);
    else if (!curr) pushTail(name, age);
    else {
        People *temp = createNode(name, age);
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
    }
}

// Function to remove a node from the front/head

void popHead(int idx) {
    if (!head[idx]) {
        return;
    } else if (head[idx] == tail[idx]) {
        free(head[idx]);
        head[idx] = tail[idx] = NULL;
    } else {
        People *temp = head[idx];
        head[idx] = head[idx]->next;
        head[idx]->prev = NULL;
        free(temp);
    }
}

// Function to remove a node from the back/tail

void popTail(int idx) {
    if (!head[idx]) {
        return;
    } else if (head[idx] == tail[idx]) {
        free(head[idx]);
        head[idx] = tail[idx] = NULL;
    } else {
        People *temp = tail[idx];
        tail[idx] = tail[idx]->prev;
        tail[idx]->next = NULL;
        free(temp);
    }
}

// Function to remove a node based on the given name

void pop(char *name) {
    int idx = hash(name);
    People *curr = head[idx];

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            if (curr == head[idx]) {
                popHead(idx);
            } else if (curr == tail[idx]) {
                popTail(idx);
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            break;
        }
        curr = curr->next;
    }

    if (!curr)
    {
        puts("Data not found!");
    }
}

// Function to print all value in hash table

void print() {
    for (int i = 0; i < SIZE; i++) {
        People *curr = head[i];
        printf("%d: ", i);
        while (curr) {
            printf("%s %d -> ", curr->name, curr->age);
            curr = curr->next;
        }
        puts("NULL");
    }
}

int main() {
    push("Budi", 20);
    push("Andi", 21);
    push("Caca", 22);
    push("Dedi", 23);
    push("Euis", 24);
    push("Fafa", 25);
    push("Gaga", 26);
    push("Haha", 27);
    push("Icha", 28);
    push("Jaja", 29);
    push("Kaka", 30);
    push("Lala", 31);

    pop("Andi");

    print();

    return 0;
}