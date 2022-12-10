#include <stdio.h>
#include <stdlib.h>

void swap(int *firstNum, int *secNum) {
    int temp = *firstNum;
    *firstNum = *secNum;
    *secNum = temp;
}

void printArray(int array[], int arrSize) {
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", array[i]);
    }
    
}

void bubbleSort(int array[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    printArray(array, arrSize);
    
}

void insertionSort(int array[], int arrSize) {
    for (int i = 1; i < arrSize; i++)
    {
        int compare = array[i];
        
        int j = i - 1;

        while (j >= 0 && array[j] > compare)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = compare;
        
    }
    

    printArray(array, arrSize);
    
}

void selectionSort(int array[], int arrSize) {
    
    for (int i = 0; i < arrSize - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < arrSize; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
            
        }
        
        if (min != i)
        {
            swap(&array[min], &array[i]);
        }
        
    }
    
    printArray(array, arrSize);
}

int main(int argc, char const *argv[])
{
    int array[] = {8, 4, 1, 2, 9, 5};
    int arrSize = sizeof(array) / sizeof(array[0]);

    printf("Original Array: \n");
    printArray(array, arrSize);
    printf("\n\n");

    printf("Bubble Sort: \n");
    bubbleSort(array, arrSize);
    printf("\n\n");

    printf("Insertion Sort: \n");
    int array2[] = {8, 4, 1, 2, 9, 5};
    insertionSort(array, arrSize);
    printf("\n\n");
    
    printf("Selection Sort: \n");
    int array3[] = {8, 4, 1, 2, 9, 5};
    selectionSort(array, arrSize);
    printf("\n\n");

    return 0;
}




