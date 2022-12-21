#include <stdio.h>

int binarySearch(int arr[], int left, int right, int find) {
    if (right >= left) 
    {
        int mid = left + (right - left) / 2;

        // Ideal Condition and Recursion Break Point
        if (arr[mid] == find)
        {
            return mid;
        }

        if (arr[mid] > find)
            return binarySearch(arr, left, mid-1, find);
        else 
            return binarySearch(arr, mid+1, right, find);    
    }

    return -1;
    
}

    int main()
    {
        // Array must be sorted to perform Binary Search
        int arr[] = {1, 3, 5, 8, 13, 22, 55, 65};
        int size = sizeof(arr) / sizeof(arr[0]);

        int find;
        scanf("%d", &find);
        getchar();

        int result = binarySearch(arr, 0, size - 1, find);

        if(result == -1)
            printf("%d was not found!\n", find);
        else
            printf("%d was found in %d\n", find, result);
        return 0;
    }