#include <stdio.h>

int main() {
    int testCase;
    scanf("%d", &testCase);
    getchar();

    for (int i = 0; i < testCase; i++)
    {
        int N;
        scanf("%d", &N);
        getchar();

        if (N == 1)
        {
            printf("*\n");
        } else {
            // Print Top Ceiling
            for (int j = 0; j < N; j++) printf("*");
            printf("\n");

            // Print X inside the box
            int innerRows = N-2;
            for (int j = 0; j < innerRows; j++)
            {
                printf("*");
                for (int k = 0; k < innerRows; k++)
                {
                    if ((k == j) || (k == innerRows + j + 1)) printf("*");
                    else printf(" ");
                }
                printf("*\n");
            }
            for (int j = 0; j < N; j++) printf("*");
            printf("\n");
        }
        
    }
    
}
