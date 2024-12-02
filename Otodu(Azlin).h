#ifndef OTODU_H
#define OTODU_H

#include <iostream>
#include <map>

#include "loginOtodu(Anugrah).h"
#include "daftarOtodu(Hana).h"
using namespace std;

void otodu() {
    int pilihan;
    do {
        

        system("cls");
        cout << "=============== OTODU ==============" << endl;
        cout << "1. Daftar";
        cout << "2. Login";
        cout << "3. Keluar";
        cout << "Pilih (angka): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuDaftar();
                break;
            case 2:
                loginOtodu();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 3);
}
#endif // OTODU_H