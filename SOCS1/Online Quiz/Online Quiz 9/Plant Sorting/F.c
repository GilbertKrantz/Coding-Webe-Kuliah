#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int NIM;
    char name[100];
} data;

struct 
{
    data items[1000];
} buffer;

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
            if (strcmp(buffer.items[j].name, buffer.items[j+1].name) > 0)
            {
                swap(&buffer.items[j], &buffer.items[j + 1]);
            }
            
        }
    }

}

int main() {
    FILE *file;
    char name[100];
    int NIM;
    int j = 0;
    int size;
    
    file = fopen("testdata.in", "r");

    if(NULL == file) {
        printf("file can't be opened\n");
        exit(0);
    }

    fscanf(file, "%d", &size);

    while (!feof(file))
    {
        fscanf(file, "%d#%[^\n]", &NIM, name);
        buffer.items[j].NIM = NIM;
        strcpy(buffer.items[j].name, name);
        j++;
    }

    bubbleSort(size);

    for (int i = 0; i < size; i++)
    {
        printf("%d %s\n", buffer.items[i].NIM, buffer.items[i].name);
    }
    
}