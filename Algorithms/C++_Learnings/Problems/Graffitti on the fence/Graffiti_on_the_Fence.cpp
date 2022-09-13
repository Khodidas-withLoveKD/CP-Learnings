#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Node
{
public:
    int start,end;
    //Node *next;
};
Node *head=NULL,*temp=NULL;

class Sorted
{
public:
    int s_start,s_end;
    Sorted *next;
};
Sorted *s_head=NULL,*s_temp,*s_temp3,*s_temp5;
int counter=0;

/*void Node_traverse()
{
    temp=head;
    int i=1;
    while(temp!=NULL)
    {
        cout<<"Node "<<i++<<": Start="<<temp->start<<" End="<<temp->end<<endl;
        temp=temp->next;
    }
    cout<<"exiting Node_traverse"<<endl;
}*/
void Sorted_traverse()
{
    s_temp=s_head;
    int i=1;
    while(s_temp!=NULL)
    {
        cout<<"Sorted "<<i++<<": Start="<<s_temp->s_start<<" End="<<s_temp->s_end<<endl;
        s_temp=s_temp->next;
    }
}
void push(int new_start,int new_end)
{
    //Node *temp2;
    Node *new_node=new Node();

    new_node->start=new_start;
    new_node->end=new_end;
    //new_node->next=NULL;
    head=new_node;

    /*if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp2=head;
        while(temp2->next!=NULL)
            temp2=temp2->next;

        temp2->next=new_node;
    }*/

}
void push_end_sort(int new_start,int new_end)
{
    Sorted *new_node=new Sorted();
    //cout<<"Inside push_end_sort"<<endl;
    new_node->s_start=new_start;
    new_node->s_end=new_end;
    new_node->next=NULL;
    if(s_head!=NULL)
        s_temp3->next=new_node;
    else
        s_head=new_node;
    //cout<<"push_end_sort "<<++counter<<": Start="<<new_node->s_start<<" End="<<new_node->s_end<<endl;
   //cout<<"exiting Push_end_sort"<<endl;

}

void push_begin_sort(int new_start,int new_end)
{
    Sorted *new_node=new Sorted();
    //cout<<"Inside push_begin_sort"<<endl;
    new_node->s_start=new_start;
    new_node->s_end=new_end;
    new_node->next=NULL;

    if(s_head==NULL)
    {
       s_head=new_node;
    }
    else
    {
        new_node->next=s_head;
        s_head=new_node;
    }
    //cout<<"push_begin_sort "<<++counter<<": Start="<<new_node->s_start<<" End="<<new_node->s_end<<endl;
   //cout<<"exiting Push_begin_sort"<<endl;


}
void push_between_sort(int new_start,int new_end)
{
    Sorted *new_node=new Sorted();
    //cout<<"Inside push_between_sort"<<endl;
    new_node->s_start=new_start;
    new_node->s_end=new_end;
    new_node->next=s_temp3->next;

    s_temp3->next=new_node;
    //cout<<"push_between_sort "<<++counter<<": Start="<<new_node->s_start<<" End="<<new_node->s_end<<endl;
   //cout<<"exiting push_between_sort"<<endl;

}
void remove()
{
    if(s_temp5->s_end <= head->end)
            s_temp3->s_end=head->end;
        else
            s_temp3->s_end=s_temp5->s_end;

            cout<<"TEMP3="<<s_temp3->s_start<<endl;
            cout<<"TEMP5="<<s_temp5->s_start<<endl;

         Sorted *s_temp4=s_temp3->next;
            if(s_temp5->next!=NULL)
                s_temp3->next=s_temp5->next;
            else
                s_temp3->next=NULL;
            
            cout<<"TEMP3="<<s_temp3->s_start<<endl;
            cout<<"TEMP5="<<s_temp5->s_start<<endl;
            //to remove in between nodes
            while(s_temp4!=s_temp5)
            {
                Sorted *s_remove=s_temp4;
                s_temp4=s_temp4->next;
                free(s_remove);
            }
}
bool check()
{
    //exchange nothing
    if(head->start >= s_temp3->s_start && head->end <= s_temp3->s_end)
        {cout<<"Exchane NOTHING"<<endl;
            return true;
        }
    //If s_temp3->next->s_start > head->start
    /*else if(head->start > s_temp3->s_end && s_temp3->next->s_start > head->start && s_temp3->next->s_end >= head->end) 
    {
        s_temp3->next->start=head->start;
        return true;
    }*/

    //Exchange end and update (many) adjacent nodes
    else if(head->start >= s_temp3->s_start && head->end > s_temp3->s_end && s_temp3->next!=NULL && head->end >= s_temp3->next->s_start)
    {   
        s_temp5=s_temp3;

        while(head->start >= s_temp5->s_start && head->end > s_temp5->s_end && s_temp5->next!=NULL && head->end >= s_temp5->next->s_start)
            s_temp5=s_temp5->next;   

        cout<<"Exchane END and UPDATE"<<endl;
        remove();
        /*s_temp3->s_end=s_temp5->s_end;
        s_temp3->next=s_temp5->next;
        free(s_temp5);*/
        return true;
    }
    //exchange single node at end
    else if(s_temp3->next==NULL && head->start >= s_temp3->s_start && head->start <= s_temp3->s_end && head->end > s_temp3->s_end )
    {
        s_temp3->s_end=head->end;
        return true;
    }
     //exchange both ends and (many) adjacent nodes

    else if(head->start < s_temp3->s_start && head->end > s_temp3->s_end)
    {
        s_temp5=s_temp3;

        while(s_temp5->next!=NULL && head->start < s_temp3->s_start && head->end > s_temp5->s_end )
            s_temp5=s_temp5->next;

        remove();
        cout<<"Exchane BOTH"<<endl;
        s_temp3->s_start=head->start;
        //s_head->s_end=head->end;
        return true;
    }
    //Exchange end
    /*else if(head->start >= s_temp3->s_start && head->end > s_temp3->s_end && head->start<=s_temp3->s_end)
    {
        cout<<"Exchane END"<<endl;
        s_temp3->s_end=head->end;
        return true;
    }*/
    //Exchange start
    else if(head->start < s_temp3->s_start && head->end <= s_temp3->s_end && head->end >= s_temp3->s_start)
    {cout<<"Exchane START"<<endl;
        s_temp3->s_start=head->start;
            return true;
    }

    return false;
}

