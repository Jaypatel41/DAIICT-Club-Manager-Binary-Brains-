#include <iostream>
#include "node.cpp"

int memberfound(node**club[],int id,int num){
    node**p;
    p=club[num-1];
    node*q;
    q=p[id%10];
    if(q==NULL){
        return 0;
    }
    else{
    while(q!=NULL){
        if(q->stdid==id){return 1;}
        q=q->next;
    }
   
   
        return 0;
    }
   
}
void insertmember(vector<vector<node *>> &Club, string N, int id, int num, list<pair<int, string>> &ls)
{
    if (num >= 0 && num <= ls.size())
    {
        if (memberfound(Club, id, num))
        {
            string clubname = ClubName(ls, num);
            if (clubname != " ")
                cout << "Person is ALREADY a Member of " << clubname << "_Club." << endl;
            else
                cout << "No such club exist !!!" << endl;
        }
        else
        {
            string clubname = ClubName(ls, num);
            if (clubname != " ")
            {
                node *ptr = new node;
                ptr->name = N;
                ptr->stdid = id;
                ptr->previous = nullptr;
                ptr->next = nullptr; // New node's next should be nullptr

                // Insert at the head of the linked list
                if (Club[num][id % 10] == nullptr)
                {
                    Club[num][id % 10] = ptr;
                }
                else
                {
                    Club[num][id % 10]->previous = ptr;
                    ptr->next = Club[num][id % 10];
                    Club[num][id % 10] = ptr;
                }
            }
            else 
                cout<<"No such club exists !!!"<<endl;
        }
    }
    else
    {
        cout << "Sorry No such Club EXIST!!!!! " << endl;
    }
}
