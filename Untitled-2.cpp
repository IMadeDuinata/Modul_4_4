#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int n;
scanf("%d", &n);

// Lebar pohon ditentukan oleh baris daun terlebar (baris ke n-1)
int width = (n <= 1) ? 1 : 2 * (n - 1) - 1;

// Mencetak daun pohon (baris 1 sampai n-1)
for (int i = 1; i < n; i++) {
    int stars = 2 * i - 1;
    int spaces = (width - stars) / 2;

    // Cetak spasi
    for (int j = 0; j < spaces; j++) {
        printf(" ");
    }
    // Cetak bintang
    for (int j = 0; j < stars; j++) {
        printf("*");
    }
    printf("\n");
}

// Cetak batang pohon di tengah (baris ke-n)
int spaces = (width - 1) / 2;
for (int j = 0; j < spaces; j++) {
    printf(" ");
}
printf("*\n");
    return 0;
}
