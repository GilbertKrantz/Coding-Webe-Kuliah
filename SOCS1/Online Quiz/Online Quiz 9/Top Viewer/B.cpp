#include <stdio.h>
#include <string.h>

struct data
{
    char title[10000];
    char artist[10000];
    long long view;
}items[105];



void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
} 

void bubbleSort(struct data items[], int structSize) {
    for (int i = 0; i < structSize - 1; i++)
    {
        for (int j = 0; j < structSize - 1 - i; j++)
        {

            if (items[j].view <= items[j + 1].view)
            {
                swap(&items[j], &items[j + 1]);
            }
        }   
    }
}

int main(int argc, char const *argv[])
{
    FILE* file;
    char title[10000];
    char artist[10000];
    long long view;
    int structCount = 0;
    
    file = fopen("testdata.in", "r");

    while (!feof(file))
    {
        fscanf(file, "%[^#]s", items[structCount].title);
        fgetc(file);
        fscanf(file, "%[^#]s", items[structCount].artist);
        fgetc(file);
        fscanf(file, "%lld ", &items[structCount].view);
        
        structCount++;
    }

    fclose(file);
    bubbleSort(items, structCount);
    for (int i = 0; i < structCount; i++)
    {
        printf("%s by %s - %lld\n", items[i].title, items[i].artist, items[i].view);
    }
    getchar();


    return 0;
}
