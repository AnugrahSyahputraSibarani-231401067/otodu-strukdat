#ifndef DAFTAROTODU_H
#define DAFTAROTODU_H

#include <cctype> // Untuk toupper

#include "AntrianSiswa(hana).h"
#include "daftarOtoduMentor(Hana).h"
#include "daftarOtoduSiswa(Yazid).h"

void daftarMentor() {
    char lanjut;

    do {
        string nama, username, password, gelar;
        float jarak;

        system("CLS");
        cout << "======= DAFTAR OTODU =======" << endl;
        cout << "Silahkan daftar akun mentor Anda!" << endl;

        cout << "Nama: ";
        cin.ignore();  // Menghindari masalah dengan getline setelah cin
        getline(cin, nama);

        cout << "Username: ";
        getline(cin, username);

        cout << "Password: ";
        getline(cin, password);

        cout << "Gelar singkat: ";
        getline(cin, gelar);

        cout << "Jarak rumah ke kantor OTODU (m): ";
        cin >> jarak;

        system("CLS");
        if (addmentor(nama, username, password, gelar, jarak)) {
            cout << "\nAkun Mentor berhasil didaftarkan!" << endl;

            // Menampilkan data yang sudah dimasukkan
            cout << "\nData yang tersimpan:\n";
            cout << "Nama: " << nama << endl;
            cout << "Username: " << username << endl;
            cout << "Password: " << string(password.length(), '*') << endl;
            cout << "Gelar: " << gelar << endl;
            cout << "Jarak: " << jarak << " meter" << endl;
        } else {
            cout << "Gagal mendaftarkan akun. Username sudah digunakan." << endl;
        }

        // Menanyakan apakah ingin mendaftarkan akun lain
        cout << "\nIngin mendaftarkan akun lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');
}


void menuDaftar() {
    char jawaban;

    cout << "Daftar sebagai mentor (M) atau siswa (S): ";
    cin >> jawaban;

    jawaban = toupper(jawaban);
    if (jawaban == 'M') {
        daftarMentor(); // Panggil fungsi daftar mentor
    } else if (jawaban == 'S') {
        daftarOtoduSiswa();
    } else {
        cout << "Pilihan tidak tersedia." << endl;
    }
}
#endif // DAFTAROTODU_H