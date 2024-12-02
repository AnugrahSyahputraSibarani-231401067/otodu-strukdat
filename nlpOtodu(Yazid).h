#ifndef MATEMATIKA_BAHASA_H
#define MATEMATIKA_BAHASA_H

#include <iostream>
#include <conio.h>
using namespace std;

// Fungsi untuk halaman Matematika
void halamanMatematika() {
    system("cls"); // Membersihkan layar
    cout << "=====================================\n";
    cout << "           HALAMAN MATEMATIKA       \n";
    cout << "=====================================\n";
    cout << "\nSelamat datang di halaman Matematika!\n";
    cout << "Di sini Anda dapat belajar berbagai materi matematika.\n\n";
    cout << "Tekan tombol apapun untuk kembali ke menu utama...";
    getch();
}

// Fungsi untuk halaman Bahasa Inggris
void halamanBahasaInggris() {
    system("cls"); // Membersihkan layar
    cout << "=====================================\n";
    cout << "        HALAMAN BAHASA INGGRIS      \n";
    cout << "=====================================\n";
    cout << "\nWelcome to English Page!\n";
    cout << "Here you can learn various English materials.\n\n";
    cout << "Tekan tombol apapun untuk kembali ke menu utama...";
    getch();
}

// Fungsi untuk menampilkan menu utama
void nlpOtodu() {
    int pilihan;

    do {
        system("cls"); // Membersihkan layar
        cout << "=====================================\n";
        cout << "            NLP OTODU               \n";
        cout << "=====================================\n";
        cout << "1. MATEMATIKA\n";
        cout << "2. BAHASA INGGRIS\n";
        cout << "3. KELUAR\n";
        cout << "=====================================\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                halamanMatematika();
                break;
            case 2:
                halamanBahasaInggris();
                break;
            case 3:
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                return; // Kembali dari fungsi nlpOtodu
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
                cout << "Tekan tombol apapun untuk melanjutkan...";
                getch();
        }

    } while (true);
}

#endif // MATEMATIKA_BAHASA_H

// Fungsi utama
int main() {
    nlpOtodu(); // Memanggil fungsi nlpOtodu
    return 0;
}
