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
void insertmember(node**club[],string N,int id,int num)
{
    if(num<=10&&num>0){
    if(memberfound(club,id,num)){
        cout<<"Person is ALREADY a Member of this CLUB"<<endl;
    }
    else{
node*ptr=new node;
     ptr->name=N;
     ptr->stdid=id;
node**p;

      p=club[num-1];
 node*q;
 
 
    q=p[id%10];
         if(q==NULL)
             {  p[id%10]=ptr;
                ptr->previous=NULL;
                ptr->next=NULL;
             }
    else{
           ptr->previous=NULL;
           p[id%10]=ptr;
           ptr->next=q;
           q->previous=ptr;
    
    }
    }
    }

    else{
        cout<<"Sorry That Club Number doesn't EXIST!!!!! "<<"\n";
    }
    
}
