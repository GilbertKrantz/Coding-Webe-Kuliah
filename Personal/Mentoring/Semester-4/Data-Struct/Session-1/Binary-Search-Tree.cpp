#include <stdio.h> // Include standard input/output library for functions like printf
#include <stdlib.h> // Include standard library for functions like malloc (memory allocation)
#include <string.h> // Include string library for functions like strcpy (string copy)
#include <ctype.h> // Include character library for functions like isalpha (check if character is alphabetic) - potentially unused in this code
#include <time.h>  // Include time library for functions like time (used for random seed)

// Define a structure named Node to represent a node in the binary search tree
struct Node {
  int value; // Integer value stored in the node
  char name[225]; // Character array to store the node's name (up to 224 characters)

  // Declare pointers for left and right child nodes
  Node *left;  // Pointer to the left child node
  Node *right; // Pointer to the right child node
};

// Global variable `root` to store the root node of the binary search tree, initially set to NULL (empty tree)
Node *root = NULL;

// Function to create a new node with a given value and name
Node* createNode(int value, char name[]) {
  // Allocate memory for a new Node using malloc
  Node *node = (Node*)malloc(sizeof(Node));

  // Check if memory allocation was successful
  if (!node) {
    printf("Memory allocation failed!\n"); // Handle error if allocation fails (optional)
    return NULL;
  }

  // Assign the value and name to the new node
  node->value = value;
  strcpy(node->name, name);

  // Initialize the left and right child pointers to NULL (no children initially)
  node->left = NULL;
  node->right = NULL;

  // Return the newly created node
  return node;
}

// Function to insert a node with a given value and name into the binary search tree
Node* pushNode(Node *curr, int value, char name[]) {
  // If the tree is empty, create a new node and make it the root
  if (!curr) {
    return createNode(value, name);
  }

  // If the value to be inserted is less than the current node's value,
  // recursively call pushNode on the left subtree
  else if (value < curr->value) {
    curr->left = pushNode(curr->left, value, name);
  }

  // If the value to be inserted is greater than the current node's value,
  // recursively call pushNode on the right subtree
  else if (value > curr->value) {
    curr->right = pushNode(curr->right, value, name);
  }

  // If the value already exists in the tree (shouldn't happen in a proper BST),
  // we can choose to ignore or handle it differently (not shown here)
  // else {
  //   // Handle duplicate values (optional)
  // }

  // Return the (potentially modified) current node
  return curr;
}

// Function to update the name of a node with a specific value (key)
Node* update_name(Node *curr, int key, char name[]) {
  // If the tree is empty, there's no node to update
  if (!curr) {
    return curr;
  }

  // If the key is less than the current node's value,
  // recursively search for the node in the left subtree
  else if (key < curr->value) {
    curr->left = update_name(curr->left, key, name);
  }

  // If the key is greater than the current node's value,
  // recursively search for the node in the right subtree
  else if (key > curr->value) {
    curr->right = update_name(curr->right, key, name);
  }

  // If the key matches the current node's value, update its name
  else {
    strcpy(curr->name, name);
    return curr; // Return the updated node
  }

  // If the key wasn't found in the tree, return the unchanged tree
  return curr;
}

// Function to find the node with the minimum value in the right subtree
Node* get_newValue(Node *curr) {
  // Traverse down the leftmost path of the right subtree
  while (curr && curr->left) {
    curr = curr->left;
  }
  // The node reached will be the one with the minimum value in the right subtree
  return curr;
}

// Function to delete a node with a specific value (key) from the binary search tree
Node* delete_node(Node *curr, int key) {
  // If the tree is empty, there's nothing to delete
  if (!curr) {
    return curr; // Return NULL (unchanged tree)
  }

  // If the key to be deleted is less than the current node's value,
  // recursively search for the node in the left subtree
  else if (key < curr->value) {
    curr->left = delete_node(curr->left, key);
  }

  // If the key to be deleted is greater than the current node's value,
  // recursively search for the node in the right subtree
  else if (key > curr->value) {
    curr->right = delete_node(curr->right, key);
  }

  // If the key matches the current node's value (node found)
  else {
    // Handle deletion based on the number of child nodes
    if (!curr->left) { // Node has only a right child or no children
      // Temporarily store the right child
      Node *temp = curr->right;

      // Free the memory of the node to be deleted
      free(curr);

      // Return the right child (or NULL if no children) as the replacement subtree
      return temp;
    } else if (!curr->right) { // Node has only a left child
      // Temporarily store the left child
      Node *temp = curr->left;

      // Free the memory of the node to be deleted
      free(curr);

      // Return the left child as the replacement subtree
      return temp;
    } else { // Node has two children (more complex deletion)
      // Find the node with the minimum value in the right subtree
      Node *temp = get_newValue(curr->right);

      // Copy the value and name of the minimum node to the current node
      curr->value = temp->value;
      strcpy(curr->name, temp->name);

      // Recursively delete the minimum node from the right subtree (where its value was copied)
      curr->right = delete_node(curr->right, temp->value);
    }
  }

  // Return the (potentially modified) current node
  return curr;
}

//------------------------------------------------------------------------//
// There's 3 type of Print (inOrder, postOrder, preOrder)

// inOrder traversal
// Steps: visit left subtree, print the current node, visit right subtree
void in_order(Node *curr) {
  if (curr) { // Check if the current node is not NULL
    // Recursively call in_order on the left subtree to visit all nodes in left branch
    in_order(curr->left);

    // Print the value and name of the current node
    printf("%d - %s\n", curr->value, curr->name);

    // Recursively call in_order on the right subtree to visit all nodes in right branch
    in_order(curr->right);
  }
}

// postOrder traversal
// Steps: visit left subtree, visit right subtree, print the current node
void post_order(Node *curr) {
  if (curr) { // Check if the current node is not NULL
    // Recursively call post_order on the left subtree to visit all nodes in left branch
    post_order(curr->left);

    // Recursively call post_order on the right subtree to visit all nodes in right branch
    post_order(curr->right);

    // Print the value and name of the current node after visiting its children
    printf("%d - %s\n", curr->value, curr->name);
  }
}

// preOrder traversal
// Steps: print the current node, visit left subtree, visit right subtree
void pre_order(Node *curr) {
  if (curr) { // Check if the current node is not NULL
    // Print the value and name of the current node before visiting its children
    printf("%d - %s\n", curr->value, curr->name);

    // Recursively call pre_order on the left subtree to visit all nodes in left branch
    pre_order(curr->left);

    // Recursively call pre_order on the right subtree to visit all nodes in right branch
    pre_order(curr->right);
  }
}
//------------------------------------------------------------------------//

int main() {
  // Create a binary search tree and insert nodes
  root = pushNode(root, 5, "A");
  root = pushNode(root, 3, "B");
  root = pushNode(root, 4, "C");
  root = pushNode(root, 2, "D");
  root = pushNode(root, 6, "E");
  root = pushNode(root, 7, "F");

  // Uncomment the desired traversal function to print the tree
  // in_order(root); // Prints nodes in left-root-right order
  // post_order(root); // Prints nodes in left-right-root order
  pre_order(root); // Prints nodes in root-left-right order
  puts(""); // Print a newline after traversal

  // Update the name of the node with value 5
  update_name(root, 5, "Ayam");

  // Print the tree in in-order after update
  in_order(root);
  puts("");

  // Delete the node with value 5
  root = delete_node(root, 5);

  // Print the tree in in-order after deletion
  in_order(root);
  return 0;
}
