#include <stdio.h>
#include <string.h>

int main() {
    int a = 10;

    char str[3];
    sprintf(str, "D%d", a);
    printf("%s", str);
}