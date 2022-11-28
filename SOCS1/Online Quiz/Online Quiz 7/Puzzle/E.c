#include <stdio.h>

void main()
{
    int N, checker = 0;

    scanf("%d", &N);

    int matrix[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < N; l++)
            {
                if (j == l)
                {
                    break;
                } else {
                    if (matrix[i][j] == matrix[i][l])
                    {
                        checker++;
                    }

                    if (matrix[j][i] == matrix[l][i])
                    {
                        checker++;
                    }
                }
                
            }
        }
    }

    if (checker > 0)
    {
        printf("Nay\n");
    } else {
        printf("Yay\n");
    }
    
    
}
