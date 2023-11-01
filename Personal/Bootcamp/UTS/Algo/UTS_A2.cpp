#include <stdio.h>
#include <string.h>

int main() {
    char string[255];
    scanf("%s", string);

    int count = 0;
    int index = 0;
    char unique[255] = "";

    for (int i = 0; i < strlen(string); i++){
         bool appears = false;
         for (int j = 0; j < i; j++){
              if (string[j] == string[i]){
                  appears = true;
                  break;
              }
         }


         if (!appears){
            count++;
            unique[index] = string[i];
            index++;
         }

        
    }

    printf("%s\n", unique);

    int uniqueCount[count] = {0};

    for (int i = 0; i < count; i++)
    {
        int uniqueCounter = 0;
        for (int j = 0; j < strlen(string); j++)
        {
            if (unique[i] == string[j])
            {
                uniqueCounter++;   
            }
            
        }
        uniqueCount[i] = uniqueCounter;
        
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c %d\n", unique[i], uniqueCount[i]);
    }

    for (int i = 0; i < count; i++)
    {
        int difference = 0;
        printf("%c ", unique[i]);
        for (int j = 0; j < count; j++)
        {
            if (uniqueCount[i] != uniqueCount[j])
            {
                printf("%d", uniqueCount[j]);
                difference = uniqueCount[i] - uniqueCount[j];
            }
            printf("%d ", difference);
            
        }
        printf("\n");
        
    }
    
}