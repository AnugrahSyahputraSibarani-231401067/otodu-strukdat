#ifndef NLP_OTODU_H
#define NLP_OTODU_H


#include <iostream>
#include <stack> // Include stack to track history
#include "siswaOtodu(Edwin).h"
#include <fstream> // Include fstream for logging
using namespace std;

#ifndef RIWATARNLP_H
#define RIWATARNLP_H

#include <stack> // Include stack for storing history

void riwayatNlp(stack<string> &history)
{
    system("CLS");
    cout << "\nRiwayat Pemilihan Menu Matematika Otodu:\n";

    if (history.empty())
    {
        cout << "Tidak ada riwayat pemilihan.\n";
    }
    else
    {
        // Display the history from the stack without popping
        stack<string> tempHistory = history; // Make a copy of the stack
        while (!tempHistory.empty())
        {
            cout << tempHistory.top() << endl;
            tempHistory.pop();
        }
    }
}

#endif // RIWATARNLP_H

// Fungsi untuk halaman Matematika
void halamanMatematika(stack<string> &history)
{ // Use stack to store history
    int choice;
    ofstream logFile("log.txt", ios_base::app); // Open log file in append mode
    do
    {
        system("CLS");
        cout << "\nMenu:\n";
        cout << "1. Trigonometri\n";
        cout << "2. Limit\n";
        cout << "3. Matriks\n";
        cout << "4. Tiga Dimensi (Volume Kubus)\n";
        cout << "5. Statistika\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // trigonometry();
            history.push("Trigonometri");                    // Save the choice
            logFile << "User selected Trigonometri" << endl; // Log the choice
            cout << "\nAnda telah memilih opsi, klik tombol apapun untuk lanjut.";
            cin.ignore();
            getch();
            break;
        case 2:
            // limit();
            history.push("Limit");                    // Save the choice
            logFile << "User selected Limit" << endl; // Log the choice
            cout << "\nAnda telah memilih opsi, klik tombol apapun untuk lanjut.";
            cin.ignore();
            getch();
            break;

        case 3:
            // matrixOperations();
            history.push("Matriks");                    // Save the choice
            logFile << "User selected Matriks" << endl; // Log the choice
            cout << "\nAnda telah memilih opsi, klik tombol apapun untuk lanjut.";
            cin.ignore();
            getch();
            break;
        case 4:
            // threeDimensional();
            history.push("Volume Kubus");                    // Save the choice
            logFile << "User selected Volume Kubus" << endl; // Log the choice
            cout << "\nAnda telah memilih opsi, klik tombol apapun untuk lanjut.";
            cin.ignore();
            getch();
            break;
        case 5:
            // statistics();
            history.push("Statistika");                    // Save the choice
            logFile << "User selected Statistika" << endl; // Log the choice
            cout << "\nAnda telah memilih opsi, klik tombol apapun untuk lanjut.";
            cin.ignore();
            getch();
            break;
        case 6:
            cout << "Keluar dari program." << endl;
            logFile << "User exited the program" << endl; // Log the exit
            system("cls");
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            logFile << "Invalid choice" << endl; // Log the invalid choice
            cin.ignore();
            getch();
            break;
        }
    } while (choice != 6);
    logFile.close(); // Close the log file
}

// Fungsi untuk halaman Bahasa Inggris
void halamanBahasaInggris()
{
    system("CLS");
    cout << "=====================================\n";
    cout << "        HALAMAN BAHASA INGGRIS      \n";
    cout << "=====================================\n";
    cout << "\nWelcome to English Page!\n";
    cout << "Here you can learn various English materials.\n\n";
    cout << "Press any key to return to the main menu...";
    cin.get(); // Use cin.get() instead of getch() for portability
}

// Fungsi untuk menampilkan menu utama
void nlpOtodu()
{
    int pilihan;
    stack<string> history; // Declare history stack here
    system("CLS");
    do
    {
        cout << "=====================================\n";
        cout << "            NLP OTODU               \n";
        cout << "=====================================\n";
        cout << "1. MATEMATIKA\n";
        cout << "2. BAHASA INGGRIS\n";
        cout << "3. KELUAR\n";
        cout << "=====================================\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            halamanMatematika(history);
            break;
        case 2:
            halamanBahasaInggris();
            break;
        case 3:
            system("cls"); // Kembali dari fungsi nlpOtodu
            return;
            // break;
            // siswaOtodu();

        default:
            cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
            cout << "Press any key to continue...";
            cin.get(); // Use cin.get() to continue
        }

    } while (true);
}

#endif // MATEMATIKA_BAHASA_H
