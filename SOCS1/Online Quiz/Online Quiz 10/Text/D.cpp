#include <stdio.h>
#include <string.h>

void rmVowels(char *string, int size) {
    char vowels[] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    int vowelArrSize = 10;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < vowelArrSize; j++)
        {
            if (string[i] == vowels[j])
            {
                for (int k = i; k < size; k++)
                {
                    string[k] = string[k+1];
                }

                size--;
                i--;
            }
            
        }
        
    }
    
}

int main() {

    int T; // Test Cases
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        char string[1010];
        scanf("%[^\n]", string);
        getchar();

        int size = strlen(string);

        rmVowels(string, size);

        printf("Case #%d: %s\n", i, string);

    }
    
}