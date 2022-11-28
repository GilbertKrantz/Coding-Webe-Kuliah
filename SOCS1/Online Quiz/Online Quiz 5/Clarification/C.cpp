#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int N, sum = 0;

    scanf("%d", &N);
    getchar();

    int tc, ts, tv;

    for (int i = 0; i < N; i++)
    {
        tc = 0;
        ts = 0;
        tv = 0;

        scanf("%d %d %d", &tc, &ts, &tv);
        getchar();

        if ( ts > tv )
        {
            sum++;
        }
        
    }
    
    printf("%d\n", sum);
    

    return 0;
}
