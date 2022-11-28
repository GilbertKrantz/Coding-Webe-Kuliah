#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int T, N[3];
    double P[3], ans[3];

    scanf("%d", &T);

    for (int i = 0; i < 3; i++)
    {
        scanf("%lf %d", &P[i], &N[i]);

        ans[i] = (P[i]/100) * N[i];

    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("%.2lf\n", ans[i]);
    }
    

    return 0;
}
