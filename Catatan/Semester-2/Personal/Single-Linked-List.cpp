#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    node *next;
} *head = NULL, *tail = NULL;

node *create_node(int n) {
    node *new_node = (node*) malloc(sizeof(node));

    new_node->number = n;
    new_node->next = NULL;

    return new_node;
}

void push_head(node *create_node) {
    node *curr = create_node;

    if (!head)
    {
        head = tail = curr;
        return;
    }

    curr->next = head;
    head = curr;
    return;
}

void push_tail(node *create_node) {
    node *curr = create_node;

    if (!tail)
    {
        head = tail = curr;
        return;
    }

    tail->next = curr;
    tail = curr;
    return;
}

void push_mid(node* create_node) {
    node *temp = create_node;
    node *curr = head;

    if (!head)
    {
        head = tail = temp;
        return;
    }
    
    if (head == tail)
    {
        push_head(create_node);
        return;
    }

    while (curr->next != NULL && curr->next->number < curr->number)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return;
}

void pop_head() {

    if (!head)
    {
        puts("There's No Data\n");
        return;
    }

    node *curr = head;

    if(head == tail) {
        free(curr);
        head = tail = NULL;
        return;
    }
    
    head = curr->next;

    free(curr);
}

void print_all() {
    node *curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->number);
        curr = curr->next;
    }

    puts("\n");
    return;
}

int main()
{
    push_head(create_node(1));
    push_tail(create_node(5));
    push_mid(create_node(4));

    print_all();
    return 0;
}
