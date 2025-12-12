#include <iostream>
#include <fstream>
#include <string>
#include <limits> 

using namespace std;

const string NAMA_FILE = "data_mahasiswa.txt";

bool cekFileAda() {
    ifstream file(NAMA_FILE);
    return file.good();
}

bool isNimAda(string nimDicari) {
    ifstream file(NAMA_FILE);
    string nim, nama;
    
    if (!file.is_open()) return false;

    while (getline(file, nim)) {
        if (getline(file, nama)) { 
            if (nim == nimDicari) {
                file.close();
                return true; 
            }
        }
    }
    file.close();
    return false; 
}

void tambahData() {
    string nim, nama;
    
    cout << "\n--- TAMBAH DATA MAHASISWA ---\n";
    cout << "Masukkan NIM: ";
    cin >> nim;

    if (isNimAda(nim)) {
        cout << "[ERROR] Data dengan NIM " << nim << " sudah ada! Penambahan digagalkan.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan Nama Lengkap: ";
    getline(cin, nama);

    ofstream file(NAMA_FILE, ios::app);
    
    if (file.is_open()) {
        file << nim << endl;
        file << nama << endl;
        cout << "[SUKSES] Data berhasil disimpan ke " << NAMA_FILE << ".\n";
        file.close();
    } else {
        cout << "[ERROR] Gagal membuka file untuk menulis.\n";
    }
}

void tampilkanData() {
    ifstream file(NAMA_FILE);
    string nim, nama;
    int no = 1;

    cout << "\n--- DAFTAR DATA MAHASISWA ---\n";
    
    if (!file.is_open() || file.peek() == ifstream::traits_type::eof()) {
        cout << "Belum ada data tersimpan atau file tidak ditemukan.\n";
        return;
    }

    cout << "No.\tNIM\t\tNama Mahasiswa\n";
    cout << "------------------------------------------------\n";

    while (getline(file, nim)) {
        if (getline(file, nama)) {
            cout << no++ << ".\t" << nim << "\t\t" << nama << endl;
        }
    }
    cout << "------------------------------------------------\n";
    file.close();
}

void cariData() {
    string nimDicari, nim, nama;
    bool ditemukan = false;

    cout << "\n--- PENCARIAN DATA MAHASISWA ---\n";
    cout << "Masukkan NIM yang dicari: ";
    cin >> nimDicari;

    ifstream file(NAMA_FILE);
    if (!file.is_open()) {
        cout << "File data belum dibuat.\n";
        return;
    }

    while (getline(file, nim)) {
        if (getline(file, nama)) {
            if (nim == nimDicari) {
                cout << "\n[DITEMUKAN] Data Mahasiswa:\n";
                cout << "NIM  : " << nim << endl;
                cout << "Nama : " << nama << endl;
                ditemukan = true;
                break;
            }
        }
    }

    if (!ditemukan) {
        cout << "[INFO] Data dengan NIM " << nimDicari << " tidak ditemukan.\n";
    }
    file.close();
}

int main() {
    int pilihan;

    if (!cekFileAda()) {
        ofstream file(NAMA_FILE);
        file.close();
    }

    do {
        cout << "\n========================================\n";
        cout << "   SISTEM INFORMASI DATA MAHASISWA      \n";
        cout << "========================================\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data (Berdasarkan NIM)\n";
        cout << "4. Keluar\n";
        cout << "----------------------------------------\n";
        cout << "Pilihan Anda [1-4]: ";
        
        while(!(cin >> pilihan)){ 
            cout << "Input salah! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cariData();
                break;
            case 4:
                cout << "Terima kasih. Program dihentikan.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}