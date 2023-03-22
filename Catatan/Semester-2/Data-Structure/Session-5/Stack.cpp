#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct node
{
    int data;
    char punct;
    node *next;
} *top = NULL;

node *createNode(int value, char punct) {
    node *curr = (node*) malloc(sizeof(node));

    curr->data = value;
    curr->punct = punct;
    curr->next = NULL;

    return curr;
}

void push(int value = 0, char punct = 'a') {
    node *curr = createNode(value, punct);

    if (!top)
    {
        top = curr;
        return;
    }

    curr->next = top;
    top = curr;
    return;
}

void pop() {
    if (!top)
    {
        puts("Stack Underflow");
        return;
    } 

    node *temp = top;
    top = top->next;

    free(temp);
    return;
}

void display() {
    if (!top)
    {
        puts("No Data");
        return;
    }

    node *curr = top;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    puts("\n");
    return;
}

void evalPost(char postExpression[]) {
    int i = 0;
    while(i != (int) strlen(postExpression)) {
        if (isdigit(postExpression[i]))
        {
            push(postExpression[i] - '0');
        } else if (ispunct(postExpression[i]))
        {
            int op1 = top->data;
            pop();
            int op2 = top->data;
            pop();

            switch (postExpression[i])
            {
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '/':
                push(op2 / op1);
                break;
            case '*':
                push(op2 * op1);
                break;
            case '%':
                push(op2 % op1);
                break;
            case '^':
                push((int) pow(op2, op1));
                break;
            }
        }
        i++;
    }
    printf("Result of Postfix Expression : %d\n", top->data);
}

void evalPre(char preExpression[]) {
    int i = (int) strlen(preExpression) + 1;
    while (i >= 0)
    {
        if (isdigit(preExpression[i]))
        {
            push(preExpression[i] - '0');
        } else if (ispunct(preExpression[i]))
        {
            int op1 = top->data;
            pop();
            int op2 = top->data;
            pop();

            switch (preExpression[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '%':
                push(op1 % op2);
                break;
            case '^':
                push((int) pow(op1, op2));
                break;
            }
        }
        i--;
    }
    printf("Result of Prefix Expression: %d\n", top->data);
}

void in_to_post(char inExpression[]) {
    int i = 0;
    int strLength = (int) strlen(inExpression);
    char postString[strLength];
    while (i != strLength)
    {
        if (isdigit(inExpression[i]))
        {
            postString[i] = inExpression[i];
        } else if (ispunct(inExpression[i]))
        {
            if (!top)
            {
                push(0, inExpression[i]);
            }
            
            switch (inExpression[i])
            {
            case '+':
                if (top->punct == '-'|| top->punct == '+')
                {
                    postString[i] = top->punct;
                    pop();
                }
                
                push(0, inExpression[i]);
                break;
            case '-':
                if (top->punct == '-'|| top->punct == '+')
                {
                    postString[i] = top->punct;
                    pop();
                }
                
                push(0, inExpression[i]);
                break;
            case '*':
                if (top->punct == '+' || top->punct == '-' || top->punct == '*' || top->punct == '/')
                {
                    postString[i] = top->punct;
                    pop();
                }
                
                push(0, inExpression[i]);
                break;
            case '/':
                if (top->punct == '+' || top->punct == '-' || top->punct == '*' || top->punct == '/')
                {
                    postString[i] = top->punct;
                    pop();
                }
                
                push(0, inExpression[i]);
                break;
            }
        }
        i++;
    }

    if (i == strLength)
    {
        int j = 0;
        while (top)
        {
            if (!isdigit(postString[j] && !ispunct(postString[j])))
            {
                postString[j] = top->punct;
                pop();
            }
            j++;
        }
        
    }
    
    printf("Result : %s\n", postString);
}

int main()
{
    char postExpression[] = "4 6 5 2 - * 3 / +";
    evalPost(postExpression);

    // char preExpression[] = "+ 2 * / 4 5 ^ ^ - 5 3 5 4";
    char preExpression[] = "+ 7 - * 6 5 ^ 3 2";
    evalPre(preExpression);

    char infix[] = "2+3";
    in_to_post(infix);

    return 0;
}

