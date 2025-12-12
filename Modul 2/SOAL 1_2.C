#include <stdio.h>
#include <stdlib.h>

// Fungsi membersihkan buffer input
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
            return 0;
    }
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

int main() {
    int tanggal, bulan;
    int pilihan;
    int hariMaks;
    char konfirmasi;

    do {
        system("cls"); // untuk Windows
        printf("=====================================\n");
        printf("            ASTRO NAVIGATOR          \n");
        printf("=====================================\n");
        printf("1. Tentukan Zodiak\n");
        printf("2. Keluar Program\n");
        printf("-------------------------------------\n");

        printf("Masukkan pilihan Anda (1-2): ");
        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput harus berupa angka!\n");
            clearBuffer();
            printf("Tekan ENTER untuk kembali ke menu...");
            getchar();
            continue; // kembali ke awal menu
        }

        switch (pilihan) {
            case 1:
                // Input bulan dengan validasi
                do {
                    printf("\nMasukkan bulan lahir (1-12): ");
                    if (scanf("%d", &bulan) != 1) {
                        printf("Input harus berupa angka!\n");
                        clearBuffer();
                        continue;
                    }
                    if (bulan < 1 || bulan > 12)
                        printf("Bulan tidak valid! Harus antara 1–12.\n");
                } while (bulan < 1 || bulan > 12);

                hariMaks = jumlahHariDalamBulan(bulan);

                // Input tanggal dengan validasi
                do {
                    printf("Masukkan tanggal lahir (1-%d): ", hariMaks);
                    if (scanf("%d", &tanggal) != 1) {
                        printf("Input harus berupa angka!\n");
                        clearBuffer();
                        continue;
                    }
                    if (tanggal < 1 || tanggal > hariMaks)
                        printf(" Tanggal tidak valid untuk bulan ini!\n");
                } while (tanggal < 1 || tanggal > hariMaks);

                // Tampilkan hasil
                printf("\n==============================\n");
                printf("Tanggal Lahir: %d-%d\n", tanggal, bulan);
                printf("Zodiak Anda adalah: ");
                tentukanZodiak(tanggal, bulan);
                printf("==============================\n");

                printf("\nTekan ENTER untuk kembali ke menu...");
                clearBuffer();
                getchar();
                break;

            case 2:
                printf("\nApakah Anda yakin ingin keluar? (y/n): ");
                clearBuffer();
                scanf("%c", &konfirmasi);

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    printf("\nTerima kasih telah menggunakan program ini!\n");
                    printf("Tekan ENTER untuk keluar sepenuhnya...");
                    clearBuffer();
                    getchar();
                    return 0;
                } else {
                    printf("\nKembali ke menu utama...\n");
                    printf("Tekan ENTER untuk melanjutkan...");
                    clearBuffer();
                    getchar();
                }
                break;

            default:
                printf("\n Pilihan tidak valid! Silakan coba lagi.\n");
                printf("Tekan ENTER untuk kembali ke menu...");
                clearBuffer();
                getchar();
        }
    } while (1);

  return 0;
}