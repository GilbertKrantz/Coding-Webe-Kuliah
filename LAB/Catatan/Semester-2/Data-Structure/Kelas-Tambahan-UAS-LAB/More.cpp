#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    char ID[100];
    char name[100];
    int page;

    int height;
    int balF;
    Node *left, *right;
}*root = NULL;

char *getID() {
    int ID = rand() % 100;
    char *charID = (char*) malloc(sizeof(char) * 100);
    sprintf(charID, "%03d", ID);
    return charID;
}

Node *createNode(char *name, int page) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->ID, getID());
    newNode->page = page;

    newNode->height = 1;
    newNode->balF = 0;
    newNode->left = newNode->right = NULL;
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
    curr->balF = setBalF(curr);
    return curr;
}

Node *leftRotate(Node *curr) {
    Node *pivot = curr->right;
    Node *leftChild = pivot->left;

    pivot->left = curr;
    curr->right = leftChild;

    updateNode(curr);
    updateNode(pivot);
    return pivot;
}

Node *rightRotate(Node *curr) {
    Node *pivot = curr->left;
    Node *rightChild = pivot->right;

    pivot->right = curr;
    curr->left = rightChild;

    updateNode(curr);
    updateNode(pivot);
    return pivot;
}

Node *insertNode(Node *root, Node *curr) {
    if (!root) return curr;
    else if (strcmp(curr->ID, root->ID) < 0) root->left = insertNode(root->left, curr);
    else if (strcmp(curr->ID, root->ID) > 0) root->right = insertNode(root->right, curr);
    return curr;
}