#include <stdio.h>

int sum(int d, int n);
int recurSum(int d, int n);

int main(int argc, char const *argv[])
{
    int d, n;
    scanf("%d %d", &d, &n);
    getchar();

    printf("%d\n", recurSum(d, n));
    return 0;
}

// No Recursion
int sum(int d, int n)
{
    int total = 0;

    printf("%d\n", n);

    for (int i = 1; i < d; i++)
    {
        int tempTotal = 0;
        for (int j = 0; j <= n; j++)
        {
            tempTotal += j;
        }

        n = tempTotal;
        printf("%d %d\n", n, tempTotal);
    }

    for (int i = 1; i <= n; i++)
    {
        total += i;
        printf("%d ", total);
    }

    printf("\n");

    return total;
}

// With Recursion
int recurSum(int d, int n) {
    int total = 0;

    for (int i = 1; i <= n; i++)
    {
        total += i;
    }

    if (d == 1)
    {
        return total;
    }

    return recurSum(d-1, total);
}