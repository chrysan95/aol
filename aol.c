#include <stdio.h>

typedef struct menuPrice{
    int paket;
    char desc [10000];
    int harga;
} mp;

typedef struct orderItem{
    int paket;
    int harga;
} oi;

int readMenuFile(){
    mp menu[100];
    FILE *f1;
    f1 = fopen("menu.txt","r");
    int i = 1;
    while(!feof(f1)){
        fscanf(f1,"%d %[^-] %d\n", &menu[i].paket, menu[i].desc, &menu[i].harga);
    }
    fclose(f1);
}

void processOrderFile(mp menu[], int menuSize){
    oi order[100];
    int total = 0;
    int howManyOrders = 0;
    FILE *f2;
    f2 = fopen("order.txt","r");
    
    printf("Paket mana yang anda inginkan? ");

    for(int i = 1; i <= menuSize; i++){
        printf("Paket Hemato %d\nDesc: %s\nHarga: %d\n", menu[i].paket, menu[i].desc, menu[i].harga);
    }    

    // TODO!

}

void writeOrderFile(oi order[], int numOrders, int total){
    FILE *f2;
    f2 = fopen("order.txt","a");

    // TODO!
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





