#ifndef ANTRIANSISWA_H
#define ANTRIANSISWA_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struct untuk data siswa
struct Siswa2 {
    string nama;
    string waktu;
};

// Fungsi untuk menampilkan dan mengelola antrian siswa
void kelolaAntrian() {
    // Array untuk menyimpan data siswa
    Siswa2 siswaList[] = {
        {"Budi", "12.00-13.00"},
        {"Siti", "13.00-14.00"},
        {"Adam", "14.00-15.00"}
    };

    // Queue untuk antrian siswa
    queue<Siswa2> antrian;

    // Memasukkan siswa ke dalam queue
    for (const auto& siswa : siswaList) {
        antrian.push(siswa);
    }

    // Tampilkan menu
    int pilihan = -1;
    while (pilihan != 0) {
        cout << "Antrian Siswa OTODU:\n";
        int index = 1;
        queue<Siswa2> tempQueue = antrian; // Salinan untuk ditampilkan
        while (!tempQueue.empty()) {
            Siswa2 siswa = tempQueue.front();
            cout << index++ << ". " << siswa.nama << " (" << siswa.waktu << ")\n";
            tempQueue.pop();
        }
        cout << "0. Kembali (Mentor OTODU)\n";

        // Input pilihan pengguna
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan > 0 && pilihan <= static_cast<int>(antrian.size())) { // Perbaiki tipe comparison
            // Menghapus siswa dari antrian
            for (int i = 1; i < pilihan; ++i) {
                antrian.push(antrian.front());
                antrian.pop();
            }
            cout << "Siswa " << antrian.front().nama 
                 << " pada waktu " << antrian.front().waktu 
                 << " diproses.\n";
            antrian.pop(); // Siswa selesai diproses
        } else if (pilihan == 0) {
            cout << "Kembali ke menu mentor OTODU.\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }

        cout << endl;
    }
}

#endif // ANTRIANSISWA_H
