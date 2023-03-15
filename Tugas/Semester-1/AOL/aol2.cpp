#include <stdio.h>
#include <string.h>

typedef struct
{
    char location_1[100];
    char location_2[100];
    double price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[100];
    int area;
    char furnish[100];
} data;

void readFile(data datas[], int& size) {
    FILE *f;

    f = fopen("file.csv", "r");

    if (f == NULL)
    {
        printf("File Doesn't Exist\n");
        return;
        
    } else {
        char trash[100];
        fscanf(f, "%[^\n]\n", trash);
        while (!feof(f))
        {
            fscanf(f, "%[^,],%[^,],%lf,%d,%d,%d,%[^,],%d,%[^\n]\n", datas[size].location_1, datas[size].location_2, &datas[size].price, &datas[size].rooms, &datas[size].bathrooms, &datas[size].carParks, datas[size].type, &datas[size].area, datas[size].furnish);
            size += 1; 
        }
    }

    fclose(f);
    
}

void display(data datas[], int index) {
    printf("%-20s|%-20s|%10.0lf|%5d|%5d|%5d|%10s|%5d|%-15s|\n", datas[index].location_1, datas[index].location_2, datas[index].price, datas[index].rooms, datas[index].bathrooms, datas[index].carParks, datas[index].type, datas[index].area, datas[index].furnish);
}

void searchLoc1(data datas[], char find[], int size);
void searchLoc2(data datas[], char find[], int size);

void searchRooms(data datas[], char find[], int size);
void searchBath(data datas[], char find[], int size);
void searchCar(data datas[], char find[], int size);
void searchType(data datas[], char find[], int size);
void searchFurnish(data datas[], char find[], int size);

int main() {
    int size = 0;

    data datas[3940];

    readFile(datas, size);

    char search[100];
    char searchCol[100];
    
    scanf("%s in %s", search, searchCol);
    getchar();

    if (strcmp(searchCol, "loc1") == 0)
    {
        searchLoc1(datas, search, size);
    } else if (strcmp(searchCol, "loc2") == 0)
    {
        searchLoc2(datas, search, size);
    } else if (strcmp(searchCol, "room") == 0)
    {
        searchRooms(datas, search, size);
    } else if (strcmp(searchCol, "bathrooms") == 0)
    {
        searchBath(datas, search, size);
    } else if (strcmp(searchCol, "carparks") == 0)
    {
        searchCar(datas, search, size);
    } else if (strcmp(searchCol, "type") == 0)
    {
        searchType(datas, search, size);
    } else if (strcmp(searchCol, "furnish") == 0)
    {
        searchFurnish(datas, search, size);
    } else {
        printf("Column Not Found!!\n");
    }
    
    
}

void searchLoc1(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char tempStr[size];
        strcpy(tempStr, datas[i].location_1);
        strlwr(tempStr);
        strlwr(find);

        if (strstr(tempStr, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
    
}

void searchLoc2(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char tempStr[size];
        strcpy(tempStr, datas[i].location_2);
        strlwr(tempStr);
        strlwr(find);

        if (strstr(tempStr, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

void searchRooms(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char convInt[2];
        sprintf(convInt, "%d", datas[i].rooms);

        if (strstr(convInt, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

void searchBath(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char convInt[2];
        sprintf(convInt, "%d", datas[i].bathrooms);

        if (strstr(convInt, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

void searchCar(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char convInt[1];
        sprintf(convInt, "%d", datas[i].carParks);

        if (strstr(convInt, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

void searchType(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char tempStr[size];
        strcpy(tempStr, datas[i].type);
        strlwr(tempStr);
        strlwr(find);

        if (strstr(tempStr, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

void searchFurnish(data datas[], char find[], int size) {
    int check = 0;
    for (int i = 0; i < size; i++)
    {
        char tempStr[size];
        strcpy(tempStr, datas[i].furnish);
        strlwr(tempStr);
        strlwr(find);

        if (strstr(tempStr, find) != NULL)
        {
            display(datas, i);
            check++;
        }
    }

    if (check == 0)
    {
        printf("Searched Data doesn't Exist!\n");
    }
}

