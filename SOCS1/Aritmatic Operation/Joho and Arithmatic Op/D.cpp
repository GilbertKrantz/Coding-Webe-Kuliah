#include <stdio.h>

int main() {

    int N;
    int M;

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i <= M; i++)
    {
        printf("%d\n", N);
        N++;
    }
    

}