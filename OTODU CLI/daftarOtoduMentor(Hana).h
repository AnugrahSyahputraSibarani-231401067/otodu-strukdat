#ifndef DAFTARMENTOR_H
#define DAFTARMENTOR_H

#include <iostream>
#include <string>
#include <functional>

using namespace std;

// Fungsi untuk menyimpan data mentor
void saveMentorToFile(const string& nama, const string& username, const string& password, 
                      const string& gelar, float jarak) {
    ofstream file("dataMentor.txt", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << nama << "," << username << "," << password << "," 
             << gelar << "," << jarak << "\n";
        file.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan data mentor." << endl;
    }
}

// Struct untuk data mentor
struct mentor {
    string nama;
    string username;
    string password;
    string gelar;
    float jarak; // Jarak rumah ke kantor
    mentor* next; // Pointer untuk linked list
};

const int HASH_TABLE_SIZE = 100;

// Fungsi hash untuk menyimpan mentor dalam hash table
inline int hashFunction(const string& key) {
    hash<string> hasher;
    return hasher(key) % HASH_TABLE_SIZE;
}

// Variabel global hash table untuk menyimpan mentor
mentor* hashTable[HASH_TABLE_SIZE] = {nullptr};

// Fungsi untuk menambah mentor ke dalam hash table
inline bool addmentor(const string& nama, const string& username, const string& password, 
                      const string& gelar, float jarak) {
    int index = hashFunction(username);

    // Cek apakah username sudah ada
    mentor* current = hashTable[index];
    while (current != nullptr) {
        if (current->username == username) {
            return false; // Username sudah ada
        }
        current = current->next;
    }

    // Tambahkan mentor baru
    mentor* newmentor = new mentor{nama, username, password, gelar, jarak, nullptr};

    if (hashTable[index] == nullptr) {
        hashTable[index] = newmentor;
    } else {
        current = hashTable[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newmentor;
    }

    // Simpan data ke file
    saveMentorToFile(nama, username, password, gelar, jarak);
    return true; // Berhasil menambahkan mentor
}

#endif // DAFTARMENTOR_H
