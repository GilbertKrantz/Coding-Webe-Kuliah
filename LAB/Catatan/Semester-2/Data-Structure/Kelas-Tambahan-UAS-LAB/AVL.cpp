#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 9;

struct Node
{
    char ID[100];
    char name[100];
    int page;

    int height;
    int BalF;
    Node *left, *right;
} *root = NULL;

char *getID() {
    counter++;
    char *scount = (char*) malloc(sizeof(char) * 100);
    sprintf(scount, "%d", counter);
    return scount;
}

Node *createNode(char *name, int page) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    strcpy(newNode->ID, getID());
    strcpy(newNode->name, name);
    newNode->page = page;
    
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    newNode->BalF = 0;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *curr) {
    return (!curr) ? 0 : curr->height;
}

int setHeight(Node *curr) {
    return (!curr) ? 0 : max(getHeight(curr->left), getHeight(curr->right)) + 1;
}

int setBalF(Node *curr) {
    return (!curr) ? 0 : getHeight(curr->left) - getHeight(curr->right);
}

Node *updateNode(Node *curr) {
    if (!curr) return curr;

    curr->height = setHeight(curr);
    curr->BalF = setBalF(curr);
    return curr;
}

Node *leftRotate(Node *curr) {
    Node *pivot = curr->right;
    Node *leftChild = pivot->left;

    pivot->left = curr;
    curr->right = leftChild;
    
    curr = updateNode(curr);
    pivot = updateNode(pivot);
    return pivot;
}

Node *rightRotate(Node *curr) {
    Node *pivot = curr->left;
    Node *rightChild = pivot->right;

    pivot->right = curr;
    curr->left = rightChild;
    
    curr = updateNode(curr);
    pivot = updateNode(pivot);
    return pivot;
}

Node *rotation(Node *curr) {
    if (!curr) return curr;
    else if(curr->BalF > 1 && curr->left->BalF >= 0) {
        // LL Case
        return rightRotate(curr);
    }
    else if(curr->BalF > 1 && curr->left->BalF < 0) {
        // LR Case
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    else if(curr->BalF < -1 && curr->right->BalF <= 0) {
        // RR Case
        return leftRotate(curr);
    }
    else if(curr->BalF < -1 && curr->right->BalF > 0) {
        // RL Case
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

Node *insertNode(Node *root, Node *curr) {
    if (!root) return curr;
    else if (strcmp(curr->ID, root->ID) < 0) root->left = insertNode(root->left, curr);
    else if (strcmp(curr->ID, root->ID) > 0) root->right = insertNode(root->right, curr);
    return rotation(updateNode(root));
}

Node *getPredes(Node *curr) {
    while (curr->right)
    {
        curr = curr->right;
    }
    
    return curr;
}

Node *deleteNode(Node *root, char *ID) {
    if (!root) return root;
    else if (strcmp(ID, root->ID) < 0) root->left = deleteNode(root->left, ID);
    else if (strcmp(ID, root->ID) > 0) root->right = deleteNode(root->right, ID);
    else {
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
        }
        else if (!root->right) {
            Node *temp = root->left;
            free(root);
            root = temp;
        }
        else if (!root->left) {
            Node *temp = root->right;
            free(root);
            root = temp;
        }
        else {
            Node *temp = getPredes(root->left);
            strcpy(root->ID, temp->ID);
            strcpy(root->name, temp->name);
            root->page = temp->page;
            
            root->left = deleteNode(root->left, temp->ID);
        }
    }
    return rotation(updateNode(root));
}

void inOrder(Node *node) {
    if (node)
    {
        inOrder(node->left);
        printf("%s [%d | %s] | [%d | %d]\n", node->name, node->page, node->ID, node->BalF, node->height);
        inOrder(node->right);
    }    
}

int main() {

    root = insertNode(root, createNode("Narnia", 12));
    root = insertNode(root, createNode("Neopolitan", 15));
    root = insertNode(root, createNode("Harry Potter", 20));
    root = insertNode(root, createNode("Narnia 2", 50));
    root = deleteNode(root, "11");

    inOrder(root);

    return 0;
}