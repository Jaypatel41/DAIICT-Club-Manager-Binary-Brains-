#include <iostream>
#include "node.cpp"

void searchbyname(node **club[], string name)
{
    node **p;
    int d = 0;
    for (int i = 0; i < 10; i++)
    {
        p = club[i];
        node *q;
        for (int j = 0; j < 10; j++)
        {
            q = p[j];
            while (q != NULL)
            {
                if (name == q->name)
                {
                    d = 1;
                    cout << "Name - " << q->name << endl;
                    cout << "Id - " << q->stdid << endl;
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
                q = q->next;
            }
        }
    }
    if (d == 0)
        cout << "Member of this name is currently not present in any of the club of DAIICT" << endl;
}