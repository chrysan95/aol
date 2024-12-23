#include <stdio.h>

// Structs
// Struct untuk menyimpan menu
typedef struct menuPaket{
    int paket;
    char desc[1000];
    int harga;
} mp;

// Struct untuk menyimpan orderan
typedef struct orderItem{
    int paket;
    int harga;
} oi;

// Functions
// Function untuk membaca file menu
int readMenuFile(mp menu[]) {
    FILE *f1 = fopen("menu.txt", "r");
    if(f1 == NULL){
        printf("File menu.txt tidak ditemukan\n");
        return -1;
    }
    
    int i = 0;
    while(fscanf(f1, "%d %s %d", &menu[i].paket, menu[i].desc, &menu[i].harga) != EOF) {
        i++;
    }

    fclose(f1);
    return i; // return jumlah menu
}

void processOrderFile(mp menu[], int menuSize) {
    oi order[100];
    int total = 0;
    int howManyOrders = 0;
    FILE *f2 = fopen("order.txt","r");
    if(f2 == NULL) {
        printf("File order.txt tidak ditemukan\n");
    }
    
    printf("Paket mana yang anda inginkan? ");

    for(int i = 0; i < menuSize; i++) {
        printf("Paket Hemato %d\nDesc: %s\nHarga: %d\n", menu[i].paket, menu[i].desc, menu[i].harga);
    }    

    // TODO: Process orders from the file, update orders, and calculate total

    fclose(f2);
}

void writeOrderFile(oi order[], int numOrders, int total){
    FILE *f2 = fopen("order.txt","a");
    if(f2 == NULL) {
        printf("File order.txt tidak ditemukan\n");
    }
    
    // TODO: Write orders to file

    fclose(f2);
}

int main(){
    mp menu[100];
    int menuSize;

    printf(
        "Selamat datang di Waroeng Baroe\n\n"
        
        "Daftar Menu\n"
        );
    // READ FILE MENU
    menuSize = readMenuFile(menu);
    // PROCESS FILE MENU
    processOrderFile(menu, menuSize);
    /*
    TODO! = sortingnya dipake pas read order list aja jadi misal
            user pilih (3 1 2) nanti pas di order list jadi (1 2 3)
    */ 
    
    return 0;
}