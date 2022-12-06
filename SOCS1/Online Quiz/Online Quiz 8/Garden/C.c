#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int arrHeight, arrWidth;
    scanf("%d %d", &arrHeight, &arrWidth);
    getchar();

    int matrix[arrHeight][arrWidth];

    for (int i = 0; i < arrHeight; i++)
    {
        for (int j = 0; j < arrWidth; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    getchar();

    int numOfChanges;
    scanf("%d", &numOfChanges);
    getchar();

    for (int i = 0; i < numOfChanges; i++)
    {
        int arrHeightIndex, arrWidthIndex, changes;
        scanf("%d %d %d", &arrHeightIndex, &arrWidthIndex, &changes);
        getchar();
        matrix[arrHeightIndex - 1][arrWidthIndex - 1] = changes;
    }

    for (int i = 0; i < arrHeight; i++)
    {
        for (int j = 0; j < arrWidth; j++)
        {
            if( j > 0 ) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}
