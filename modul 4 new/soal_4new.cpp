#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

const string NAMA_FILE = "data_mahasiswa.txt";

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
        getline(cin >> ws, nim); 
        if (!isNumber(nim)) {
            cout << "[ERROR] NIM harus berupa angka dan tidak boleh kosong!\n";
            nim.clear();
        } else if (isNimAda(nim)) {
            cout << "[ERROR] Data dengan NIM ini sudah ada!\n";
            nim.clear();
        }
    } while (nim.empty());

    do {
        cout << "Masukkan Nama Lengkap (huruf saja): ";
        getline(cin, nama);
        if (!isAlphabetic(nama)) {
            cout << "[ERROR] Nama harus huruf saja dan tidak boleh kosong!\n";
            nama.clear();
        }
    } while (nama.empty());

    ofstream file(NAMA_FILE, ios::app);
    file << nim << endl << nama << endl;
    file.close();

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
    file.close();
}

void cariData() {
    string nimDicari, nim, nama;
    bool ditemukan = false;

    cout << "\n--- PENCARIAN DATA MAHASISWA ---\n";

    do {
        cout << "Masukkan NIM yang dicari (angka saja): ";
        getline(cin >> ws, nimDicari);
        if (!isNumber(nimDicari)) {
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

int main() {
    int pilihan;

    if (!cekFileAda()) {
        ofstream file(NAMA_FILE);
        file.close();
    }

    do {
        cout << "\n========================================\n";
        cout << "  SISTEM INFORMASI DATA MAHASISWA       \n";
        cout << "========================================\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data (Berdasarkan NIM)\n";
        cout << "4. Keluar\n";
        cout << "----------------------------------------\n";
        cout << "Pilihan Anda [1-4]: ";

        while (!(cin >> pilihan)) {
            cout << "Input salah! Masukkan angka 1-4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}
