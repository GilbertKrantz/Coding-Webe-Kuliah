#include <stdio.h>
#include <string.h>

int CountUniqueCharacters(char* str){
    int count = 0; // set count as 0

    int index = 0;
    char unique[255] = "";

    for (int i = 0; i < strlen(str); i++){
         bool appears = false;
         for (int j = 0; j < i; j++){
              if (str[j] == str[i]){
                  appears = true;
                  break;
              }
         }


         if (!appears){
             count++;
             unique[index] = str[i];
             index++;
         }

        
    }

    printf("%s", unique);
    return count;
}

int main() {
    int Testcase;
    scanf("%d", &Testcase);

    for (int i = 1; i <= Testcase; i++)
    {
        char string[255];
        
        scanf("%s", string);

        printf("%d\n", CountUniqueCharacters(string));

        int strLength = strlen(string);

        int index = 0;
        char uniqueChar[255] = "";
        for (int j = 0; j < strLength; j++)
        {
            int found = 0;
            for (int k = 0; k < j; k++)
            {
                if (string[j] != string[k])
                {
                    found = 1;
                    break;
                }
                
            }

            if (found == 0)
            {
                printf("%c", string[j]);
            }
            
        }

        printf("%s", uniqueChar);
        
    }
    
}