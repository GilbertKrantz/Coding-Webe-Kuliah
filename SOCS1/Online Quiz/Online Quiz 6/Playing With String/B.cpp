#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int T, M;
    char string[1000], char1, char2;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%s", string);
        getchar();
        scanf("%d", &M);
        getchar();

        for (int j = 0; j < M; j++)
        {
            scanf("%c", &char1);
            getchar();
            scanf("%c", &char2);
            getchar();

            for (int l = 0; l < strlen(string); l++)
            {
                if (string[l] == char1)
                {
                    string[l] = char2;
                }
            }
            
        }

        printf("Case #%d: %s\n", i, string);
    }
    

    return 0;
}
