#include <stdio.h>

int main(int argc, char const *argv[])
{

    int N, Q, H;
    
    printf("input a decimal number : ");
    scanf("%d", &N);

    while( N != 0) {
        Q = N % 16;
        N = N / 16;

        switch (Q)
        {
        case Q => 0 && Q =< 9:
            H = Q;
            break;
        
        default:
            break;
        }
    }

}
