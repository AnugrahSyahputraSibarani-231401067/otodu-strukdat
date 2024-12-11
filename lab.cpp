#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Struktur produk
struct Product {
    int id;
    string name;
    string category;
    int price;
};

// Data produk
vector<Product> products = {
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

// Array keranjang belanja
vector<int> cart;

// Fungsi untuk menampilkan semua produk
void displayProducts() {
    cout << "ID\tNama Produk\t\t\tKategori\tHarga (Rp)" << endl;
    for (const auto &product : products) {
        cout << product.id << "\t" << product.name << "\t" << product.category << "\t" << product.price << endl;
    }
}

// Fungsi mencari produk berdasarkan ID
void searchProductByID(int id) {
    auto it = find_if(products.begin(), products.end(), [id](const Product &p) {
        return p.id == id;
    });

    if (it != products.end()) {
        cout << "Produk ditemukan: " << it->name << " - Rp. " << it->price << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// Fungsi menambahkan produk ke keranjang
void addToCart(int id) {
    auto it = find_if(products.begin(), products.end(), [id](const Product &p) {
        return p.id == id;
    });

    if (it != products.end()) {
        cart.push_back(id);
        cout << "Produk " << it->name << " berhasil ditambahkan ke keranjang." << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// Fungsi melihat keranjang
void viewCart() {
    if (cart.empty()) {
        cout << "Keranjang belanja kosong." << endl;
        return;
    }

    cout << "ID\tNama Produk\t\t\tHarga (Rp)" << endl;
    int total = 0;
    for (int id : cart) {
        auto it = find_if(products.begin(), products.end(), [id](const Product &p) {
            return p.id == id;
        });
        if (it != products.end()) {
            cout << it->id << "\t" << it->name << "\t" << it->price << endl;
            total += it->price;
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
