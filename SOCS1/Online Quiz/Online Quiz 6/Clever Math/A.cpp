#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int T;
    unsigned long long int A, B, C, temp1, temp2, tempSum, sum, count;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%llu %llu", &A, &B);
        sum = 0;
        tempSum = 0;
        count = 0;

        // if (B > A)
        // {
        //     C = A;
        //     A = B;
        //     B = C;
        // }
        do
        {
           do
            {
                temp1 = A % 10;
                A /= 10;

                temp2 = B % 10;
                B /= 10;

                tempSum = temp1 + temp2;

                if (tempSum >= 10)
                {
                    tempSum %= 10;
                }

                for (int j = 0; j < count; j++)
                {
                    tempSum *= 10;
                }

                sum += tempSum;
                
                count++;
            
            } while (A != 0); 
        } while (B != 0);
        

        printf("Case #%d: %llu\n", i, sum);
    }
    
    return 0;
}
