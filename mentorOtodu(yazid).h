void mentorYazid() {
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Siswa Anda" << endl;
        cout << "2. Antrian Siswa Anda" << endl;
        cout << "3. Logout" << endl;
        cout << "Pilih (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                siswaAnda();
                break;
            case 2:
                antrianSiswaAnda();
                break;
            case 3:
                logout();
                return; // Kembali ke fungsi pemanggil (main)
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (true);
}

