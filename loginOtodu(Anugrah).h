#ifndef LOGINOTODU_H
#define LOGINOTODU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "siswaOtodu(Edwin).h"  // Pastikan header file siswaOtodu tersedia
#include "mentorOtodu(yazid).h"  // Pastikan header file mentorOtodu tersedia
using namespace std;



void loginOtodu() {
    system("cls");

    string username, password;
    string fileUsername, filePassword;
    bool loginSuccess = false;
    int userChoice;

    cout << "---- LOGIN OTODU ----" << endl;
    cout << endl;

    // Pilihan untuk login sebagai Mentor atau Siswa
    cout << "Pilih login sebagai:\n";
    cout << "1. Mentor\n";
    cout << "2. Siswa\n";
    cout << "Pilih (1/2): ";
    cin >> userChoice;
    cin.ignore();  // To clear the input buffer after the choice

    // Input username dan password
    cout << "Username: ";
    getline(cin, username);

    cout << "Password: ";
    getline(cin, password);

    // Fungsi untuk memeriksa file login (dataSiswa.txt dan dataMentor.txt)
    auto checkLoginInFile = [&](const string& filename) -> bool {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string nama, jarak;

                // Format: Nama,Username,Password,Jarak
                getline(ss, nama, ',');
                getline(ss, fileUsername, ',');
                getline(ss, filePassword, ',');
                getline(ss, jarak, ',');

                // Verifikasi username dan password
                if (fileUsername == username && filePassword == password) {
                    return true;  // Login berhasil ditemukan di file
                }
            }
            file.close();
        } else {
            cout << "File " << filename << " tidak ditemukan." << endl;
        }
        return false;
    };

    // Menentukan file mana yang harus dicek berdasarkan pilihan user
    if (userChoice == 1) {
        // Jika pilih mentor, cek dataMentor.txt
        if (checkLoginInFile("dataMentor.txt")) {
            loginSuccess = true;
        }
    } else if (userChoice == 2) {
        // Jika pilih siswa, cek dataSiswa.txt
        if (checkLoginInFile("dataSiswa.txt")) {
            loginSuccess = true;
        }
    } else {
        cout << "\nPilihan tidak valid! Silakan pilih 1 untuk Mentor atau 2 untuk Siswa.\n";
        return;  // Kembali dari fungsi jika pilihan tidak valid
    }

    // Menampilkan hasil login
    if (loginSuccess) {
        system("CLS");
        cout << "\nLogin berhasil! Selamat datang, " << username << "!\n";
        
        // Mengarahkan ke halaman sesuai jenis pengguna
        if (userChoice == 1) {
            mentorOtodu();  // Fungsi untuk mentor
        } else if (userChoice == 2) {
            siswaOtodu();  // Fungsi untuk siswa
        }
    } else {
        cout << "\nLogin gagal! Username atau password salah.\n";
    }
}

#endif // LOGINOTODU_H