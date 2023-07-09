#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    char name[100];
    int age;
    char ID[6];

    int height, balF;
    Node *left, *right;
} *root;

Node *createNode(char *name, int age) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    sprintf(newNode->ID, "AB%03d", rand() % 999 + 1);

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
    else if (curr->balF > 1 && curr->left->balF >= 0) {
        // LL Case
        return rightRotate(curr);
    }
    else if (curr->balF > 1 && curr->left->balF < 0) {
        // LR Case
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    else if (curr->balF < 1 && curr->right->balF <= 0) {
        // RR Case
        return leftRotate(curr);
    }
    else if (curr->balF < 1 && curr->right->balF > 0) {
        // RL Case
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

Node *insertion(Node *root, Node *curr) {
    if (!root) return curr;
    else if (strcmp(root->ID, curr->ID) < 0) root->left = insertion(root->left, curr);
    else if (strcmp(root->ID, curr->ID) > 0) root->right = insertion(root->right, curr);
    return rotation(updateNode(root));
}

Node *getPredes(Node *curr) {
    curr = curr->left;
    while (curr->right)
    {
        curr = curr->right;
    }
    return curr;
}

Node *deletion(Node *root, char *ID) {
    if (!root) return root;
    else if (strcmp(root->ID, ID) < 0) root->left = deletion(root->left, ID);
    else if (strcmp(root->ID, ID) > 0) root->right = deletion(root->right, ID);
    else {
        if (!root->left, !root->right) {
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
            Node *temp = getPredes(root);
            strcpy(root->name, temp->name);
            strcpy(root->ID, temp->ID);
            root->age = temp->age;

            root->left = deletion(root->left, temp->ID);
        }
    }
    return rotation(updateNode(root));
}

void inOrder(Node *curr) {
    if(curr) {
        inOrder(curr->left);
        printf("%s %d [%s | %d]", curr->name, curr->age, curr->ID, curr->height);
        inOrder(curr->right);
    }
}

int main() {
    char input[100];

    do
    {   
        printf("Input\n");
        scanf("%[^\n]", input);
		getchar();

        if (strncmp(input, "insert", 6) == 0) {
            printf("Insert\n");
            char name[100];
			int age;

            char *token = strtok(input, " ");
            token = strtok(NULL, "-");
            
            if(token != NULL){
				strcpy(name, token);
				token = strtok(NULL, " ");
				
				if(token != NULL){
					age = atoi(token);
					token = strtok(NULL, "");
						
					root = insertion(root, createNode(name, age));
                }
            }
        }

        else if(strncmp(input, "delete" , 6) == 0){
			char id[50];
            printf("delete : ");
			sscanf(input, "delete %s", id);
			
			root = deletion(root, id);
			
		}
		else if(strncmp(input, "view" , 4) == 0){
            printf("View\n");
			inOrder(root);
		}
		
		
	}while(strcmp(input, "exit") != 0);
    
    return 0;
}
