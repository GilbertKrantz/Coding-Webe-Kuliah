#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ID_counter = 1;

struct Node
{
    char BookID[225];
    char Title[225];
    char Author[225];
    char ISBN[225];
    int page;

    Node *next, *prev;
} *HEAD[10], *TAIL[10];

char *ID_maker(char Title[], char Author[], char ISBN[], int page) {
    char *temp_ID = (char*) malloc(225 * sizeof(char));
    sprintf(temp_ID, "B%05d-%s-%c%c", ID_counter, ISBN, Author[0], Title[0]);
    return temp_ID;
}

int hash_function(char *BookID) {
    int ASCII_sum = 0;
    for (int i = 0; i < strlen(BookID); i++)
    {
        ASCII_sum += BookID[0];
    }
    
    int KEY = ASCII_sum % 10;
    return KEY;
}

Node *create_node(char Title[], char Author[], char ISBN[], int page, char *BookID, int KEY) {
    Node *curr = (Node*) malloc(sizeof(Node));
    strcpy(curr->Title, Title);
    strcpy(curr->Author, Author);
    strcpy(curr->ISBN, ISBN);
    strcpy(curr->BookID, BookID);
    curr->page = page;

    curr->next = NULL;
    curr->prev = NULL;

    return curr;
}

void insert(Node *curr, int KEY) {
    if (!HEAD[KEY]) HEAD[KEY] = TAIL[KEY] = curr; 
    else {
        TAIL[KEY]->next = curr;
        curr->prev = TAIL[KEY];
        TAIL[KEY] = curr;
    }
    ID_counter++;
}

void remove(char *BookID, int KEY) {
    Node *curr = HEAD[KEY];
    
    if (!HEAD[KEY]) puts("Book ID Not Found!!");
    else if (HEAD[KEY] == TAIL[KEY])
    {
        free(HEAD[KEY]);
        free(TAIL[KEY]);
    }
    else if (strcmp(HEAD[KEY]->BookID, BookID) == 0)
    {
        HEAD[KEY] = curr->next;
        HEAD[KEY]->prev = NULL;
        free(curr);
    }
    else if (strcmp(TAIL[KEY]->BookID, BookID) == 0)
    {
        curr = TAIL[KEY];
        TAIL[KEY] = curr->prev;
        TAIL[KEY]->next = NULL;
        free(curr);
    }
    else {
        while (curr && strcmp(curr->BookID, BookID) != 0)
        {
            curr = curr->next;
        }
        
        if (!curr) puts("Book ID Not Found!!");
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
        }
    }   
}

void print_all() {
    for (int i = 0; i < 10; i++)
    {
        Node *curr = HEAD[i];
        printf("%d. ", i);
        while (curr)
        {
            printf("%s - %s - %s - %s - %d -> ", curr->BookID, curr->Title, curr->Author, curr->ISBN, curr->page);
            curr = curr->next;
        }
        puts(" ");
    }
}

int main() {
    insert(create_node("Ayam", "WB", "12345678", 16, ID_maker("Ayam", "WB", "12345678", 16), hash_function(ID_maker("Ayam", "WB", "12345678", 16))), hash_function(ID_maker("Ayam", "WB", "12345678", 16)));
    insert(create_node("Byam", "WB", "12345678", 16, ID_maker("Ayam", "WB", "12345678", 16), hash_function(ID_maker("Ayam", "WB", "12345678", 16))), hash_function(ID_maker("Ayam", "WB", "12345678", 16)));
    print_all();
    remove("B00001-12345678-WA", hash_function("B00001-12345678-WA"));
    print_all();
    return 0;
}