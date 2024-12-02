#ifndef MATEMATIKA_BAHASA_H
#define MATEMATIKA_BAHASA_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Struktur untuk menyimpan data user
struct User {
    string nama;
    string username;
    string password;
    double jarak;
};

// Fungsi untuk mengecek apakah username sudah ada
bool isUsernameTaken(const unordered_set<string>& usernames, const string& username) {
    return usernames.find(username) != usernames.end();
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

        User newUser ;

        // Input nama
        cout << "Nama: ";
        cin.ignore(); // Menghindari masalah dengan getline setelah cin
        getline(cin, newUser .nama);

        bool usernameValid = false;
        while (!usernameValid) {
            cout << "Username: ";
            getline(cin, newUser .username);

            // Mengecek apakah username sudah ada
            if (isUsernameTaken(usernames, newUser .username)) {
                cout << "\nUsername sudah terpakai! Silakan gunakan username lain.\n\n";
            } else {
                usernameValid = true;
            }
        }

        cout << "Password: ";
        getline(cin, newUser .password);

        // Input jarak dengan validasi
        do {
            cout << "Jarak antara kantor OTODU dengan rumah anda (meter): ";
            cin >> newUser .jarak;

            if (cin.fail() || newUser .jarak <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Masukkan jarak yang valid (angka positif)!\n";
            } else {
                break;
            }
        } while (true);

        // Menyimpan data user baru
        users.push_back(newUser );
        usernames.insert(newUser .username);

        cout << "\nPendaftaran berhasil!\n";
        cout << "\nData yang tersimpan:\n";
        cout << "Nama: " << newUser .nama << endl;
        cout << "Username: " << newUser .username << endl;
        cout << "Password: " << string(newUser .password.length(), '*') << endl;
        cout << "Jarak: " << newUser .jarak << " meter\n";

        cout << "\nIngin mendaftarkan akun lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    // Menampilkan semua user yang terdaftar
    cout << "\n=====================================\n";
    cout << "      DAFTAR AKUN TERDAFTAR         \n";
    cout << "=====================================\n";

    for (size_t i = 0; i < users.size(); i++) {
        cout << "\nUser  #" << i + 1 << endl;
        cout << "Nama: " << users[i].nama << endl;
        cout << "Username: " << users[i].username << endl;
        cout << "Password: " << string(users[i].password.length(), '*') << endl;
        cout << "Jarak: " << users[i].jarak << " meter\n";
    }

    cout << "\nTerima kasih telah menggunakan program ini!\n";
}

// Fungsi utama
int main() {
    daftarOtoduSiswa(); // Memanggil fungsi pendaftaran
    return 0;
}

#endif // MATEMATIKA_BAHASA_H
