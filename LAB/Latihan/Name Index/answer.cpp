#include <stdio.h>
#include <string.h>

int linearSearch (char arr[][1000], int size, char *find) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i], find) == 0)
        {
            return i;
        }
        
    }

    return -1;
    
} 

int main() {
    int N;
    scanf("%d", &N); 
    getchar();

    char name[N][1000];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", name[i]);
        getchar();
    }

    char find[1000];
    scanf("%s", find);

    printf("%d", linearSearch(name, N, find) + 1);
    
}