#include <iostream>
#include "node.cpp"

void insertmember(node**club[],string N,int id,int num)
{
node*ptr=new node;
     ptr->name=N;
     ptr->stdid=id;
node**p;
if(num<=10&&num>0){
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
    else{
        cout<<"Sorry That Club Number doesn't EXIST!!!!! "<<"\n";
    }
    
}