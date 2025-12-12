#include <stdio.h>
#include <stdlib.h> 

double pi = 3.141592653589793;

void clearBuffer();
void displayHeader();

void processTriangle();
void processRhombus();
void processParallelogram();
void processTrapezoid();
void processCircle();

int inputMenu(); 

int main() {
    int choice;

    displayHeader();

    do {
        choice = inputMenu(); 

        if (choice < 0 || choice > 5) {
            if (choice != 0) {
                printf("\nTekan tombol apa saja untuk kembali ke menu...\n");
                system("pause"); 
            }
            continue; 
        }
        
        printf("===================================================================\n");

        switch (choice) {
            case 1: processTriangle(); break;
            case 2: processRhombus(); break;
            case 3: processParallelogram(); break;
            case 4: processTrapezoid(); break;
            case 5: processCircle(); break;
            case 0: printf("Terima kasih! Keluar dari program.\n"); break;
        }

        if (choice != 0 && choice >= 1 && choice <= 5) {
            printf("\nTerimakasih, Silahkan Kembali Ke Menu Jika Ingin Keluar atau Melanjutkan Program..\n");
            printf("\nTekan tombol apa saja untuk kembali ke menu...\n");
            system("pause");
        }

    } while (choice != 0);

    return 0;
}

int inputMenu() {
    int choice;
    int scan_status;
    
    system("cls");

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
    
    scan_status = scanf("%d", &choice);
    
    if (scan_status != 1) {
        clearBuffer(); 
        choice = -1;
    }
    
    if (choice < 0 || choice > 5) {
        printf("===================================================================\n");
        printf("Pilihan tidak valid. Silakan masukkan angka 0 sampai 5.\n");
        return choice;
    }
    
    return choice;
}

void processTriangle() {
    double base, height, side1, side2, side3;
    double area, perimeter;
    
    printf("=== Segitiga ===\n");
    do { printf("Masukkan alas: "); if (scanf("%lf", &base) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan tinggi: "); if (scanf("%lf", &height) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi pertama: "); if (scanf("%lf", &side1) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi kedua: "); if (scanf("%lf", &side2) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi ketiga: "); if (scanf("%lf", &side3) != 1) { clearBuffer(); continue; } break; } while (1);
    
    area = 0.5 * base * height;
    perimeter = side1 + side2 + side3;
    
    printf("=========================================\n");
    printf("Luas Segitiga: %.2lf\n", area);
    printf("Keliling Segitiga: %.2lf\n", perimeter);
}

void processRhombus() {
    double diagonal1, diagonal2, side;
    double area, perimeter;
    
    printf("=== Belah Ketupat ===\n");
    do { printf("Masukkan diagonal 1: "); if (scanf("%lf", &diagonal1) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan diagonal 2: "); if (scanf("%lf", &diagonal2) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan panjang sisi: "); if (scanf("%lf", &side) != 1) { clearBuffer(); continue; } break; } while (1);
    
    area = 0.5 * diagonal1 * diagonal2;
    perimeter = 4 * side;
    
    printf("=========================================\n");
    printf("Luas Belah Ketupat: %.2lf\n", area);
    printf("Keliling Belah Ketupat: %.2lf\n", perimeter);
}

void processParallelogram() {
    double base, height, side1, side2;
    double area, perimeter;
    
    printf("=== Jajar Genjang ===\n");
    do { printf("Masukkan alas: "); if (scanf("%lf", &base) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan tinggi: "); if (scanf("%lf", &height) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi pertama: "); if (scanf("%lf", &side1) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi kedua: "); if (scanf("%lf", &side2) != 1) { clearBuffer(); continue; } break; } while (1);
    
    area = base * height;
    perimeter = 2 * (side1 + side2);
    
    printf("=========================================\n");
    printf("Luas Jajar Genjang: %.2lf\n", area);
    printf("Keliling Jajar Genjang: %.2lf\n", perimeter);
}

void processTrapezoid() {
    double top_side, bottom_side, height, slanted_1, slanted_2;
    double area, perimeter;

    printf("=== Trapesium ===\n");
    do { printf("Masukkan sisi atas: "); if (scanf("%lf", &top_side) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi bawah: "); if (scanf("%lf", &bottom_side) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan tinggi: "); if (scanf("%lf", &height) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi miring 1: "); if (scanf("%lf", &slanted_1) != 1) { clearBuffer(); continue; } break; } while (1);
    do { printf("Masukkan sisi miring 2: "); if (scanf("%lf", &slanted_2) != 1) { clearBuffer(); continue; } break; } while (1);
    
    area = 0.5 * (top_side + bottom_side) * height;
    perimeter = top_side + bottom_side + slanted_1 + slanted_2;
    
    printf("=========================================\n");
    printf("Luas Trapesium: %.2lf\n", area);
    printf("Keliling Trapesium: %.2lf\n", perimeter);
}

void processCircle() {
    double radius;
    double area, perimeter;
    
    printf("=== Lingkaran ===\n");
    do { printf("Masukkan jari-jari: "); if (scanf("%lf", &radius) != 1) { clearBuffer(); continue; } break; } while (1);
    
    area = pi * radius * radius;
    perimeter = 2 * pi * radius;
    
    printf("=========================================\n");
    printf("Luas Lingkaran: %.2lf\n", area);
    printf("Keliling Lingkaran: %.2lf\n", perimeter);
}

void clearBuffer() {
    int c;
    printf("\n>>> INPUT GAGAL! Harap masukkan angka. <<<\n");
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayHeader() {
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