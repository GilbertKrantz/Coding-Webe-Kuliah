#include <stdio.h>

int main(int argc, char const *argv[])
{

    char ans;
    
    printf("6 * 3 = ?\n");
    printf("a. 18\n");
    printf("b. 19\n");
    printf("c. 21\n");

    printf("Answer = ");
    scanf("%c", &ans);

    switch (ans)
    {
    case 'a':
        printf("Kamu Hebat!");
        break;
    
    default:
        printf("Semangat ayok coba lagi!");
    }


    return 0;
}
