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
