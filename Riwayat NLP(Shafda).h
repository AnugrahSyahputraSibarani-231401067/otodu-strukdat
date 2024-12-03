#ifndef RIWATARNLP_H
#define RIWATARNLP_H

#include <iostream>
#include <stack> // Include stack for storing history
#include <string>
#include "MatematikaOtodu(Shafda).h"

using namespace std;

void riwayatNlp(stack<string>& history) {
    cout << "\nRiwayat Pemilihan Menu Matematika Otodu:\n";
    
    if (history.empty()) {
        cout << "Tidak ada riwayat pemilihan.\n";
    } else {
        // Display the history from the stack
        while (!history.empty()) {
            cout << history.top() << endl;
            history.pop();
        }
    }
}

#endif // RIWATARNLP_H
