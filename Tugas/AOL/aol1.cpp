#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
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
};

void readFile(data datas[], int& size);

void describeMenu(data datas[], int size);

int main()
{
    data datas[3939];
    int size = 0;

    readFile(datas, size);

    printf("%d\n", size);

    int input;

    printf("\tMenu\n");
    printf("1. Describe\n");
    printf("2. Search\n");

    do
    {
        printf("Choose: ");
        scanf("%d", &input); 
        getchar();

        switch (input)
        {
        case 1:
            describeMenu(datas, size);
            break;
        case 2: 
            break;
        default:
            break;
        }
    } while (input != 0);

    return 0;
}

void readFile(data datas[], int& size) {
    FILE *f;

    f = fopen("file.csv", "r");

    if (f == NULL)
    {
        printf("File Doesn't Exist\n");
        return;
        
    } else {
        while (!feof(f))
        {
            fscanf(f, "%[^,],%[^,],%lf,%d,%d,%d,%[^,],%d,%[^\n]\n", datas[size].location_1, datas[size].location_2, &datas[size].price, &datas[size].rooms, &datas[size].bathrooms, &datas[size].carParks, datas[size].type, &datas[size].area, datas[size].furnish);
            size += 1; 
        }
    }

    fclose(f);
    
}

void describeLoc1(data datas[], int size);
void describeLoc2(data datas[], int size);
void describeRoom(data datas[], int size);
void describeBathroom(data datas[], int size);
void describeCarPark(data datas[], int size);
void describeType(data datas[], int size);
void describeFurnish(data datas[], int size);

void describeArea(data datas[], int size);
void describePrice(data datas[], int size);

void describeMenu(data datas[], int size) {

    int input;
    do {
        printf("What to Describe?\n");
        printf("1. Location 1\n");
        printf("2. Location 2\n");
        printf("3. Room\n");
        printf("4. Bathroom\n");
        printf("5. Car Parks\n");
        printf("6. Type\n");
        printf("7. Furnish\n");
        printf("8. Area\n");
        printf("9. Price\n");

        printf("Choose: ");
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 1:
            describeLoc1(datas, size);
            getchar();
            system("clear");
            break;
        case 2:
            describeLoc2(datas, size);
            getchar();
            system("clear");
            break;
        case 3:
            describeRoom(datas, size);
            getchar();
            system("clear");
            break;
        case 4:
            describeBathroom(datas, size);
            getchar();
            system("clear");
            break;
        case 5:
            describeCarPark(datas, size);
            getchar();
            system("clear");
            break;
        case 6:
            describeType(datas, size);
            getchar();
            system("clear");
            break;
        case 7:
            describeFurnish(datas, size);
            getchar();
            system("clear");
            break;
        case 8:
            describeArea(datas, size);
            getchar();
            system("clear");
            break;
        case 9:
            describePrice(datas, size);
            getchar();
            system("clear");
            break;
        default:
            break;
        }
    } while (input != 0);

    return;
}

void describeLoc1(data datas[], int size) {
    char loc[65][100] = {'0'};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 65; j++)
        {
            if (strcmp(datas[i].location_1, loc[j]) == 0)
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            strcpy(loc[counter], datas[i].location_1);
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 65; i++)
    {
        int count = 0;
        printf("%s: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (strcmp(loc[i], datas[j].location_1) == 0)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %s with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %s with frequency %d\n", loc[min_index], min);

    return;
}

void describeLoc2(data datas[], int size) {
    char loc[1][100] = {'0'};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 1; j++)
        {
            if (strcmp(datas[i].location_2, loc[j]) == 0)
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            strcpy(loc[counter], datas[i].location_2);
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 1; i++)
    {
        int count = 0;
        printf("%s: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (strcmp(loc[i], datas[j].location_2) == 0)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %s with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %s with frequency %d\n", loc[min_index], min);
    
    return;
}

void describeRoom(data datas[], int size) {
    int loc[9] = {0};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 9; j++)
        {
            if (datas[i].rooms == loc[j])
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            loc[counter] = datas[i].rooms;
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 9; i++)
    {
        int count = 0;
        printf("%d Rooms: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (loc[i] == datas[j].rooms)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %d Rooms with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %d Rooms with frequency %d\n", loc[min_index], min);

    return;
}

void describeBathroom(data datas[], int size) {
    int loc[10] = {0};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 10; j++)
        {
            if (datas[i].bathrooms == loc[j])
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            loc[counter] = datas[i].bathrooms;
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 10; i++)
    {
        int count = 0;
        printf("%d Bathrooms: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (loc[i] == datas[j].bathrooms)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %d Bathrooms with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %d Bathrooms with frequency %d\n", loc[min_index], min);

    return;
}

void describeCarPark(data datas[], int size) {
    int loc[1] = {0};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 1; j++)
        {
            if (datas[i].carParks == loc[j])
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            loc[counter] = datas[i].carParks;
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 1; i++)
    {
        int count = 0;
        printf("%d Car Parks: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (loc[i] == datas[j].carParks)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %d Car Parks with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %d Car Parks with frequency %d\n", loc[min_index], min);

    return;
}

void describeType(data datas[], int size) {
    char loc[2][100] = {'0'};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 2; j++)
        {
            if (strcmp(datas[i].type, loc[j]) == 0)
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            strcpy(loc[counter], datas[i].type);
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 2; i++)
    {
        int count = 0;
        printf("%s: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (strcmp(loc[i], datas[j].type) == 0)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %s with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %s with frequency %d\n", loc[min_index], min);

    return;
}

void describeFurnish(data datas[], int size) {
    char loc[3][100] = {'0'};

    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int found = 0;
        
        for (int j = 0; j < 3; j++)
        {
            if (strcmp(datas[i].furnish, loc[j]) == 0)
            {
                found = 1;
                break;
            }
            
        }

        if (found == 0)
        {
            strcpy(loc[counter], datas[i].furnish);
            counter++;
        }
    }

    int max = 0;
    int max_index;

    int min = 1000;
    int min_index;

    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        printf("%s: ", loc[i]);

        for (int j = 0; j < size; j++)
        {
            if (strcmp(loc[i], datas[j].furnish) == 0)
            {
                count++;
            }
            
        }
        
        if (count > max)
        {
            max = count;
            max_index = i;
        }

        if (count < min)
        {
            min = count;
            min_index = i;
        }

        printf("%d\n", count);
    }

    printf("Maximum Value: %s with frequency %d\n", loc[max_index], max);
    printf("Minimum Value: %s with frequency %d\n", loc[min_index], min);

    return;
}

void describeArea(data datas[], int size) {

    int max = 0;

    int min = 99999999;
    
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (datas[i].area > max)
        {
            max = datas[i].area;
        }

        if (datas[i].area < min)
        {
            min = datas[i].area;
        }

        sum += (double)datas[i].area;
    }

    double mean = sum / size;

    printf("Maximum Area: %d\n", max);
    printf("Minimum Area: %d\n", min);
    printf("Average Area: %.2lf\n", mean);

    return;
}

void describePrice(data datas[], int size) {

    double max = 0;

    double min = 99999999;
    
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (datas[i].price > max)
        {
            max = datas[i].price;
        }

        if (datas[i].price < min)
        {
            min = datas[i].price;
        }

        sum += datas[i].price;
    }

    double mean = sum / size;

    printf("Maximum Price: %.0lf\n", max);
    printf("Minimum Price: %.0lf\n", min);
    printf("Average Price: %.2lf\n", mean);

    return;
}