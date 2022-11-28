#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, Q;

    scanf("%d", &N);

    int views[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &views[i]);
    }

    scanf("%d", &Q);

    int A, B;
    int total = 0;

    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &A, &B);
        total = 0;

        for (int j = A; j <= B; j++)
        {
            total += views[j-1];
        }

        printf("Case #%d: %d\n", i+1, total);
    }
    
    
    

    return 0;
}
