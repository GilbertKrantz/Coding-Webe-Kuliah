#include <stdio.h>

void main() {
    int N, count = 0;
    scanf("%d", &N);

    int roomWant[N];
    int doubleRoom[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &roomWant[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                break;
            } else if (roomWant[i] == roomWant[j])
            {
                if (roomWant[i] == doubleRoom[i])
                {
                    break;
                } else {
                    count++;
                }
                doubleRoom[i] = roomWant[j];
            }
        }
        
    }
    
    printf("%d\n", N - count);
    
}