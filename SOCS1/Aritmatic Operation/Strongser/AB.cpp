#include <stdio.h>

int main(int argc, char const *argv[])
{
    float n;
    int a = 100;
    int b = 50;

    scanf("%f", &n); 

    unsigned long long int total = n/2 * (2 * a + ((n-1) * b));
        
    printf("%llu\n", total);
}
