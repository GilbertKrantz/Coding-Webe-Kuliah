#include <stdio.h>

long double factorialCalc(int N) {
    int A[N];
    long double factorial[N];
    long double sum = 1;
    
    for (int j = 0; j < N; j++)
    {
        factorial[j] = 1;
        scanf("%d", &A[j]);
        

        for (int k = 1; k <= A[j] ; k++)
        {
            factorial[j] *= k;
        }

        sum *= factorial[j];
    }

    return sum;
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
        
        long double sum =  factorialCalc(N);

        printf("Case #%d: %.0Lf\n", i, sum);
        
        
    }
    

    return 0;
}
