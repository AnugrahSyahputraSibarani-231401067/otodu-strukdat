#include <bits/stdc++.h>
#define li pair<int, int>
using namespace std;

// Maksimum jumlah produk
const int MAX_PRODUCTS = 20;
const int MAX_TRANSACTIONS = 100;
const int MAX_PURCHASED_ITEMS = 50;
const int HASH_TABLE_SIZE = 23; // Prime number for better distribution

// Struktur produk
struct Product {
    int id;
    string name;
    string category;
    int price;
};

// Struktur transaksi
struct Transaction {
    int transactionID;
    int productIDs[MAX_PURCHASED_ITEMS];
    int productCount;
    int total;
};

// Array untuk keranjang belanja
int cart[MAX_PRODUCTS];
int cartSize = 0;

// Array untuk riwayat transaksi
Transaction transactionHistory[MAX_TRANSACTIONS];
int transactionCount = 0;

// Peta Graf
int jumlah_kota = 10;
vector<vector<li>> adj(jumlah_kota);

// Hash table untuk produk
class HashTable {
private: 
    int SIZE;
    list<Product>* table;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable(int size) {
        SIZE = size;
        table = new list<Product>[SIZE];
    }

    void insert(Product product) {
        int index = hashFunction(product.id);
        table[index].push_back(product);
    }

    Product* search(int key) {
        int index = hashFunction(key);
        for(auto& product : table[index]) {
            if (product.id == key) {
                return &product;
            }
        }
        return nullptr;
    }

    void sortByPrice() {
        vector<Product> allProducts;
        for(int i = 0; i < SIZE; i++) {
            for(auto& product : table[i]) {
                allProducts.push_back(product);
            }
        }

        // Selection sort by price
        for (int i = 0; i < allProducts.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < allProducts.size(); j++) {
                if (allProducts[j].price < allProducts[minIndex].price) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(allProducts[i], allProducts[minIndex]);
            }
        }

