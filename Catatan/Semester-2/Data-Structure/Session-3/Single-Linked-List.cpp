#include <stdio.h>
#include <stdlib.h>

// Declare node Struct
struct node
{
    int num;
    node *next;
} *head = NULL, *tail = NULL;

void push_head(int num) {
    // Declare Current node
    node *curr = (node*) malloc(sizeof(node));

    // Store the data to Current
    curr->num = num;

    // Set next of Current to NULL
    curr->next = NULL;

    // Check if theres's data
    if (head == NULL)
    {   
        // If there's no data then set head and tail as current
        head = tail = curr;
    } else {
        // If there's data then set current next to head and set head to current
        curr->next = head;
        head = curr;
    }


    return;
    
}

void push_tail(int num) {
    node *curr = (node*) malloc(sizeof(node));

    curr->num = num;
    curr->next = NULL;

    if (tail == NULL)
    {
        head = tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }

    return;
    
}

void pop_head() {
    node *curr = (node*) malloc(sizeof(node));

    if (head == NULL)
    {
        printf("No Data to Pop\n");
        return;
    }

    // Set Current As Head
    curr = head;

    // If there's only 1 node
    if (head == tail)
    {
        head = tail = NULL;
    } else {
        // Set Head to next node
        head = head->next;
    }

    // Destroy Current Node
    free(curr);
}

void pop_tail() {
    node *curr = (node*) malloc(sizeof(node));

    if (tail == NULL)
    {
        printf("No Data to Pop\n");
        return;
    }

    // Set Current as Tail
    curr = tail;

    // If there's only 1 node
    if (head == tail)
    {
        head = tail = NULL;
    } else {
        // Set Tail as Head to reset position
        tail = head;

        // Iterate ver all node to the last not deleted node
        while (tail->next != curr) {
            tail = tail->next;
        }
    }

    // Destroy Current Data
    free(curr);

    // Set tail next to NULL (to Avoid Error)
    tail->next = NULL;
}

void pop(int num) {
    node *curr = (node*) malloc(sizeof(node));
    node *temp = (node*) malloc(sizeof(node));

    // Delete if its in the head or tail
    if (head->num == num)
    {
        pop_head();
        return;
    } else if (tail->num == num) {
        pop_tail();
        return;
    }

    // Point current to head
    curr = head;

    // Searching for data until NULL
    while (curr != NULL && curr->num != num)
    {
        temp = curr;
        curr = curr->next;
    }

    // if data not found then return Function
    if (curr == NULL)
    {
        printf("Data Not Found!!\n");
        return;
    }
    
    // Point Temp to front of current
    temp->next = curr->next;
    
    // Free Current
    free(curr);

    return;
}

void print_all() {
    node *curr = (node*) malloc(sizeof(node));  

    curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }

    printf("\n");

    return;
}


int main()
{
    push_head(50);
    push_head(25);
    push_head(10);

    push_tail(100);

    print_all();

    pop(19);

    print_all();

    return 0;
}
