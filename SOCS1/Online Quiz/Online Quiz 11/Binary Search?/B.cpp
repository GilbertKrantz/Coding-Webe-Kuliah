#include <stdio.h>

int main() {
    int T; //Test Cases
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        double M;
        scanf("%lf", &M);
        getchar();

        double N = 0;
        double sumInt = 0;
        do
        {
            N++;
            sumInt = (N * (N + 1) * (2*N + 1)) / 6;
        } while (sumInt < M);
        
        if (M == 1)
        {
            printf("Case #%d: 1\n", i);
        } else {
            printf("Case #%d: %.0lf\n", i, N);
        }
        
    }
    
}