#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data Siswa
struct Siswa {
    string nama;
    int kelas;
};

// Fungsi untuk menampilkan siswa di kelas
void siswaAndaKelas() {
    vector<Siswa> daftarSiswa = {
        {"Yazid", 10},
        {"Aisyah", 11},
        {"Ali", 12}
    };

    cout << "\nDaftar Siswa:" << endl;
    for (const auto& siswa : daftarSiswa) {
        cout << "- Nama: " << siswa.nama << ", Kelas: " << siswa.kelas << endl;
    }
}