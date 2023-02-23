#include <stdio.h>

// mergeSort

void merge(int arr[], int left, int right, int middle) {
    int tempArray[right - left];
    int leftIndex = left;
    int leftLimit = middle;
    int rightIndex = middle + 1;
    int rightLimit = right;

    int tempIndex = 0;

    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        if(arr[leftIndex] < arr[rightIndex]) {
            tempArray[tempIndex] = arr[leftIndex];
            leftIndex++;
        } else {
            tempArray[tempIndex] = arr[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }

    while (leftIndex <= leftLimit) {
        tempArray[tempIndex] = arr[leftIndex];
        leftIndex++;
        tempIndex++;
    }

        while (rightIndex <= rightLimit) {
        tempArray[tempIndex] = arr[rightIndex];
        rightIndex++;
        tempIndex++;
    }
    
    tempIndex = 0;

    for (int i = left; i <= right; i++)
    {
        arr[i] = tempArray[tempIndex];
        tempIndex++;
    }
    
    
}

void mergeSort(int arr[], int left, int right) {
    
    if (left < right)
    {
        int middle = (right - left) / 2 + left;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge Function
        merge(arr, left, right, middle);
    }
    
}

// quicksort

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <  high; j++) 
    {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);

        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

int main()
{
    
    int numbers[] = {10, 9, 12, 11, 8, 2, 3, 1, 4, 6, 5, 7};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    // Before Sorting
    printArray(numbers, arraySize);
    printf("\n");

    // Sorting
    // mergeSort(numbers, 0, arraySize-1);
    quickSort(numbers, 0, arraySize - 1);

    // After Sorting
    printArray(numbers, arraySize);
    return 0;
}
