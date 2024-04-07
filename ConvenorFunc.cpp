void printConvenors(vector<vector<string>>&Convenor, vector<int>&Convenori){
cout << "\t\t\t\t\t\t\tLIST of CLUBS - Convenors\n\n";
for(int i=0;i<Convenor.size();i++){
    cout<<i+1<<")\t"<<Convenor[i][0]<<"---"<<Convenor[i][1]<<"---"<<Convenori[i]<<"\n";
    
}
}
