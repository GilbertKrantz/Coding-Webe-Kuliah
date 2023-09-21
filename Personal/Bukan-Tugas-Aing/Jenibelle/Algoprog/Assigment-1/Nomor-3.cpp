#include <stdio.h>
#include <string.h>

int main() {

    int T;
    scanf("%d", &T); getchar();

    for (int i = 1; i <= T; i++)
    {
        int N;
        int j = 0;
        char binary[1000];
        scanf("%d", &N); getchar();

        while (N >= 1)
        {
            sprintf(&binary[j], "%d", N % 2);
            N /= 2;
            j++;
        }
        
        strrev(binary);
        printf("Case #%d: %s\n", i, binary);
    }
    
    return 0;
}
