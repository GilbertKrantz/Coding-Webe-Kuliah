#include <stdio.h>

int interpolationSearch(int arr[], int size, int find) {
    int left = 0;
    int right = size - 1;

    while(right >= left && find >= arr[left] && find <= arr[right]) {
        if (right == left)
        {
            if (arr[left] == find)
            {
                return left;
            }
            return -1;
        }

        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (find - arr[left]);

        if (arr[pos] == find)
            return pos;

        if (arr[pos] > find)
            right = pos - 1;
        else
            left = pos + 1;
    } 
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 13, 22, 55, 65};
    int size = sizeof(arr) / sizeof(arr[0]);

    int find;
    scanf("%d", &find);
    getchar();

    int result = interpolationSearch(arr, size, find);

    if(result == -1)
        printf("%d was not found!\n", find);
    else
        printf("%d was found in %d\n", find, result);
    return 0;
}