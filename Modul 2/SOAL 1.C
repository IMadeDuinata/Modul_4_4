#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk menentukan jumlah hari maksimal tiap bulan (tidak menghitung tahun kabisat)
int jumlahHariDalamBulan(int bulan) {
    switch (bulan) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 29; // diasumsikan Februari bisa sampai 29
        default:
            return 0; // bulan tidak valid
    }
}

// Fungsi untuk menampilkan nama bulan
const char* namaBulan(int bulan) {
    const char *nama[] = {
        "Tidak Valid", "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };
    return (bulan >= 1 && bulan <= 12) ? nama[bulan] : nama[0];
}

// Fungsi untuk menentukan zodiak berdasarkan tanggal dan bulan
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

// Fungsi validasi input hanya angka (tanpa huruf/spasi/enter kosong)
int inputAngkaValid(const char *pesan, int min, int max) {
    char buffer[100];
    int nilai;
    char *ptr;

    while (1) {
        printf("%s", pesan);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf(" Input tidak boleh kosong!\n");
            continue;
        }

        // Hapus newline
        buffer[strcspn(buffer, "\n")] = 0;

        if (strlen(buffer) == 0) {
            printf(" Input tidak boleh kosong!\n");
            continue;
        }

        // Cek semua karakter apakah angka
        int valid = 1;
        for (int i = 0; i < strlen(buffer); i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf(" Input harus berupa angka tanpa huruf!\n");
            continue;
        }

        nilai = strtol(buffer, &ptr, 10);
        if (nilai < min || nilai > max) {
            printf(" Nilai harus antara %d dan %d!\n", min, max);
            continue;
        }

        return nilai;
    }
}

int main() {
    int tanggal, bulan;
    int pilihan;
    int hariMaks;

    while (1) {
        system("cls"); // untuk Windows
        printf("=====================================\n");
        printf("            ASTRO NAVIGATOR          \n");
        printf("=====================================\n");
        printf("1. Tentukan Zodiak\n");
        printf("2. Keluar Program\n");
        printf("-------------------------------------\n");

        pilihan = inputAngkaValid("Masukkan pilihan Anda (1-2): ", 1, 2);

        switch (pilihan) {
            case 1:
                bulan = inputAngkaValid("\nMasukkan bulan lahir (1-12): ", 1, 12);
                hariMaks = jumlahHariDalamBulan(bulan);

                char pesanTanggal[50];
                sprintf(pesanTanggal, "Masukkan tanggal lahir (1-%d): ", hariMaks);
                tanggal = inputAngkaValid(pesanTanggal, 1, hariMaks);

                // Tampilkan hasil
                printf("\n==============================\n");
                printf("Tanggal Lahir: %d %s\n", tanggal, namaBulan(bulan));
                printf("Zodiak Anda adalah: ");
                tentukanZodiak(tanggal, bulan);
                printf("==============================\n");

                printf("\nTekan ENTER untuk kembali ke menu...");
                getchar();
                break;

            case 2:
                printf("\nTerima kasih telah menggunakan program ini!\n");
                printf("Tekan ENTER untuk keluar...");
                getchar();
                return 0;
        }
    }

    return 0;
}
