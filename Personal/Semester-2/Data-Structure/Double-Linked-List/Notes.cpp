#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int num;
    node *next;
    node *prev;
} *head = NULL, *tail = NULL;

node* createNode(int num) {
    node *newNode = (node*) malloc(sizeof(node));

    newNode->num = num;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void push_head(node* newNode) {
    if (!head)
    {
        head = tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void push_tail(node* newNode) {
    if (!tail)
    {
        head = tail = newNode;
        return;
    }
    
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return;
}

void pop_head() {
    if (!head)
    {
        puts("No Data!!!\n");
        return;
    }

    if (head == tail)
    {
        head = tail = NULL;
        free(head);
        return;
    }

    node *curr = head;
    head = head->next;
    head->prev = NULL;

    free(curr);
    return;
}

void pop_tail() {
    if (!tail)
    {
        puts("No Data!!!\n");
        return;
    }

    if (head == tail)
    {
        head = tail = NULL;
        free(head);
        return;
    }
    
    node *curr = tail;
    tail = tail->prev;
    tail->next = NULL;

    free(curr);
    return;
}

void pop(int num) {
    if (!head)
    {
        puts("No Data!!!\n");
        return;
    }

    if (num == head->num)
    {
        pop_head();
        return;
    } else if (num == tail->num) {
        pop_tail();
        return;
    }

    node *curr = head;

    while (curr && curr->num != num)
    {
        curr = curr->next;
    }

    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;

    free(curr);
    return;
}

void print_front() {
    node *curr = head;

    while (curr)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
        
    puts("");

    return;
}

void print_back() {
    node *curr = tail;

    while (curr)
    {
        printf("%d ", curr->num);
        curr = curr->prev;
    }
    
    puts("");

    return;
}

int main()
{
    push_head(createNode(10));
    print_front();

    push_head(createNode(15));
    push_head(createNode(20));

    print_back();

    push_tail(createNode(30));
    print_front();

    push_tail(createNode(35));
    push_tail(createNode(30));

    print_back();

    print_front();

    pop_head();
    pop_tail();

    pop(30);
    print_front();
    print_back();
    return 0;
}

