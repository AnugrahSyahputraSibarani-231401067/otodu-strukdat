#ifndef MATEMATIKAOTODU_H

#define MATEMATIKAOTODU_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void trigonometry() {
    double angle;
    cout << "Masukkan sudut dalam derajat: ";
    cin >> angle;
    
    double radian = angle * (M_PI / 180.0);
    
    cout << "Sin(" << angle << ") = " << sin(radian) << endl;
    cout << "Cos(" << angle << ") = " << cos(radian) << endl;
    cout << "Tan(" << angle << ") = " << tan(radian) << endl;
}

void limit() {
    double x;
    cout << "Masukkan nilai x untuk limit saat x mendekati 0 (f(x) = sin(x)/x): ";
    cin >> x;
    
    if (x == 0) {
        cout << "Limit saat x mendekati 0 adalah 1." << endl;
    } else {
        double limitValue = sin(x) / x;
        cout << "Limit f(" << x << ") = " << limitValue << endl;
    }
}

void matrixOperations() {
    int rows, cols;
    cout << "Masukkan jumlah baris dan kolom matriks: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matriks yang Anda masukkan:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void threeDimensional() {
    double side;
    cout << "Masukkan panjang sisi kubus: ";
    cin >> side;
    
    double volume = pow(side, 3);
    cout << "Volume kubus = " << volume << endl;
}

void statistics() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<double> data(n);
    cout << "Masukkan data:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    double sum = 0;
    for (double num : data) {
        sum += num;
    }
    
    double mean = sum / n;
    cout << "Rata-rata = " << mean << endl;
}

void matematikaOtodu() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Trigonometri\n";
        cout << "2. Limit\n";
        cout << "3. Matriks\n";
        cout << "4. Tiga Dimensi (Volume Kubus)\n";
        cout << "5. Statistika\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                trigonometry();
                break;
            case 2:
                limit();
                break;
            case 3:
                matrixOperations();
                break;
            case 4:
                threeDimensional();
                break;
            case 5:
                statistics();
                break;
            case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 6);
}

// int main() {
//     matematikaOtodu();
//     return 0;
// }
#endif // MATEMATIKAOTODU_H