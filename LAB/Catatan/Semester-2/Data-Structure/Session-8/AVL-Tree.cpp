#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Balance Factor = Left child height - RIght child height

struct Node
{
    int key;
    int height;
    char name[100];

    Node *left, *right;
} *root;

Node *createNode(int key, char name[]) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->key = key;
    new_node->height = 1;

    new_node->left = new_node->right = NULL;
    return new_node;
}


int getHeight(Node *curr) {
    if(!curr) return 0;
    return curr->height;
}

int getBalF(Node *curr) {
    return getHeight(curr->left) - getHeight(curr->right);
}

int max(int a, int b) {
    return a > b ? a : b;
}

Node *leftRotate(Node *curr) {
    Node* child = curr -> right;
	Node* subChild = curr -> left;
	
	child -> left = curr;
	curr -> right = subChild;
	
	curr ->  height = max(getHeight(curr -> left), getHeight (curr -> right)) + 1;
	child -> height = max(getHeight(curr -> left), getHeight (curr -> right)) + 1;
	
	return child;
}

Node* rightRotate (Node* curr){
	Node* child = curr -> left;
	Node* subChild = child -> right;

	child -> right = curr;
	curr -> left = subChild;
	
	curr ->  height = max(getHeight(curr -> left), getHeight (curr -> right)) + 1;
	child -> height = max(getHeight(curr -> left), getHeight (curr -> right)) + 1;
	
	return child;
}


Node* insertion(Node* curr, Node* new_node) {
    if(!curr) return new_node;
    else if(new_node->key > curr->key) curr->right = insertion(curr->right, new_node);
    else if(new_node->key < curr->key) curr->left = insertion(curr->left, new_node);
    else return curr;

    curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;

    int bal_factor = getBalF(curr);

    // left left
    if (bal_factor > 1 && getBalF(curr->left) >= 0)
    {
        return rightRotate(curr);
    }
    // left right
    else if (bal_factor > 1 && getBalF(curr->left) < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    // right right
    else if (bal_factor < -1 && getBalF(curr->right) <= 0)
    {
        return leftRotate(curr);
    }
    // right left
    else if (bal_factor < -1 && getBalF(curr->left) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}

Node* inOrder(Node *curr) {
    if(curr) {
        inOrder(curr->left);
        printf("[%s - %d - %d] -> ", curr->name, curr->key, curr->height);
        inOrder(curr->right);
    }
}

int main() {
    root = NULL;
    root = insertion(root, createNode(6, "Budi"));
    root = insertion(root, createNode(7, "Jason"));
    root = insertion(root, createNode(8, "Vito"));
    inOrder(root);
}