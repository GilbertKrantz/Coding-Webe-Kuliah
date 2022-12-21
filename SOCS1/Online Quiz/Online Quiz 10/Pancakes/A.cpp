#include <stdio.h>

void calc(int array[], int n, int i) {
    if (i <= n)
    {
        array[i] = array[i - 1] + i;
        i++;
        calc( array, n, i);
    }
    
}

int main(int argc, char const *argv[])
{
    
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int N, count = 1;
        scanf("%d", &N);

        int array[N];
        array[0] = 1;

        calc( array, N, count);

        printf("Case %d: ", i);
        for (int j = 0; j < N; j++)
        {
            if (j > 0)
            {
                printf(" ");
            }
            
            printf("%d", array[j]);
        }
        printf("\n");
        
    }
    

    return 0;
}
