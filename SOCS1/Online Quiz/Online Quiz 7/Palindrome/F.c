#include <stdio.h>
#include <string.h>

int main() {
    int T, count;
    char string[500], revString[500], tempStr[500];

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        count = 0;
        
        for (int j = 0; j < strlen(revString); j++)
        {
            revString[j] = '\0';
        }
        

        scanf("%s", string);
    
            for (int j = 0; j < strlen(string); j++)
            {
                revString[j] = string[strlen(string) - j - 1];
            }
            
            printf("%s", revString);


            for (int j = 0; j < strlen(string); j++)
            {
                if (string[j] == revString[j])
                {
                    count++;
                }
                
            }

            if (count == strlen(string))
            {
                printf("Case #%d: Yay, it's a palindrome\n", i);
            } else {
                printf("Case #%d: Nah, it's not a palindrome\n", i);
            }
        
    }
    
    return 0;
}
