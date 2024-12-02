#ifndef SISWAOTODU_H
#define SISWAOTODU_H

#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

void siswaOtodu(){
    int pilihan;
    
    system("cls"); // Membersihkan layar
    cout << "=====================================\n";
    cout << "            SISWA OTODU              \n";
    cout << "=====================================\n";
    cout << "1. Beli Kursus NLP\n";
    cout << "2. Pesan Mentor   \n";
    cout << "3. Riwayat NLP    \n";
    cout << "4. Logout         \n";
    cout << "=====================================\n";
    cout << "Pilih Menu (1-4): ";

    if (!(cin >> pilihan)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pilihan = 0; // Default jika input salah
    }

    switch(pilihan){
        case 1: 
            // Beralih ke halaman beli kursus
            beliNLP();
            break;
        case 2:
            // Beralih ke halaman pesan mentor
            pesanMentor();
            break;  
        case 3: 
            // Beralih ke halaman riwayat NLP
            riwayatNLP();
            break;
        case 4:
            // Beralih ke halaman awal yaitu login
            login();
            break;
        default: 
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            getch();
            siswaOtodu();
            break;
        }
        
}
#endif // SISWAOTODU_H