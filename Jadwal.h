#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Jadwal {
    string namaSiswa;
    string jadwalAjar;
};

int main() {
    // Daftar jadwal mentor
    string jamAjar[] = {"13:00 - 14:00", "14:00 - 15:00", "16:00 - 17:00"};
    queue<Jadwal> queueJadwal; // Queue untuk menyimpan jadwal

    int kapasitas = 3; // Kapasitas maksimum siswa per jam
    int slotTerisi[3] = {0, 0, 0}; // Slot terisi untuk masing-masing jadwal

    char lanjut;
    do {
        // Input data siswa
        string namaSiswa;
        cout << "Masukkan nama siswa: ";
        cin >> namaSiswa;

        // Cari slot kosong dan tambahkan ke queue
        bool jadwalDiberikan = false;
        for (int i = 0; i < 3; i++) {
            if (slotTerisi[i] < kapasitas) {
                queueJadwal.push({namaSiswa, jamAjar[i]});
                slotTerisi[i]++;
                cout << "Jadwal diberikan untuk " << namaSiswa << ": " << jamAjar[i] << endl;
                jadwalDiberikan = true;
                break;
            }
        }

        // Jika semua slot penuh
        if (!jadwalDiberikan) {
            cout << "Maaf, semua jadwal mentor penuh." << endl;
        }

        // Tanya apakah ingin menambahkan siswa lain
        cout << "Apakah ingin menambahkan siswa lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    // Menampilkan daftar jadwal yang telah diberikan
    cout << "\nDaftar Jadwal Mentor Adam:" << endl;
    while (!queueJadwal.empty()) {
        Jadwal j = queueJadwal.front();
        cout << "Nama: " << j.namaSiswa << " | Jam: " << j.jadwalAjar << endl;
        queueJadwal.pop();
    }

    return 0;
}
