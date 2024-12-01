#include <string>
#include <functional> // Untuk hash

struct mentor {
    string nama;
    string username;
    string password;
    string gelar;
    float jarak; // Jarak rumah ke kantor
    mentor* next;  // Pointer untuk linked list
};

const int HASH_TABLE_SIZE = 100;

int hashFunction(const string& key) {
    hash<string> hasher;
    return hasher(key) % HASH_TABLE_SIZE;
}

mentor* hashTable[HASH_TABLE_SIZE] = {nullptr};

bool addmentor(const string& nama, const string& username, const string& password, 
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

    // Jika tidak ada, tambahkan pengajar baru
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

    return true; // Berhasil menambahkan pengajar
}

int main() {
    char jawaban;

    cout <<" Daftar sebagai mentor (M) atau siswa (s) :";
    cin >> jawaban; 

    jawaban = toupper(jawaban);
     if(jawaban == 'M') {
        goto daftar_mentor;
     }
    //  else if(jawaban == 'S'){
    //     // goto daftar_siswa;
    //  }
     else{
        cout<<"pilihan tidak tersedia";
        return 0;
     }



    daftar_mentor:
    string nama, username, password, gelar;
    float jarak;

    system("CLS");
    cout << "======= DAFTAR OTODU =======" << endl;
    cout << "Silahkan daftar akun mentor Anda!" << endl;

    cout << "Nama: ";
    cin >> nama;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    cout << "Gelar singkat: ";
    cin >> gelar;

    cout << "Jarak rumah ke kantor OTODU (m): ";
    cin >> jarak;

    if (addmentor(nama, username, password, gelar, jarak)) {
        cout << "Akun berhasil didaftarkan!" << endl;
    } else {
        cout << "Gagal mendaftarkan akun. Username sudah digunakan." << endl;
    }

    return 0;
}
