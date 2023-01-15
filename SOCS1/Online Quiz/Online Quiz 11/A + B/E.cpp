#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fl = fopen("testdata.in", "r");

    int A, B;
    fscanf(fl, "%d %d", &A, &B);

    printf("%d\n", A + B);
    fclose(fl);
    
    return 0;
}
