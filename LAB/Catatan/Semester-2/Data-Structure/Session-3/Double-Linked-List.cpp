#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Food
{
    char foodID[10]; // incremental, FD001-FD002-FD003...

    char name[225];
    int price;
    char custID[10]; // Random CU256-CU123-CU999...

    Food *next;
    Food *prev;
} *head = NULL, *tail = NULL;

int foodID = 1;

Food* createNode(char name[], int price) {
    Food *node = (Food*) malloc(sizeof(Food));
    strcpy(node->name, name);
    node->price = price;

    node->next = NULL;
    node->prev = NULL;

    // food ID [Incremental]
    char foodID_temp[10];
    sprintf(foodID_temp, "FD%03d", foodID);
    strcpy(node->foodID, foodID_temp);
    foodID++;

    // cust ID [Random]
    char cusID_temp[10];
    int cusID_num = rand() % 1000; // 1000 from 999 + 1 (upper limit + 1)
    sprintf(cusID_temp, "CU%03d", cusID_num); // CU001-CU999
    strcpy(node->custID, cusID_temp);

    return node;
}

void push_head(Food *node) {
    if (!head)
    {
        head = tail = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;

    head->prev = NULL;
    
    return;
}

void push_tail(Food *node) {
    if (!tail)
    {
        head = tail = node;
        return;
    }
    
    tail->next = node;
    node->prev = tail;
    tail = node;
    
    tail->next = NULL;

    return;
}

void push_mid(Food *node) {
    if (!head)
    {
        head = tail = node;
        return;
    }

    if (strcmp(node->name, head->name) <= 0)
    {
        push_head(node);
        return;
    } else if (strcmp(node->name, tail->name) >= 0)
    {
        push_tail(node);
        return;
    }

    Food *curr = head;

    while (curr && strcmp(node->name, curr->name) >= 0)
    {
        curr = curr->next;
    }
    
    node->prev = curr->prev;
    node->next = curr;

    curr->prev->next = node;
    curr->prev = node;
    return;  
}

void pop_head() {
    if (!head)
    {
        return;
    } else if (head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }
    
    Food *temp = head;
    
    head = head->next;
    free(temp);
    head->prev = NULL;
    return;
}

void pop_tail() {
    if (!tail)
    {
        return;
    } else if (head == tail)
    {
        free(head);
        head = tail = NULL;
        return;
    }
    
    Food *temp = tail;
    
    tail = tail->prev;
    free(temp);
    tail->next = NULL;
    return;
}

void pop(char name[]) {
    if (!head)
    {
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        pop_head();
        return;
    } else if (strcmp(tail->name, name) == 0)
    {
        pop_tail();
        return;
    }

    Food *curr = head;
 
    while (curr && strcmp(curr->name, name) != 0)
    {
        curr = curr->next;
    }

    if (curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        free(curr);
    }
    return;
}

void print_all() {
    Food *curr = head;
    while (curr)
    {
        printf("%s - %s %d %s\n", curr->foodID, curr->name, curr->price, curr->custID);
        curr = curr->next;
    }
    
    return;
}

int main()
{
    srand(time(NULL));

    push_mid(createNode("c", 10000));
    push_mid(createNode("b", 10000));
    push_mid(createNode("d", 10000));
    push_mid(createNode("a", 10000));
    push_mid(createNode("e", 10000));
    pop_head();
    pop_tail();
    pop("c");

    print_all(); 

    return 0;
}
