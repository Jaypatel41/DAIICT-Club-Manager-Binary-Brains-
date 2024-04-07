#include<iostream>
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
        {"Programming", "Dhruv"},
        {"Chess", "Riyaa"},
    };
    vector<int> Convenorsi = {202101233, 202101431, 202101473, 202101243, 202101263, 202101273, 202101169, 202101338, 202101339,
                              202101215

    };
    vector<vector<node *>>Club(10, vector<node *>(10, nullptr));

    //     ****Press  Club  *****

    insertmember(Club, "Mohit", 202101233, 0, ls);
    insertmember(Club, "Parshv Joshi", 202301039, 0, ls);
    insertmember(Club, "Siddharth Rambhia", 202301072, 0, ls);
    insertmember(Club, "Sanya Vaishnavi", 202301117, 0, ls);
    insertmember(Club, "Guru Vyas", 202301196, 0, ls);
    insertmember(Club, "Sharnam Shah", 202301247, 0, ls);

    //    *****Debate  Club  *****

    insertmember(Club, "shabhnam", 202101431, 1, ls);
    insertmember(Club, "Shashank Upadhyay", 202101411, 1, ls);
    insertmember(Club, "Dipak Dabhi", 202101229, 1, ls);
    insertmember(Club, "Harsh Kanani", 202103033, 1, ls);
    insertmember(Club, "Aadey Shah", 202101101, 1, ls);
    insertmember(Club, "Maulik Thakkar", 202101415, 1, ls);

    //    *****Film  Club  *****

    insertmember(Club, "Rishit ", 202101473, 2, ls);
    insertmember(Club, "Nirva Patel", 202201071, 2, ls);
    insertmember(Club, "Archi Jariwala", 202201450, 2, ls);
    insertmember(Club, "Aditya Prajapati", 202101133, 2, ls);
    insertmember(Club, "Preyali Dave", 202318028, 2, ls);

    //    *****Dance  Club  *****

    insertmember(Club, "Raj", 202101243, 3, ls);
    insertmember(Club, "Swayam Hingu", 202201207, 3, ls);
    insertmember(Club, "Janardan Pandya", 202101081, 3, ls);
    insertmember(Club, "Dev Vyas", 202201453, 3, ls);
    insertmember(Club, "Dhrudeep Sharma", 202201150, 3, ls);

    //    *****Music  Club  *****

    insertmember(Club, "Rishit Jain", 202301167, 4, ls);
    insertmember(Club, "Devin", , 202101263, ls);
    insertmember(Club, "Ishti Patel ", 202301212, 4, ls);
    insertmember(Club, "Bilwa Raval", 202304030, 4, ls);
    insertmember(Club, "Mohit Dhanwani", 202304035, 4, ls);

    //    *****Khelaiya  Club  *****

    insertmember(Club, "Jhil Patel", 202301090, 5, ls);
    insertmember(Club, "Utsav Tala", 202303018, 5, ls);
    insertmember(Club, "Meet Gandhi", 202301219, 5, ls);
    insertmember(Club, "Namra Sanandiya", 202301130, 5, ls);
    insertmember(Club, "Vansh Vora", 202301266, 5, ls);
    insertmember(Club, "Dhruv Patel", 202301095, 5, ls);
    insertmember(Club, "Harshil Vora", 202301104, 5, ls);
    insertmember(Club, "Nisarg Divecha", 202301043, 5, ls);

    //    *****Drama  Club  *****

    insertmember(Club, "Virat", 202101163, 6, ls);
    insertmember(Club, "Ram Kulkarni", 202201354, 6, ls);
    insertmember(Club, "David Tandel", 202101251, 6, ls);
    insertmember(Club, "Darshil Radadiya", 202203056, 6, ls);
    insertmember(Club, "Parmar Uday", 202203031, 6, ls);

    //    *****Research  Club  *****

    insertmember(Club, " Het ", 202101338, 7, ls);
    insertmember(Club, "Manit Shah", 202301425, 7, ls);
    insertmember(Club, "Manan Chhabhaya", 202301425, 7, ls);
    insertmember(Club, "Arav Vaithia", 202301267, 7, ls);
    insertmember(Club, "Yashsavi Jadav", 202301069, 7, ls);
    insertmember(Club, "Tith Modi", 202201513, 7, ls);

    //    *****Programming  Club  *****

    insertmember(Club, "Dhruval", 202101339, 8, ls);
    insertmember(Club, "Dhruv Goti", 202103024, 8, ls);
    insertmember(Club, "Srushti Kaneriya", 202103045, 8, ls);
    insertmember(Club, "Jalp Patel", 202101267, 8, ls);
    insertmember(Club, "Naisheel Patel", 202101014, 8, ls);
    insertmember(Club, "Shashank Upadhyay", 202101411, 8, ls);

    //    *****Chess  Club  *****

    insertmember(Club, "Riyaa", 202101215, 9, ls);
    insertmember(Club, "Aarzoo Khambhoo", 202103026, 9, ls);
    insertmember(Club, "Himani Singh", 202101258, 9, ls);
    insertmember(Club, "Kanishk Dad", 202103005, 9, ls);
    insertmember(Club, "Parth Tolani", 202201455, 9, ls);

    cout << "Hey, where would you like to have assistance in??\n\n\n";
    cout << "1. Calendar\t\t\t\t\t"
         << "2. Clubs-Members-Handling\n";
    cout << "3. Clubs-Convenors\t\t\t\t"
         << "4. Clubs-Information\n";
    cout << "5. Addition/Deletion-Club\n\n\n";

    cout << "Enter your choice (enter 0 to exit the program): ";
    int sect = 0;
    cin >> sect;
    string usertype, n, n2;
    string fac;
    string q;
    string username, password;
    int choiceEv = 0, idd = 0;
    string mode, user2, pass2;
    int g;
    string a;
    int choiceMc = 0;
    do
    {
        switch (sect)
        {
        case 1:
            cout << "Are You an admin/student?? : ";

            cin >> usertype;
            editString(usertype);
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
                        cout << "\n\n\t\t\t\t\t\t Admin Mode - Menu to handle Events :\n\n";
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
                }
                else if (usertype == "student")
                {
                    cout << "\n\t\t\t\t\tView Calendar\n\n";
                    displayCalendar(calendar);
                }
                else
                {
                    cout << "\t\t\tInvalid usertype! enter 'admin' or 'student'";
                }
            }
            break;
        case 2:
            cout << "\n\t\t\t\tFunctionalities to perform:\n\n";
            cout << "\t\t1.Add-Member\t\t\t"
                 << "2.Delete-Member\t\t\t\n";
            cout << "\t\t3.Search Member ID\t\t"
                 << "4.Search-Member-Name \n";
            cout << "\t\t\t\t5.view-Club-Members\n";
            cout << "Enter option to proceed(or 6 to exit) : ";
            
            cin >> choiceMc;
            do
            {
                switch (choiceMc)
                {
                case 1:
                    cout << "\t\tEnter name of Club to insert member : ";
                    cin >> n;
                    editString(n);
                    cout << "\t\t\tEnter name of member: ";
                    getline(cin, n2);
                    editString(n2);
                    cout << "\t\tis member a faculty/student??";
                    cin >> fac;
                    if (fac == "faculty")
                        insertion(Club, n2, 11, ls);
                    else
                    {
                        cout << "\n\t\tEnter student id : ";
                        cin >> idd;
                        cout << "Enter club name: ";
                        string x;
                        cin >> x;
                        editString(x);
                        int index = ClubIndex(ls, x);
                        insertmember(Club, n2, idd, index, ls);
                    }
                    break;
                case 2:
                    deletion(Club, ls);
                    break;
                case 3:
                    searchbyid(Club, ls) break;
                case 4:
                    searchbyname(Club, ls) break;
                case 5:
                    cout << "\nview Members : 1.A Particular Club , 2.All Clubs , 3. CLub Category\n";
                    int p;
                    cout << "Enter you Choice : ";
                    cin >> P;
                    if (p = 2)
                        printAllMembers(Club, ls);
                    (p = 1) { printaclub(Clube, ls); }
                    if (p = 3)
                    {
                        printclubcategory(Club, ls);
                    }
                    break;
                case 6:
                    cout << "\t\t\t\tExiting Club-Handling Menu\n\n";
                    break;
                default:
                    cout << "\t\t\tEnter a valid Option\n";
                }
            } while (choiceMc != 6);
            break;
        case 3:
            cout << "\t\t\tAre you an admin / viewer ?? ";
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
                cout << "\t\t\t\t\t\tExiting Convenor Section\n\n";
            }
            else
            {
                cout << "\t\t\tConvenors of Clubs at DA-IICT \n\n";
                printConvenors(Convenors, Convenorsi);
                cout << "\t\t\t\t\t\tExiting Convenor Section\n\n";
            }
            break;
        case 4:
            cout << "\n";
            Clubinfo(ls);
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
                cout << "Enter you choice : " 
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
            break;
        case 0:
            cout << "\n\n\n\n\n\n\n*THANK YOU VISIT AGAIN********* ";
            cout << "Enter a Valid choice\n";
            break;
        default:
            break;
        }
    } while (sect != 0);
    return 0;
}
