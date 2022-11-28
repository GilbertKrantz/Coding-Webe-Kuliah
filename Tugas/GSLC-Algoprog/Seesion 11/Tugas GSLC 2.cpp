#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to Check the data thats inputed
int dataCheck(char* name, int ticket) {
    if (strlen(name) >= 3 && strlen(name) <= 50)
    {
        if (ticket % 2 == 0)
        {
            return 1;
        }
    }

    return 0;
    
}

//Function to display the inputed data
int dataDisplay(int count, char name[50][50], int* ticket, int check) {
    if (check == 0)
    {
        printf("Tidak ada Data\n");
        getchar();
    } else {
        printf("Data Pembelian Tiket\n\n");
        printf(" | %3s | %-20s | %15s | %17s |\n\n", "No", "Nama", "Jumlah Tiket", "Pembayaran");

        for (int i = 0; i < count; i++)
        {
            double price = ticket[i] * 500000;
            printf(" | %3d | %-20s | %15d | Rp%'15.2lf |\n", i+1, name[i], ticket[i], price);
        }
        getchar();
    }
    
    return 0;
}

int main()
{
    // Variable and Array Declaration
    int choose, ticket[50], dbCount, limit = 1, check = 0;
    double price = 0;

    char name[50][50];

    while (limit == 1) //Infinite loop
    {
        printf("---------------------------------------------------------\n");
        printf("PENJUALAN TIKET\n");
        printf("   1. Add Pembelian\n");
        printf("   2. Lihat history pembelian\n");
        printf("   3. Exit\n");
        do
        {
            printf("Pilihan: ");
            scanf("%d", &choose);
        } while (choose != 1 && choose != 2 && choose != 3);
        
        getchar();

        switch (choose)
        {
        case 1:
            do
            {
                printf("   Nama: ");
                scanf("%s", name[dbCount]);
                printf("   Ticket [Kelipatan 2]: ");
                scanf("%d", &ticket[dbCount]);

                getchar();

                price = ticket[dbCount] * 500000;

            } while (!dataCheck(name[dbCount], ticket[dbCount]));

            printf("   Total Pembayaran: Rp%'.2lf\n", price);
            getchar();

            dbCount++;
            check = 1;

            printf("\e[1;1H\e[2J"); // Clear Console Screen
            break;
        
        case 2:
            dataDisplay(dbCount, name, ticket, check); //Calling dataDisplay function to display data
            printf("\e[1;1H\e[2J"); // Clear Console Screen
            break;
        
        case 3:
            limit = 0;
            printf("\e[1;1H\e[2J"); // Clear Console Screen
            break;

        default:
            break;
        }
    }

    printf("---------------------------------------------------------\n");
    return 0;
}
