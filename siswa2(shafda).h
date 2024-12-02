#ifndef SISWA2_H
#define SISWA2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Siswa {
public:
    Siswa(const string& nama);
    string getNama() const;

private:
    string nama;
};

Siswa::Siswa(const string& nama) : nama(nama) {}

string Siswa::getNama() const {
    return nama;
}

void urutkanSiswa(vector<Siswa>& daftarSiswa) {
    sort(daftarSiswa.begin(), daftarSiswa.end(), [](const Siswa& a, const Siswa& b) {
        return a.getNama() < b.getNama();
    });
}

void tampilkanDaftarSiswa(const vector<Siswa>& daftarSiswa) {
    cout << "Daftar Siswa:\n";
    for (const auto& siswa : daftarSiswa) {
        cout << siswa.getNama() << endl;
    }
}

void tambahSiswa(vector<Siswa>& daftarSiswa, const string& nama) {
    daftarSiswa.emplace_back(nama);
}

// int main() {
//     vector<Siswa> daftarSiswa;

//     tambahSiswa(daftarSiswa, "abdi");
//     tambahSiswa(daftarSiswa, "bani");
//     tambahSiswa(daftarSiswa, "budi");
//     tambahSiswa(daftarSiswa, "caca");

//     urutkanSiswa(daftarSiswa);

//     tampilkanDaftarSiswa(daftarSiswa);

//     string namaBaru;
//     cout << "Masukkan nama siswa baru: ";
//     getline(cin, namaBaru);
//     tambahSiswa(daftarSiswa, namaBaru);

//     urutkanSiswa(daftarSiswa);

//     tampilkanDaftarSiswa(daftarSiswa);

//     return 0;
// }
#endif // SISWA2_H