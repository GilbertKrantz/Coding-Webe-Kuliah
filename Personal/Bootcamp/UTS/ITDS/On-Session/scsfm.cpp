#include <stdio.h>

int main() {
    int Length;
    scanf("%d", &Length); getchar();

    int indexArray[Length];
    for (int i = 0; i < Length; i++) {
        scanf("%d", &indexArray[i]);
    }

    int Array[Length];
    for (int i = 0; i < Length; i++)
    {
        scanf("%d", &Array[indexArray[i]]);
    }

    // Print
    for (int i = 0; i < Length; i++)
    {
        if (i > 0) printf(" ");
        printf("%d", Array[i]);
        
    }
    printf("\n");
    
}