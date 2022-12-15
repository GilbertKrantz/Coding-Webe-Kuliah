#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char title[10000];
    char artist[10000];
    int view;
};


int main(int argc, char const *argv[])
{
    FILE* file;
    long fileSize;
    char* buffer;
    size_t res;

    file = fopen("testdata.in", "r+");

    if (NULL == file) {
        printf("file can't be opened \n");

        exit(1);
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    buffer = (char*) malloc (sizeof(char) * fileSize);
    if (buffer == NULL) {
        fputs("Memory Error", stderr);
        exit(2);
    }

    res = fread (buffer,1,fileSize,file);
    if (res != fileSize) {
        fputs ("Reading error",stderr); 
        exit (3);
    }

    char* strtok_res;
    strtok_res = strtok(buffer, "#");
    while (strtok_res != NULL)
    {
        printf("%s", strtok_res);
        strtok_res = strtok (NULL, "#");
    }

    fclose(file);
    free (buffer);

    return 0;
}
