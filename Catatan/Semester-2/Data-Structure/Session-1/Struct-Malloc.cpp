#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address
{
    char street[100];
    int rt;
    int rw;
};


struct Mahasiswa
{
    char name[100];
    char NIM[11];
    int age;
    struct Address address;
};


int main(int argc, char const *argv[])
{
    
    // Static Memory Allocation
    Mahasiswa kaisar;

    strcpy(kaisar.name, "Kaisar");
    strcpy(kaisar.NIM, "2602113546");
    kaisar.age = 19;
    strcpy(kaisar.address.street, "Binus Square lt.2");
    kaisar.address.rt = 5;
    kaisar.address.rw = 2;

    printf(" Name: %s\n NIM: %s\n Address: %s\n", kaisar.name, kaisar.NIM, kaisar.address.street);

    // Dynamic Memory Allocation
    Mahasiswa *adam = (Mahasiswa*) malloc(sizeof(struct Mahasiswa));

    strcpy(adam->name, "Adam");
    strcpy(adam->NIM, "2625905112");
    adam->age = 19;
    strcpy(adam->address.street, "Binus Square lt.2");
    adam->address.rt = 5;
    adam->address.rw = 2;

    printf(" Name: %s\n NIM: %s\n Address: %s\n", adam->name, adam->NIM, adam->address.street);
    free(adam);

    return 0;
}
