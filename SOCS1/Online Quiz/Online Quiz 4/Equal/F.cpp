#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned long long int a, b, c, d;
    unsigned long long int left, right;

    scanf("%llu %llu %llu %llu", &a, &b, &c, &d);

    left = a * b;
    right = c - d;

    if (left == right)
    {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    
    return 0;
}
