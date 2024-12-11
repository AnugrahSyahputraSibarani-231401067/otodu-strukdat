/*
https://prod.liveshare.vsengsaas.visualstudio.com/join?9111CB7F24204A8C389B739B47DDE936C0CD
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Maksimum jumlah produk
const int MAX_PRODUCTS = 20;

// Struktur produk
struct Product {
    int id;
    string name;
    string category;
    int price;
};

// Data produk (menggunakan array)
Product products[MAX_PRODUCTS] = {
    {1, "Smartphone Samsung Galaxy S23", "Elektronik", 12000000},
    {2, "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000},
    {3, "TV LED LG 43 Inch", "Elektronik", 6500000},
    {4, "Earbuds Apple AirPods Pro", "Elektronik", 3500000},
    {5, "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000},
    {6, "Sepeda MTB Polygon", "Fitness", 5000000},
    {7, "Dumbbell 5kg", "Fitness", 200000},
    {8, "Matras Yoga", "Fitness", 250000},
    {9, "Mesin Elliptical", "Fitness", 7500000},
    {10, "Resistance Band", "Fitness", 100000},
    {11, "Serum Wajah Vitamin C", "Kecantikan", 150000},
    {12, "Masker Wajah Aloe Vera", "Kecantikan", 75000},
    {13, "Lipstik Matte L'Oréal", "Kecantikan", 120000},
    {14, "Parfum Chanel", "Kecantikan", 2500000},
    {15, "Sabun Cuci Muka Himalaya", "Kecantikan", 35000},
    {16, "Roti Tawar Serba Roti", "Konsumsi", 15000},
    {17, "Kopi Arabica 100g", "Konsumsi", 50000},
    {18, "Mie Instan", "Konsumsi", 5000},
    {19, "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000},
    {20, "Teh Kotak Sosro 500ml", "Konsumsi", 7500}
};

// Array untuk keranjang belanja
int cart[MAX_PRODUCTS];
int cartSize = 0;

// Fungsi untuk menampilkan semua produk
void displayProducts() {
    cout << "ID\tNama Produk\t\t\tKategori\tHarga (Rp)" << endl;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        cout << products[i].id << "\t" << products[i].name << "\t" 
             << products[i].category << "\t" << products[i].price << endl;
    }
}

// Fungsi mencari produk berdasarkan ID
void searchProductByID(int id) {
    bool found = false;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == id) {
            cout << "Produk ditemukan: " << products[i].name 
                 << " - Rp. " << products[i].price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// Fungsi menambahkan produk ke keranjang
void addToCart(int id) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == id) {
            cart[cartSize] = id;
            cartSize++;
            cout << "Produk " << products[i].name 
                 << " berhasil ditambahkan ke keranjang." << endl;
            return;
        }
    }
    cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
}

// Fungsi melihat keranjang
void viewCart() {
    if (cartSize == 0) {
        cout << "Keranjang belanja kosong." << endl;
        return;
    }

    cout << "ID\tNama Produk\t\t\tHarga (Rp)" << endl;
    int total = 0;
    for (int i = 0; i < cartSize; i++) {
        for (int j = 0; j < MAX_PRODUCTS; j++) {
            if (products[j].id == cart[i]) {
                cout << products[j].id << "\t" << products[j].name 
                     << "\t" << products[j].price << endl;
                total += products[j].price;
            }
        }
    }
    cout << "Total: Rp. " << total << endl;
}

int main() {
    int choice, id;

    while (true) {
        cout << "\n=== Menu Toko Online ===" << endl;
        cout << "1. Lihat Semua Produk" << endl;
        cout << "2. Cari Produk Berdasarkan ID" << endl;
        cout << "3. Tambah Produk ke Keranjang" << endl;
        cout << "4. Lihat Keranjang Belanja" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                cout << "Masukkan ID produk: ";
                cin >> id;
                searchProductByID(id);
                break;
            case 3:
                cout << "Masukkan ID produk yang ingin ditambahkan: ";
                cin >> id;
                addToCart(id);
                break;
            case 4:
                viewCart();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan toko online kami!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}