        displaySortedProducts(allProducts);
    }

    void sortByCategory() {
        vector<Product> allProducts;
        for(int i = 0; i < SIZE; i++) {
            for(auto& product : table[i]) {
                allProducts.push_back(product);
            }
        }

        // Selection sort by category
        for (int i = 0; i < allProducts.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < allProducts.size(); j++) {
                if (allProducts[j].category < allProducts[minIndex].category) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(allProducts[i], allProducts[minIndex]);
            }
        }

        displaySortedProducts(allProducts);
    }

    void displaySortedProducts(const vector<Product>& products) {
        cout << "+-----+--------------------------------+------------+------------+" << endl;
        cout << "| ID  | Nama Produk                    |  Kategori  | Harga (Rp) |" << endl;
        cout << "+-----+--------------------------------+------------+------------+" << endl;
        for (const auto& product : products) {
            cout << "| " << setw(3) << product.id << " | " << setw(30) << product.name 
                 << " | " << setw(10) << product.category << " | " << setw(10) << product.price << " |" << endl;
        }
        cout << "+-----+--------------------------------+------------+------------+" << endl;
    }

    void display() {
        for(int i = 0; i < SIZE; i++) {
            cout << "index " << i << ": ";
            for(auto& product : table[i]) {
                cout << product.id << " ";
            }
            cout << endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};


HashTable productHashTable(HASH_TABLE_SIZE);

// Inisialisasi produk
void initProducts() {
    Product products[] = {
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

    // Masukkan ke hash table
    for (const auto& product : products) {
        productHashTable.insert(product);
    }
}

// Fungsi untuk menampilkan semua produk
void displayProducts() {
    int pilih;
    cout << "1. Urutkan berdasarkan Harga " << endl;
    cout << "2. Urutkan berdasarkan kategori " << endl;
    cout << "Pilih : "; cin >> pilih;

    if (pilih == 1) {
        productHashTable.sortByPrice();
    } else if (pilih == 2) {
        productHashTable.sortByCategory();
    }
}

// Fungsi mencari produk berdasarkan ID
void searchProductByID(int id) {
    Product* product = productHashTable.search(id);
    if (product) {
        cout << "Produk ditemukan: " << product->name
             << " - Rp. " << product->price << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// Fungsi menambahkan produk ke keranjang
void addToCart(int id) {
    Product* product = productHashTable.search(id);
    if (product) {
        cart[cartSize] = id;
        cartSize++;
        cout << "Produk " << product->name
             << " berhasil ditambahkan ke keranjang." << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan." << endl;
    }
}

void displayCartWithIndices() {
    if (cartSize == 0) {
        cout << "Keranjang belanja kosong." << endl;
        return;
    }

    cout << "+-----+-----+--------------------------------+------------+" << endl;
    cout << "| No  | ID  |          Nama Produk           | Harga (Rp) |" << endl;
    cout << "+-----+-----+--------------------------------+------------+" << endl;
    int total = 0;
    for (int i = 0; i < cartSize; i++) {
        Product* product = productHashTable.search(cart[i]);
        if (product) {
            cout << "| " << setw(3) << i+1 << " | " 
                 << setw(3) << product->id << " | " 
                 << setw(30) << product->name << " | " 
                 << setw(10) << product->price << " |" << endl;
            total += product->price;
        }
    }
    cout << "+-----+-----+--------------------------------+------------+" << endl;
    cout << "Total Belanja : Rp. " << setw(10) << total << endl;
}

// Fungsi menghapus produk dari keranjang
void removeFromCart() {
    if (cartSize == 0) {
        cout << "Keranjang belanja kosong." << endl;
        return;
    }

    // Tampilkan keranjang dengan nomor indeks
    displayCartWithIndices();

    int indexToRemove;
    cout << "Masukkan nomor produk yang ingin dihapus: ";
    cin >> indexToRemove;

    // Validasi input
    if (indexToRemove < 1 || indexToRemove > cartSize) {
        cout << "Nomor produk tidak valid." << endl;
        return;
    }

    // Dapatkan nama produk sebelum menghapus
    Product* removedProduct = productHashTable.search(cart[indexToRemove - 1]);
    string removedProductName = removedProduct ? removedProduct->name : "Produk";

    // Hapus produk dari keranjang dengan geser elemen
    for (int i = indexToRemove - 1; i < cartSize - 1; i++) {
        cart[i] = cart[i + 1];
    }
    cartSize--;

    cout << removedProductName << " berhasil dihapus dari keranjang." << endl;
}

// Fungsi melihat keranjang
void viewCart() {
    if (cartSize == 0) {
        cout << "Keranjang belanja kosong." << endl;
        return;
    }

    cout << "+-----+--------------------------------+------------+" << endl;
    cout << "| ID  |          Nama Produk           | Harga (Rp) |" << endl;
    cout << "+-----+--------------------------------+------------+" << endl;
    int total = 0;
    for (int i = 0; i < cartSize; i++) {
        Product* product = productHashTable.search(cart[i]);
        if (product) {
            cout << "| " << setw(3) << product->id << " | " 
                 << setw(30) << product->name << " | " 
                 << setw(10) << product->price << " |" << endl;
            total += product->price;
        }
    }
    cout << "+-----+--------------------------------+------------+" << endl;
    cout << "Total Belanja : Rp. " << setw(10) << total << endl;
}

int hitungOngkir(int kota){
    adj[0].push_back({3,4});
    adj[0].push_back({2,7});
    adj[0].push_back({6,4});
    adj[0].push_back({8,5});
    adj[2].push_back({1,5});
    adj[4].push_back({7,7});
    adj[5].push_back({4,9});
    adj[5].push_back({7,8});
    adj[5].push_back({9,3});
    adj[6].push_back({1,4});
    adj[6].push_back({5,11});
    adj[6].push_back({4,2});
    adj[8].push_back({5,10});
    adj[9].push_back({7,4});

    priority_queue<li, vector<li>, greater<li>> pq;
    vector<int> dist(jumlah_kota, INT_MAX);
    vector<int> pred(jumlah_kota, -1);
    dist[0] = 0;
    pq.push({dist[0], 0});

    while(!pq.empty()){
        auto [currDist, currNode] = pq.top(); pq.pop();

        if(currDist > dist[currNode]) continue;

        for(auto [v,w]: adj[currNode]){
            if(dist[v] > dist[currNode]+w){
                dist[v] = dist[currNode] + w;
                pred[v] = currNode;
                pq.push({dist[v], v});
            }
        }
    }

    int ongkir = dist[kota] * 3000;
    return ongkir;
}

// Fungsi melakukan pembayaran
void checkout() {
    if (cartSize == 0) {
        cout << "Keranjang belanja kosong. Tidak ada yang bisa dibayar." << endl;
        return;
    }
    int kota,ongkir;
    cout << "Masukkan nomor kota yang dituju: ";
    cin >> kota;
    ongkir = hitungOngkir(kota);
    cout << "Harga dari toko ke kota " << kota << " = " << ongkir << "\n";



    int total = 0;
    for (int i = 0; i < cartSize; i++) {
        Product* product = productHashTable.search(cart[i]);
        if (product) {
            total += product->price;
        }
    }
    total += ongkir;

    // Simpan transaksi ke riwayat
    transactionHistory[transactionCount].transactionID = transactionCount + 1;
    transactionHistory[transactionCount].productCount = cartSize;
    transactionHistory[transactionCount].total = total;
    for (int i = 0; i < cartSize; i++) {
        transactionHistory[transactionCount].productIDs[i] = cart[i];
    }
    transactionCount++;

    cout << "Total pembayaran: Rp. " << total << endl;
    cout << "Pembayaran berhasil." << endl;

    // Kosongkan keranjang
    cartSize = 0;
}

// Fungsi melihat riwayat transaksi
void viewTransactionHistory() {
    if (transactionCount == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }

    cout << "ID Transaksi\tTotal Pembayaran (Rp)" << endl;
    for (int i = 0; i < transactionCount; i++) {
        cout << transactionHistory[i].transactionID << "\t\t" 
             << transactionHistory[i].total << endl;
    }
}

// Fungsi melihat detail transaksi
void viewTransactionDetails(int transactionID) {
    for (int i = 0; i < transactionCount; i++) {
        if (transactionHistory[i].transactionID == transactionID) {
            cout << "Detail Transaksi ID: " << transactionID << endl;
            cout << "Produk yang Dibeli:" << endl;
            for (int j = 0; j < transactionHistory[i].productCount; j++) {
                Product* product = productHashTable.search(transactionHistory[i].productIDs[j]);
                if (product) {
                    cout << product->name << " - Rp. " << product->price << endl;
                }
            }
            cout << "Total: Rp. " << transactionHistory[i].total << endl;
            return;
        }
    }
    cout << "Transaksi dengan ID " << transactionID << " tidak ditemukan." << endl;
}



int main() {
    // Inisialisasi produk ke hash table
    initProducts();

    int choice, id, kota;

    while (true) {
        cout << "\n=== Menu Toko Online ===" << endl;
        cout << "1. Lihat Semua Produk" << endl;
        cout << "2. Cari Produk Berdasarkan ID" << endl;
        cout << "3. Tambah Produk ke Keranjang" << endl;
        cout << "4. Lihat Keranjang Belanja" << endl;
        cout << "5. Hapus Produk dari Keranjang" << endl;
        cout << "6. Hitung Ongkos Kirim" << endl;
        cout << "7. Checkout" << endl;
        cout << "8. Lihat Riwayat Transaksi" << endl;
        cout << "9. Lihat Detail Transaksi" << endl;
        cout << "10. Keluar" << endl;
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
                removeFromCart();
                break;
            case 6:
                int kota,ongkir;
                cout << "Masukkan nomor kota yang dituju: ";
                cin >> kota;
                ongkir = hitungOngkir(kota);
                cout << "Harga dari toko ke kota " << kota << " = " << ongkir << "\n";
                break;
            case 7:
                checkout();
                break;
            case 8:
                viewTransactionHistory();
                break;
            case 9:
                cout << "Masukkan ID transaksi: ";
                cin >> id;
                viewTransactionDetails(id);
                break;
            case 10:
                cout << "Terima kasih telah menggunakan toko online kami!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." <<endl;
        }
    }
}
