#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[10000];
    char artist[10000];
    int view;
}data;

struct buffer
{
    data items[100];
}buffer;


void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
} 

void bubbleSort(int structSize) {
    for (size_t i = 0; i < structSize; i++)
    {
        for (int j = 0; j < structSize - 1 - i; j++)
        {
            if (buffer.items[j].view < buffer.items[j + 1].view)
            {
                swap(&buffer.items[j], &buffer.items[j + 1]);
            }
            
        }
    }

}

int main(int argc, char const *argv[])
{
    FILE* file;
    char ch;
    char title[10000];
    char artist[10000];
    int view;
    int structCount = 0;
    
    file = fopen("testdata.in", "r");

    if (NULL == file)
    {
        printf("File can't be Opened\n");
        exit(0);
    }

    while (!feof(file))
    {
        fscanf(file, "%99[^#]#%99[^#]#%d", title, artist, &view);
        strcpy(buffer.items[structCount].title, title);
        strcpy(buffer.items[structCount].artist, artist);
        buffer.items[structCount].view = view;
        structCount++;
    }

    int structSize = structCount - 1;
    bubbleSort(structSize);
    
    

    for (size_t i = 0; i < structCount; i++)
    {
        printf("%s by %s - %d", buffer.items[i].title, buffer.items[i].artist, buffer.items[i].view);
    }
    


    return 0;
}
