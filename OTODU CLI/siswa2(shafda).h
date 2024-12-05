#ifndef SISWA2_H
#define SISWA2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>  // For handling input validation
#include "siswa3.h"  // Assuming this file exists and contains necessary code
#include "mentorOtodu(yazid).h"

using namespace std;

class Siswa3 {
public:
    Siswa3(const string& nama);
    string getNama() const;

private:
    string nama;
};

Siswa3::Siswa3(const string& nama) : nama(nama) {}

string Siswa3::getNama() const {
    return nama;
}

void urutkanSiswa(vector<Siswa3>& daftarSiswa) {
    sort(daftarSiswa.begin(), daftarSiswa.end(), [](const Siswa3& a, const Siswa3& b) {
        return a.getNama() < b.getNama();
    });
}

void tampilkanDaftarSiswa(const vector<Siswa3>& daftarSiswa) {
    system("cls");
    cout << "Daftar Siswa:\n\n";
    for (const auto& siswa : daftarSiswa) {
        cout << siswa.getNama() << endl;
    }

}

void tambahSiswa(vector<Siswa3>& daftarSiswa, const string& nama) {
    daftarSiswa.emplace_back(nama);
}

void pilihSiswa() {
    // Initialize the siswa list
    vector<Siswa3> daftarSiswa = {
        {"Busi"},
        {"Aci"},
        {"Lian"},
        {"Diana"}
    };

    // Sort the siswa list based on the names
    urutkanSiswa(daftarSiswa);
    tampilkanDaftarSiswa(daftarSiswa);
    cout << endl;
    cout << "Ketik apapun untuk kembali";
    getch();
    mentorOtodu();
    
    char choice;
    do {
        // Display the sorted siswa list
        cout << "\n---- DAFTAR SISWA OTODU ----\n";
        for (size_t i = 0; i < daftarSiswa.size(); ++i) {
            cout << i + 1 << ". " << daftarSiswa[i].getNama() << endl;
        }

        // Prompt user to select a siswa
        int siswaChoice;
        cout << "\nPilih siswa yang ingin Anda pilih (1-" << daftarSiswa.size() << "): ";
        while (!(cin >> siswaChoice) || siswaChoice < 1 || siswaChoice > static_cast<int>(daftarSiswa.size())) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Pilihan tidak valid! Silakan masukkan angka antara 1 dan " << daftarSiswa.size() << ": ";
        }

        // Display the chosen siswa
        Siswa3 chosenSiswa = daftarSiswa[siswaChoice - 1];
        cout << "\nAnda telah memilih siswa berikut:\n";
        cout << "Nama: " << chosenSiswa.getNama() << "\n";
        cout << "Siswa berhasil dipilih!\n";

        // Ask if the user wants to choose another siswa
        cout << "\nApakah Anda ingin memilih siswa lain? (y/n): ";
        cin >> choice;
        while (choice != 'y' && choice != 'n') {
            cout << "Input tidak valid! Masukkan 'y' untuk ya atau 'n' untuk tidak: ";
            cin >> choice;
        }

    } while (choice == 'y');  // Repeat if user wants another siswa

    cout << "\nTerima kasih telah menggunakan layanan kami!\n";
}


void pilihSiswa1() {
    int pilihan;
    cout << "Urutkan berdasarkan\n";
    cout << "1. Nama\n";
    cout << "2. Kelas\n";
    cin >> pilihan;

    if (pilihan == 1) {
        pilihSiswa();
    }
    else if (pilihan == 2) {
        siswa3();  
    }
    else {
        cout << "Pilihan tidak valid\n";
    }
}

#endif // SISWA2_H
