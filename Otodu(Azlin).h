#include <iostream>
#include <map>
using namespace std;

void daftar(map<int, int>& akun) {
    int id, pin;
    cout << "=== Daftar Akun Baru ===" << endl;
    cout << "Masukkan ID (angka): ";
    cin >> id;
    cout << "Masukkan PIN (angka 4 digit): ";
    cin >> pin;

    // Cek apakah ID sudah terdaftar
    if (akun.find(id) != akun.end()) {
        cout << "ID sudah terdaftar. Coba ID lain.\n";
    } else {
        akun[id] = pin;
        cout << "Akun berhasil didaftarkan!\n";
    }
}

void login(const map<int, int>& akun) {
    int id, pin;
    cout << "=== Login ===" << endl;
    cout << "Masukkan ID: ";
    cin >> id;
    cout << "Masukkan PIN: ";
    cin >> pin;

    // Cek apakah ID dan PIN cocok
    if (akun.find(id) != akun.end() && akun.at(id) == pin) {
        cout << "Login berhasil! Selamat datang, ID " << id << "!\n";
    } else {
        cout << "ID atau PIN salah. Coba lagi.\n";
    }
}

void menu() {
    map<int, int> akun; // Menyimpan ID dan PIN
    int pilihan;

    do {
        cout << "\n=== OTODU ===" << endl;
        cout << "1. Daftar\n2. Login\n3. Keluar\n";
        cout << "Pilih (angka): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                daftar(akun);
                break;
            case 2:
                login(akun);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 3);
}