void sort_list()
{
    //Sorted *s_temp4;
    //bool checker=false;
    //cout<<"Inside sort_list"<<endl;
    cout<<"------------\n";
    Sorted_traverse();
    cout<<"------------\n";
    s_temp3=s_head;
    if(s_head==NULL)
        push_end_sort(head->start,head->end);
    else
    {
        if(head->start < s_head->s_start)
        {
            if(check())
                return;
            else
                push_begin_sort(head->start,head->end);

            return;
        }
        else if(head->start > s_head->s_start)
        {   //cout<<"Inside sort_list ELSE IF"<<endl;
            //If  END overlapping
           while(s_temp3->next != NULL && head->start >= s_temp3->next->s_start && head->end >= s_temp3->next->s_end )
                {
                    //cout<<"Inside sort_list WHILE"<<endl;
                    s_temp3=s_temp3->next;        
                }
            //if(s_temp3->next->s_start >= head->start)
                //s_temp3=s_temp3->next;

                cout<<"S_TEMP_STart="<<s_temp3->s_start<<endl;
            if(s_temp3->next==NULL)
                {   
                     //cout<<"Inside sort_list IF"<<endl;
                    if(check())
                        return;
                    else
                        push_end_sort(head->start,head->end);

                    return;
                }
            else
            {
                if(check())
                    return;
                else
                    push_between_sort(head->start,head->end);
            }
        }
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int L;
    cin >> L; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int st;
        int ed;
        cin >> st >> ed; cin.ignore();
        push(st,ed);
        cout<<"st="<<st<<" ed="<<ed<<endl;
        s_temp3=s_head;
        sort_list();
        free(head);
    }
    //Node_traverse();
    //sorting list
    
    /*while(head!=NULL)
    {
        sort_list();
        head=head->next;
    }*/
    Sorted_traverse();
    //Output Answer
    cout<<"\nOutputting answer\n";
    if(s_head->s_start==0)
        {   
            if(s_head->s_end==L)
            {
                cout<<"All painted";
                return 0;
            }
            else if(s_head->next!=NULL)
           { 
                cout<<s_head->s_end<<" ";
               s_head=s_head->next;
                cout<<s_head->s_start<<endl;
            }
            else
            {
                cout<<s_head->s_end<<" "<<L;
                return 0
 ;           }
        }
    else
    {
        cout<<"0 ";
        if(s_head!=NULL)
            cout<<s_head->s_start<<endl;
        else
            cout<<L;

    }

    while(s_head!=NULL && s_head->s_end!=L)
    {
       if(s_head->next!=NULL)
       {   //cout<<"First If\n";
            cout<<s_head->s_end<<" ";
           s_head=s_head->next;
            cout<<s_head->s_start<<endl;
        }
        else
        {//cout<<"ELSE\n";
            cout<<s_head->s_end<<" "<<L;
            return 0;
        }
    }
}
