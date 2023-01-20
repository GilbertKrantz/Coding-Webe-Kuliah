#include <stdio.h>

int main () {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    getchar();

    if ((a * b) == (c + d))
    {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
    
}