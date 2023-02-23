#include <stdio.h>
#include <string.h>

void merge(char *arr[], int left, int right, int middle) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    char *leftArr[100];
    char *rightArr[100];

    
    
    for (int i = 0; i < leftSize; i++)
    {
        strcpy(leftArr[i], arr[left + i]);
    }
    
    for (int i = 0; i < rightSize; i++)
    {
        strcpy(rightArr[i], arr[middle + i + 1]);
    }
    
    int tempIndex = left;
    int j = 0, k = 0; // left and right Limit

    while(j < leftSize && k < rightSize)
    {
        if(strcmp(leftArr[j], rightArr[k]) < 0)
            strcpy(arr[tempIndex++], leftArr[j++]);

        else strcpy(arr[tempIndex++], rightArr[k++]);
    }
    while(j < leftSize)
        strcpy(arr[tempIndex++], leftArr[j++]);
    while(k < rightSize)
        strcpy(arr[tempIndex++], rightArr[k++]);
    
}

void mergeSort(char *arr[], int left, int right) {
    
    if (left < right)
    {
        int middle = (right - left) / 2 + left;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge Function
        merge(arr, left, right, middle);
        printf("* ");
    }
    
}

void printArray(char *arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
    }
    
}

int main() {
    char *strings[100] = {"brandon", "lauren", "asu", "edbert"};
    int arraySize = sizeof(strings) / sizeof(strings[0]);

    printf("%d\n", arraySize);
    strcpy(strings[2], "LOL");
    // Before Sorting
    printArray(strings, arraySize);
    printf("\n");

    printArray(strings, arraySize);
    return 0;
}