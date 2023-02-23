#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    int scoreSize;
    int scores[100];
} data;

int linearSearch(data Data[], int size, char find[]) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(Data[i].name, find) == 0)
        {
            return i;
        }
        
    }

    return -1;
    
}

double averageCount(data Data, int scoreSize) {
    int sum = 0;
    for (int i = 0; i < scoreSize; i++)
    {
        sum += Data.scores[i];
    }

    return (double)sum / scoreSize;
    
}

int main() {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("File Doesn't Exist\n");
        exit(0);
    }

    int T;
    fscanf(fp, "%d", &T);
    fgetc(fp);

    data studentData[T];

    for (int i = 0; i < T; i++)
    {
        fscanf(fp, "%[^\n]s\n", studentData[i].name);
        fgetc(fp);

        fscanf(fp, "%d", &studentData[i].scoreSize);
        fgetc(fp);

        for (int j = 0; j < studentData[i].scoreSize; j++)
        {
            fscanf(fp, "%d", &studentData[i].scores[j]);
            fgetc(fp);
        }
        
    }

    int Q;
    fscanf(fp, "%d", &Q);
    fgetc(fp);

    for (int i = 0; i < Q; i++)
    {
        char findStr[31];
        fscanf(fp, "%[^\n]s\n", findStr);
        fgetc(fp);

        printf("%s\n", findStr);

        int strIndex = linearSearch(studentData, T, findStr);

        if (strIndex == -1)
        {
            printf("Case %d: Invalid Name\n", i + 1);
            break;
        }
        

        double average = averageCount(studentData[strIndex], studentData[strIndex].scoreSize);

        printf("Case %d: %.2lf\n", i + 1, average);
    }
    
}