#include <stdio.h>

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int a[60], j;
        unsigned long long int N;

        scanf("%llu", &N);

        for (j = 0; N > 0; j++)
        {
            a[j] = N % 2;
            N = N / 2;
        }

        printf("Case #%d: ", i);

        for (j = j - 1; j >= 0; j--)
        {
            printf("%d", a[j]);
        }

        printf("\n");
        
    }
    
    return 0;
}
