#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int num;
} data;

void merge(data arr[], int left, int right, int middle) {
    data tempArr[right - left];
    int leftIndex = left;
    int leftLimit = middle;
    int rightIndex = middle + 1;
    int rightLimit = right;

    int tempIndex = 0;

    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        if (arr[leftIndex].num < arr[rightIndex].num)
        {
            tempArr[tempIndex++] = arr[leftIndex++];
        } else {
            tempArr[tempIndex++] = arr[rightIndex++];
        }
        // printf("%s %d %d\n", tempArr[tempIndex].name, tempArr[tempIndex].num, tempIndex);
    }


    while (leftIndex <= leftLimit)
    {
        tempArr[tempIndex++] = arr[leftIndex++];
    }

    while (rightIndex <= rightLimit)
    {
        tempArr[tempIndex++] = arr[rightIndex++];
    }

    for (tempIndex = 0; tempIndex <= right - left; tempIndex++)
    {
        arr[tempIndex + left] =  tempArr[tempIndex];
    }
}

void mergeSort(data arr[], int left, int right) {
    if (left < right)
    {
        int mid = (right - left) / 2 + left;
        // printf("%d %d %d\n", left, right, mid);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, right, mid);
    }
    
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    data arr[N];

    int numArr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%s %d", arr[i].name, &arr[i].num);
        // scanf("%d", &arr[i].num);
        getchar();
    }

    mergeSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", arr[i].name, arr[i].num);
        // printf("%d\n", arr[i].num);
    }
    
    return 0;
}
