#include <iostream>
#include "node.cpp"


void deletion(node **club[], int id, int num)
{
    node **p;
    if (num <= 10 && num > 0)
    {
        p = club[num - 1];
        node *q;
        q = p[id % 10];
        if (q == NULL)
            cout << "Empty array" << endl;
        else
        {
            if (q->stdid == id)
            {
                p[id % 10] = q->next;
                q->next = NULL;
                // delete node
            }
            else
            {
                int c = 0;
                while (q->next != NULL)
                {
                    if (q->stdid == id)
                    {
                        c = 1;
                        node *a;
                        node *b;
                        a = q->previous;
                        b = q->next;
                        b->previous = a;
                        a->next = b;
                        // doubly linked list deletion
                        break;
                    }
                    else
                        q = q->next;
                }
                if (c)
                    cout << "Wrong id entered" << endl;
            }
        }
    }
    else
        cout << "Wrong club number entered" << endl;
}
