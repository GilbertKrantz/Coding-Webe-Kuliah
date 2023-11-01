#include <stdio.h>
#include <string.h>

int main() {
    int arrSize;

    scanf("%d", &arrSize); getchar();

    int array[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &array[i]); getchar();
    }

    int maxCount = 0;
    for (int i = 0; i < arrSize; i++)
    {
        int count = 0;
        for (int j = 0; j < arrSize; j++)
        {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (maxCount < count)
        {
            maxCount = count;
        }
        
    }

    printf("%d\n", maxCount);
    
}