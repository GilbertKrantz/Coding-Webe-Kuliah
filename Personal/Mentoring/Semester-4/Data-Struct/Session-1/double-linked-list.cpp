#include <stdio.h> // Include standard input/output library for functions like printf
#include <stdlib.h> // Include standard library for functions like malloc (memory allocation)
#include <string.h> // Include string library for functions like strcpy (string copy)
#include <time.h>  // Include time library for functions like time (used for random seed)

// Define a structure named Food to store food information
struct Food {
  char foodID[10]; // Character array to store food ID (e.g., FD001, FD002)
  char name[225];  // Character array to store food name
  int price;       // Integer to store food price
  char custID[10]; // Character array to store customer ID (e.g., CU256, CU123)

  Food *next; // Pointer to the next node in the linked list
  Food *prev; // Pointer to the previous node in the linked list
};

// Global variables to store head and tail pointers of the linked list
Food *head = NULL;
Food *tail = NULL;

// Global variable to keep track of the food ID (incremental)
int foodID = 1;

// Function to create a new food node
Food* createNode(char name[], int price) {
  // Allocate memory for a new Food node
  Food *node = (Food*) malloc(sizeof(Food));

  // Copy the name and price to the new node
  strcpy(node->name, name);
  node->price = price;

  // Initialize next and prev pointers to NULL
  node->next = NULL;
  node->prev = NULL;

  // Generate a unique food ID (FD001 format) and store it in the node
  char foodID_temp[10];
  sprintf(foodID_temp, "FD%03d", foodID);
  strcpy(node->foodID, foodID_temp);
  foodID++; // Increment foodID for the next node

  // Generate a random customer ID (CU001 - CU999 format) and store it in the node
  char cusID_temp[10];
  int cusID_num = rand() % 1000; // Generate random number between 0 and 999
  sprintf(cusID_temp, "CU%03d", cusID_num);
  strcpy(node->custID, cusID_temp);

  // Return the newly created node
  return node;
}

// Function to insert a node at the head of the linked list
void push_head(Food *node) {
  // If the list is empty, set both head and tail to the new node
  if (!head) {
    head = tail = node;
    return;
  }

  // Insert the new node at the head
  node->next = head;
  head->prev = node;
  head = node;

  // Set the new head's prev pointer to NULL
  head->prev = NULL;
  return;
}

// Function to insert a node at the tail of the linked list
void push_tail(Food *node) {
  // If the list is empty, set both head and tail to the new node
  if (!tail) {
    head = tail = node;
    return;
  }

  // Insert the new node at the tail
  tail->next = node;
  node->prev = tail;
  tail = node;

  // Set the new tail's next pointer to NULL
  tail->next = NULL;
  return;
}

// Function to insert a node in the middle of the linked list based on name (alphabetical order)
void push_mid(Food *node) {
  // Check if the list is empty
  if (!head) {
    // If empty, set both head and tail to the new node
    head = tail = node;
    return;
  }

  // Check if the new node's name should be inserted at the head (lexicographically less than or equal to head)
  if (strcmp(node->name, head->name) <= 0) {
    push_head(node); // Utilize push_head function for efficient insertion at head
    return;
  }

  // Check if the new node's name should be inserted at the tail (lexicographically greater than or equal to tail)
  if (strcmp(node->name, tail->name) >= 0) {
    push_tail(node); // Utilize push_tail function for efficient insertion at tail
    return;
  }

  // Initialize a current pointer to start traversing from the head
  Food *curr = head;

  // Traverse the list until the new node's name is alphabetically greater than or equal to the current node's name
  while (curr && strcmp(node->name, curr->name) >= 0) {
    curr = curr->next;
  }

  // Set the new node's previous pointer to the node before the insertion position (curr->prev)
  node->prev = curr->prev;

  // Set the new node's next pointer to the node at the insertion position (curr)
  node->next = curr;

  // If there's a node before the insertion position, update its next pointer to point to the new node
  if (curr->prev) {
    curr->prev->next = node;
  }

  // Update the previous pointer of the node at the insertion position (curr) to point to the new node
  curr->prev = node;

  // **Note:** Since head and tail pointers might change due to insertions at the beginning or end, 
  // we explicitly set head->prev and tail->next to NULL at the end for clarity, 
  // although not strictly necessary in this function.
  head->prev = NULL;
  tail->next = NULL;
  return;
}

