#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

struct Student
{
    char name[225];
    char email[225];
    char ID[50];

    Student *next, *prev;
} *head[SIZE], *tail[SIZE];

Student *create_node(char name[], char email[]) {
    Student *node = (Student*) malloc(sizeof(Student));

    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    node->prev = NULL;

    // rand() % (max - min + 1) + 1
    sprintf(node->ID, "ST%03d", rand() % 1000);

    return node;
}

int hash_function(char name[]) {
    return name[0] % SIZE;
}

void insert(char name[], char email[]) {
    int key = hash_function(name);
    Student *node = create_node(name, email);

    if (!head[key]) head[key] = tail[key] = node;
    else {
        tail[key]->next = node;
        node->prev = tail[key];
        tail[key] = node;
    }
}

void view() {
    for (int i = 0; i < SIZE; i++)
    {
        Student *curr = head[i];
        printf("%d - ", i + 1);
        while (curr)
        {
            printf("%s %s - %s -> ", curr->ID, curr->name, curr->email);
            curr = curr->next;
        }
        puts(" ");
    }
    
}

void add() {
    char *name = (char*) malloc(225 * sizeof(char));
    char *email = (char*) malloc(225 * sizeof(char));
    
    bool error = true;

    while (error)
    {
        printf("Name : ");
        scanf("%[^\n]", name); getchar();
        
        if (strlen(name) >= 1 && strlen(name) <= 50 && strchr(name, ' ')) error = false;
    }

    error = true;
    while (error)
    {
        printf("Email : ");
        scanf("%[^\n]", email); getchar();
        
        int occurance = 0;

        for (int i = 0; email[i] != '\0'; i++)
        {
            if (email[0] == '@') break;
            else if (email[i] == '@') occurance++;
        }
        
        if (occurance == 1 && (strstr(email, "@") + 1 < strstr(email, ".com"))) error = false;
    }
    
    insert(name, email); 
    free(name);
    free(email);
}

void menu() {
    int input;

    do
    {
        puts("1. Add");
        puts("2. View");
        puts("3. Delete");
        puts("4. Update");
        puts("5. Exit");
        printf(">> ");
        scanf("%d", &input); getchar();
        
        switch (input)
        {
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        }
    } while (input != 5);   
}


int main() {
    srand(time(NULL));

    menu();

    view();
}