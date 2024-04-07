void printaclub(const vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    string n;
    cout << "Enter the name of the club " << endl;
    cin >> n;
    editString(n);
    int i = ClubIndex(ls, n);
    if (i != 100)
    {
        bool clubHasMembers = false;
        cout << n << "_Club"
             << " Members:" << endl;
        for (int j = 0; j < Club[i].size(); ++j)
        {
            node *p = Club[i][j];
            while (p != nullptr)
            {
                cout << "Name: " << p->name << ", ID: " << p->stdid << endl;
                p = p->next;
                clubHasMembers = true;
            }
        }
        cout << endl;
        if (!clubHasMembers)
        {
            cout << "No members in this club." << endl;
        }
    }
}

void printclubcategory(const vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    int a;
    cout << "Enter 1 for co-curricular clubs" << endl;
    cout << "Enter 2 for cultural clubs" << endl;
    cout << "Enter 3 for science and technology clubs" << endl;
    cout << "Enter 4 for sports clubs" << endl;
    cout << "Enter 5 for newly added clubs" << endl;
    cin >> a;
    int p = ls.size();
    switch (a)
    {
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
        for(int i= 10; i <= p; ++i)
        printclubi(Club, ls, i);
    }
}

void searchbyid(vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    int id;
    cout << "Enter the id you want to search " << endl;
    cin >> id;
    short int c = 0;
    for (int i = 0; i < ls.size(); i++)
    {
        node *q;
        q = Club[i][id % 10];
        while (q != NULL)
        {
            if (q->stdid == id)
            {
                c = 1;
                string s = ClubName(ls, i);
                cout << s << "_Club" << endl;
                cout << "Id - " << q->stdid << endl;
                cout << "Name - " << q->name << endl;
                
                cout<<"\n\n";
                break;
            }
            else
                q = q->next;
        }
    }
    if (c == 0)
        cout << "Member of this ID is currently not present in any of the club of DAIICT" << endl;
}

void searchbyname(vector<vector<node *>> Club, list<pair<int, string>> ls)
{
    string n;
    cout<< "Enter the name you want to search" << endl;
    getline(cin,n);
    editString(n);
    cout<<"\n";
    int k = 0;
    for (int i = 0; i <Club.size(); i++)
    {
        node * p;
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            p = Club[i][j];
            while (p != NULL)
            {
                if (p->name == n)
                {
                    cout << "Name: " << p->name << endl;
                    cout << "ID: " << p->stdid << endl; 
                    count++;
                    k++;
                    break;
                }
                else 
                p= p->next;
            }
        }
        if (count > 0)
        {
            cout << ClubName(ls, i) << endl;
        }
    }
    if (k = 0)
    {
        cout << "No member found in Any CLUBS\n";
    }
}

void printAllMembers(const vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    bool anyMembers = false;
    for (int i = 0; i < Club.size(); ++i)
    {
        bool clubHasMembers = false;
        string clubname = ClubName(ls, i);

        if(clubname!=" ")
        {
        cout << i + 1 << ") " << clubname << "_Club"
             << " Members:" << endl;
        for (int j = 0; j < Club[i].size(); ++j)
        {
            node *p = Club[i][j];
            while (p != nullptr)
            {
                cout << "Name: " << p->name << ", ID: " << p->stdid << endl;
                p = p->next;
                clubHasMembers = true;
                anyMembers = true;
            }
        }}
        if (!clubHasMembers)
        {
            cout << "No members in this club." << endl;
        }
        cout << endl;
    }
    if (!anyMembers)
    {
        cout << "No members in any club." << endl;
    }
}
