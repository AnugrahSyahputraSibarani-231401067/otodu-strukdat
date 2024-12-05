#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struktur data untuk menyimpan informasi Mentor3
struct Mentor3 {
    string name;
    string degree;
    int distance; // Jarak dari node awal
};

// Fungsi untuk menampilkan graph Mentor3 berdasarkan jarak
void displayGraph(vector<Mentor3> &Mentor3List) {
    cout << "\nGraf Jarak Mentor3 (dari terkecil ke terbesar):\n";
    cout << left << setw(10) << "Nama" << setw(10) << "Gelar" << setw(10) << "Jarak (m)" << endl;
    cout << "-----------------------------------\n";
    for (const auto &Mentor3 : Mentor3List) {
        cout << left << setw(10) << Mentor3.name << setw(10) << Mentor3.degree << setw(10) << Mentor3.distance << endl;
    }
    cout << "-----------------------------------\n";
}

// Implementasi algoritma Dijkstra
void dijkstra(vector<Mentor3> &Mentor3List) {
    int n = Mentor3List.size();
    vector<int> dist(n, numeric_limits<int>::max());  // Menyimpan jarak terpendek dari sumber
    vector<bool> visited(n, false);  // Menyimpan apakah Mentor3 telah dikunjungi
    dist[0] = 0;  // Mulai dari Mentor3 pertama (sumber)

    // Dijkstra's Algorithm
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minDist = numeric_limits<int>::max();

        // Cari Mentor3 yang belum dikunjungi dan memiliki jarak terkecil
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;  // Semua Mentor3 sudah dikunjungi

        visited[u] = true;

        // Memperbarui jarak untuk Mentor3 yang terhubung dengan Mentor3 u
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                // Menggunakan jarak antar Mentor3 sebagai bobot edge
                int weight = abs(Mentor3List[u].distance - Mentor3List[v].distance);
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Tampilkan hasil jarak terpendek antar Mentor3
    cout << "\nJarak Terpendek dari Mentor3 Pertama:\n";
    for (int i = 0; i < n; i++) {
        cout << "Jarak dari " << Mentor3List[0].name << " ke " << Mentor3List[i].name << ": " << dist[i] << " meter\n";
    }
}

void run12() {
    // Daftar Mentor3
    vector<Mentor3> Mentor3List = {
        {"adam", "S.kom", 11},
        {"anugrah", "S.sos", 121},
        {"edwin", "S.sos", 120},
        {"rizky", "S.kom", 15}
    };

    // Tampilkan graph dan jalankan algoritma Dijkstra
    displayGraph(Mentor3List);
    dijkstra(Mentor3List);

}
