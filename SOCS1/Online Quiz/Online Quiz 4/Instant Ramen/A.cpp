#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, M, N, K;

    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d %d", &K, &M, &N);

        if ( K <= M + N )
        {
            printf("Case #%d: yes\n", i);
        } else {
            printf("Case #%d: no\n", i);
        }
        

    }
    

    return 0;
}
