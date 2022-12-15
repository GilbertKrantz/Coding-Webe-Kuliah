#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        double num, sum, limit; 
        int powerCount = 0;

        scanf("%lf %lf", &num, &limit);
        sum = num;

        while (sum <= limit)
        {
            powerCount++;
            sum *= num;
        }
        
        printf("Case #%d: %d\n", i, powerCount);
    }
    

    return 0;
}
