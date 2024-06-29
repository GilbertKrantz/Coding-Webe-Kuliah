#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node {
    char teams[100];
    char institution[100];
    struct Node *next;
}*head = NULL, *tail = NULL;

struct Node* createNode(char *teams, char *institution) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->teams, teams);
    strcpy(newNode->institution, institution);
    newNode->next = NULL;
    return newNode;
}

void push(struct Node *newNode) {
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int inst_present(char passed_inst[100][100], int j, struct Node *node) {
    for (int i = 0; i < j; i++) {
        if (strcmp(passed_inst[i], node->institution) == 0) {
            return 1;
        }
    }
    return 0;
}

void count_Golden(int N, int M, int K) {
    struct Node *curr = head;
    int inst_count = 0;
    int count = 0;
    char passed_inst[100][100];
    char golden_team[100][100];

    while (curr && M > 0) {
        strcpy(passed_inst[inst_count], curr->institution);
        curr = curr->next;
        M--;
        inst_count++;
    }
    
    while (curr && count < K) {
        if (inst_present(passed_inst, inst_count, curr) == 0) {
            strcpy(golden_team[count], curr->teams);
            strcpy(passed_inst[inst_count], curr->institution);
            inst_count++;
            count++;
        }

        curr = curr->next;
    }

    printf("%d\n", count);
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("%s\n", golden_team[i]);
        }
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        char teams[100], institution[100];
        scanf("%s %s", teams, institution);
        getchar();
        push(createNode(teams, institution));
    }

    count_Golden(N, M, K);
    return 0;
}
