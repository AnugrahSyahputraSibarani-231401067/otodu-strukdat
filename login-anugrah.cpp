#include <iostream>
#include <string>

void loginOtodu()
{
    // Usn & pw tersimpan di sini
    string username, password;

    cout << "---- LOGIN OTODU ----" << endl;
    cout << endl;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    return 0;
}
