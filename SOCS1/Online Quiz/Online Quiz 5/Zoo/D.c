#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int cage;
    int animals;

    scanf("%d", &cage);

    int animal[cage];

    for (int i = 0; i < cage; i++)
    {
        scanf("%d", &animal[i]);
    }

    for (int i = 0; i < cage; i++)
    {
        animals += animal[i];
    }
    
    printf("%d\n", animals);

    

    return 0;
}
