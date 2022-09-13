#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
}*start=NULL,*temp,*temp2;

void traverse(Node *start)
{
    temp=start;
    if(temp==NULL)
        cout<<"NULL";
    else
        while(temp!=NULL)
    {
        //cout<<"Inside Traverse"<<endl;
        cout<<temp->data<<endl;
        //cout<<"Address="<<temp<<endl;
        temp=temp->next;
    }
    //cout<<"Address="<<temp<<endl;
}

void reverse_list()
{
    cout<<"\nREVERSING\n-----------------\n";
    Node *curr,*prev,*agal;
    if(start==NULL){
        cout<<"List Empty. Reversing not possible"<<endl;
        return ;
    }
    if(start->next==NULL)
        return;

    prev=start;
    curr=prev->next;
    if(curr->next==NULL){
        curr->next=prev;
        start->next=NULL;
        start=curr;
        return ;
    }
    agal=curr->next;

    while(agal!=NULL){
        curr->next=prev;
        prev=curr;
        curr=agal;
        agal=agal->next;
    }
    curr->next=prev;
    start->next=NULL;
    start=curr;

}
Node * insert_begin(int  new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    if(start==NULL)
    {
        //cout<<"Inside NULL"<<endl;
        start=new_node;
        new_node->next=NULL;
    }
    else
        {
        new_node->next=start;
        start=new_node;
        }
    //cout<<"start->Data="<<start->data;
    //cout<<"Exiting\n";
    //traverse(start);
    return start;
}

void delete_end()
{
   temp2=start;
    cout<<"Start="<<start<<endl;
    if(temp2==NULL)
        cout<<"List Empty";
  else if(temp2->next==NULL)
   {
       cout<<"when only one loop"<<endl;
       free(temp2);
       start=NULL;
   }
   else
    {
        while(temp2->next->next!=NULL)
        {
           //.cout<<"Inside While"<<endl;
           temp2=temp2->next;
        }
            free(temp2->next);
            temp2->next=NULL;

    }
    //cout<<"taverseing\n";
            //traverse(start);
}

int main()
{
   // Node *start=NULL,*temp;
    int n,val,del;
    cout<<"Enter no. of nodes:";
    cin>>n;
    del=n+1;

    while(n--)
    {
        cin>>val;
        start=insert_begin(val);
        //cout<<"Start="<<start<<endl;

    }
    cout<<"before Reverse\n";
    traverse(start);
    reverse_list();
    traverse(start);
    /*while(del--)
    {
        //cout<<"\n NOW DELETING"<<endl;

        delete_end();
        //traverse(start);
    }*/
}
