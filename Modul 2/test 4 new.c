#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  Fungsi untuk menampilkan header kelompok
void displayHeader() {
    system("cls"); // Bersihkan layar
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
    printf("\nTekan tombol apa saja untuk melanjutkan ke menu utama...\n");
    system("pause");
}

//  Fungsi untuk menentukan jumlah hari maksimal tiap bulan
int jumlahHariDalamBulan(int bulan) {
    switch (bulan) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 29; // Februari maksimal 29 (tanpa cek kabisat)
        default:
            return 0;
    }
}

//  Fungsi untuk menampilkan nama bulan
const char* namaBulan(int bulan) {
    const char *nama[] = {
        "Tidak Valid", "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };
    if (bulan >= 1 && bulan <= 12)
        return nama[bulan];
    else
        return nama[0];
}

//  Fungsi untuk menentukan zodiak
void tentukanZodiak(int tanggal, int bulan) {
    if ((bulan == 3 && tanggal >= 21) || (bulan == 4 && tanggal <= 19))
        printf("Aries\n");
    else if ((bulan == 4 && tanggal >= 20) || (bulan == 5 && tanggal <= 20))
        printf("Taurus\n");
    else if ((bulan == 5 && tanggal >= 21) || (bulan == 6 && tanggal <= 20))
        printf("Gemini\n");
    else if ((bulan == 6 && tanggal >= 21) || (bulan == 7 && tanggal <= 22))
        printf("Cancer\n");
    else if ((bulan == 7 && tanggal >= 23) || (bulan == 8 && tanggal <= 22))
        printf("Leo\n");
    else if ((bulan == 8 && tanggal >= 23) || (bulan == 9 && tanggal <= 22))
        printf("Virgo\n");
    else if ((bulan == 9 && tanggal >= 23) || (bulan == 10 && tanggal <= 22))
        printf("Libra\n");
    else if ((bulan == 10 && tanggal >= 23) || (bulan == 11 && tanggal <= 21))
        printf("Scorpio\n");
    else if ((bulan == 11 && tanggal >= 22) || (bulan == 12 && tanggal <= 21))
        printf("Sagitarius\n");
    else if ((bulan == 12 && tanggal >= 22) || (bulan == 1 && tanggal <= 19))
        printf("Capricorn\n");
    else if ((bulan == 1 && tanggal >= 20) || (bulan == 2 && tanggal <= 18))
        printf("Aquarius\n");
    else if ((bulan == 2 && tanggal >= 19) || (bulan == 3 && tanggal <= 20))
        printf("Pisces\n");
}

//  Fungsi validasi input angka
int inputAngkaValid(const char *pesan, int min, int max) {
    char buffer[100];
    int nilai;
    int i;

    while (1) {
        printf("%s", pesan);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf(" Input tidak boleh kosong!\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf(" Input tidak boleh kosong!\n");
            continue;
        }

        int valid = 1;
        for (i = 0; i < (int)strlen(buffer); i++) {
            if (!isdigit((unsigned char)buffer[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf(" Input harus berupa angka tanpa huruf atau simbol!\n");
            continue;
        }

        nilai = atoi(buffer);
        if (nilai < min || nilai > max) {
            printf("Nilai harus antara %d dan %d!\n", min, max);
            continue;
        }

        return nilai;
    }
}

//  Program utama
int main() {
    int tanggal, bulan, pilihan, hariMaks;

    displayHeader();

    while (1) {
        system("cls");
        printf("=====================================\n");
        printf("            ASTRO NAVIGATOR          \n");
        printf("=====================================\n");
        printf("1. Tentukan Zodiak\n");
        printf("2. Keluar Program\n");
        printf("-------------------------------------\n");

        pilihan = inputAngkaValid("Masukkan pilihan Anda (1-2): ", 1, 2);

        if (pilihan == 1) {
            system("cls");
            printf("==============================\n");
            printf("     PILIH BULAN KELAHIRAN    \n");
            printf("==============================\n");
            for (int i = 1; i <= 12; i++) {
                printf("%2d. %s\n", i, namaBulan(i));
            }

            bulan = inputAngkaValid("\nMasukkan pilihan bulan (1-12): ", 1, 12);
            hariMaks = jumlahHariDalamBulan(bulan);

            char pesanTanggal[50];
            sprintf(pesanTanggal, "Masukkan tanggal lahir (1-%d): ", hariMaks);
            tanggal = inputAngkaValid(pesanTanggal, 1, hariMaks);

            printf("\n==============================\n");
            printf("Tanggal Lahir: %d %s\n", tanggal, namaBulan(bulan));
            printf("Zodiak Anda adalah: ");
            tentukanZodiak(tanggal, bulan);
            printf("==============================\n");

            printf("\nTekan ENTER untuk kembali ke menu...");
            getchar();
        } 
        else if (pilihan == 2) {
            printf("\nTerima kasih telah menggunakan program ini!\n");
            exit(0); //  langsung keluar tanpa bisa ketik lagi
        }
    }

   return 0;
}