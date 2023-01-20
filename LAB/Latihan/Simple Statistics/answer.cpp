#include <stdio.h>

void merge(int arr[], int left, int right, int middle) {
    int tempArr[right - left];
    int leftIndex = left;
    int leftLimit = middle;
    int rightIndex = middle + 1;
    int rightLimit = right;

    int tempIndex = 0;

    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        if (arr[leftIndex] < arr[rightIndex])
        {
            tempArr[tempIndex] = arr[leftIndex];
            leftIndex++;
        } else {
            tempArr[tempIndex] = arr[rightIndex];
            rightIndex++;
        }
        
        tempIndex++;
    }
    
    while (leftIndex <= leftLimit)
    {
        tempArr[tempIndex] = arr[leftIndex];
        leftIndex++;
        tempIndex++;
    } 
    
    while (rightIndex <= rightLimit)
    {
        tempArr[tempIndex] = arr[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    tempIndex = 0;

    for (int i = left; i <= right; i++)
    {
        arr[i] = tempArr[tempIndex];
        tempIndex++;
    }
    
}

void mergeSort(int arr[], int left, int right) {
    if (left < right)
    {
        int mid = (right - left) / 2 + left;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, right, mid);
    }
    
}

double mean(int arr[], int size, int reduct) {
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }

    return total / (double)(size - reduct * 2);
    
}

int main()
{
    
    int N, K;
    scanf("%d %d", &N, &K);
    getchar();

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, N - 1);
    
    for (int i = 0; i < K; i++)
    {
        arr[i] = 0;
        arr[N - 1 - i] = 0;
    }

    printf("%.2lf", mean(arr, N, K));

    return 0;
}
