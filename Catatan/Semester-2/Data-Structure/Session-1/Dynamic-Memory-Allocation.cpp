#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Single Value
    int *ptr = (int*) malloc(sizeof(int));

    *ptr = 100;

    printf("Value of Pointer : %d\n\n", *ptr);

    free(ptr);

    // Array

    int *aptr = (int*) malloc(5 * sizeof(int));
    aptr[0] = 10;
    aptr[1] = 20;
    aptr[2] = 30;
    aptr[3] = 40;
    aptr[4] = 50;

    printf("Value of an Array from Pointer\n");

    // Ways to print an Array
    for (int i = 0; i < 5; i++)
        printf("%d ", aptr[i]);
    printf("\n");

    for (int i = 0; i < 5; i++)
        printf("%d ", *(aptr + i));
    printf("\n\n");

    free(aptr); 

    // Double Pointer

    int **dptr;

    dptr = &aptr;

    printf("%d\n", **dptr);

    return 0;
}
