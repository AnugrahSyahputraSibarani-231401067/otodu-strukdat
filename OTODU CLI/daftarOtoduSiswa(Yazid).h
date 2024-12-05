#ifndef DAFTAROTODUSISWA_H
#define DAFTAROTODUSISWA_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>
using namespace std;

// Struktur untuk menyimpan data user
struct User {
    string nama;
    string username;
    string password;
    int kelas;
    double jarak;
};

// Deklarasi fungsi
void loadSiswaFromFile();
bool isUsernameTaken(const unordered_set<string>& usernames, const string& username);
void daftarOtoduSiswa();

// Fungsi untuk mengecek apakah username sudah ada
bool isUsernameTaken(const unordered_set<string>& usernames, const string& username) {
    return usernames.find(username) != usernames.end();
}

// Fungsi untuk membaca data siswa dari file
void loadSiswaFromFile() {
    ifstream file("dataSiswa.txt");
    if (file.is_open()) {
        string line;
        cout << "\n=====================================\n";
        cout << "      DAFTAR AKUN TERDAFTAR         \n";
        cout << "=====================================\n";

        while (getline(file, line)) {
            // Format: Nama,Username,Password,Jarak
            stringstream ss(line);
            string nama, username, password, kelas, jarak;

            getline(ss, nama, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, kelas, ',');
            getline(ss, jarak, ',');

            cout << "Nama: " << nama << endl;
            cout << "Username: " << username << endl;
            cout << "Password: " << string(password.length(), '*') << endl;
            cout << "Kelas: " << kelas << endl;
            cout << "Jarak: " << jarak << " meter\n";
            cout << "-------------------------------------\n";
        }

        file.close();
    } else {
        cout << "File dataSiswa.txt tidak ditemukan." << endl;
    }
}

// Fungsi untuk menyimpan data siswa
void saveSiswaToFile(const User& siswa) {
    ofstream file("dataSiswa.txt", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << siswa.nama << "," << siswa.username << "," << siswa.password << "," <<siswa.kelas << "," << siswa.jarak << "\n";
        file.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan data siswa." << endl;
    }
}


// Fungsi untuk mendaftar akun siswa
void daftarOtoduSiswa() {
    vector<User> users; // Vector untuk menyimpan semua user
    unordered_set<string> usernames; // Hash set untuk username yang sudah terpakai
    char lanjut;

    do {
        system("cls"); // Membersihkan layar (hanya berfungsi di Windows)
        cout << "=====================================\n";
        cout << "          DAFTAR OTODU              \n";
        cout << "=====================================\n";
        cout << "Silahkan Daftar Akun Anda!\n\n";

        User newUser;

        // Input nama
        cout << "Nama: ";
        cin.ignore(); // Menghindari masalah dengan getline setelah cin
        getline(cin, newUser.nama);

        bool usernameValid = false;
        while (!usernameValid) {
            cout << "Username: ";
            getline(cin, newUser.username);

            // Mengecek apakah username sudah ada
            if (isUsernameTaken(usernames, newUser.username)) {
                cout << "\nUsername sudah terpakai! Silakan gunakan username lain.\n\n";
            } else {
                usernameValid = true;
            }
        }

        cout << "Password: ";
        getline(cin, newUser.password);

        cout << "Kelas: ";
        cin >> newUser.kelas;

        // Input jarak dengan validasi
        do {
            cout << "Jarak antara kantor OTODU dengan rumah anda (meter): ";
            cin >> newUser.jarak;

            if (cin.fail() || newUser.jarak <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Masukkan jarak yang valid (angka positif)!\n";
            } else {
                break;
            }
        } while (true);

        // Menyimpan data user baru
        users.push_back(newUser);
        usernames.insert(newUser.username);

        // Simpan data ke file
        saveSiswaToFile(newUser);

        system("CLS");
        cout << "\nAkun Siswa berhasil didaftarkan!" << endl;
        cout << "Nama: " << newUser.nama << endl;
        cout << "Username: " << newUser.username << endl;
        cout << "Password: " << string(newUser.password.length(), '*') << endl;
        cout << "Kelas: " << newUser.kelas << endl;
        cout << "Jarak: " << newUser.jarak << " meter\n";

        cout << "\nIngin mendaftarkan akun lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    // Memuat data dari file
    loadSiswaFromFile();
}

#endif // DAFTAROTODUSISWA_H
