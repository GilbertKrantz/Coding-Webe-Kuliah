#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum nodeColor {RED, BLACK};

struct Node {
    int num, color;
    Node *left, *right, *parent;
} *root = NULL;

void insert_case_1(Node*);
void insert_case_2(Node*);
void insert_case_3(Node*);
void insert_case_4(Node*);
void insert_case_5(Node*);

// Creating The RBT Tree
Node *createNode(int num) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->num = num;
    temp->color = RED;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

// Getting grand-parents
Node *Grand_Parent(Node *curr) {
    if (curr && curr->parent)
        return curr->parent->parent;
    else
        return NULL;
}

// Getting Uncle
Node *Uncle(Node *curr) {
    Node *grandParent = Grand_Parent(curr);
    if (!grandParent) {
        return NULL;
    } else if (curr->parent == grandParent->left)
    {
        return grandParent->right;
    } else {
        return grandParent->left;
    }
}

// Getting Sibling
Node *Sibling(Node *curr) {
    Node *parent = curr->parent;
    if (!curr)
    {
        return NULL;
    } else if (curr == parent->right)
    {
        return parent->left;
    } else {
        return parent->right;
    }
}

// Is it a Leaf?
int is_leaf(Node *curr) {
    if (!curr)
    {
        return 1;
    }
    
    return 0;
}

// Getting Child
Node *Child (Node *curr) {
    Node *child;

    if (is_leaf(curr->right))
    {
        child = curr->left;
    } else {
        child = curr->right;
    }

    return child;
}

// Replace
void Replace(Node *topNode, Node *bottomNode) {
    
}


// Insertion
void insert(int num) {
    Node *curr = root;
    Node *newNode = createNode(num);

    if (!root) {
        root = createNode(num);
        insert_case_1(root);
    } else {
        while (curr) {
            if (curr->num > num)
            {
                if(curr->left) {
                    curr = curr->left;
                } else {
                    curr->left = newNode;
                    newNode->parent = curr;
                    insert_case_1(curr->left);
                    break;
                }
            } else if (curr->num < num)
            {
                if (curr->right)
                {
                    curr = curr->right;
                } else {
                    curr->right = newNode;
                    newNode->parent = curr;
                    insert_case_1(curr->right);
                    break;
                }
            }
        }
    }
}

// Print In-Order
void in_order(Node *curr) {
    if (curr)
    {
        in_order(curr->left);
        printf("%d[%d] -> ", curr->num, curr->color);
        in_order(curr->right);
    }
}

void pre_order(Node *curr) {
    if (curr)
    {
        printf("%d[%d] -> ", curr->num, curr->color);
        pre_order(curr->left);
        pre_order(curr->right);
    }
    
}

// Rotation
void rotate_left(Node *curr) {
    Node *grandParent = Grand_Parent(curr);
    Node *child = curr->left;
    Node *parent = curr->parent;

    if (parent == root)
    {
        root = curr;
    }

    if(grandParent && parent == grandParent->right) {
        grandParent->right = curr;
        curr->parent = grandParent;
    } else if( grandParent && parent == grandParent->left) {
        grandParent->left = curr;
        curr->parent = grandParent;
    }

    curr->left = parent;
    parent->parent = curr;

    parent->right = child;
    if (child)
    {
        child->parent = parent;
    }
}

void rotate_right(Node *curr) {
    Node *grandParent = Grand_Parent(curr);
    Node *child = curr->right;
    Node *parent = curr->parent;

    if (parent == root)
    {
        root = curr;
    }

    if(grandParent && parent == grandParent->right) {
        grandParent->right = curr;
        curr->parent = grandParent;
    } else if( grandParent && parent == grandParent->left) {
        grandParent->left = curr;
        curr->parent = grandParent;
    }

    curr->right = parent;
    parent->parent = curr;

    parent->left = child;
    if (child)
    {
        child->parent = parent;
    }
}

// RBT Insertion Operation

// If Root
void insert_case_1(Node *curr) {
    if (!curr->parent)
    {
        curr->color = BLACK;
        return;
    } else {
        insert_case_2(curr);
    }
}

// If Parent is Black
void insert_case_2(Node *curr) {
    if (curr->parent->color == BLACK)
    {
        return;
    } else {
        insert_case_3(curr);
    }
}

// If Uncle is Red
void insert_case_3(Node *curr) {
    Node *grandParent, *uncle;
    grandParent = Grand_Parent(curr);
    uncle = Uncle(curr);

    if (uncle && uncle->color == RED)
    {
        curr->parent->color = BLACK;
        uncle->color = BLACK;
        grandParent->color = RED;
        root->color = BLACK;
    } else {
        insert_case_4(curr);
    }   
}

// If Uncle is Black (2 Rotation)
void insert_case_4(Node *curr) {
    Node *grandParent;
    grandParent = Grand_Parent(curr);

    if (curr == curr->parent->right && curr->parent == grandParent->left)
    {
        rotate_left(curr);
        curr = curr->left;
    } else if (curr == curr->parent->left && curr->parent == grandParent->right)
    {
        rotate_right(curr);
        curr = curr->right;
    }
    insert_case_5(curr); 
}

// If Uncle is Black (1 Rotation)
void insert_case_5(Node *curr) {
    Node *grandParent;
    grandParent = Grand_Parent(curr);

    if (curr == curr->parent->left && curr->parent == grandParent->left)
    {
        rotate_right(curr->parent);
    } else if (curr == curr->parent->right && curr->parent == grandParent->right)
    {
        rotate_left(curr->parent);
    }
    curr->parent->color = BLACK;
    grandParent->color = RED;
    root->color = BLACK;
}


int main() {
    insert(41);
    insert(22);
    insert(5);
    insert(51);
    insert(48);
    insert(29);
    insert(18);
    insert(21);
    insert(45);
    insert(3);
    
    printf("In Order Traversal of the Created Tree\n");
    in_order(root);
    return 0;
}