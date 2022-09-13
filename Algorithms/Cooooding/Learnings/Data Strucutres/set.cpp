#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

set <int, greater<int> > :: iterator it;
set <int> :: iterator it2;

void display(set< int, greater<int> > s){

    for(it = s.begin(); it != s.end(); it++)
        cout<<"\t"<<*it;
}
void simple_display(set<int> s){

    for(it2 = s.begin(); it2 != s.end(); it2++)
        cout<<"\t"<<*it2;
}
int main(){

    set <int> s1;//, greater<int> > s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    s1.insert(30);

    cout<<"S1: ";
    simple_display(s1);
    set<int> s2(s1.begin(), s1.end());
    cout<<"\nS2: ";
    simple_display(s2);

    s2.erase(50);
    cout<<"\nAfter erasing 50: ";
    simple_display(s2);

    s2.erase(s2.begin(), s2.find(30));
    cout<<"\nAfter erasing less than 30: ";
    simple_display(s2);

    s1.insert(100);
    s1.insert(1);
    cout<<"\n To see implementation of Red-Black Tree: ";
    simple_display(s1);

    cout<<"\n\nset.find()\n";
    if(s1.find(0) != s1.end())
        cout<<"Element FOund\n";
    else
        cout<<"NOT FOUND!!!\n";


}
