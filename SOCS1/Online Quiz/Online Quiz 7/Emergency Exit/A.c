#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, N, K, temp;
    int floors = 1;

    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++)
    {
        scanf("%d %d", &N, &K);
        temp = K;
        char stairs[N];

        scanf("%s", stairs);

        for (int j = 0; j  < N; j  ++)
        {

            if (stairs[j] == '0' && floors == 1)
            {
                K--;
            } else if (stairs[j] == '1' && floors == 1){
                K = temp;
                K--;
                floors = 2;
            } else if (stairs[j] == '1' && floors == 2) {
                floors = 1;
            } else if (stairs[j] == '0' && floors == 2){
                K = temp;
            }

            if (K == 0)
            {
                break;
            }
        }

        if (K > 0)
        {
            printf("Case #%d: Alive\n", i);
        } else {
            printf("Case #%d: Dead\n", i);
        }
        
        
    }
    

    return 0;
}
