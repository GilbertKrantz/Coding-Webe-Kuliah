#include <stdio.h>

int main(int argc, char const *argv[])
{
    int X[4], Y[4];

    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
    }

        for (int i = 0; i < 4; i++)
    {
        printf("%d\n", X[i] * Y[i]);
    }
    


    return 0;
}
