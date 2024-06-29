#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < N; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
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

int main() {
    int N = 3; // Length of the array
    int D = 5; // Desired sum of array elements

    generateAllCombinations(N, D);

    return 0;
}
