#include <stdio.h>

int main(int argc, char const *argv[])
{
    int A, B, C;
    float D;

    scanf("%d %d", &A, &B);

    C = A - B;
    D = (float)C / A;

    printf("%.4f%\n", D*100);

    return 0;
}
