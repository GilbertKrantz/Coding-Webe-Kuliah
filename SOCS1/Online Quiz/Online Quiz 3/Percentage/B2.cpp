#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int T, N;
    float P, ans;
    
    scanf("%d", T);

    for (int i = 0; i < 3; i++) {
        scanf("%f %d", &P, &N);

        ans = (P/100) * N;

        printf("%.2f\n", ans);
	}
     

    return 0;
}
