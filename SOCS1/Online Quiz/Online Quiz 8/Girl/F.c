#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int count = 0;
        char str[10000];
        scanf("%s", str);

        for (int j = 0; j < strlen(str); j++)
        {
            for (int k = 0; k < strlen(str); k++)
            {
                if ( j < k )
                {
                    if (str[j] == str[k])
                    {
                        count++;
                    }
                }
            }
        }

        int discChar = strlen(str) - count;
        
        if (discChar % 2 == 0)
        {
            printf("Case #%d: Yay\n", i);
        } else {
            printf("Case #%d: Ewwww\n", i);
        }
        
        
    }
    

    return 0;
}
