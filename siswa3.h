#ifndef SISWA3_H
#define SISWA3_H

// Struktur data Siswa
struct Siswa {
    string nama;
    int kelas;
};

// Fungsi untuk menampilkan siswa di kelas
void siswa3(const vector<Siswa>& daftarSiswa) {
    cout << "\nDaftar Siswa:" << endl;
    for (const auto& siswa : daftarSiswa) {
        cout << "- Nama: " << siswa.nama << ", Kelas: " << siswa.kelas << endl;
    }
}

// Fungsi utama
void siswa3() {
    vector<Siswa> daftarSiswa = {
        {"Budi", 1},
        {"Caca", 2},
        {"Andi", 4},
        {"Abdi", 7}
    };

    // Memanggil fungsi tampilkanSiswa
    siswa3(daftarSiswa);
    cin.ignore();
    cin.get();
}
#endif // SISWA3_H