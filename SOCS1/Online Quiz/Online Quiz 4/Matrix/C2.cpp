#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, N;
    char c = ' ';

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        int matrix1[N][N];
        int matrix2[N][N];
        int matrix3[N][N];
        int total1[N][N];
        int total2[N][N];

        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < N; l++)
            {
                scanf("%d", &matrix1[k][l]);
            }    
        }
        
        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < N; l++)
            {
                scanf("%d", &matrix2[k][l]);
            }     
        }

        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < N; l++)
            {
                scanf("%d", &matrix3[k][l]);
            }
        }
        
        // MATRIX CALCULATION //
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    total1[j][k] = 0;
                    for (int l = 0; l < N; l++)
                    {
                        total1[j][k] += matrix1[j][l] * matrix2[l][k];
                    }
                
                }
            
            }
        
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    total2[j][k] = 0;
                    for (int l = 0; l < N; l++)
                    {
                        total2[j][k] += total1[j][l] * matrix3[l][k];
                    }
                
                }
            
            }


        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if ( k > 0 ) {
                    putchar(c);
                } 
                printf("%d", total2[j][k]);
            }
            printf("\n");
        }

    }
    

    return 0;
}
