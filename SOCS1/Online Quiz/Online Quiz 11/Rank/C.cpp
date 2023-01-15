#include <stdio.h>
#include <string.h>

struct a
{
    char name[11];
    int nilai;
} data[1010];


int searchName(a arr[], int size, char *findName) {
    int searchNum;
    
    for (int i = 0; i < size; i++)
    {
        if (strcmp(findName, arr[i].name) == 0)
        {
            searchNum = arr[i].nilai;
        }
        
    }

    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (searchNum < arr[i].nilai)
        {
            count++;
        }
        else if (searchNum == arr[i].nilai) {
            if (strcmp(findName, arr[i].name) > 0)
            {
                count++;
            }
        }
        
    }
    
    return count;
}

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
            scanf("%[^#]#%d", data[j].name, &data[j].nilai);
            getchar();
        };
        
        char nameSearch[11];
        scanf("%s", nameSearch);
        getchar();


        

        printf("Case #%d: %d\n", i, searchName(data, M, nameSearch));
    }
    
}
