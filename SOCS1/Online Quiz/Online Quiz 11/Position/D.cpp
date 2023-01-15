#include <stdio.h>

int binarySearch(int arr[], int left, int right, int find) {

    if (find == arr[left])
    {
        return left + 1;
    }

    if (right >= left) 
    {
        int mid = left + (right - left) / 2;

        // Ideal Condition and Recursion Break Point
        if (arr[mid] == find)
        {
            return mid + 1;
        }

        if (arr[mid] > find)
            return binarySearch(arr, left, mid-1, find);
        else 
            return binarySearch(arr, mid+1, right, find);    
    }

    return -1;
    
}

int linearSearch(int *arr, int size, int find) {
    for (int i = 0; i < size; i++)
    {
        if (find == arr[i])
        {
            return i + 1;
        }
        
    }

    return -1;
    
}

int checkArr(int *arr, int size) {

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[j] = -1;
            }
            
        }
        
    }
    
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();

    int numArr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numArr[i]);
        getchar();
    }

    checkArr(numArr, N);
    

    int searchArr[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &searchArr[i]);
        getchar();
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d\n", binarySearch(numArr, 0, N-1, searchArr[i]));
    }


    return 0;
}
