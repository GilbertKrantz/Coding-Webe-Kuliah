#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int numOfRow, numOfCol, numOfQueries;
    scanf("%d %d %d", &numOfRow, &numOfCol, &numOfQueries);
    getchar();

    int matrix[numOfRow][numOfCol];

    for (int i = 0; i < numOfRow; i++)
    {
        for (int j = 0; j < numOfCol; j++)
        {
            matrix[i][j] = 0;
        }
        
    }
    

    for (int i = 0; i < numOfQueries; i++)
    {
        int matrixRowIndex, matrixColIndex, changes;
        scanf("%d %d %d", &matrixRowIndex, &matrixColIndex, &changes);
        getchar();
        matrix[matrixRowIndex][matrixColIndex] = changes;
    }

    for (int i = 0; i < numOfRow; i++)
    {
        for (int j = 0; j < numOfCol; j++)
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
