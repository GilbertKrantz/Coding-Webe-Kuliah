#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int num;
    node *next;
} *head = NULL, *tail = NULL;

node* createNode(int num) {
    node *temp = (node*) malloc(sizeof(node));

    temp->num = num;
    temp->next = NULL;

    return temp;
}

void push_head(int num) {
    node *curr = createNode(num);

    if (!head)
    {
        head = tail = curr;
    } else {
        curr->next = head;
        head = curr;}

    return;
}

void push_tail(int num) {
    node *curr = createNode(num);

    if (!tail)
    {
        head = tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }
    
    return;
} 

void push_mid(int num) {
    // Create node for the new data
    node *newData = createNode(num);

    // Basic if there's no head
    if (!head)
    {
        head = tail = newData;
        return;
    } 

    // Reference Current to head
    node *curr = head;

    // If newData is smaller than head or bigger than tail
    if (head->num > newData->num)
    {
        push_head(num);
    } else if (tail->num < newData->num)
    {
        push_tail(num);
    }
    
    // Iterate to search for mid position
    while (curr != NULL && curr->next->num < newData->num)
    {
        curr = curr->next;
    }

    newData->next = curr->next;
    curr->next = newData;

    return;
}

void pop_head() {

    if (!head)
    {
        puts("No Data!!\n");
        return;
    } else if (head == tail)
    {
        head = tail = NULL;
        free(head);
        return;
    }
    
    

    node *curr = head;

    head = curr->next;

    free(curr);
    return;
}

void pop_tail() {
    if (!tail)
    {
        puts("No Data!!\n");
        return;
    } else if (head == tail)
    {
        head = tail = NULL;
        free(head);
        return;
    }

    node *curr = tail;
    node *temp = head;

    while (temp->next != curr)
    {
        temp = temp->next;
    }

    tail = temp;
    
    free(curr);
    tail->next = NULL;
    return;
}

node* search(int num) {
    if (!head)
    {
        puts("No Data");
        return NULL;
    }
    node *curr = head;
    node *temp = curr;
    while (curr != NULL && curr->num != num)
    {    
        temp = curr;
        curr = curr->next;
    }

    return temp;
    
}

void pop(int num) {
    if (!head)
    {
        puts("No Data!!\n");
        return;
    } else if (head == tail && head->num == num)
    {
        head = tail = NULL;
        free(head);
        return;
    }

    if (head->num == num)
    {
        pop_head();
        return;
    } else if (tail->num == num)
    {
        pop_tail();
        return;
    }

    node *curr = search(num);

    if (curr)
    {
        node *toDel = curr->next;
        curr->next = toDel->next;
        free(toDel);
    }
    
    return;
}

void print_all() {

    if (!head)
    {
        puts("No Data Found!!\n");
        return;
    }
    
    node *curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }

    puts("\n");
    return;
}

int main()
{
    push_head(10);
    push_head(5);
    push_head(70);

    print_all();

    push_tail(100);
    push_tail(500);

    pop_head();
    pop_tail();
    
    print_all();

    push_mid(7);
    push_mid(9);

    pop(10);
    pop(5);

    node *searching = search(20);
    if (searching)
    {
        printf("Data Found on: %d\n", searching);
    } else {
        puts("Data Not Found\n");
    }
    

    print_all();
    return 0;
}
