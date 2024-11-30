#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Fungsi placeholder (belum diimplementasikan)
void siswaAnda() {
    cout << "\nFitur ini belum tersedia. Akan segera hadir!" << endl;
}

// Fungsi untuk menampilkan antrian siswa
void antrianSiswaAnda() {
    cout << "\nFitur ini belum tersedia. Akan segera hadir!" << endl;
}

// Fungsi untuk logout
bool logout() {
    char pilihan;
    cout << "\nApakah Anda yakin ingin logout? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y') {
        cout << "Anda telah logout. Kembali ke halaman utama." << endl;
        return true;
    } else {
        cout << "Logout dibatalkan. Kembali ke menu utama." << endl;
        return false;
    }
}

// Fungsi menu utama
void mainMenu() {
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Siswa Anda" << endl;
        cout << "2. Antrian Siswa Anda" << endl;
        cout << "3. Logout" << endl;
        cout << "Pilih (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                siswaAnda();
                break;
            case 2:
                antrianSiswaAnda();
                break;
            case 3:
                if (logout()) {
                    return; // Kembali ke fungsi pemanggil (main)
                }
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (true);
}

// Fungsi utama
int main() {
    while (true) {
        mainMenu();
    }

    return 0;
}
