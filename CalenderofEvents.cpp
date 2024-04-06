#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include "event.cpp"
using namespace std;





void displayCalendar(const vector<Event>& calendar) {
    cout << "Event Calendar:" << endl;
    cout << setw(20) << "Title" << setw(15) << "Date" << setw(10) << "Time" << endl;
    for (const auto& event : calendar) {
        cout << setw(20) << event.title << setw(15) << event.date << setw(10) << event.time << endl;
    }
}

