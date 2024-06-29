#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 15
#define MAX_D 100

struct Node {
    int size;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;
int min_cost;

void insertNode(int size) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->size = size;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    if (size < head->size) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (size > tail->size) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->size < size) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

int calc_cost(int num, int size) {
    return num * num * size;
}

void calculate_min_cost(int N, int D) {
    min_cost = INT_MAX;
    struct Node* temp = head;

    for (int i = 0; i <= D; i++) {
        int total_cost = 0;
        for (int j = 0; j < N && temp != NULL; j++) {
            total_cost += calc_cost(i, temp->size);
            temp = temp->next;
        }
        if (temp != NULL)
            temp = head;
        if (total_cost < min_cost)
            min_cost = total_cost;
    }
}

// clear the memory allocated for the linked list
void clear() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = tail = NULL;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, D;
        scanf("%d %d", &N, &D);
        head = tail = NULL;

        for (int j = 0; j < N; j++) {
            int size;
            scanf("%d", &size);
            insertNode(size);
        }

        calculate_min_cost(N, D);
        printf("%d\n", min_cost);

        clear();
    }

    return 0;
}
