#include <stdio.h>
#include <stdlib.h>

# define MAX 1000000000

struct Node
{
    int size;
    struct Node *next;
    struct Node *prev;
}*head = NULL, *tail = NULL;

int min_cost = MAX;

struct Node* createNode(int size)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->size = size;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(int size)
{
    struct Node *newNode = createNode(size);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    if(size < head->size) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if(size > tail->size) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        struct Node *temp = head;
        while(temp->next != NULL && temp->next->size < size)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

int calc_cost(int num, int size) {
    int cost = (num * num) * size;
    return cost;
}

void generateCombinations(int N, int D, int index, int currentSum, int* current, void (*callback)(int*, int)) {
    if (index == N) {
        if (currentSum == D) {
            callback(current, N);
        }
        return;
    }

    for (int i = 0; i <= D; i++) {
        if (currentSum + i <= D) {
            current[index] = i;
            generateCombinations(N, D, index + 1, currentSum + i, current, callback);
        }
    }
}

void printCombination(int* combination, int N) {
    struct Node *temp = head;
    int temp_cost = 0;
    for (int i = 0; i < N; i++) {
        temp_cost = temp_cost + calc_cost(combination[i], temp->size);
        temp = temp->next;
    }

    if (temp_cost < min_cost) {
        min_cost = temp_cost;
    }
}

void generateAllCombinations(int N, int D) {
    int* current = (int*)malloc(N * sizeof(int));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    generateCombinations(N, D, 0, 0, current, printCombination);
    free(current);
}

int calc_min_cost(int D) {
    struct Node *temp = head;
}

// Clear the linked list
void clear() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = tail = NULL;
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        int N, D;
        scanf("%d %d", &N, &D);
        for (int j = 0; j < N; j++)
        {
            int size;
            scanf("%d", &size);
            insertNode(size);
        }
        generateAllCombinations(N, D);
        printf("%d\n", min_cost);
        min_cost = MAX;
        clear();
    }
}
