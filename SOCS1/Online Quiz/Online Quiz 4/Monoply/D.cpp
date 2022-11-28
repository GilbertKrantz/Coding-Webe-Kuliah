#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int N;
   

    scanf("%d", &N);
    int k[N];
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &k[i]);
        total += k[i];
        if (total == 30)
        {
            total = 10;
        } else if (total == 12)
        {
            total = 28;
        } else if (total == 35)
        {
            total = 7;   
        } else if (total >= 40)
        {
            total -= 40;
        }
        
    }
    printf("%d\n", total);

    return 0;
}
