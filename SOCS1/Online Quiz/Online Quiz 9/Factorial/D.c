#include <stdio.h>

const int buffer = 1000000007;

long long factorialCalc(int n) {
    if(n >= 2)
        return (n * factorialCalc(n - 1)) % buffer;
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    int T; // Test Cases
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        int N;
        scanf("%d", &N);
        getchar();

        long long int sum = 1;

        for (int j = 0; j < N; j++)
        {
            int n;
            scanf("%d", &n);
            getchar();

            sum *= factorialCalc(n);
            sum %= buffer;
        }
        


        printf("Case #%d: %lld\n", i, sum);
        
        
    }
    

    return 0;
}
