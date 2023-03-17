#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

float stack[MAX];
int top = -1;

float char_to_float(char a) {
    float value = (float) a - '0';
    return value;
}

void push(float value) {
    if (top == MAX -1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;

    // printf("Top %.2f\n", stack[top]);

    return;
}

float pop() {
    float value = 0;
    
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    value = stack[top];
    top--;
    
    return value;
}

float evalPostfix(char expression[]) {
    int i = 0;
    float x, y, value;

    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            push(char_to_float(expression[i]));
        } else if (ispunct(expression[i]))
        {
            x = pop();
            y = pop();
            switch (expression[i])
            {
            case '+':
                value = x + y;
                break;
            case '-':
                value = y - x;
                break;
            case '*':
                value = x * y;
                break;
            case '/':
                value = y / x;
                break;
            case '%':
                value = (int) x % (int) y;
                break;
            }
            push(value);
        }
        i++;
    }
    return pop();
}

int main()
{
    float result;
    char postExpression[MAX];

    printf("Enter a Postfix Expression : ");
    gets(postExpression);

    result = evalPostfix(postExpression);
    printf("The Evaluated Value of the postfix expression is = %.2f", result);

    return 0;
}

