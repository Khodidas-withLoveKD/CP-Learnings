#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void showlist(list <int> l)
{
    list <int>::iterator it;

    for(it = l.begin(); it != l.end(); it++){
        cout<<" "<<*it;
    }
    cout<<endl;
}

int main()
{
    list <int> l1,l2;

    for(int i=0; i<5; i++){
        l1.push_back(i*2);
        l2.push_front(i*3);
    }
    cout<<"\nList 1=";
    showlist(l1);
    cout<<"\nList 2=";
    showlist(l2);

    cout<<"l1.size()="<<l1.size();
    cout<<"\nList 1 Before Sort=";
    showlist(l1);
    cout<<"\nAdding some elements to List 1\n";
    l1.push_back(1);
    l1.push_front(23);
    cout<<"\nBefore Sorting List 1=";
    showlist(l1);
    cout<<"\nAfter sorting List 1=";
    l1.sort();
    showlist(l1);
    cout<<"reversing l1\n";
    l1.reverse();
    showlist(l1);
    cout<<"\nPopping from front List 1=";
    l1.pop_front();
    showlist(l1);
    cout<<"\nPopping from back List 1=";
    l1.pop_back();
    showlist(l1);
}
