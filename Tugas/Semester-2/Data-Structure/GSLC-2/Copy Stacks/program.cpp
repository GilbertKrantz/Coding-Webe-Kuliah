#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

typedef struct node
{
    int data;
    node *next;
} stack;

node *createNode(int data) {
    node *ptr = (node*) malloc(sizeof(stack));

    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

int isEmpty(stack *stk) {
    if (!stk)
    {
        return 1;
    }
    
    return 0;
}

stack* push(stack *stk, int data) {

    node *ptr = createNode(data);

    if (isEmpty(stk))
    {
        stk = ptr;
        return stk;
    } 
    
    ptr->next = stk;
    stk = ptr;

    return stk;
}

void display(stack *stk) {
    if (isEmpty(stk))
    {
        puts("Stack is Empty");
    } else {
        node *ptr = stk;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        
        puts("\n");
    }
    
}

stack *pop(stack *stk) {
    if (isEmpty(stk))
    {
        puts("Stack Underflow");
        return stk;
    }
    
    node *temp = stk;
    stk = stk->next;

    temp->next = NULL;
    free(temp);
    
    return(stk);
}

stack *copyStacks(stack *stk1, stack *stk2) {
    stack *temp = NULL;

    while (!isEmpty(stk1)) {
        temp = push(temp, stk1->data);
        stk1 = pop(stk1);
    }

    while (!isEmpty(temp))
    {
        stk2 = push(stk2, temp->data);
        temp = pop(temp);
    }

    return stk2;
}

int main()
{
    stack *stk1 = NULL;

    stk1 = push(stk1, 10);
    stk1 = push(stk1, 20);
    stk1 = push(stk1, 30);

    stk1 = pop(stk1);
    display(stk1);

    stack *stk2 = NULL;
    stk2 = copyStacks(stk1, stk2);

    display(stk2);
    return 0;
}


