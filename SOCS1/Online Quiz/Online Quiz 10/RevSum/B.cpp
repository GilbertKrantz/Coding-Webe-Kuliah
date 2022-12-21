#include <stdio.h>

long long reverser(long long number) {
    int lastDigit; 
    long long reversed = 0;
    while (number > 0)
    {
        lastDigit = number % 10;
        reversed = (reversed * 10) + lastDigit;

        number /= 10;
    }

    return reversed;
    
}

int main(int argc, char const *argv[])
{
    
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        long long number1;
        scanf("%lld", &number1);

        long long revNum = reverser(number1);

        long long sum = number1 + revNum;

        printf("Case #%lld: %lld\n", i, sum);
    }
    

    return 0;
}
