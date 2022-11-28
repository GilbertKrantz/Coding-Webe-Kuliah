#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, A, B, C;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        if (A <= B && B <= C)
        {
            if (A + B > C)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        } else if (A <= C && C <= B)
        {
            if (A + C > B)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        } else if (B <= A && A <= C)
        {
            if (B + A > C)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        } else if (B <= C && C <= A)
        {
            if (B + C > A)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        } else if (C <= A && A <= B)
        {
            if (C + A > B)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        } else if (C <= B && B <= A)
        {
            if (C + B > A)
            {
                printf("BISA\n");
            } else {
                printf("TIDAK BISA\n");
            }
        }
    }
    

    return 0;
}
