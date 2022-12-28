#include <stdio.h>
#include <string.h>

int changeChar(char *string, int size, char initChar, char afterChar) {
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (string[i] == initChar)
        {
            string[i] = afterChar;
            count++;
        }
        
    }

    return count;
    
}

int main() {
    
    FILE *fptr;
    
    fptr = fopen("testdata.in", "r");

    int T; //Test Cases
    fscanf(fptr, "%d", &T);

    for (int i = 1; i <= T; i++)
    {
        char string[110];
        fscanf(fptr, "%s", string);
        
        int size = strlen(string);

        int N; //Number of Changes
        fscanf(fptr, "%d", &N);

        char initChar;
        char afterChar[N];
        int M[N];
        
        for (int j = 0; j < N; j++)
        {
            fscanf(fptr, "%s %s", &initChar, &afterChar[j]);

            M[j] = changeChar(string, size, initChar, afterChar[j]);
            
        }

        for (int j = N - 1; j >= 0; j--)
        {
            printf("%c %d\n", afterChar[j], M[j]);
        }
        
        
    }
    
}