#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int banyakMBarang = 0;

struct masterBarang{
	char kodeBarang[120];
	char namaBarang[120];
	int harga;
	int stok;
}mBarang[100];

struct barang{
	char kodeBarang[120];
	int qty;
};

struct transaksi{
	int kodeTransaksi;
	char namaKasir[120];
	struct barang listBarang[120];
}listTransaksi[100];

int checkCode(char *kodeBarang) {
    int a = 0;
    
    while (a < 100)
    {
        if (strcmp(kodeBarang, mBarang[a].kodeBarang) == 0)
        {
            return a;
        }
        
        a++;
    }
    
    return 0;
}

int checkQty(int quantity, int id) {
    
    if (quantity <= mBarang[id].stok)
    {
        return 1;
    }
    
    return 0;
}

int addProduct(int productCount, int transactionCount) {
    char kodeProduk[120];
    int price;
    int quantity;

    do
    {
        printf("Kode Produk: ");
        scanf("%[^\n]", kodeProduk);
        getchar();
    } while ((strlen(kodeProduk) < 1) && (checkCode(kodeProduk) == 0));

    strcpy(listTransaksi[transactionCount].listBarang[productCount].kodeBarang, kodeProduk);

    // making an id of the product
    int id = checkCode(kodeProduk);
    
    do
    {
        printf("Jumlah Pembelian: ");
        scanf("%d", &quantity);
        getchar();
    } while (quantity < 1 && !checkQty(quantity, id));

    listTransaksi[transactionCount].listBarang[productCount].qty = quantity;

    price = mBarang[id].harga * quantity;

    return price;
}

void addTransaksi(int transCount) {
    char namaKasir[120];
    char choose;
    int prdCount = 0;
    int totalPrice = 0;

    do
    {
        printf("Nama Kasir: ");
        scanf("%[^\n]", namaKasir);
        getchar();
    } while (strlen(namaKasir) > 20 && strlen(namaKasir) < 5);

    strcpy(listTransaksi[transCount].namaKasir, namaKasir);
    
    do
    {
        totalPrice += addProduct(prdCount, transCount);
        prdCount++;
        printf("Apakah ingin menambah produk pada transaksi?\n");
        printf("Choose Y/N (Case Sensitive)\n");
        printf("Y/N: ");
        scanf("%c", &choose);
    } while (choose == 'Y');

    listTransaksi[transCount].kodeTransaksi = (transCount + 1);

    printf("Total Transaksi TK%d adalah Rp %d", transCount + 1, totalPrice);

}

void showTransaction(int transCount) {
    if (transCount == 0)
    {
        printf("Tidak Ada Transaksi\n");
        getchar();
        return;
    }

    for (int i = 0; i < transCount; i++)
    {
        char namaKasir[120];
        strcpy(namaKasir, listTransaksi[i].namaKasir);
        int quantity = listTransaksi[i].listBarang[0].qty;
        char kodeProduk = listTransaksi[i].listBarang[0].kodeBarang;

        int id = checkCode(kodeProduk);

        int price = mBarang[id].harga;
        
        printf(" %d | TX%d | %s | Rp.%d | %s - %s - %d - Rp.%d\n");
    }

    return;
    
    
}

int kasirMenu(){
	int pilihan;
    int trcCount = 0;

	do{
		// system("cls");
		puts("1. Menambah Transaksi");
		puts("2. List Transaksi");
		puts("3. Kembali");
		
		
		do{
			printf("Masukkan pilihan [1-3]: ");
			scanf("%d", &pilihan);
			scanf("%[^\n]");
			getchar();
		}while(pilihan<1 || pilihan>3);
		
		if(pilihan==1){
			printf("Menu input Transaksi\n");
			addTransaksi(trcCount);
            trcCount++;
		}
		else if(pilihan == 2){
			printf("Transaction Data\n");
			showTransaction(trcCount);
		}
		else if(pilihan == 3){
			printf("babai anak haram\n");
		}
		getchar();
	}while(pilihan !=3);
	


	return 0;
}

void main() {
    int pilihan;

	do{
		// system("cls");
		puts("1. Staff Gudang");
		puts("2. Kasir");
		puts("3. Keluar");
		
		
		do{
			printf("Masukkan pilihan [1-3]: ");
			scanf("%d", &pilihan);
			scanf("%[^\n]");
			getchar();
		}while(pilihan<1 || pilihan>3);
		
		if(pilihan==1){
			printf("Menu Staff Gudang\n");
			// staff();
		}
		else if(pilihan == 2){
			printf("Menu Kasir\n");
			kasirMenu();
		}
		else if(pilihan == 3){
			printf("babai anak haram\n");
            exit(0);
		}
		getchar();
	}while(pilihan !=3);
}
