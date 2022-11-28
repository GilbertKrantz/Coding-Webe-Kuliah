#include <stdio.h>

int main(int argc, char const *argv[])
{
    char id[11];
    char name[100];
    char kelas;
    int num;

    scanf("%s\n", id);
    scanf("%[^\n]", name);
    getchar();
    scanf("%c %d", &kelas, &num);

    printf("Id\t: %s\n", id);
    printf("Name\t: %s\n", name);
    printf("Class\t: %s\n", kelas);
    printf("Num\t: %d\n", num);

    return 0;
}

