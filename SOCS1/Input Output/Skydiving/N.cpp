#include <stdio.h>

int main(int argc, char const *argv[])
{
    char Name1[100];
    double height1;
    int age1;

    char Name2[100];
    double height2;
    int age2;

    scanf("%s", Name1);
    scanf("%lf", &height1);
    scanf("%d", &age1);

    scanf("%s", Name2);
    scanf("%lf", &height2);
    scanf("%d", &age2);

    printf("Name 1: %s\n", Name1);
    printf("Height 1: %.2lf\n", height1);
    printf("Age 1: %d\n", age1);
    printf("Name 2: %s\n", Name2);
    printf("Height 2: %.2lf\n", height2);
    printf("Age 2: %d\n", age2);

    return 0;
}
