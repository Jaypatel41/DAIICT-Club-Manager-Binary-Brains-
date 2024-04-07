#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cctype> // for std::toupper and std::tolower
#include <algorithm> // for std::find

using namespace std;

struct node {
    string name;
    int stdid;
    node* previous = nullptr;
    node* next = nullptr;
};


struct Event {
    string title;
    string date;
    string time;
};




int memberfound(const vector<vector<node*>>& Club, int id, int num) {
    node* p = Club[num][id % 10];
    while (p != nullptr) {
        if (p->stdid == id) {
            return 1; // Return 1 if member is found
        }
        p = p->next;
    }
    return 0; // Return 0 if member is not found
}

int ClubIndex(const list<pair<int, string>>& ls, const string& clubname) {
    int index = 0;
    for (const auto& pair : ls) {
        if (pair.second == clubname) {
            return index;
        }
        index++;
    }
    return -1;
}

void editString(string& clubname) {
    if (!clubname.empty()) {
        // Convert first character to uppercase
        clubname[0] = toupper(clubname[0]);
        // Convert the rest of the characters to lowercase
        for (size_t i = 1; i < clubname.size(); i++) {
            clubname[i] = tolower(clubname[i]);
        }
    }
}

void clubAddition(vector<vector<node*>>& Club, list<pair<int, string>>& ls, vector<vector<string>>& Convenor, vector<int>& Convenori) {
    string clubname;
    cout << "Enter the name of the new club: ";
    cin >> clubname;
    editString(clubname);

    vector<node*> temp(10, nullptr);
    Club.push_back(temp);

    int listSize = ls.size();
    ls.push_back(make_pair(listSize, clubname));

    node* p = new node;
    cout << "For making a new Club, you need to appoint a Convenor to it at least.\n\n";
    cout << "Enter the name of the Convenor: ";
    cin>>ws;
    getline(cin,p->name);
    editString(p->name);
    cout << "\nEnter the Id of the Convenor: ";
    cin >> p->stdid;

    int num = ClubIndex(ls, clubname);
    if (num != -1) {
        Club[num][(p->stdid) % 10] = p;
        p->next = nullptr;

        Convenor.push_back({clubname, p->name});
        Convenori.push_back(p->stdid);
    } else {
        cout << "Error: Club not found!" << endl;
    }
}

void clubDeletion(vector<vector<node*>>& Club, list<pair<int, string>>& ls, vector<vector<string>>& Convenor, vector<int>& Convenori) {
    string clubname;
    cout << "Enter the name of the club to be disbanded: ";
    cin >> clubname;
    editString(clubname);

    int num = ClubIndex(ls, clubname);
    if (num == -1) {
        cout << "Error: Club not found!" << endl;
        return;
    }

    for (auto& row : Club[num]) {
        delete row; // Free memory occupied by nodes
        row = nullptr;
    }
    Club[num].clear();

    // Remove the club from the list of convenors
    auto it = find_if(Convenor.begin(), Convenor.end(), [&](const vector<string>& c) { return c[0] == clubname; });
    if (it != Convenor.end()) {
        Convenor.erase(it);
    }

    // Remove the club from the list of clubs
    auto iter = find_if(ls.begin(), ls.end(), [&](const pair<int, string>& p) { return p.second == clubname; });
    if (iter != ls.end()) {
        ls.erase(iter);
    }

    cout << clubname << " Club has been disbanded.\n\n";
}

void deletion(const vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    int id;
    int n;
     node *q;
    cout << "Enter the id of student you want to delete" << endl;
    cin >> id;
    string s;
    cout << "Enter the name of the club from which you want to delete a member" ;
    getline(cin, s);
    n = ClubIndex(ls, s);
        q = Club[n][id % 10];
    while (q != NULL)
    {
        if (q->stdid == id)
        {
            node *p= q;
            q=q->next;
            p->next->previous=NULL;
            p->next=NULL;
            delete p;
        }
        else
        {
            q = q->next;
            if (q->stdid == id)
            {
                node *a;
                node *b;
                a = q->next;
                b = q->previous;
                b->next = a;
                a->previous = b;
                delete q;
            }
            else
                q = q->next;
        }
    }
}

