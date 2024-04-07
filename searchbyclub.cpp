void searchbyclub(node **club[], int num)
{
    node **p;
    p = club[num - 1];
    node *q;
    int i = 0;
    int count = 1;
    switch (num - 1)
    {
    case 0:
        cout << "Press Club" << endl;
        break;
    case 1:
        cout << "Debate Club" << endl;
        break;
    case 2:
        cout << "Film Club" << endl;
        break;
    case 3:
        cout << "Dance Club" << endl;
        break;
    case 4:
        cout << "Music Club" << endl;
        break;
    case 5:
        cout << "Garba Club" << endl;
        break;
    case 6:
        cout << "Drama Club" << endl;
        break;
    case 7:
        cout << "Research Club" << endl;
        break;
    case 8:
        cout << "Programming Club" << endl;
        break;
    case 9:
        cout << "Chess Club" << endl;
        break;
    }
    for (int i = 0; i < 10; i++)
    {
        q = p[i];
        while (q != NULL)
        {
            cout << count << " . " << q->stdid << " , " << q->name << endl;
            q = q->next;
            count++;
        }
    }
}

void searchbyclubcategory(node **club[], int num)
{
    switch (num)
    {
    case 1:
        searchbyclub(club, 0);
        searchbyclub(club, 1);
        searchbyclub(club, 2);
        break;
    case 2:
        searchbyclub(club, 3);
        searchbyclub(club, 4);
        searchbyclub(club, 5);
        searchbyclub(club, 6);
        break;
    case 3:
        searchbyclub(club, 7);
        searchbyclub(club, 8);
    case 4:
        searchbyclub(club, 9);
    }
}

void searchbyid(node **club[], int id)
{
    short int c = 0;
    node **p;
    for (int i = 0; i < 10; i++)
    {
        p = club[i];
        node *q;
        q = p[id % 10];
        short int d = 0;
        while (q->next != NULL)
        {
            if (q->stdid == id)
            {
                if (c == 0)
                {
                    c = 1;
                    d = 1;
                    cout << "Id - " << q->stdid << endl;
                    cout << "Name - " << q->name << endl;

                    break;
                }
                else
                    d = 1;
            }
            else
                q = q->next;
        }
        if (d == 1)
        {
            switch (i)
            {
            case 0:
                cout << "Press Club" << endl;
                break;
            case 1:
                cout << "Debate Club" << endl;
                break;
            case 2:
                cout << "Film Club" << endl;
                break;
            case 3:
                cout << "Dance Club" << endl;
                break;
            case 4:
                cout << "Music Club" << endl;
                break;
            case 5:
                cout << "Garba Club" << endl;
                break;
            case 6:
                cout << "Drama Club" << endl;
                break;
            case 7:
                cout << "Research Club" << endl;
                break;
            case 8:
                cout << "Programming Club" << endl;
                break;
            case 9:
                cout << "Chess Club" << endl;
                break;
            }
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
