#include <stdio.h>

int prime(int num) {
    int flag = 1; 
  
    // loop to iterate through 2 to N/2 
    for (int i = 2; i <= num / 2; i++) { 
  
        // if num is perfectly divisible by i 
        // flag is set to 0 i.e false 
        if (num % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
    return flag; 
}

int square(int num) {
    for (int i = 1; i < num; i++)
    {
        if (i * i == num)
        {
            return 1;
        }
        
    }
    return 0;
}

int cubic(int num) {
    for (int i = 1; i < num; i++)
    {
        if (i * i * i == num)
        {
            return 1;
        }
        
    }
    return 0;
}

int main() {
    int testCase;
    scanf("%d", &testCase); getchar();

    for (int i = 1; i <= testCase; i++)
    {
        int num;
        scanf("%d", &num); getchar();

        printf("Case #%d : ", i);
        if (prime(num))
        {
            printf("prime\n");
        } else if (square(num) || cubic(num))
        {
            if (square(num))
            {
                printf("square");
            }

            if (cubic(num))
            {
                if (square(num))
                {
                    printf(" ");
                }
                printf("cubic");
            }
            printf("\n");
        } else {
            printf("none\n");
        }
        
        
    }
    
}