void printConvenors(const vector<vector<string>>& Convenor, const vector<int>& Convenori) {
    cout << "\t\t\t\t\t\t\tLIST of CLUBS - Convenors\n\n";
    int i = 1;
    for (const auto& conv : Convenor) {
        cout << i++ << ")\t" << conv[0] << "---" << conv[1] << "---" << Convenori[i - 2] << "\n";
    }
}

void Changeconvenor(vector<vector<string>>& Convenor, vector<int>& Convenori, vector<vector<node*>>& Club, list<pair<int, string>>& ls) {
    cout << "Enter Name of the Club for which you have to change Convenor: ";
    string clubname;
    cin >> clubname;
    editString(clubname);
    cout << "\n";
    for (size_t i = 0; i < Convenor.size(); i++) {
        if (Convenor[i][0] == clubname) {
            string name;
            cout << "Enter Name of the Convenor: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, name);
            editString(name);
            cout << "\n";

            int id;
            cout << "Enter ID of the Convenor: ";
            cin >> id;

            int num = ClubIndex(ls, clubname);

            if (num == 100) {
                cout << "There is NO such Club as " << clubname << "_Club.\n";
                return;
            }
            if (memberfound(Club, id, num)) {
                Convenor[i][1] = name;
                Convenori[i] = id;
                cout << "\n\n";
                cout << "\t\t\t Convenor is Updated for " << Convenor[i][0] << "\n\n";
                break;
            } else {
                cout << name << " is not a member of " << clubname << "_Club. So we can't assign him as Convenor.\n";
                return;
            }
        }
    }
    cout << "Updated List of Convenor is given below.\n\n\n";
    printConvenors(Convenor, Convenori);
}

