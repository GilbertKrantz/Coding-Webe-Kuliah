#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct Node
{
    int value;
    char name[225];

    // Declare pointer for right and left leaves
    Node *left;
    Node *right;
} *root = NULL;

Node *createNode(int value, char name[]) {
    Node *node = (Node*) malloc(sizeof(Node));

    node->value = value;
    strcpy(node->name, name);

    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *pushNode(Node *curr, int value, char name[]) {
    if (!curr) return createNode(value, name);
    // if value is smaller than current value then it's on the left
    else if (value < curr->value) curr->left = pushNode(curr->left, value, name);
    // if value is bigger than current value then it's on the right
    else if (value > curr->value) curr->right = pushNode(curr->right, value, name);
    
    return curr;
}

Node *update_name(Node *curr, int key, char name[]) {
    if (!curr) return curr;
    else if (key < curr->value) curr->left = update_name(curr->left, key, name);
    else if (key > curr->value) curr->right = update_name(curr->right, key, name);
    else {
        strcpy(curr->name, name);
        return curr;
    }
    
    return curr;
} 

Node *get_newValue(Node *curr) {
    while (curr && curr->left) curr = curr->left;
    return curr;
}

Node *delete_node(Node *curr, int key) {
    if (!curr) return curr;
    else if (key < curr->value) curr->left = delete_node(curr->left, key);
    else if (key > curr->value) curr->right = delete_node(curr->right, key);
    else 
    {
        if (!curr->left)
        {
            Node *temp = curr->right;
            free(curr);
            return temp;
        } else if (!curr->right)
        {
            Node *temp = curr->left;
            free(curr);
            return temp;
        } else
        {
            Node *temp = get_newValue(curr->right);

            curr->value = temp->value;
            strcpy(curr->name, temp->name);

            curr->right = delete_node(curr->right, temp->value);
        }
    }

    return curr;
}

//------------------------------------------------------------------------//
// There's 3 type of Print (inOrder, postOrder, preOrder)

// inOrder
// Steps : visit left most node, print the node, visit right node.
void in_order(Node *curr) {
    if (curr)
    {
        in_order(curr->left);
        printf("%d - %s\n", curr->value, curr->name);
        in_order(curr->right);
    }

}

// postOrder
// Steps : Visit left node, visit right node, print the node
void post_order(Node *curr) {
    if (curr)
    {
        post_order(curr->left);
        post_order(curr->right);
        printf("%d - %s\n", curr->value, curr->name);
    }

}

// preOrder
// Steps : Print the node, visit left, visit right
void pre_order(Node *curr) {
    if (curr)
    {
        printf("%d - %s\n", curr->value, curr->name);
        pre_order(curr->left);
        pre_order(curr->right);
    }
    
}
//------------------------------------------------------------------------//

int main()
{
    root = pushNode(root, 5, "A");
    root = pushNode(root, 3, "B");
    root = pushNode(root, 4, "C");
    root = pushNode(root, 2, "D");
    root = pushNode(root, 6, "E");
    root = pushNode(root, 7, "F");

    // in_order(root);
    // post_order(root);
    pre_order(root);
    puts("");

    update_name(root, 5, "Ayam");
    in_order(root);
    puts("");

    root = delete_node(root, 5);
    in_order(root);
    return 0;
}
