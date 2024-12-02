#include <iostream>
#include <vector>
#include <string>
#include <limits> // Untuk validasi input

using namespace std;

// Fungsi untuk membersihkan layar
void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk menampilkan menu awal
void displayMenu(const vector<string> &jadwal) {
    clearScreen();
    cout << "+" << string(30, '-') << "+" << endl;
    cout << "|" << " Mentor Adam " << string(15, ' ') << "|" << endl;
    cout << "+" << string(30, '-') << "+" << endl;
    cout << "Apa yang ingin dipelajari:" << endl;
    cout << "(input)" << endl;
    cout << "Jam ajar:" << endl;
    for (size_t i = 0; i < jadwal.size(); ++i) {
        cout << i + 1 << ". " << jadwal[i] << endl;
    }
    cout << "\n(input angka...)" << endl;
}

// Fungsi untuk menampilkan konfirmasi
void bookingComplete(const string &jam) {
    clearScreen();
    cout << "+" << string(30, '-') << "+" << endl;
    cout << "|" << " Mentor Adam " << string(15, ' ') << "|" << endl;
    cout << "+" << string(30, '-') << "+" << endl;
    cout << "\nPemesanan mentor selesai pada jam " << jam << endl;
    cout << "(sesuai dengan pilihan user sebelumnya)!" << endl;
    cout << "\nKetik 1 untuk kembali ke menu awal." << endl;
}

void mentorAdam() {
    // Daftar jadwal mentor
    vector<string> jadwal = {
        "13:00 - 14:00",
        "14:00 - 15:00",
        "15:00 - 16:00",
        "16:00 - 17:00",
        "17:00 - 18:00"
    };

    vector<string> pilihanUser; // Untuk menyimpan pilihan user

    while (true) {
        displayMenu(jadwal);

        int pilihan;
        cout << "Masukkan pilihan (1-5): ";
        cin >> pilihan;

        // Validasi input angka
        if (cin.fail()) {
            cin.clear(); // Reset error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input tidak valid
            cout << "Input harus berupa angka antara 1-5!" << endl;
            cout << "Tekan Enter untuk kembali ke menu awal...";
            cin.get(); // Tunggu Enter
            cin.get();
            continue; // Kembali ke awal loop
        }

        if (pilihan >= 1 && pilihan <= 5) {
            // Simpan pilihan user
            pilihanUser.push_back(jadwal[pilihan - 1]);

            // Tampilkan konfirmasi
            bookingComplete(jadwal[pilihan - 1]);

            int kembali;
            cout << "\nMasukkan pilihan: ";
            cin >> kembali;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid! Kembali ke menu awal..." << endl;
                cin.get();
                continue;
            }

            if (kembali == 1) {
                continue; // Kembali ke menu awal
            } else {
                cout << "Input tidak valid! Program akan diakhiri." << endl;
                break;
            }
        } else {
            cout << "Input tidak valid! Masukkan angka antara 1-5." << endl;
            cin.clear(); // Bersihkan error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input
            cout << "Tekan Enter untuk kembali ke menu awal...";
            cin.get(); // Tunggu Enter
            cin.get();
        }
    }

    return 0;
}
