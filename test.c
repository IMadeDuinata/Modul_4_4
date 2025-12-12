#include <stdio.h>
#include <stdlib.h> 

// Konstanta
double pi = 3.141592653589793;

// ============================
// Deklarasi (Prototipe) Fungsi
// ============================
void bersihkanBuffer();
void hitungLuasSegitiga(double alas, double tinggi);
void hitungKelilingSegitiga(double a, double b, double c);
void hitungLuasBelahKetupat(double d1, double d2);
void hitungKelilingBelahKetupat(double sisi);
void hitungLuasJajarGenjang(double alas, double tinggi);
void hitungKelilingJajarGenjang(double sisi1, double sisi2);
void hitungLuasTrapesium(double atas, double bawah, double tinggi);
void hitungKelilingTrapesium(double atas, double bawah, double miring1, double miring2);
void hitungLuasLingkaran(double r);
void hitungKelilingLingkaran(double r);
void tampilkanHeader();

// ============================
// FUNGSI UTAMA (MAIN)
// ============================
int main() {
    int pilihan;
    int status_scan; 
    
    // Variabel input
    double sisiAtasTrapesium, sisiBawahTrapesium, tinggiTrapesium, sisiMiringTrapesium1, sisiMiringTrapesium2;
    double alasSegitiga, tinggiSegitiga, sisiSegitiga1, sisiSegitiga2, sisiSegitiga3;
    double jariJariLingkaran;
    double alasJajarGenjang, tinggiJajarGenjang, sisiJajarGenjang1, sisiJajarGenjang2;
    double diagonalBelahKetupat1, diagonalBelahKetupat2, sisiBelahKetupat;

    // HEADER AWAL
     tampilkanHeader();

    do {
        system("cls"); // Membersihkan layar saat program dijalankan (untuk menu)

        printf("=====================================================================\n");
        printf("|Selamat Datang Di Program Menghitung Luas Dan Keliling Bangun Datar|\n");
        printf("=====================================================================\n");
        printf("|[1] = Menghitung Luas dan Keliling Segitiga                        |\n");
        printf("|[2] = Menghitung Luas dan Keliling Belah Ketupat                   |\n");
        printf("|[3] = Menghitung Luas dan Keliling Jajar Genjang                   |\n");
        printf("|[4] = Menghitung Luas dan Keliling Trapesium                       |\n");
        printf("|[5] = Menghitung Luas dan Keliling Lingkaran                       |\n");
        printf("|[0] = Keluar dari Program                                          |\n");
        printf("=====================================================================\n");
        printf("Masukkan pilihan Anda: ");
        
        status_scan = scanf("%d", &pilihan);
        
        // --- LOGIKA VALIDASI INPUT UTAMA ---
        if (status_scan != 1) {
            bersihkanBuffer(); 
            pilihan = -1;      
        }
        
        if (pilihan < 0 || pilihan > 5) {
            printf("===================================================================\n");
            printf("Pilihan tidak valid. Silakan masukkan angka 0 sampai 5.\n");
            
            if (pilihan != 0) {
                printf("\nTekan tombol apa saja untuk kembali ke menu...\n");
                system("pause"); 
            }
            continue; 
        }
        // ------------------------------------

        printf("===================================================================\n");

        switch (pilihan) {
            // ======================================
            // KASUS 1: SEGITIGA
            // ======================================
            case 1: {
                printf("=== Segitiga ===\n");
                
                // INPUT ALAS
                do {
                    printf("Masukkan alas: ");
                    if (scanf("%lf", &alasSegitiga) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1); // Kondisi 'while(1)' dihentikan oleh 'break' jika input benar

                // INPUT TINGGI
                do {
                    printf("Masukkan tinggi: ");
                    if (scanf("%lf", &tinggiSegitiga) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI 1
                do {
                    printf("Masukkan sisi pertama: ");
                    if (scanf("%lf", &sisiSegitiga1) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI 2
                do {
                    printf("Masukkan sisi kedua: ");
                    if (scanf("%lf", &sisiSegitiga2) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI 3
                do {
                    printf("Masukkan sisi ketiga: ");
                    if (scanf("%lf", &sisiSegitiga3) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);
                printf("=========================================\n");
                hitungLuasSegitiga(alasSegitiga, tinggiSegitiga);
                hitungKelilingSegitiga(sisiSegitiga1, sisiSegitiga2, sisiSegitiga3);
                break;
            }
            // ======================================
            // KASUS 2: BELAH KETUPAT
            // ======================================
            case 2: {
                printf("=== Belah Ketupat ===\n");
                
                // INPUT DIAGONAL 1
                do {
                    printf("Masukkan diagonal 1: ");
                    if (scanf("%lf", &diagonalBelahKetupat1) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT DIAGONAL 2
                do {
                    printf("Masukkan diagonal 2: ");
                    if (scanf("%lf", &diagonalBelahKetupat2) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI
                do {
                    printf("Masukkan panjang sisi: ");
                    if (scanf("%lf", &sisiBelahKetupat) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);
                printf("=========================================\n");
                hitungLuasBelahKetupat(diagonalBelahKetupat1, diagonalBelahKetupat2);
                hitungKelilingBelahKetupat(sisiBelahKetupat);
                break;
            }
            // ======================================
            // KASUS 3: JAJAR GENJANG
            // ======================================
            case 3: {
                printf("=== Jajar Genjang ===\n");
                
                // INPUT ALAS
                do {
                    printf("Masukkan alas: ");
                    if (scanf("%lf", &alasJajarGenjang) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT TINGGI
                do {
                    printf("Masukkan tinggi: ");
                    if (scanf("%lf", &tinggiJajarGenjang) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI 1
                do {
                    printf("Masukkan sisi pertama: ");
                    if (scanf("%lf", &sisiJajarGenjang1) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI 2
                do {
                    printf("Masukkan sisi kedua: ");
                    if (scanf("%lf", &sisiJajarGenjang2) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);
                printf("=========================================\n");
                hitungLuasJajarGenjang(alasJajarGenjang, tinggiJajarGenjang);
                hitungKelilingJajarGenjang(sisiJajarGenjang1, sisiJajarGenjang2);
                break;
            }
            // ======================================
            // KASUS 4: TRAPESIUM
            // ======================================
            case 4: {
                printf("=== Trapesium ===\n");
                
                // INPUT SISI ATAS
                do {
                    printf("Masukkan sisi atas: ");
                    if (scanf("%lf", &sisiAtasTrapesium) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT SISI BAWAH
                do {
                    printf("Masukkan sisi bawah: ");
                    if (scanf("%lf", &sisiBawahTrapesium) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT TINGGI
                do {
                    printf("Masukkan tinggi: ");
                    if (scanf("%lf", &tinggiTrapesium) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT MIRING 1
                do {
                    printf("Masukkan sisi miring 1: ");
                    if (scanf("%lf", &sisiMiringTrapesium1) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);

                // INPUT MIRING 2
                do {
                    printf("Masukkan sisi miring 2: ");
                    if (scanf("%lf", &sisiMiringTrapesium2) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);
                printf("=========================================\n");
                hitungLuasTrapesium(sisiAtasTrapesium, sisiBawahTrapesium, tinggiTrapesium);
                hitungKelilingTrapesium(sisiAtasTrapesium, sisiBawahTrapesium, sisiMiringTrapesium1, sisiMiringTrapesium2);
                break;
            }
            // ======================================
            // KASUS 5: LINGKARAN
            // ======================================
            case 5: {
                printf("=== Lingkaran ===\n");
                
                // INPUT JARI-JARI
                do {
                    printf("Masukkan jari-jari: ");
                    if (scanf("%lf", &jariJariLingkaran) != 1) { bersihkanBuffer(); continue; }
                    break;
                } while (1);
                printf("=========================================\n");
                hitungLuasLingkaran(jariJariLingkaran);
                hitungKelilingLingkaran(jariJariLingkaran);
                break;
            }
            // ======================================
            
            case 0:
                printf("Terima kasih! Keluar dari program.\n");
                break;
        }

        if (pilihan != 0 && pilihan >= 1 && pilihan <= 5) {
            printf("\nTerimakasih, Silahkan Kembali Ke Menu Jika Ingin Keluar atau Melanjutkan Program..\n");
            printf("\nTekan tombol apa saja untuk kembali ke menu...\n");
            system("pause");
        }

    } while (pilihan != 0);

    return 0;
}

// ---------------------------

// ============================
// Definisi Fungsi Bantuan
// ============================

void bersihkanBuffer() {
    int c;
    printf("\n>>> INPUT GAGAL! Harap masukkan angka. <<<\n");
    // Membersihkan buffer hingga karakter newline atau EOF
    while ((c = getchar()) != '\n' && c != EOF);
}

// ---------------------------

// ============================
// Definisi Fungsi Perhitungan
// ============================

void hitungLuasSegitiga(double alas, double tinggi) {
    double luas = 0.5 * alas * tinggi;
    printf("Luas Segitiga: %.2lf\n", luas);
}

void hitungKelilingSegitiga(double a, double b, double c) {
    double keliling = a + b + c;
    printf("Keliling Segitiga: %.2lf\n", keliling);
}

void hitungLuasBelahKetupat(double d1, double d2) {
    double luas = 0.5 * d1 * d2;
    printf("Luas Belah Ketupat: %.2lf\n", luas);
}

void hitungKelilingBelahKetupat(double sisi) {
    double keliling = 4 * sisi;
    printf("Keliling Belah Ketupat: %.2lf\n", keliling);
}

void hitungLuasJajarGenjang(double alas, double tinggi) {
    double luas = alas * tinggi;
    printf("Luas Jajar Genjang: %.2lf\n", luas);
}

void hitungKelilingJajarGenjang(double sisi1, double sisi2) {
    double keliling = 2 * (sisi1 + sisi2);
    printf("Keliling Jajar Genjang: %.2lf\n", keliling);
}

void hitungLuasTrapesium(double atas, double bawah, double tinggi) {
    double luas = 0.5 * (atas + bawah) * tinggi;
    printf("Luas Trapesium: %.2lf\n", luas);
}

void hitungKelilingTrapesium(double atas, double bawah, double miring1, double miring2) {
    double keliling = atas + bawah + miring1 + miring2;
    printf("Keliling Trapesium: %.2lf\n", keliling);
}

void hitungLuasLingkaran(double r) {
    double luas = pi * r * r;
    printf("Luas Lingkaran: %.2lf\n", luas);
}

void hitungKelilingLingkaran(double r) {
    double keliling = 2 * pi * r;
    printf("Keliling Lingkaran: %.2lf\n", keliling);
}
void tampilkanHeader() {
    system("cls");
    printf("============================================================= \n");
    printf("|              KELOMPOK 4 ALGORITMA PEMOGRAMAN              |\n");
    printf("============================================================= \n");
    printf("| [1] Dhika Pradana                   2505551054            |\n");
    printf("| [2] I Made Duinata                  2505551143            |\n");
    printf("| [3] Reva Majesty Sentanu Karang     2505551171            |\n");
    printf("| [4] Ni Putu Niniek Anjaswari        2505551170            |\n");
    printf("| [5] Ni Ketut Deswita Krismayanti    2505551125            |\n");
    printf("| [6] Muhammad Izzanurdin Hasan       2505551075            |\n");
    printf("| [7] I Gusti Ayu Dwi Kencana Putri   2505551058            |\n");
    printf("============================================================= \n");
    printf("\nTekan tombol apa saja untuk melanjutkan ke menu utama...\n");
    system("pause");
}