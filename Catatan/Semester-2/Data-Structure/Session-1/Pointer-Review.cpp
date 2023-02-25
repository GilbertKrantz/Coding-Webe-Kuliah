#include <stdio.h>

int main(int argc, char const *argv[])
{
    // * -> Get Real Value of a Pointer
    // & -> Get Address of a Variable

    // Single Pointer

    int *ptr;
    int x = 10;

    ptr = &x;

    // Double Pointer -> must be directed to Single Pointer (number of star - 1)

    int **dptr;
    dptr = &ptr;

    printf(" Address from ptr : %d\n Real Value of Address : %d\n Address from variable : %d\n Value from Double Pointer : %d\n", ptr, *ptr, &x, **dptr);

    return 0;
}
