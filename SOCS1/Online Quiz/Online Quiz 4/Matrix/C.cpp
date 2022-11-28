#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int T, N;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        int num[2][N][N];
        int totmat1[N][N];
        int totmat2[N][N];
        for (int M = 0; M < 3; M++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    scanf("%d", &num[M][j][k]);
                }
            }
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                totmat1[j][k] = 0;
                for (int l = 0; l < N; l++)
                {
                    totmat1[j][k] += num[0][j][l] * num[1][l][k];
                }
                
            }
            
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                totmat2[j][k] = 0;
                for (int l = 0; l < N; l++)
                {
                    totmat2[j][k] += totmat1[j][l] * num[2][l][k];
                }
                
            }
            
        }
        
        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                printf("%d ", totmat2[j][k]);
            }
            printf("\n");
        }
        printf("\n");
        
    }
    

    return 0;
}