// Function to remove the head node from the linked list
void pop_head() {
  // Check if the list is empty
  if (!head) {
    return;
  }

  // If there's only one node (head == tail)
  if (head == tail) {
    // Free the memory of the head (and tail) node
    free(head);
    // Set both head and tail to NULL since the list is now empty
    head = tail = NULL;
    return;
  }

  // Create a temporary pointer to store the head node
  Food *temp = head;

  // Update the head pointer to point to the next node
  head = head->next;

  // If there's still a head node, update its previous pointer to NULL (since it becomes the new head)
  if (head) {
    head->prev = NULL;
  }

  // Free the memory of the original head node stored in temp
  free(temp);
  return;
}

// Function to remove the tail node from the linked list
void pop_tail() {
  // Check if the list is empty
  if (!tail) {
    return;
  }

  // If there's only one node (head == tail)
  if (head == tail) {
    // Free the memory of the head (and tail) node
    free(tail);
    // Set both head and tail to NULL since the list is now empty
    head = tail = NULL;
    return;
  }

  // Create a temporary pointer to store the tail node
  Food *temp = tail;

  // Update the tail pointer to point to the previous node
  tail = tail->prev;

  // If there's still a tail node, update its next pointer to NULL (since it becomes the new tail)
  if (tail) {
    tail->next = NULL;
  }

  // Free the memory of the original tail node stored in temp
  free(temp);
  return;
}

// Function to remove a node with a specific name from the linked list
void pop(char name[]) {
  // Check if the list is empty
  if (!head) {
    // Nothing to remove if the list is empty
    return;
  }

  // Check if the node to remove is the head
  if (strcmp(head->name, name) == 0) {
    // Use pop_head function for efficient removal of the head node
    pop_head();
    return;
  }

  // Check if the node to remove is the tail
  if (strcmp(tail->name, name) == 0) {
    // Use pop_tail function for efficient removal of the tail node
    pop_tail();
    return;
  }

  // Initialize a current pointer to start traversing from the head
  Food *curr = head;

  // Traverse the list until the node with the matching name is found
  while (curr && strcmp(curr->name, name) != 0) {
    // Keep iterating as long as there's a next node and the names don't match
    curr = curr->next;
  }

  // Check if the node to remove was found (curr != NULL)
  if (curr) {
    // Update the next pointer of the node before the one to remove (curr->prev) to point to the node after (curr->next)
    curr->prev->next = curr->next;

    // Update the previous pointer of the node after the one to remove (curr->next) to point to the node before (curr->prev)
    curr->next->prev = curr->prev;

    // Free the memory of the removed node (stored in curr)
    free(curr);
  }

  return;
}

// Function to print information of all nodes in the linked list
void print_all() {
  // Initialize a current pointer to start traversing from the head
  Food *curr = head;

  // Loop as long as there's a next node
  while (curr) {
    // Print the food information (ID, name, price, customer ID) for the current node
    printf("%s - %s %d %s\n", curr->foodID, curr->name, curr->price, curr->custID);

    // Move the current pointer to the next node
    curr = curr->next;
  }

  return;
}

int main() {
  // Seed the random number generator for creating random customer IDs
  srand(time(NULL));

  // Create and insert food nodes with names "c", "a", "b", "f", and "g" (alphabetically ordered)
  push_mid(createNode("c", 10000));
  push_mid(createNode("a", 10000));
  push_mid(createNode("b", 10000));
  push_mid(createNode("f", 10000));
  push_mid(createNode("g", 10000));

  // Remove the head node (should be "a")
  pop_head();

  // Remove the tail node (should be "g")
  pop_tail();

  // Remove the node with name "c"
  pop("c");

  // Print the information of all remaining nodes in the list
  print_all();

  return 0; // Indicate successful program termination
}