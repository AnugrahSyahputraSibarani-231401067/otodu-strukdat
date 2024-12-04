#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "siswaOtodu(Edwin).h"

using namespace std;

// Struktur data untuk menyimpan informasi mentor
struct Mentor2
{
    string name;
    string degree; // Gelar
};

// Daftar mentor
vector<Mentor2> mentors = {
    {"Alice Johnson", "S.Kom"},
    {"Bob Smith", "S.Pd"},
    {"Charlie Brown", "S.Kom"},
    {"Diana White", "S.T"},
    {"Eve Black", "S.Psi"}};

void siswaOtodu();

// Fungsi untuk mencari mentor berdasarkan gelarnya
void searchMentorByDegree(const vector<Mentor2> &mentors, const string &degree)
{
    bool found = false;
    for (const auto &mentor : mentors)
    {
        if (mentor.degree == degree)
        {
            cout << "- " << mentor.name << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Mentor dengan gelar " << degree << " tidak ditemukan ." << endl;
    }

    cout << "\nKetik apapun untuk kembali";
    cin.ignore();
    getch();
    siswaOtodu();
}

// Fungsi untuk meminta input dari pengguna dan melakukan pencarian
void inputAndSearch(const vector<Mentor2> &mentors)
{
    string degreeToSearch;
    cout << "====== Mencari Mentor ======" << endl;
    cout << "Masukkan gelar singkat (contoh: S.Kom, S.Pd): ";
    cin >> degreeToSearch;

    // Panggil fungsi pencarian
    searchMentorByDegree(mentors, degreeToSearch);
}