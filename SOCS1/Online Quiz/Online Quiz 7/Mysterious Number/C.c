#include <stdio.h>
#include <math.h>

int sqrtcheck(int number) {
    float floatVar;
    int intVar;

    floatVar = sqrt((double)number);
    // printf("square float is :%f\n", floatVar);
    intVar = floatVar;
    // printf("square int is :%d\n", intVar);

    if (intVar == floatVar)
        return 1;
    else
        return 0;
}

int cubecheck(int number) {
    float floatVar;
    int intVar;

    floatVar = cbrt((double)number);
    // printf("cubic float is :%f\n", floatVar);
    intVar = floatVar;
    // printf("cubic float is :%d\n", intVar);

    if (intVar == floatVar)
        return 1;
    else
        return 0;
}

int primecheck(int number) {
    int count = 0;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            count ++;
        }
    }

    if (count == 2)
    {
        return 1;
    } else
        return 0;
    
}

void main()
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int X;
        scanf("%d", &X);

        if (sqrtcheck(X) && cubecheck(X))
        {
            printf("Case #%d: square cubic\n", i);
        } else if (sqrtcheck(X))
        {
            printf("Case #%d: square\n", i);
        } else if (cubecheck(X))
        {
            printf("Case #%d: cubic\n", i);
        } else if (primecheck(X))
        {
            printf("Case #%d: prime\n", i);
        } else {
            printf("Case #%d: none\n", i);
        }
    }
}
