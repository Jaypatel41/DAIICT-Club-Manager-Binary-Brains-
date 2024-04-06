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


void addEvent(vector<Event>& calendar) {
    Event newEvent;
    cout << "Enter event title: ";
    getline(cin >> ws, newEvent.title); 
    cout << "Enter event date (YYYY-MM-DD): ";
    cin >> newEvent.date;
    cout << "Enter event time (HH:MM): ";
    cin >> newEvent.time;
    calendar.push_back(newEvent);
    cout << "Event added successfully!" << endl;
}

void deleteEvent(vector<Event>& calendar) {
    int index;
    cout << "Enter the index of the event you want to delete: ";
    cin >> index;
    if (index >= 0 && index < calendar.size()) {
        calendar.erase(calendar.begin() + index);
        cout << "Event deleted successfully!" << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

