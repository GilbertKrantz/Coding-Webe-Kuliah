#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int count = 0, j, k;
        char str[1000000];
        scanf("%s", str);

        for (j = 0; j < strlen(str); j++)
        {
            for (k = 0; k < j; k++)
            {
                if (str[j] == str[k])
                {
                    break;
                }
            }

            if ( j == k ) {
                count++;
            }
        }

        if (count % 2 == 0)
        {
            printf("Case #%d: Yay\n", i);
        } else {
            printf("Case #%d: Ewwww\n", i);
        }
        
        
    }
    

    return 0;
}
