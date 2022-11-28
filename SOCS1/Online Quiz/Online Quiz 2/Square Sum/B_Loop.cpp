#include <stdio.h>

int main()
{
    int a[3], b[3], c[3], d[3];
    long double answer[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        answer[i] = (((float)a[i] / 1) * 2) + (((float)b[i] / 2) * 4) + (((float)c[i] / 3) * 6) + (((float)d[i] / 4) * 4);

        printf("%.2Lf\n", answer[i]);
    }
    
    return 0;
}

