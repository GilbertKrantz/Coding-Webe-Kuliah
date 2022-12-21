#include <stdio.h>

int main(int argc, char const *argv[])
{
    double pi = 3.14;

    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int R, H;
        scanf("%d %d", &R, &H);

        double surfArea = 2 * pi * R * ( R + H );

        printf("Case #%d: %.02lf\n", i, surfArea);
    }
    

    return 0;
}
