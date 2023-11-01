#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int length;
    scanf("%d", &length); getchar();

    char str[length];
    scanf("%s", str);

    char rev[length];

    int j = 0;
    for(int i = length-1; i >= 0; i--) {
        rev[j] = str[i];
        j++;
    }

    if (strcmp(rev, str) == 0)
    {
        printf("Sama");
    } else {
        printf("beda");
    }
    
}