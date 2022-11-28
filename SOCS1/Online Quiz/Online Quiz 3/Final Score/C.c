#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    double a, b, c, sum;
    double m1 = 0.2, m2 = 0.3, m3 = 0.5;

    scanf("%lf %lf %lf", &a, &b, &c);

    sum = a*m1 + b*m2 + c*m3;

    printf("%.2lf\n", sum);

    return 0;
}
