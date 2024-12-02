#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For formatting

using namespace std;

// Define a structure to hold mentor details
struct Mentor {
    string name;
    string degree;
    int number;
};

void listMentor() {
    // Initialize the mentor list
    vector<Mentor> mentorList = {
        {"adam", "S.kom", 122},
        {"dummy1", "S.sos", 121},
        {"dummy2", "S.sos", 11},
        {"dummy2", "S.kom", 123}
    };

    // Sort the mentor list based on the smallest number
    sort(mentorList.begin(), mentorList.end(), [](const Mentor& a, const Mentor& b) {
        return a.number < b.number;
    });

    // Display the sorted mentor list
    cout << "LIST MENTOR OTODU\n";
    for (size_t i = 0; i < mentorList.size(); ++i) {
        cout << i + 1 << ". " << mentorList[i].name << ", " << mentorList[i].degree
             << ", " << mentorList[i].number << " Meter" << endl;
    }

    return 0;
}
