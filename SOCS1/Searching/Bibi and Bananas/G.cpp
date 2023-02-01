#include <stdio.h>

int linearSearch(int arr[], int size, int find) {
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= find)
        {
            count++;
        }
        
    }

    return count;
    
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        int N, K;
        scanf("%d %d", &N, &K);
        getchar();

        int A[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[j]);
        }
        
        printf("Case #%d: %d\n", i, linearSearch(A, N, K));
    }
    
}