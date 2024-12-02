#ifndef LOGINOTODU_H
#define LOGINOTODU_H

#include "siswaOtodu(Edwin).h"

#include <bits/stdc++.h>
using namespace std;

void loginOtodu(){
    system("cls");
    
    // Usn & pw tersimpan di sini
    string username, password;

    cout << "---- LOGIN OTODU ----" << endl;
    cout << endl;
    cout << "Username: " << endl;
    getline(cin, username);
    cin.ignore();
    cout << "Password: " << endl;
    getline(cin, password);
    cin.ignore();

    siswaOtodu();
}
#endif // LOGINOTODU_H