void displayCalendar(const vector<Event>& calendar) {
    cout << "Event Calendar:" << endl;
    cout  << "\t\t\tTitle" << "\t\t\t" << "Date"<< "\t\t\t"<< "Time" << endl;
    for (const auto& event : calendar) {
        cout << "\t\t\t" << event.title <<"\t\t\t"<< event.date  <<"\t\t\t" << event.time << endl;
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

string ClubName(list<pair<int, string>>& ls, int num) {
    for (const auto& pair : ls) {
        if (pair.first == num) {
            return pair.second;
        }
    }
    cout << "No such club currently present at a time.\n\n";
    return " ";
}


void insertmember(vector<vector<node*>>& Club, string N, int id, int num, list<pair<int, string>>& ls) {
    if (num >= 0 && num <= ls.size()) {
        if (memberfound(Club, id, num)) {
            string clubname = ClubName(ls, num);
            if (clubname != " ") {
                cout << "Person is ALREADY a Member of " << clubname << "_Club." << endl;
            } else {
                cout << "No such club exist !!!" << endl;
            }
        } else {
            string clubname = ClubName(ls, num);
            if (clubname != " ") {
                node* ptr = new node;
                ptr->name = N;
                ptr->stdid = id;
                ptr->previous = nullptr;
                ptr->next = nullptr; // New node's next should be nullptr

                // Insert at the head of the linked list
                if (Club[num][id % 10] == nullptr) {
                    Club[num][id % 10] = ptr;
                } else {
                    Club[num][id % 10]->previous = ptr;
                    ptr->next = Club[num][id % 10];
                    Club[num][id % 10] = ptr;
                }
            } else {
                cout << "No such club exists !!!" << endl;
            }
        }
    } else {
        cout << "Sorry No such Club EXIST!!!!! " << endl;
    }
}

void printclubi(const vector<vector<node*>>& Club, list<pair<int, string>>& ls, int i) {
    bool clubHasMembers = false;
    int p = ls.size();
    string n = ClubName(ls, i);
    if (i <= p - 1) {
        cout << n << "_Club" << " Members:" << endl;
        for (int j = 0; j < Club[i].size(); ++j) {
            node* p = Club[i][j];
            while (p != nullptr) {
                cout << "Name: " << p->name << ", ID: " << p->stdid << endl;
                p = p->next;
                clubHasMembers = true;
            }
        }
        cout << endl;
        if (!clubHasMembers) {
            cout << "No members in this club." << endl;
        }
    }
}

void printclubcategory(const vector<vector<node*>>& Club, list<pair<int, string>>& ls) {
    int a;
    cout << "Enter 1 for co-curricular clubs" << endl;
    cout << "Enter 2 for cultural clubs" << endl;
    cout << "Enter 3 for science and technology clubs" << endl;
    cout << "Enter 4 for sports clubs" << endl;
    cout << "Enter 5 for newly added clubs" << endl;
    cin >> a;
    int p = ls.size();
    switch (a) {
        case 1:
            printclubi(Club, ls, 0);
            printclubi(Club, ls, 1);
            printclubi(Club, ls, 2);
            break;
        case 2:
            printclubi(Club, ls, 3);
            printclubi(Club, ls, 4);
            printclubi(Club, ls, 5);
            printclubi(Club, ls, 6);
            break;
        case 3:
            printclubi(Club, ls, 7);
            printclubi(Club, ls, 8);
            break;
        case 4:
            printclubi(Club, ls, 9);
            break;
        case 5:
            for (int i = 10; i < p; ++i) {
                printclubi(Club, ls, i);
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}


void printaclub(const vector<vector<node*>>& Club, list<pair<int, string>>& ls) {
    string n;
    cout << "Enter the name of the club: " << endl;
    cin >> n;
    editString(n);
    int i = ClubIndex(ls, n);
    if (i != -1) {
        bool clubHasMembers = false;
        cout << n << "_Club Members:" << endl;
        for (int j = 0; j < Club[i].size(); ++j) {
            node* p = Club[i][j];
            while (p != nullptr) {
                cout << "Name: " << p->name << ", ID: " << p->stdid << endl;
                p = p->next;
                clubHasMembers = true;
            }
        }
        cout << endl;
        if (!clubHasMembers) {
            cout << "No members in this club." << endl;
        }
    } else {
        cout << "Club not found!" << endl;
    }
}

void printAllMembers(const vector<vector<node*>>& Club, list<pair<int, string>>& ls) {
    bool anyMembers = false;
    for (int i = 0; i < Club.size(); ++i) {
        bool clubHasMembers = false;
        string clubname = ClubName(ls, i);

        if (clubname != " ") {
            cout << i + 1 << ") " << clubname << "_Club Members:" << endl;
            for (int j = 0; j < Club[i].size(); ++j) {
                node* p = Club[i][j];
                while (p != nullptr) {
                    cout << "Name: " << p->name << ", ID: " << p->stdid << endl;
                    p = p->next;
                    clubHasMembers = true;
                    anyMembers = true;
                }
            }
            if (!clubHasMembers) {
                cout << "No members in this club." << endl;
            }
            cout << endl;
        }
    }
    if (!anyMembers) {
        cout << "No members in any club." << endl;
    }
}

void searchbyid(vector<vector<node*>>& Club, list<pair<int, string>>& ls) {
    int id;
    cout << "Enter the ID you want to search: ";
    cin >> id;

    bool memberFound = false;

    for (int i = 0; i < ls.size(); i++) {
        node* q;
        q = Club[i][id % 10];
        while (q != nullptr) {
            if (q->stdid == id) {
                memberFound = true;
                string clubName = ClubName(ls, i);
                cout << clubName << "_Club" << endl;
                cout << "ID: " << q->stdid << endl;
                cout << "Name: " << q->name << endl;
                cout << endl;
                break;
            } else {
                q = q->next;
            }
        }
    }

    if (!memberFound) {
        cout << "Member with ID " << id << " is currently not present in any club of DAIICT." << endl;
    }
}

void searchbyname(vector<vector<node*>> Club, list<pair<int, string>> ls) {
    string n;
    cout << "Enter the name you want to search: ";
    cin >> ws; // Clear leading whitespace
    getline(cin, n);
    editString(n);
    cout << endl;

    int k = 0;
    for (int i = 0; i < Club.size(); i++) {
        node* p;
        int count = 0;
        for (int j = 0; j < 10; j++) {
            p = Club[i][j];
            while (p != nullptr) {
                if (p->name == n) {
                    cout << "Name: " << p->name << endl;
                    cout << "ID: " << p->stdid << endl;
                    count++;
                    k++;
                    break;
                } else {
                    p = p->next;
                }
            }
        }
        if (count > 0) {
            cout << ClubName(ls, i) <<"_Club"<< endl;
        }
    }
    if (k == 0) {
        cout << "No member found in any club." << endl;
    }
}
void Clubinfo(list<pair<int,string>> ls){
    cout<<"\t\t\t\t\tClubs Currently Running At DA-IICT\n\n";
    int i=1;
for (auto it = ls.begin(); it != ls.end(); ++it) {
      if(it->second==" "){
          
      }
      else{  cout <<i<<") "<< it->second <<"_Club"<< endl;
          i++;
      }
    }
    
    
}

int main()
{
    vector<Event> calendar;
    Event e1, e2, e3, e4, e5;
    e1.title = "Rang-Manch";
    e1.date = "2024-05-11";
    e1.time = "20:00";
    e2.title = "Radio-Clash";
    e2.date = "2024-05-26";
    e2.time = "11:30";
    e3.title = "Dandiya-Nights";
    e3.date = "2024-10-9";
    e3.time = "21:00";
    e4.title = "Mono-Play";
    e4.date = "2024-07-3";
    e4.time = "19:00";
    e5.title = "Parliamentry-Nights";
    e5.date = "2024-06-14";
    e5.time = "23:00";
    calendar.push_back(e1);
    calendar.push_back(e2);
    calendar.push_back(e3);
    calendar.push_back(e4);
    calendar.push_back(e5);

    list<pair<int, string>> ls;
    ls.push_back(make_pair(0, "Press"));
    ls.push_back(make_pair(1, "Debate"));
    ls.push_back(make_pair(2, "Film"));
    ls.push_back(make_pair(3, "Dance"));
    ls.push_back(make_pair(4, "Music"));
    ls.push_back(make_pair(5, "Khelaiya"));
    ls.push_back(make_pair(6, "Drama"));
    ls.push_back(make_pair(7, "Research"));
    ls.push_back(make_pair(8, "Programming"));
    ls.push_back(make_pair(9, "Chess"));
    vector<vector<string>> Convenors = {
        {"Press", "Mohit"},
        {"Debate", "shaam"},
        {"Film", "Risit"},
        {"Dance", "Rajvi"},
        {"Music", "Devin"},
        {"Khelaiya", "Siraj"},
        {"Drama", "Virat"},
        {"Research", "Hetvi"},
        {"Programming", "Dhruval"},
        {"Chess", "Riyaa"},
    };
    vector<int> Convenorsi = {202101233, 202101431, 202101473, 202101243, 202101263, 202101273, 202101169, 202101338, 202101339,
                              202101215

    };

 vector<vector<node *>>Club(10, vector<node *>(10, nullptr));

    //     *Press  Club  **

    insertmember(Club, "Mohit", 202101233, 0, ls);
    insertmember(Club, "Parshv Joshi", 202301039, 0, ls);
    insertmember(Club, "Siddharth Rambhia", 202301072, 0, ls);
    insertmember(Club, "Sanya Vaishnavi", 202301117, 0, ls);
    insertmember(Club, "Guru Vyas", 202301196, 0, ls);
    insertmember(Club, "Sharnam Shah", 202301247, 0, ls);
  //    **Debate  Club  **

    insertmember(Club, "shabhnam", 202101431, 1, ls);
    insertmember(Club, "Shashank Upadhyay", 202101411, 1, ls);
    insertmember(Club, "Dipak Dabhi", 202101229, 1, ls);
    insertmember(Club, "Harsh Kanani", 202103033, 1, ls);
    insertmember(Club, "Aadey Shah", 202101101, 1, ls);
    insertmember(Club, "Maulik Thakkar", 202101415, 1, ls);

    //    **Film  Club  **

    insertmember(Club, "Rishit ", 202101473, 2, ls);
    insertmember(Club, "Nirva Patel", 202201071, 2, ls);
    insertmember(Club, "Archi Jariwala", 202201450, 2, ls);
    insertmember(Club, "Aditya Prajapati", 202101133, 2, ls);
    insertmember(Club, "Preyali Dave", 202318028, 2, ls);

    //    **Dance  Club  **

    insertmember(Club, "Raj", 202101243, 3, ls);
    insertmember(Club, "Swayam Hingu", 202201207, 3, ls);
    insertmember(Club, "Janardan Pandya", 202101081, 3, ls);
    insertmember(Club, "Dev Vyas", 202201453, 3, ls);
    insertmember(Club, "Dhrudeep Sharma", 202201150, 3, ls);

    //    **Music  Club  **

    insertmember(Club, "Rishit Jain", 202301167, 4, ls);
    insertmember(Club, "Devin",  202101263,4, ls);
    insertmember(Club, "Ishti Patel ", 202301212, 4, ls);
    insertmember(Club, "Bilwa Raval", 202304030, 4, ls);
    insertmember(Club, "Mohit Dhanwani", 202304035, 4, ls);

    //    **Khelaiya  Club  **

    insertmember(Club, "Jhil Patel", 202301090, 5, ls);
    insertmember(Club, "Utsav Tala", 202303018, 5, ls);
    insertmember(Club, "Meet Gandhi", 202301219, 5, ls);
    insertmember(Club, "Namra Sanandiya", 202301130, 5, ls);
    insertmember(Club, "Vansh Vora", 202301266, 5, ls);
    insertmember(Club, "Dhruv Patel", 202301095, 5, ls);
    insertmember(Club, "Harshil Vora", 202301104, 5, ls);
    insertmember(Club, "Nisarg Divecha", 202301043, 5, ls);

    //    **Drama  Club  **

    insertmember(Club, "Virat", 202101163, 6, ls);
    insertmember(Club, "Ram Kulkarni", 202201354, 6, ls);
    insertmember(Club, "David Tandel", 202101251, 6, ls);
    insertmember(Club, "Darshil Radadiya", 202203056, 6, ls);
    insertmember(Club, "Parmar Uday", 202203031, 6, ls);

    //    **Research  Club  **

    insertmember(Club, "Het", 202101338, 7, ls);
    insertmember(Club, "Manit Shah", 202301425, 7, ls);
    insertmember(Club, "Manan Chhabhaya", 202301435, 7, ls);
    insertmember(Club, "Arav Vaithia", 202301267, 7, ls);
    insertmember(Club, "Yashsavi Jadav", 202301069, 7, ls);
    insertmember(Club, "Tith Modi", 202201513, 7, ls);

    //    **Programming  Club  **

    insertmember(Club, "Dhruval", 202101339, 8, ls);
    insertmember(Club, "Dhruv Goti", 202103024, 8, ls);
    insertmember(Club, "Srushti Kaneriya", 202103045, 8, ls);
    insertmember(Club, "Jalp Patel", 202101267, 8, ls);
    insertmember(Club, "Naisheel Patel", 202101014, 8, ls);
    insertmember(Club, "Shashank Upadhyay", 202101411, 8, ls);

    //    **Chess  Club  **

    insertmember(Club, "Riyaa", 202101215, 9, ls);
    insertmember(Club, "Aarzoo Khambhoo", 202103026, 9, ls);
    insertmember(Club, "Himani Singh", 202101258, 9, ls);
    insertmember(Club, "Kanishk Dad", 202103005, 9, ls);
    insertmember(Club, "Parth Tolani", 202201455, 9, ls);
    cout<<"\n\n\n\n\n";
   cout<<"\t\t\t\t\t\t\t**************************\n";
   cout<<"\t\t\t\t\t\t\t\033[1;31m|| DA-IICT CLUB MANAGER ||\033[0m\n";
   cout<<"\t\t\t\t\t\t\t**************************\n\n";
   
   cout<<"\t\t\tA Console Manager That assists in Handling Club details of all Clubs present at DA-IICT\n ";
   cout<<"\t\t\tand also maintains Calender of Upcoming events Scheduled by respective clubs.\n\n";
cout << " \t\t\t \033[35m Hey, where would you like to have assistance in??  \033[0m\n\n\n";
    cout << " \033[33m1. Calendar \033[0m\t\t\t\t\t"
         << "\033[33m2. Clubs-Members-Handling\033[0m\n";
    cout << "\033[33m3. Clubs-Convenors\033[0m\t\t\t\t"
         << "\033[33m 4. Clubs-Information\033[0m\n";
    cout <<"\033[33m 5. Addition/Deletion-Club\033[0m\n\n\n";

    cout << "Enter your choice (enter 0 to exit the program): ";
    int sect = 0;
    cin >> sect;
    string usertype, n, n2;
    string fac;
    string q;
    string username, password;
    int choiceEv = 0, idd = 0;
    string mode, user2, pass2;
    int g,j;
    string a;
    int choiceMc = 0;
    do
    {
        switch (sect)
        {
        case 1:
            cout << "\033[31m Are You an admin/student?? 0\33[0m : ";
            cin >> usertype;
            if (usertype == "admin")
            {

                cout << "\n\nEnter username: ";
                cin >> username;
                cout << "\nEnter password: ";
                cin >> password;
                if (username == "admin" && password == "password")
                {
                    do
                    {
                        cout << "\n\n\t\t\t\t\t\t  Admin Mode - Menu to handle Events :\n\n";
                        cout << "\t\t1.Add Event\t\t\t"
                             << "2.Delete Event\t\t\t"
                             << "3.Exit\n\n";
                        cout << "Enter your Choice : ";
                        cin >> choiceEv;
                        switch (choiceEv)
                        {
                        case 1:
                            addEvent(calendar);
                            break;
                        case 2:
                            deleteEvent(calendar);
                            break;
                        case 3:
                            cout << "\n\n\t\t\t\t\tExiting admin menu. " << endl;
                            break;
                        default:
                            cout << "Invalid Choice!!" << endl;
                        }
                    } while (choiceEv != 3);
                    cout << "\n\n\t\t\t\t\tView Calender.\n\n";
                    displayCalendar(calendar);
                }}
                else if (usertype == "student")
                {
                    cout << "\n\t\t\t\t\tView Calendar\n\n";
                    displayCalendar(calendar);
                }
                else
                {
                    cout << "\t\t\t\033[31mInvalid usertype! enter 'admin' or 'student' \033[0m";
                }
                cout<<endl;
            cout<<"Do you want to continue (enter 0 to exit or Select index from Main Menu)?? ";
                    cin>>sect;
            break;
        case 2:
            cout << "\n\t\t\t\t\033[35mFunctionalities to perform:\033[0m\n\n";
            cout << "\t\t1.Add-Member\t\t\t"
                 << "2.Delete-Member\t\t\t\n";
            cout << "\t\t3.Search Member ID\t\t"
                 << "4.Search-Member-Name \n";
            cout << "\t\t\t\t5.view-Club-Members\n";
            cout << "\033[31mEnter option to proceed(or 6 to exit) : \033[0m ";
            
            cin >> choiceMc;
            do
            {
                switch (choiceMc)
                {
                case 1:
                    cout << "\t\t\033[35mEnter name of Club to insert member : \033[0m ";
                    cin >> n;
                    editString(n);
                    cout << "\t\t\tEnter name of member: ";
                    cin>>ws;
                    getline(cin, n2);
                    editString(n2);
                    cout << "\t\tis member a faculty/student??";
                    cin >> fac;
                    if (fac == "faculty"){
                         j = ClubIndex(ls,n);
                        insertmember(Club, n2, 11, j , ls);
                    }
                    else
                    {
                        cout << "\n\t\tEnter student id : ";
                        cin >> idd;
                        //cout << "Enter club name: ";
                        // string x;
                        // cin >> x;
                        // editString(x);
                        int index = ClubIndex(ls, n);
                        insertmember(Club, n2, idd, index, ls);
                    }cout<<"Do you want to exit??(enter 6 to exit or select other option)";
                    cin>>choiceMc;
                    break;
                case 2:
                    deletion(Club, ls);
                    cout<<"Do you want to exit??(enter 6 to exit or select other option)";
                    cin>>choiceMc;
                    break;
                case 3:
                    searchbyid(Club, ls); 
                    cout<<"Do you want to exit??(enter 6 to exit or select other option)";
                    cin>>choiceMc;
                    break;
                case 4:
                    searchbyname(Club, ls); 
                    cout<<"Do you want to exit??(enter 6 to exit or select other option)";
                    cin>>choiceMc;
                    break;
                case 5:
                    cout << "\n\033[33m view Members : 1.A Particular Club , 2.All Clubs , 3. CLub Category \033[0m\n";
                    int p;
                    cout << "Enter you Choice : ";
                    cin >> p;
                    if (p == 2)
                        printAllMembers(Club, ls);
                    if(p == 1) { printaclub(Club, ls); }
                    if (p == 3)
                    {
                        printclubcategory(Club, ls);
                    }
                    cout<<"Do you want to exit??(enter 6 to exit or select other option)";
                    cin>>choiceMc;
                    break;
                case 6:
                    cout << "\t\t\t\t \033[31mExiting Club-Handling Menu \033[0m\n\n";
                    break;
                default:
                    cout << "\t\t\tEnter a valid Option\n";
                }
            } while (choiceMc != 6);
            cout<<"Do you want to continue (enter 0 to exit or Select from Main Menu)?? ";
                    cin>>sect;
            break;
        case 3:
            cout << "\t\t\t\033[33mAre you an admin / viewer ?? \033[0m ";
            cin >> mode;

            if (mode == "admin")
            {

                for (int i = 0; i < 3; i++)
                {
                    cout << "\n\n\t\tEnter your username : ";
                    cin >> user2;
                    cout << "\n\t\tEnter password: ";
                    cin >> pass2;

                    if (user2 == "admin" && pass2 == "password")
                    {
                        cout << "\t\t\t\t\t\t ADMIN MODE\n";
                        cout << "\t\t1.Change Convenor Details\t\t\t\t"
                             << "2.Print Convenors\n\n";
                        cout << "Enter your Choice : ";
                        int o;
                        cin >> o;
                        cout << "\n";
                        if (o == 2)
                        {
                            printConvenors(Convenors, Convenorsi);
                        }
                        else
                        {
                            if (o == 1)
                            {
                                Changeconvenor(Convenors, Convenorsi, Club, ls);
                            }
                            else
                            {
                                cout << "Invalid Option!!! ";
                            }
                        }
                    }
                    else
                    {
                        cout << "Incorrect Login Details ," << 2 - i << " chance left\n";
                    }
                }
                cout << "\t\t\t\t\t\t \033[31mExiting Convenor Section\033[0m\n\n";
            }
            else
            {
                cout << "\t\t\tConvenors of Clubs at DA-IICT \n\n";
                printConvenors(Convenors, Convenorsi);
                cout << "\t\t\t\t\t\t \033[31mExiting Convenor Section\033[0m\n\n";
            }
            cout<<"Do you want to continue (enter 0 to exit)?? ";
                    cin>>sect;
            break;
            
        case 4:
            cout << "\n";
            Clubinfo(ls);
            cout<<"Do you want to continue (enter 0 to exit or Select from Main Menu)?? ";
                    cin>>sect;
            break;
            
        case 5:
            cout << "Enter your username to perform club changes: ";
            
            cin >> q;
            cout << "Enter password: ";
            
            cin >> a;
            if (q == "admin" && a == "password")
            {
                cout << "\t\t\t\t\t\t1. ADD-CLUB..\t\t\t\t"
                     << "2.DELETE-CLUB\n\n";
                cout << "Enter you choice : " ;
                cin>>g;
                if (g == 1)
                {
                    clubAddition(Club, ls, Convenors, Convenorsi);
                }
                if (g == 2)
                {
                    clubDeletion(Club, ls, Convenors, Convenorsi);
                }
            }
            else
            {
                cout << "\t\t\t\tInvalid Login details";
            }
            cout<<"Do you want to continue (enter 0 to exit)?? ";
                    cin>>sect;
            break;
        case 0:
            cout << "\n\n\n\n\n\n\n*THANK YOU VISIT AGAIN*** ";
            cout << "Enter a Valid choice\n";
            break;
        default:
            break;
        }
    } while (sect != 0);
    return 0;
}
