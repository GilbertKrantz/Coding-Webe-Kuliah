#include <stdio.h>

int main(int argc, char const *argv[])
{
    char courseCode[5][10];
    int HH1[5], MM1[5], HH2[5], MM2[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%s %02d:%02d-%02d:%02d", courseCode[i], &HH1[i], &MM1[i], &HH2[i], &MM2[i]); 

        HH1[i]--;
        HH2[i]--;

        printf("%s %02d:%02d-%02d:%02d\n", courseCode[i], HH1[i], MM1[i], HH2[i], MM2[i]); 
    }

    

    return 0;
}
