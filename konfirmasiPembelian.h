#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

void konfirmasiPembelian(){
    int pilihan;

    system("cls");
    cout << "=====================================\n";
    cout << "        Konfirmasi Pembelian         \n";
    cout << "=====================================\n";
    cout << "Anda akan membeli kursus NLP \n\" " << materi << "\" dengan harga Rp5.000.\n\n";
    cout << "Ketik 1 untuk konfirmasi\n";
    cout << "Ketik 2 untuk ke halaman awal\n";
    cout << "Pilih Menu (1-2): ";

    if (!(cin >> pilihan)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pilihan = 0; // Default jika input salah
    }
        
    switch(pilihan){
        case 1 :
            riwayatNLP();
            break;
        case 2 : 
            halamanSiswa();
            break;
        default: 
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            getch();
            konfirmasiPembelian();
            break;
    }

}
