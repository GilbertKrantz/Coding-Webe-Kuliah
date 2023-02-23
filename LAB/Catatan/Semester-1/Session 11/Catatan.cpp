#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef long long int longInt;

typedef struct Course
{
    char code[50];
    char name[50];
} Co;

union Course2
{
    char code[50];
    char name[50];
};


struct Student
{
    char name[50];
    int age;
    Co course;
};

void writeFile(char *name, int age) {
    FILE *fptr = fopen("students.txt", "w");

    fprintf(fptr, "%s#%d\n", name, age);

    fclose(fptr);
}

void appendFile(char *name, int age) {
    FILE *fptr = fopen("students.txt", "a");

    fprintf(fptr, "%s#%d\n", name, age);

    fclose(fptr);
}

void readFile() {
    FILE *fptr = fopen("students.txt", "r");
    
    if (fptr == NULL)
    {
        printf("File doesn't exist!!\n");
        exit(0);
    }

    char name[50];
    int age;

    while (!feof(fptr))
    {
        fscanf(fptr, "%[^#]#%d\n", name, &age);

        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
    }
}

int main()
{
    // Course course1 = {"COMP5432", "Computer Science"};
    // Co course2 = {"DATA5324", "Data Science"};

    // printf("%s is the code of %s\n", course1.code, course1.name);
    // printf("%s is the code of %s\n", course2.code, course2.name);

    // Student student1 = {"Budi", 20, "STAT4124", "Statistics"};

    // student1.age = 22;

    // printf("%s is %d years old with the Course Code %s with course %s\n", student1.name, student1.age, student1.course.code, student1.course.name);

    // Student studentArr[10];

    // studentArr[0].age = 20;

    // printf("%d\n", studentArr[0].age);

    // Student *studentPtr = &student1;

    // printf("The Student Age is %d\n", (*studentPtr).age);
    // printf("The Student Name is %s\n", studentPtr->name);

    // printf("Course : %d\n", sizeof(Course));
    // printf("Course2 : %d\n", sizeof(Course2));

    // while (true)
    // {
    //     char name[50];
    //     int age;
    //     printf("Input Student Name: ");
    //     scanf("%[^\n]", name);
    //     getchar();

    //     printf("Input Student Age: ");
    //     scanf("%d", &age);
    //     getchar();

    //     appendFile(name, age);
    // }
    
    readFile();

}
