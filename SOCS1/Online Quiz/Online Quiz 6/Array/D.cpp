#include <stdio.h>


int main(int argc, char const *argv[])
{
    int N;

    scanf("%d", &N);

    int Array[N], A[N], B[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < N; i++)
    {
        Array[A[i]] = B[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        
        printf("%d", Array[i]);
    }

    printf("\n");
    
    

    return 0;
}
