#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[100];
    char NIM[8];
    int age;

    scanf("%[^\n]", name);
    getchar();
    scanf("%s", &NIM);
    scanf("%d", &age);

    printf("Name: %s\n", name);
    printf("NIS: %s\n", NIM);
    printf("Age: %d\n",age);
    

    return 0;
}
