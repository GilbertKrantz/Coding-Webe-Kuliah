#include <stdio.h>

int main()
{
    // Pointer Fundamentals
    int x = 5;
    int *ptr = &x;

    printf("%d\n", *ptr);

    char y = 'y';
    char *px = &y;

    printf("%c\n", *px);

    // Array (Array is a Pointer)
    int nums[5] = {1, 2, 3, 4, 5};
    printf("%d\n", nums[0]); // Shortcut to Access Array
    printf("%d\n", nums);
    printf("%d\n", &nums[0]);
    printf("%d\n", *(nums + 1));
    return 0;
}
