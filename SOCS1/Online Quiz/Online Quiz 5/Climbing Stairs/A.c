#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int N;

    scanf("%d", &N);

    int A[N];

    int c, a;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        if ( A[i] >= A[i+1])
        {
            c = A[i];
            if (a > 0)
            {
                printf(" ");
            }
            

            printf("%d", c);
            a++;;
        }
    
    } 

    printf("%d", A[N]);  
    
    
    return 0;
}
