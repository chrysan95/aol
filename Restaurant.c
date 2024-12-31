#include <stdio.h>
#include <stdlib.h>

// Structs
// Struct untuk menu
typedef struct menuPaket {
    int paket;
    char desc[1000];
    int harga;
} mp;

// Struct untuk orderan
typedef struct orderItem {
    int paket;
    int harga;
} oi;

// Functions
// Function untuk membaca file menu
int readMenuFile(mp menu[]) {
    FILE *f1 = fopen("menu list.txt", "r");
    if (f1 == NULL) {
        printf("File menu list.txt tidak ditemukan\n");
        return -1;
    }

    int i = 0;
    while (fscanf(f1, "%[^@]@%d\n", menu[i].desc, &menu[i].harga) != EOF) {
        menu[i].paket = i + 1;
        printf("\nPaket Hemato %d\nDesc: %s\nHarga: Rp%d\n", menu[i].paket, menu[i].desc, menu[i].harga);
        i++;
    }

    fclose(f1);
    return i;
}

// Function untuk mensorting order berdasarkan nomor paket
void sortOrder(oi order[], int orderSize) {
    for (int i = 0; i < orderSize; i++) {
        for (int j = i + 1; j < orderSize; j++) {
            if (order[i].paket > order[j].paket) {
                oi temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

// Function untuk mengupdate file order
void writeOrderFile(oi order[], int orderSize) {
    FILE *f2 = fopen("order list.txt", "w");
    if (f2 == NULL) {
        printf("File order list.txt tidak ditemukan\n");
        return;
    }

    fclose(f2);
}


int main() {
    mp menu[100];
    oi order[100];
    int orderSize = 0;
    int menuSize;

    printf(
        "Selamat datang di Waroeng Baroe\n\n"
        "Daftar Menu:\n"
        );

        // READ FILE MENU
        menuSize = readMenuFile(menu);

        // INPUT ORDER
        int paket;
        printf("\nMasukkan pesanan Anda (0 untuk selesai):\n");

        do {
        printf("Paket (1 - 4): "); fflush(stdin); scanf("%d", &paket);
        if (paket == 0) {
            break;
        }
        if (paket < 1 || paket > 4) {
            printf("Paket tidak valid. Silakan masukkan paket antara 1 dan 4.\n");
            continue;
        }

        order[orderSize].paket = paket;
        order[orderSize].harga = menu[paket - 1].harga;
        orderSize++;
        } while (paket != 0);

    // SORT ORDERS
    sortOrder(order, orderSize);

    // WRITE ORDERS TO FILE
    writeOrderFile(order, orderSize);

    // PRINT ORDERS AND TOTAL
    int total = 0;
    printf("\nPesanan Anda:\n");
    for (int i = 0; i < orderSize; i++) {
        printf("Paket Hemato %d\nDesc: %s\nHarga: Rp%d\n", order[i].paket, menu[order[i].paket - 1].desc, order[i].harga);
        total += order[i].harga;
    }

    printf("\nTotal Harga: Rp%d\n", total); 

    return 0;
}