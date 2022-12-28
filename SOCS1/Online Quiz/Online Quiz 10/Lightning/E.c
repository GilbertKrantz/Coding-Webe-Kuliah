#include <stdio.h>
#include <string.h>

long long lightningCount(char string[], int size, int min, int max) {
    long long durCount = 0;
    long long lightCount = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (string[i] == '1')
        {
            durCount++;
            
            
        } else if (string[i] != '1') {
            
            if (durCount >= min && durCount <= max)
            {
                lightCount++;
            }
            durCount = 0;
        }
        
    }
    if (durCount >= min && durCount <= max)
    {
        lightCount++;
    }

    return lightCount;
    
}

int main() {
    
    FILE *fptr;
    fptr = fopen("testdata.in", "r");

    int T; //Test Cases
    fscanf(fptr, "%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int N; //Duration
        int A; //Minimum
        int B; //Maximum

        fscanf(fptr, "%d %d %d", &N, &A, &B);

        char string[N + 1];
        fscanf(fptr, "%s", string);

        printf("Case #%d: %lld\n", i, lightningCount(string, N, A, B));
    }

    fclose(fptr);
    
}