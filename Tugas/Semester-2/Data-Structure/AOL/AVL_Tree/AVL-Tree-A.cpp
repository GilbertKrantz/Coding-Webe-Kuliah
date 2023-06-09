#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data, height;

    Node *left, *right;
} *root = NULL;

Node *create_node(int num) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = num;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
} 

int get_height(Node *curr) {
    if (!curr) return 0;
    return curr->height;
}

int get_balF(Node *curr) {
    return get_height(curr->left) - get_height(curr->right);
}

int max(int a, int b) {
    if (!a) a = 0;
    if (!b) b = 0;
    if (a > b) return a;
    else return b;
}

Node *left_rotate(Node *curr) {
    Node *child, *subChild;
    child = curr->right;
    subChild = curr->left;


    child->left = curr;
    curr->right = subChild;

    curr->height = 1 + max(get_height(curr->left), get_height(curr->right));
    // printf("%d[%d]\n", curr->data, curr->height);
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    // printf("%d[%d]\n", child->data, child->height);

    return child;
}

Node *right_rotate(Node *curr) {
    Node *child, *subChild;
    child = curr->left;
    subChild = curr->right;

    child->right = curr;
    curr->left = subChild;

    curr->height = max(get_height(curr->left), get_height(curr->right)) + 1;
    child->height = max(get_height(child->left), get_height(child->right)) + 1;

    return child;
}

Node *insertion(Node *curr, int num) {
    if (!curr) return create_node(num);
    else if (num > curr->data) curr->right = insertion(curr->right, num);
    else if (num < curr->data) curr->left = insertion(curr->left, num);
    else return curr;

    curr->height = 1 + max(get_height(curr->left), get_height(curr->right));

    int balF = get_balF(curr);

    // left left
    if (balF > 1 && num < curr->left->data) {
        return right_rotate(curr);
    }
    // left right
    else if (balF > 1 && num > curr->left->data) {
        curr->left = left_rotate(curr->left);
        return right_rotate(curr);
    }
    // right right
    else if (balF < -1 && num > curr->right->data) {
        return left_rotate(curr);
    }
    // right left
    else if (balF < -1 && num < curr->right->data) {
        curr->right = right_rotate(curr->right);
        return left_rotate(curr);
    }
    
    return curr;
} 

Node *get_node(Node *curr) {
    while (curr->right) curr = curr->right;
    return curr;
}

Node *deletion(Node *curr, int num) {
    // Standart BST
    if(!curr) return curr;
    else if(curr->data < num) curr->right = deletion(curr->right, num);
    else if(curr->data > num) curr->left = deletion(curr->left, num);
    else {
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
            Node *temp = get_node(curr->left);

            curr->data = temp->data;

            curr->left = deletion(curr->left, temp->data);
        }
    }

    // if there's only 1 node
    if (!curr) return curr;

    // Update Height
    curr->height = max(get_height(curr->left), get_height(curr->right)) + 1;

    // get Balance Factor
    int balF = get_balF(curr);

    // if Imbalance
    // left left
    if (balF > 1 && get_balF(curr->left) >= 0) {
        return right_rotate(curr);
    }
    // left right
    else if (balF > 1 && get_balF(curr->left) < 0) {
        curr->left = left_rotate(curr->left);
        return right_rotate(curr);
    }
    // right right
    else if (balF < -1 && get_balF(curr->right) <= 0) {
        return left_rotate(curr);
    }
    // right left
    else if (balF < -1 && get_balF(curr->right) > 0) {
        curr->right = right_rotate(curr->right);
        return left_rotate(curr);
    }

    return curr;
}

void in_order(Node *curr) {
    if(curr) {
        in_order(curr->left);
        printf("%d[%d] -> ", curr->data, curr->height);
        in_order(curr->right);
    }
}

void pre_order(Node *curr) {
    if(curr) {
        printf("%d[%d] -> ", curr->data, curr->height);
        in_order(curr->left);
        in_order(curr->right);
    }
}

int main() {
    root = insertion(root, 6);
    root = insertion(root, 27);
    root = insertion(root, 19);
    root = insertion(root, 11);
    root = insertion(root, 36);
    root = insertion(root, 14);
    root = insertion(root, 81);
    root = insertion(root, 75);

    root = deletion(root, 14);
    root = deletion(root, 75);
    root = deletion(root, 36);
    root = deletion(root, 19);
    root = deletion(root, 11);

    // printf("%d\n", root->left->data);
    pre_order(root);

    return 0;
}