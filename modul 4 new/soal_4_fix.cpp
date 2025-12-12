#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib> 
using namespace std;

const string NAMA_FILE = "data_mahasiswa.txt";

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
    printf("\nTekan tombol apa saja untuk melanjutkan ke menu utama...\n");
    system("pause");
}

bool cekFileAda() {
    ifstream file(NAMA_FILE);
    return file.good();
}

bool isNumber(const string &str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool isAlphabetic(const string &str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isalpha(c) && c != ' ')
            return false;
    }
    return true;
}

bool isNimAda(const string &nimDicari) {
    ifstream file(NAMA_FILE);
    string nim, nama;

    while (getline(file, nim)) {
        getline(file, nama);
        if (nim == nimDicari) {
            return true;
        }
    }
    return false;
}

void tambahData() {
    string nim, nama;

    cout << "\n--- TAMBAH DATA MAHASISWA ---\n";

    do {
        cout << "Masukkan NIM (angka saja): ";
        getline(cin, nim);

        if (nim.empty()) {
            cout << "[ERROR] NIM tidak boleh kosong!\n";
        }
        else if (!isNumber(nim)) {
            cout << "[ERROR] NIM harus berupa angka!\n";
            nim.clear();
        }
        else if (isNimAda(nim)) {
            cout << "[ERROR] NIM sudah terdaftar!\n";
            nim.clear();
        }

    } while (nim.empty());

    do {
        cout << "Masukkan Nama Lengkap (huruf saja): ";
        getline(cin, nama);

        if (nama.empty()) {
            cout << "[ERROR] Nama tidak boleh kosong!\n";
        }
        else if (!isAlphabetic(nama)) {
            cout << "[ERROR] Nama hanya boleh huruf dan spasi!\n";
            nama.clear();
        }

    } while (nama.empty());

    ofstream file(NAMA_FILE, ios::app);
    file << nim << endl << nama << endl;

    cout << "[SUKSES] Data berhasil disimpan!\n";
}

void tampilkanData() {
    ifstream file(NAMA_FILE);
    string nim, nama;
    int no = 1;

    cout << "\n--- DAFTAR DATA MAHASISWA ---\n";

    if (!file.good() || file.peek() == EOF) {
        cout << "Belum ada data tersimpan.\n";
        return;
    }

    cout << "No.\tNIM\t\tNama\n";
    cout << "---------------------------------------\n";

    while (getline(file, nim)) {
        getline(file, nama);
        cout << no++ << ".\t" << nim << "\t\t" << nama << endl;
    }

    cout << "---------------------------------------\n";
}

void cariData() {
    string nimDicari, nim, nama;
    bool ditemukan = false;

    cout << "\n--- PENCARIAN DATA MAHASISWA ---\n";

    do {
        cout << "Masukkan NIM yang dicari (angka saja): ";
        getline(cin, nimDicari);

        if (nimDicari.empty()) {
            cout << "[ERROR] NIM tidak boleh kosong!\n";
        }
        else if (!isNumber(nimDicari)) {
            cout << "[ERROR] NIM harus angka!\n";
            nimDicari.clear();
        }

    } while (nimDicari.empty());

    ifstream file(NAMA_FILE);

    while (getline(file, nim)) {
        getline(file, nama);
        if (nim == nimDicari) {
            cout << "\n[DITEMUKAN]\n";
            cout << "NIM  : " << nim << endl;
            cout << "Nama : " << nama << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "[INFO] Data mahasiswa tidak ditemukan.\n";
    }
}

int getMenuChoice() {
    string input;
    int pilihan = 0;

    do {
        cout << "Pilihan Anda [1-4]: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "[ERROR] Input tidak boleh kosong!\n";
            continue;
        }

        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) valid = false;
        }

        if (!valid) {
            cout << "[ERROR] Input harus angka 1-4!\n";
            continue;
        }

        pilihan = stoi(input);

        if (pilihan < 1 || pilihan > 4) {
            cout << "[ERROR] Pilihan harus 1-4!\n";
        }

    } while (pilihan < 1 || pilihan > 4);

    return pilihan;
}

int main() {
    int pilihan;

    if (!cekFileAda()) {
        ofstream file(NAMA_FILE);
        file.close();
    }

    displayHeader();

    do {
        system("cls");
        cout << "\n========================================\n";
        cout << "        SISTEM INFORMASI MAHASISWA      \n";
        cout << "========================================\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "----------------------------------------\n";

        pilihan = getMenuChoice();  
        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: cout << "Terima kasih!\n"; break;
        }

        if (pilihan != 4) system("pause");

    } while (pilihan != 4);

    return 0;
}
