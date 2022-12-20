#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arrSize,int array[]) {
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }   
        }   
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        int arrSize;
        scanf("%d", &arrSize);
        getchar();
        
        int array[arrSize];

        for (int j = 0; j < arrSize; j++)
        {
            scanf("%d", &array[j]);
            getchar();
        }

        // Sort Array
        bubbleSort(arrSize, array);

        int checkMMR;
        scanf("%d", &checkMMR);
        getchar();
        

        if (checkMMR == array[arrSize-1])
        {
            printf("CASE #%d: %d %d\n", i, array[arrSize-2], array[arrSize-1]);
            continue;
        }

        int check = 0;
        
        for (int j = 0; j < arrSize-2; j++)
        {
            if (checkMMR == array[j])
            {
                printf("CASE #%d: %d %d\n", i, array[j], array[j + 1]);
                check = 1;
            }
        }
        
        if (check == 0)
        {
            printf("CASE #%d: -1 -1\n", i);
        }
        
        

    }
    
    return 0;
}
