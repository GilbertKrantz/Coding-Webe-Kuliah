#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    int x;
    tree *left, *right;
} *root = NULL;

tree *insert(tree *curr, int new_value) {
    if (!curr)
    {
        curr = (tree*) malloc(sizeof(tree));
        curr->x = new_value;
        curr->left = NULL;
        curr->right = NULL;
    }
    else if (new_value < curr->x) curr->left = insert(curr->left, new_value);
    else curr->right = insert(curr->right, new_value);

    return curr;
}

int main() {
    root = insert(root, 50);

    return 0;
}
