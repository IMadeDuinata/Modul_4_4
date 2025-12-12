#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAMA_FILE "data_mahasiswa.txt"

void displayHeader() {
    system("cls");
    printf("=============================================================\n");
    printf("|              KELOMPOK 4 ALGORITMA PEMOGRAMAN              |\n");
    printf("=============================================================\n");
    printf("| [1] Dhika Pradana                   2505551054            |\n");
    printf("| [2] I Made Duinata                  2505551143            |\n");
    printf("| [3] Reva Majesty Sentanu Karang     2505551171            |\n");
    printf("| [4] Ni Putu Niniek Anjaswari        2505551170            |\n");
    printf("| [5] Ni Ketut Deswita Krismayanti    2505551125            |\n");
    printf("| [6] Muhammad Izzanurdin Hasan       2505551075            |\n");
    printf("| [7] I Gusti Ayu Dwi Kencana Putri   2505551058            |\n");
    printf("=============================================================\n");
    printf("\nTekan tombol apa saja untuk melanjutkan...\n");
    system("pause");
}

int cekFileAda() {
    FILE *file = fopen(NAMA_FILE, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int isNumber(const char *str) {
    if (strlen(str) == 0) return 0;
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int isAlphabetic(const char *str) {
    if (strlen(str) == 0) return 0;
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') return 0;
    }
    return 1;
}

int isNimAda(const char *nimDicari) {
    FILE *file = fopen(NAMA_FILE, "r");
    if (!file) return 0;

    char nim[50], nama[100];

    while (fgets(nim, 50, file)) {
        fgets(nama, 100, file);

        nim[strcspn(nim, "\n")] = 0;
        if (strcmp(nim, nimDicari) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void tambahData() {
    char nim[50], nama[100];

    printf("\n--- TAMBAH DATA MAHASISWA ---\n");
    
    while (1) {
        printf("Masukkan NIM (angka saja): ");
        fgets(nim, sizeof(nim), stdin);
        nim[strcspn(nim, "\n")] = 0;

        if (strlen(nim) == 0) {
            printf("[ERROR] NIM tidak boleh kosong!\n");
        }
        else if (!isNumber(nim)) {
            printf("[ERROR] NIM harus angka!\n");
        }
        else if (isNimAda(nim)) {
            printf("[ERROR] NIM sudah terdaftar!\n");
        }
        else break;
    }

    while (1) {
        printf("Masukkan Nama Lengkap (huruf saja): ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;

        if (strlen(nama) == 0) {
            printf("[ERROR] Nama tidak boleh kosong!\n");
        }
        else if (!isAlphabetic(nama)) {
            printf("[ERROR] Nama hanya boleh huruf dan spasi!\n");
        }
        else break;
    }

    FILE *file = fopen(NAMA_FILE, "a");
    fprintf(file, "%s\n%s\n", nim, nama);
    fclose(file);

    printf("[SUKSES] Data berhasil disimpan!\n");
}

void tampilkanData() {
    FILE *file = fopen(NAMA_FILE, "r");
    if (!file) {
        printf("Belum ada data tersimpan.\n");
        return;
    }

    char nim[50], nama[100];
    int no = 1;

    printf("\n--- DAFTAR DATA MAHASISWA ---\n");

    if (fgetc(file) == EOF) {
        printf("Belum ada data tersimpan.\n");
        fclose(file);
        return;
    }
    rewind(file);

    printf("No.\tNIM\t\tNama\n");
    printf("---------------------------------------\n");

    while (fgets(nim, 50, file)) {
        fgets(nama, 100, file);

        nim[strcspn(nim, "\n")] = 0;
        nama[strcspn(nama, "\n")] = 0;

        printf("%d.\t%s\t\t%s\n", no++, nim, nama);
    }

    printf("---------------------------------------\n");
    fclose(file);
}

void cariData() {
    char nimDicari[50], nim[50], nama[100];
    int ditemukan = 0;

    printf("\n--- PENCARIAN DATA MAHASISWA ---\n");

    while (1) {
        printf("Masukkan NIM yang dicari (angka saja): ");
        fgets(nimDicari, sizeof(nimDicari), stdin);
        nimDicari[strcspn(nimDicari, "\n")] = 0;

        if (strlen(nimDicari) == 0) {
            printf("[ERROR] NIM tidak boleh kosong!\n");
        }
        else if (!isNumber(nimDicari)) {
            printf("[ERROR] NIM harus angka!\n");
        }
        else break;
    }

    FILE *file = fopen(NAMA_FILE, "r");
    if (!file) {
        printf("[INFO] Data mahasiswa tidak ditemukan.\n");
        return;
    }

    while (fgets(nim, 50, file)) {
        fgets(nama, 100, file);

        nim[strcspn(nim, "\n")] = 0;

        if (strcmp(nim, nimDicari) == 0) {
            printf("\n[DITEMUKAN]\n");
            printf("NIM  : %s\n", nim);
            printf("Nama : %s\n", nama);
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("[INFO] Data mahasiswa tidak ditemukan.\n");
    }

    fclose(file);
}

int getMenuChoice() {
    char input[10];
    int pilihan = 0;

    while (1) {
        printf("Pilihan Anda [1-4]: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0;

        if (!isNumber(input)) {
            printf("[ERROR] Input harus angka 1-4!\n");
            continue;
        }

        pilihan = atoi(input);

        if (pilihan >= 1 && pilihan <= 4)
            return pilihan;

        printf("[ERROR] Pilihan harus 1-4!\n");
    }
}

int main() {
    int pilihan;

    if (!cekFileAda()) {
        FILE *file = fopen(NAMA_FILE, "w");
        fclose(file);
    }

    displayHeader();

    do {
        system("cls");
        printf("\n========================================\n");
        printf("        SISTEM INFORMASI MAHASISWA      \n");
        printf("========================================\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tampilkan Semua Data\n");
        printf("3. Cari Data Mahasiswa\n");
        printf("4. Keluar\n");
        printf("----------------------------------------\n");

        pilihan = getMenuChoice();

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: printf("Terima kasih!\n"); break;
        }

        if (pilihan != 4) system("pause");

    } while (pilihan != 4);

    return 0;
}
