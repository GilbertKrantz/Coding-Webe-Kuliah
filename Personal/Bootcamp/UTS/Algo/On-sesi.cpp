#include <stdio.h>
#include <stdlib.h>

int main() {
    // int a;

    // scanf("%d", &a);

    // char string[5];
    // // BO003

    // sprintf(string, "BO%03d", a);

    // printf("%s", string);

    // Looping

    // for(int i = 0; i < a; i++) {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("%d", j);
    //     }
        
    // }


    int a = 0;
    // while (a = 0)
    // {
    //     printf("%d", a);
    // }

    // do {
    //     printf("%d", a);
    // } while (a > 0);
    
    int array[20];

    int matrix[2][2];

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        
    }

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", matrix[i][j]);
        }
        
    }

}