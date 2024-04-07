void clubAddition(vector<vector<node *>> Club,list<pair<int,string>>& ls,vector<vector<string>> &Convenor, vector<int> &Convenori)
{
    string clubname;
    cin >> clubname;
    editString(clubname);
    vector<node *> temp(10, nullptr);
    Club.push_back(temp); //new club row creted in main node* vector

    //pushback in linked list
    int listSize=ls.size();
    ls.push_back(make_pair(listSize,"clubname"));


    //adding to main vector
    node* p;
    cout<<"For making new Club you need to appoint a Convenor to it at least.\n\n";
    cout<<"Enter the name of the Convenor: ";
    cin>>p->name;
    cout<<"\n";
    cout<<"Enter the Id of the Convenor: ";
    cin>>p->stdid;

    int num=ClubIndex(ls,clubname);
    Club[num][(p->stdid) % 10]=p;
    p->next=NULL;


    //adding to convenor vector
    Convenor.push_back(make_pair(clubname,p->name));
    Convenori.push_back(p->stdid);
    
}

void clubDeletion(vector<vector<node *>> &Club, list<pair<int, string>> &ls, vector<vector<string>> &Convenor, vector<int> &Convenori)
{
    string clubname;
    cin >> clubname;
    editString(clubname);
    int num = ClubIndex(ls, clubname);
    if (num == 100)
       { cout << "There is NO such Club as " << clubname << "_Club.";
        return;}
    for (int i = 0; i < 10; i++)
    {
        Club[num][i] = NULL;
    }
    
    // Deleting Convenor also from Convenor list
    int index;
    for(int i=0;i<Convenor.size();i++)
    {
        if(Club[i][0]==clubname)
        {
            index=i;
        }
    }
    Convenor.erase(Convenor.begin()+index);
    Convenori.erase(Convenori.begin()+index);
    
    //Changing List of Clubs also
    for (const auto &pair : ls)
    {
        if(pair.second==clubname)
        {
            pair.second=" ";
        }
    }

    cout << clubname << "_Club has been disbanded.\n\n";
}
