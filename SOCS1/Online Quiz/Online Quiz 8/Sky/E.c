#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    int matrixSize;
    scanf("%d", &matrixSize);
    getchar();

    char *matrixSky[matrixSize][matrixSize];

    for (int i = 0; i < matrixSize; i++)
    {
        scanf("%s", &matrixSky[i]);
        getchar();
    }
    
    // Vertical Flip
    int limit = matrixSize - 1;

    for (int i = 0; i < limit; i++)
    {
        char tempStr[matrixSize];
        strcpy(tempStr,  matrixSky[i]);
        strcpy(matrixSky[i] ,  matrixSky[limit]);
        strcpy(matrixSky[limit],  tempStr);\
        limit--;
    }

    // Horizontal Flip
    for (int i = 0; i < matrixSize; i++)
    {
        int lenLimit = matrixSize - 1;
        char temp, tempStr2[matrixSize];

        strcpy(tempStr2, matrixSky[i]);

        for (int j = 0; j < lenLimit; j++)
        {
            temp = tempStr2[j];  
            tempStr2[j] = tempStr2[lenLimit];  
            tempStr2[lenLimit] = temp;  
            lenLimit--;
        }
        
        strcpy(matrixSky[i], tempStr2);
    }
    

    for (int i = 0; i < matrixSize; i++)
    {
        printf("%s\n", matrixSky[i]);
    }
    
    


    return 0;
}
