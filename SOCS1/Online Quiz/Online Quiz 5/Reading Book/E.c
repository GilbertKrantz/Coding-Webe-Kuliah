#include <stdio.h>
#include <math.h>
#include <conio.h>z

int main()
{
    
    unsigned long long int  T, X, N, Y, A, B;

    scanf("%llu", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%llu %llu", &N, &X);

        A = (N - X) / 2;
        B = (X - 1) / 2;

        if ( X ==  1 || X == N)
        {
            Y = 0;
        } else if (X == 2)
        {
            Y = 1;
        } else if ( N % 2 == 0 && X >= N/2)
        {
            if (X % 2 != 0) {
                X--;
            }
            Y = (N - X) / 2;
        } else if ( N % 2 == 0 && X <= N/2)
        {
            if (X % 2 != 0) {
                X--;
            }
            Y = X / 2;
        } else if ( N % 2 != 0 && X >= N/2)
        {
            if (X + 1 == N)
            {
                Y = 0;
            }

            N++;
            
            if (X % 2 != 0) {
                X--;
            }
            Y = (N - X) / 2;
        } else {
            if (X + 1 == N)
            {
                Y = 0;
            }
            
            if (X % 2 != 0) {
                X--;
            }
            Y = X / 2;
        }

        printf("Case #%llu: %llu\n", i, Y);
        
        
        
    }
    

    return 0;
}
