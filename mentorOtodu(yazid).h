#ifndef MENTOROTODU_H
#define MENTOROTODU_H
#include "AntrianSiswa(hana).h"
#include "siswa2(shafda).h"

void mentorOtodu() {
    int choice;
    do {
        system("CLS");
        cout << "\nMenu:" << endl;
        cout << "1. Siswa Anda" << endl;
        cout << "2. Antrian Siswa Anda" << endl;
        cout << "3. Logout" << endl;
        cout << "Pilih (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Panggil fungsi tampilkanDaftarSiswa dengan memberikan daftar siswa
                pilihSiswa1();
                break;
            case 2:
                kelolaAntrian();  // Pastikan fungsi kelolaAntrian() sudah didefinisikan
                break;
            case 3:
                
                return; // Logout, kembali ke fungsi pemanggil
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (true);
}

#endif // MENTOROTODU_H
