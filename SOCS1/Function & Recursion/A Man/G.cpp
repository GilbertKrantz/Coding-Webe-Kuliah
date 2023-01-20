#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int revStr(char string[], int size) {
    char newStr[size];

    for (int i = 0; i < size; i++)
    {
        newStr[i] = string[size - i - 1];
    }

    if (strcmp(newStr, string) == 0)
    {
        return 1;
    }
    
    return 0;
}

int main() {

    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        char string[1010];
        scanf("%s", string);
        getchar();

        int size = strlen(string);

        if(revStr(string, size) == 1)
            printf("Case #%d: yes\n", i);
        else 
            printf("Case #%d: no\n", i);

    }
    

    return 0;
}