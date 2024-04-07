#include <iostream>
#include "node.cpp"


void deletion(const vector<vector<node *>> &Club, list<pair<int, string>> &ls)
{
    int id;
    int n;
    node *q;
    cout << "Enter the id of student you want to delete" << endl;
    cin >> id;
    string s;
    cout << "Enter the name of the club from which you want to delete a member" getline(cin, s);
    n = ClubIndex(ls, s)
    q = Club[n][id % 10];
    while (q != NULL)
    {
        if (q->id == id)
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
            if (q->id == id)
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
