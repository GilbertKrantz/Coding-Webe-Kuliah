#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    float total1, total2, total3;

    scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
    scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
    scanf("%d %d %d %d", &a3, &b3, &c3, &d3);

    total1 = ((a1 / 1) * 2) + ((b1 / 2) * 4) + ((c1 / 3) * 6) + ((d1 / 4) * 4);
    total2 = ((a2 / 1) * 2) + ((b2 / 2) * 4) + ((c2 / 3) * 6) + ((d2 / 4) * 4);
    total3 = ((a3 / 1) * 2) + ((b3 / 2) * 4) + ((c3 / 3) * 6) + ((d3 / 4) * 4);

    printf("%.2f\n", total1);
    printf("%.2f\n", total2);
    printf("%.2f\n", total3);

    return 0;
}
