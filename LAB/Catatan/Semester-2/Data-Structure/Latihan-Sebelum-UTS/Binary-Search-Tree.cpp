#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node
{
    int value;

    node *left, *right;
} *Root = NULL;


node *createNode(int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *pushNode(node *curr, int value) {
    if (!curr) return createNode(value);
    // if value is smaller than current value then it's on the left
    else if (value < curr->value) curr->left = pushNode(curr->left, value);
    // if value is bigger than current value then it's on the right
    else if (value > curr->value) curr->right = pushNode(curr->right, value);
    
    return curr;
}

node *get_value(node *curr) {
    while (curr && curr->left) curr = curr->left;
    return curr;
}

node *del(node *curr, int value) {
    if (!curr) return curr;
    else if (curr->value > value) curr->left = del(curr->left, value);
    else if (curr->value < value) curr->right = del(curr->right, value);
    else {
        if (!curr->left)
        {
            node *temp = curr->right;
            free(curr);
            return(temp);
        } else if (!curr->right) {
            node *temp = curr->left;
            free(curr);
            return temp;
        } else {
            node *temp = get_value(curr->right);

            curr->value = temp->value;

            curr->right = del(curr->right, temp->value);
        }
    }

    return curr;
}

void in_order(node *curr) {
    if (curr) {
        in_order(curr->left);
        printf("%d -> ", curr->value);
        in_order(curr->right);
    }
}

void pre_order(node *curr) {
    if (curr) {
        printf("%d -> ", curr->value);
        in_order(curr->left);
        in_order(curr->right);
    }
}

void post_order(node *curr) {
    if (curr) {
        in_order(curr->left);
        in_order(curr->right);
        printf("%d -> ", curr->value);
    }
}

int main() {
    Root = pushNode(Root, 5);
    Root = pushNode(Root, 3);
    Root = pushNode(Root, 4);
    Root = pushNode(Root, 2);
    Root = pushNode(Root, 7);
    Root = pushNode(Root, 6);

    Root = del(Root, 5);

    in_order(Root);
    puts(" ");
    pre_order(Root);
    puts(" ");
    post_order(Root);

    return 0;
}