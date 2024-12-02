#ifndef DAFTAROTODU_H

#define DAFTAROTODU_H

#include <cctype> // Untuk toupper
#include "daftarOtoduMentor(Hana).h"
#include "AntrianSiswa(hana).h"
#include "daftarOtoduSiswa(Yazid).h"

void daftarMentor() {
    string nama, username, password, gelar;
    float jarak;

    cout << "======= DAFTAR OTODU =======" << endl;
    cout << "Silahkan daftar akun mentor Anda!" << endl;

    cout << "Nama: ";
    cin >> nama;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    cout << "Gelar singkat: ";
    cin >> gelar;

    cout << "Jarak rumah ke kantor OTODU (m): ";
    cin >> jarak;

    if (addmentor(nama, username, password, gelar, jarak)) {
        cout << "Akun berhasil didaftarkan!" << endl;
    } else {
        cout << "Gagal mendaftarkan akun. Username sudah digunakan." << endl;
    }
}

void menuDaftar() {
    char jawaban;

    cout << "Daftar sebagai mentor (M) atau siswa (S): ";
    cin >> jawaban;

    jawaban = toupper(jawaban);
    if (jawaban == 'M') {
        cout << "Memilih daftar sebagai mentor." << endl;
        daftarMentor(); // Panggil fungsi daftar mentor
    } else if (jawaban == 'S') {
        cout << "Memilih daftar sebagai siswa." << endl;
        daftarOtoduSiswa();
    } else {
        cout << "Pilihan tidak tersedia." << endl;
    }
}
#endif // DAFTAROTODU_H