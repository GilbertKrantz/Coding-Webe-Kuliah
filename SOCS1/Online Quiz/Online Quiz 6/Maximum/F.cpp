#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long int T, N;
    
    scanf("%lld", &T);

    for (int i = 1; i <= T; i++)
    {
        int max[2] = {0}, absMax = 0, check = 0;
        scanf("%lld", &N);
        
        int V[N+1] = {0};

        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &V[j]);
        }

        for (int l = 0; l < N; l++)
        {
            if (V[l] > max[0])
            {
                max[0] = V[l];
            }
        }

        for (int j = 0; j < N; j++)
        {
            if (V[j] == max[0] && check == 0)
            {
                V[j] = 0;
                check = 1;
            }
            

            if (V[j] > max[1])
            {
                max[1] = V[j];
            }
        }
        
        
        absMax = max[0] + max[1];
        
        printf("Case #%lld: %lld\n", i, absMax);
    }
    

    return 0;
}
