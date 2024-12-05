#ifndef LISTMENTORS_H
#define LISTMENTORS_H
#define SISWAOTODU_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For formatting
#include <limits>  // For handling input validation
#include "run12.h"

#include "siswaOtodu(Edwin).h"

using namespace std;

// Define a structure to hold mentor details
struct Mentor
{
    string name;
    string degree;
    int number;
};

vector<Mentor> mentorList = {
        {"adam", "S.kom", 11},
        {"anugrah", "S.sos", 121},
        {"edwin", "S.sos", 120},
        {"rizky", "S.kom", 15}};

int mentorChoice;

void siswaOtodu();

void listMentor()
{
    // Initialize the mentor list
    // vector<Mentor> mentorList = {
    //     {"adam", "S.kom", 122},
    //     {"dummy1", "S.sos", 121},
    //     {"dummy2", "S.sos", 11},
    //     {"dummy3", "S.kom", 123}};

    // Sort the mentor list based on the smallest number
    sort(mentorList.begin(), mentorList.end(), [](const Mentor &a, const Mentor &b)
         { return a.number < b.number; });

    char choice;
    do
    {
        // Display the sorted mentor list
        cout << "\nLIST MENTOR OTODU\n";
        for (size_t i = 0; i < mentorList.size(); ++i)
        {
            cout << i + 1 << ". " << mentorList[i].name << ", " << mentorList[i].degree
                 << ", " << mentorList[i].number << " Meter" << endl;
        }

        // Prompt user to select a mentor
        cout << "\nPilih mentor yang ingin Anda pesan (1-" << mentorList.size() << "): ";

        run12();

        while (!(cin >> mentorChoice) || mentorChoice < 1 || mentorChoice > static_cast<int>(mentorList.size()))
        {   
            cin.clear();                                         // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Pilihan tidak valid! Silakan masukkan angka antara 1 dan " << mentorList.size() << ": ";
        }

        // Display the chosen mentor
        Mentor chosenMentor = mentorList[mentorChoice - 1];
        system("cls");
        cout << "\nAnda telah memilih mentor berikut:\n";
        cout << "Nama: " << chosenMentor.name << "\n";
        cout << "Gelar: " << chosenMentor.degree << "\n";
        cout << "Jarak: " << chosenMentor.number << " Meter\n";
        cout << "Mentor berhasil dipesan!\n";

        // Ask if the user wants to choose another mentor
        cout << "\nApakah Anda ingin memesan mentor lain? (y/n): ";
        cin >> choice;
        while (choice != 'y' && choice != 'n')
        {
            cout << "Input tidak valid! Masukkan 'y' untuk ya atau 'n' untuk tidak: ";
            cin >> choice;
        }

    } while (choice == 'y');

    cout << "\nTerima kasih telah menggunakan layanan kami!\n";

    siswaOtodu();
}

#endif