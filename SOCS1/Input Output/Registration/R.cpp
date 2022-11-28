#include <stdio.h>

int main(int argc, char const *argv[])
{
    char id[100];
    char name[100];
    char kelas[100];
    int num;

    scanf("%s\n", id);
    scanf("%[^\n]", name);
    getchar();
    scanf("%s %d", &kelas, &num);

    printf("Id    : %s\n", id);
    printf("Name  : %s\n", name);
    printf("Class : %s\n", kelas);
    printf("Num   : %d\n", num);

    return 0;
}
