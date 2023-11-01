#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int aan[N];
    int kenken[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &aan[i]);
        scanf("%d", &kenken[i]);
    }

    int aanTotal = 0;
    int kenkenTotal = 0;

    if (N % 2 == 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (i % 2 != 0)
            {
                aanTotal = aanTotal + aan[i] + 2000;
            } else {
                aanTotal += aan[i];
            }
            kenkenTotal += kenken[i];
        }
        
    } else {
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                aanTotal = aanTotal + aan[i] + 2500;
            } else {
                aanTotal += aan[i];
            }
            kenkenTotal += kenken[i];
        }
    }
    
    if (kenkenTotal >= aanTotal)
    {
        printf("kenken\n");
    } else {
        printf("aan\n");
    }
    
    
}