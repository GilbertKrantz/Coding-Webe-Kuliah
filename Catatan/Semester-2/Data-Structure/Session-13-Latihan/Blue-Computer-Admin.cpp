#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[225];
    char type[225];
    char level[225];
    int level_int;
    Node *next, *prev;
} *head = NULL, *tail = NULL;

Node *create_node(const char *name, const char *type, const char *level) {
    Node *curr = (Node*) malloc(sizeof(Node));
    strcpy(curr->name, name);
    strcpy(curr->type, type);
    strcpy(curr->level, level);

    if (strcmp(level, "High") == 0) curr->level_int = 1;
    if (strcmp(level, "Medium") == 0) curr->level_int = 2;
    if (strcmp(level, "Low") == 0) curr->level_int = 3;

    curr->next = curr->prev = NULL;

    return curr;
}

void push(Node *curr) {
    if (!head) head = tail = curr;
    else if (head->level_int >= curr->level_int)
    {
        head->prev = curr;
        curr->next = head;
        head = curr;
    }
    else if (tail->level_int <= curr->level_int)
    {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    else {
        Node *temp = head;
        while (curr->level_int > temp->level_int)
        {
            temp = temp->next;
        }
        temp->prev->next = curr;
        temp->prev = curr;
        curr->next = temp;
        
    }
}

void print_all() {
    if (!head) puts("No data");
    else {
        int i = 1;
        Node *curr = head;
        puts("No. Name  Type  Level");
        while (curr)
        {
            printf("%-d. %-s %-s %-s\n", i, curr->name, curr->type, curr->level);
            curr = curr->next;
            i++;
        }
    }
}

void add() {
    char *name = (char*) malloc(225 * sizeof(char));
    char *type = (char*) malloc(225 * sizeof(char));
    char *level = (char*) malloc(225 * sizeof(char));

    do
    {
        printf("Input New Item Name [3-20] : ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 20);
    
    do
    {
        printf("Input Item Type [processor || graphic card || memory] : ");
        scanf("%[^\n]", type); getchar();
    } while (strcmp(type, "processor") != 0 && strcmp(type, "graphic card") != 0 && strcmp(type, "memory") != 0);
    
    do
    {
        printf("Input Item Level [High || Medium || Low] : ");
        scanf("%[^\n]", level); getchar();
    } while (strcmp(level, "High") != 0 && strcmp(level, "Medium") != 0 && strcmp(level, "Low") != 0);
    
    push(create_node(name, type, level));
    free(name);
    free(type);
    free(level);
    puts("--Item Added Succesfully--");
}

void menu() {
    int option;
    do
    {
        puts("1. Item List");
        puts("2. Add New Item");
        puts("3. Exit");
        printf(">> ");
        scanf("%d", &option); getchar();

        switch (option)
        {
        case 1:
            print_all();
            break;
        
        case 2:
            add();
            break;
        }
    } while (option != 3);
    
}

int main() {
    menu();
    return 0;
}