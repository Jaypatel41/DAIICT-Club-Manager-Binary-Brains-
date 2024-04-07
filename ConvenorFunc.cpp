void printConvenors(vector<vector<string>>&Convenor, vector<int>&Convenori){
cout << "\t\t\t\t\t\t\tLIST of CLUBS - Convenors\n\n";
for(int i=0;i<Convenor.size();i++){
    cout<<i+1<<")\t"<<Convenor[i][0]<<"---"<<Convenor[i][1]<<"---"<<Convenori[i]<<"\n";
    
}
}
void Changeconvenor(vector<vector<string>>& Convenor,vector<int>&Convenori,vector<vector<node*>>Club,list<pair<int,string>>& ls)
{
    cout<<"Enter Name of the Club for which you have to change Convenor: ";
    string clubname;
    cin >> clubname;
    editString(clubname);
    cout<<"\n";
    for(int i=0;i<10;i++)
    {
        if(Convenor[i][0]==clubname)
        {
            
            string name;
            cout<<"Enter Name of the Convenor: ";
            getline(cin,name);
            editString(name);
            
            cout<<"\n";

            int id;
            cout<<"Enter ID of the Convenor: ";
            cin>>id;
            
            int num=ClubIndex(ls,clubname);

            if(num==100)
            {
                cout<<"There is NO such Club as "<<clubname<<"_Club.\n";
                return;
            }
            if(memberfound(Club,id,num) && num!=100)
            {
                Convenor[i][1] = name;
                Convenori[i] = id;
                cout<<"\n\n";
                cout<<"\t\t\t Convenor is Updated for "<<Convenor[i][0]<<"\n\n";
                break;
            }
            else{cout<<name<<" is not a member of "<<clubname<<"_Club. So we can't assign him as Convenor.\n";return;}            
        }
    }
    cout<<"Updated List of Convenor is given below.\n\n\n";
    printConvenors(Convenor,Convenori);
}
