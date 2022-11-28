#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T;
    int A[3];
    float R[3];
    float K[3];
    float F[3];

    scanf("%d", &T);

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        R[i] = 0.8 * A[i];
        F[i] = (1.8 * A[i]) + 32;
        K[i] = A[i] + 273;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%.2f %.2f %.2f\n", R[i], F[i], K[i]);
    }
    
    
    
    return 0;
}
