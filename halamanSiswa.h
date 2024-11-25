#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

void halamanSiswa(){
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
            beliNLP();
            break;
        case 2:
            pesanMentor();
            break;  
        case 3: 
            riwayatNLP();
            break;
        case 4:
            login();
            break;
        default: 
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            getch();
            halamansiswa();
            break;
        }
        
}
