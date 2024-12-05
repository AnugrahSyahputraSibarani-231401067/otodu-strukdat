#ifndef SISWA3_H
#define SISWA3_H

#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::sort
#include <conio.h>
#include "mentorOtodu(yazid).h"
using namespace std;

// Struktur data Siswa
struct Siswa {
    string nama;
    int kelas;
};

// Fungsi untuk menampilkan daftar siswa
void tampilkanSiswa(const vector<Siswa>& daftarSiswa) {
    system("cls");
    cout << "\nDaftar Siswa:" << endl;
    for (const auto& siswa : daftarSiswa) {
        cout << "- Nama: " << siswa.nama << ", Kelas: " << siswa.kelas << endl;
    }
}

// Fungsi untuk mengurutkan siswa berdasarkan kelas menggunakan Bubble Sort
void bubbleSort(vector<Siswa>& daftarSiswa) {
    int n = daftarSiswa.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (daftarSiswa[j].kelas > daftarSiswa[j + 1].kelas) {
                // Tukar elemen
                swap(daftarSiswa[j], daftarSiswa[j + 1]);
            }
        }
    }
}

void mentorOtodu();

// Fungsi utama
void siswa3() {
    vector<Siswa> daftarSiswa = {
        {"Caca", 2},
        {"Budi", 1},
        {"Andi", 4},
        {"Abdi", 7}
    };

    // Sorting menggunakan Bubble Sort
    bubbleSort(daftarSiswa);

    // Tampilkan setelah sorting
    tampilkanSiswa(daftarSiswa);
    cout << "\n\nKetik apapun untuk kembali.";
    getch();
    mentorOtodu();

    cin.ignore();
    cin.get();
}

#endif // SISWA3_H