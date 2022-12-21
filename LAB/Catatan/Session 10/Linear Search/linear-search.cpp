#include <stdio.h>

int linearSearch(int arr[], int size, int find) {

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == find)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    
    int arr[] = {2, 1, 5, 13, 74, 19, 7, 65};
    int size = sizeof(arr) / sizeof(arr[0]);

    int find;
    scanf("%d", &find);
    getchar();

    int result = linearSearch(arr, size, find);

    if(result == -1)
        printf("%d was not found!\n", find);
    else
        printf("%d was found in %d\n", find, result);
    return 0;
}
