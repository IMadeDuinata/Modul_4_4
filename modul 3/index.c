#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 64000

const char *red = "\033[31m";    
const char *green = "\033[32m";  
const char *yellow = "\033[33m"; 
const char *blue = "\033[34m";   
const char *reset = "\033[0m";   

void clearScreenFull() {
    printf("%sPress Enter to continue...%s\n", green, reset);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void welcome(){
    printf("%s========================================================%s\n", red, reset);
    printf("%s[                      MODUL 3                         ]%s\n", red, reset);
    printf("%s[          PRAKTIKUM ALGORITMA DAN PEMROGRAMAN         ]%s\n", red, reset);
    printf("%s[        [Program Metode Sorting dan Searching]        ]%s\n", red, reset);
    printf("%s========================================================%s\n", red, reset);

    clearScreenFull();
}

void validateInputInt(int *var, const char *message) 
{
    char buff[1024];
    char check;
    while (1) {
        printf("%s%s%s", yellow, message, reset);
        if (fgets(buff, sizeof(buff), stdin) != NULL) {
            if (sscanf(buff, "%d %c", var, &check) == 1) {
                return;
            }
        }
        printf("\t %sInput salah! Silahkan masukkan angka.%s\n", red, reset);
    }
}

void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int sequentialSearch(int arr[], int n, int key);
int binarySearch(int arr[], int left, int right, int key);
void generateRandomArray(int arr[], int n);
void displayArray(int arr[], int n);
int validateInput(int min, int max); 

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n + 1); 
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int validateInput(int min, int max){
    char buff[128];
    int value;
    char extra;
    while (1) {
        if (fgets(buff, sizeof(buff), stdin) == NULL) continue;
        if (sscanf(buff, "%d %c", &value, &extra) == 1) {
            if (value < min || value > max) {
                printf("%sMasukkan angka antara %d dan %d.%s\n", red, min, max, reset);
            } else {
                return value;
            }
        } else {
            printf("%sInput tidak valid. Silakan masukkan angka.%s\n", red, reset);
        }
    }
}

int main() {
    int n = 0;
    int arr[MAX_SIZE];
    int choice, key, index;
    
    srand((unsigned int)time(NULL));

    welcome ();

    do {
        clearScreenFull();
        printf("%s============================================%s\n", red, reset);
        printf("%s[            Pilih Jumlah Data             ]%s\n", red, reset);
        printf("%s============================================%s\n", red, reset);
        printf("%s[              1. n = 1000                 ]%s\n", red, reset);
        printf("%s[              2. n = 16000                ]%s\n", red, reset);
        printf("%s[              3. n = 64000                ]%s\n", red, reset);
        printf("%s[              0. Keluar                   ]%s\n", red, reset);
        printf("%s============================================%s\n", red, reset);
        validateInputInt(&choice, "Masukkan pilihan (0-3): ");

        if (choice < 0 || choice > 3) {
            printf("%s\tPilihan tidak valid. Masukkan angka antara 0 sampai 3!%s\n", red, reset);
        }
    } while (choice < 0 || choice > 3);

    switch (choice) {
        case 1:
            n = 1000;
            break;
        case 2:
            n = 16000;
            break;
        case 3:
            n = 64000;
            break;
        case 0:
            printf("Keluar. Terima kasih!\n");
            return 0;
        default:
            printf("%sPilihan tidak valid.%s\n", red, reset);
            return 0;
    }

    generateRandomArray(arr, n);

    printf("\nArray Sebelum Diurutkan (50 elemen pertama):\n");
    displayArray(arr, (n < 50) ? n : 50);

    while (1) {
        printf("\nPilih metode:\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Sequential Search\n");
        printf("5. Binary Search\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda (1-6): ");

        choice = validateInput(1, 6);

        if (choice == 6) {
            printf("Terima kasih telah menggunakan program ini!\n");
            break;
        }

        clock_t start, end;
        double cpu_time_used;

        switch (choice) {
            case 1:
                start = clock();
                insertionSort(arr, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Waktu Insertion Sort: %.6f detik\n", cpu_time_used);
                printf("Array Setelah Insertion Sort (50 elemen pertama):\n");
                displayArray(arr, (n < 50) ? n : 50);
                break;

            case 2:
                start = clock();
                bubbleSort(arr, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Waktu Bubble Sort: %.6f detik\n", cpu_time_used);
                printf("Array Setelah Bubble Sort (50 elemen pertama):\n");
                displayArray(arr, (n < 50) ? n : 50);
                break;

            case 3:
                start = clock();
                quickSort(arr, 0, n - 1);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Waktu Quick Sort: %.6f detik\n", cpu_time_used);
                printf("Array Setelah Quick Sort (50 elemen pertama):\n");
                displayArray(arr, (n < 50) ? n : 50);
                break;

            case 4:
                printf("Masukkan angka yang ingin dicari: ");
                key = validateInput(0, n); 
                start = clock();
                index = sequentialSearch(arr, n, key);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                if (index != -1) {
                    printf("Angka %d ditemukan pada indeks %d\n", key, index);
                } else {
                    printf("Angka %d tidak ditemukan\n", key);
                }
                printf("Waktu Sequential Search: %.6f detik\n", cpu_time_used);
                break;

            case 5:
                printf("Array harus terurut untuk Binary Search. Melakukan Quick Sort terlebih dahulu...\n");
                quickSort(arr, 0, n - 1); 
                printf("Masukkan angka yang ingin dicari: ");
                key = validateInput(0, n);
                start = clock();
                index = binarySearch(arr, 0, n - 1, key);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                if (index != -1) {
                    printf("Angka %d ditemukan pada indeks %d\n", key, index);
                } else {
                    printf("Angka %d tidak ditemukan\n", key);
                }
                printf("Waktu Binary Search: %.6f detik\n", cpu_time_used);
                break;

            default:
                printf("%sPilihan tidak valid.%s\n", red, reset);
                break;
        }
    }

    return 0;
}