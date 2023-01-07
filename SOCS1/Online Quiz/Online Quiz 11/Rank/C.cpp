#include <stdio.h>

struct a
{
    char name[11];
    int nilai;
} data[1010];

int main() {
    int T;// Test Case
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        int M;
        scanf("%d", &M);
        getchar();

        for (int j = 0; j < M; j++)
        {
            scanf("%s#%d", data[j].name, &data[j].nilai);
        };
        
        char nameSearch[11];
        scanf("%s", nameSearch);
        getchar();
        
    }
    
}
