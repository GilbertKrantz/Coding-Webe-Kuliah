#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        int str_len;
        scanf("%d", &str_len);
        getchar();

        char str[str_len];
        scanf("%s", str);
        getchar();

        printf("%c%c\n", str[str_len - 1], str[0]);
    }
    
    

    return 0;
}
