#include <iostream>
#include <string>
#include <algorithm>

struct Siswa {
    std::string nama;
    std::string kelas;
};

bool bandingkanSiswa(const Siswa &a, const Siswa &b) {
    if (a.nama == b.nama) {
        return a.kelas < b.kelas; 
    }
    return a.nama < b.nama;
}

int main() {
    const int MAX_SISWA = 100;
    Siswa daftarSiswa[MAX_SISWA];
    int jumlahSiswa;

    std::cout << "Masukkan jumlah siswa (maksimal " << MAX_SISWA << "): ";
    std::cin >> jumlahSiswa;

    for (int i = 0; i < jumlahSiswa; ++i) {
        std::cout << "Masukkan nama siswa " << (i + 1) << ": ";
        std::cin >> daftarSiswa[i].nama;
        std::cout << "Masukkan kelas siswa " << (i + 1) << ": ";
        std::cin >> daftarSiswa[i].kelas;
    }

    std::sort(daftarSiswa, daftarSiswa + jumlahSiswa, bandingkanSiswa);

    std::cout << "\nDaftar siswa setelah diurutkan:\n";
    for (int i = 0; i < jumlahSiswa; ++i) {
        std::cout << "Nama: " << daftarSiswa[i].nama << ", Kelas: " << daftarSiswa[i].kelas << std::endl;
    }

    return 0;
}