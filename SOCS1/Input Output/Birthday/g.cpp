#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    char Name[100];

    scanf("%[^\n]", Name);
    getchar();
    printf("Happy Birthday to %s.\n", Name);

    return 0;
}
