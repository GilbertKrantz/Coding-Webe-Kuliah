#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char title[225];
    int price;
    Book *next;
}*head, *tail;

Book* createNode(char title[], int price) {
    // Use malloc(size) -> void *

    Book *temp = (Book*) malloc(sizeof(Book));
    temp->price = price;
    strcpy(temp->title, title);

    temp->next = NULL;

    return temp;
}

// * Push Data to the Front (Foward)
void pushHead(char title[], int price) {
    Book *node = createNode(title, price);
    if(head == NULL)
        head = tail = node;
    else {
        node->next = head;
        head = node;
    }
}

// * Push data from the Back (Backwards)
void pushTail(char title[], int price) {
    Book *node = createNode(title, price);
    if (tail == NULL)
        head = tail = node;
    else {
        tail->next = node;
        tail = node;
    }
    
}

// ! Push mid Validation
/*  
    1. No Data
    2. Node->price < head->Next price pushHead 
    3. Node->price < head->Next price pushTail
    4. Mush be in the middle
*/

void printAll() {
    // Make new Current Pointer
    Book *curr = head;

    while (curr != NULL) {
        printf("%s %d\n", curr->title, curr->price);

        // Change Current Address to the next Address
        curr = curr->next;
    }
    
}

int main()
{
    pushHead("Narnia", 15000);
    pushHead("Harry Potter", 20000);
    pushTail("Dragoon", 40000);
    pushHead("Frostfall", 30000);

    printAll();
    return 0;
}
