#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int N, totalPosibility;

    scanf("%d", &N);

    N++;

    for (int i = 0; i < (N); i++)
    {
        totalPosibility = 2 * (N);
    }

    printf("%d\n", totalPosibility - 1);
    

    return 0;
}
