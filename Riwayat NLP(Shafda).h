#ifndef RIWATARNLP_H
#define RIWATARNLP_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void calculateTrigonometry(double angle) {
    double radian = angle * (M_PI / 180.0);
    
    cout << fixed << setprecision(4);
    cout << "Sin(" << angle << ") = " << sin(radian) << endl;
    cout << "Cos(" << angle << ") = " << cos(radian) << endl;
    cout << "Tan(" << angle << ") = " << tan(radian) << endl;
}

void displayHistory() {
    cout << "Riwayat Trigonometri dalam Natural Language Processing (NLP):" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "1. Trigonometri digunakan dalam analisis sinyal dan pemrosesan suara." << endl;
    cout << "2. Beberapa algoritma NLP menggunakan transformasi Fourier, yang melibatkan fungsi sinus dan kosinus." << endl;
    cout << "3. Dalam pengenalan pola, trigonometri dapat membantu dalam mengukur sudut dan jarak antara fitur." << endl;
    cout << "4. Model-model tertentu dalam NLP, seperti model vektor ruang, dapat menggunakan representasi sudut untuk menghitung kesamaan antar dokumen." << endl;
    cout << "5. Trigonometri juga digunakan dalam visualisasi data, di mana sudut dan jarak dapat merepresentasikan hubungan antar data." << endl;
    cout << "----------------------------------------------------------" << endl;
}

// int main() {
//     int choice;
//     double angle;

//     do {
//         cout << "\nMenu:\n";
//         cout << "1. Tampilkan Riwayat Trigonometri dalam NLP\n";
//         cout << "2. Hitung Nilai Trigonometri\n";
//         cout << "3. Keluar\n";
//         cout << "Pilih opsi: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 displayHistory();
//                 break;
//             case 2:
//                 cout << "Masukkan sudut dalam derajat: ";
//                 cin >> angle;
//                 calculateTrigonometry(angle);
//                 break;
//             case 3:
//                 cout << "Keluar dari program." << endl;
//                 break;
//             default:
//                 cout << "Pilihan tidak valid!" << endl;
//         }
//     } while (choice != 3);

//     return 0;
// }
#endif // RIWATARNLP_H