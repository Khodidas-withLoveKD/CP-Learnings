#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#define pb push_back
using namespace std;

int main(){
    vector<int> vect;
    vect.pb(1);
    vect.pb(4);
    vect.pb(2);
    vect.pb(5);
    vect.pb(3);

    set<int> s1;
    set<int ,greater<int> > s2;

    s1.insert(vect.begin(), vect.end());
    s2.insert(vect.begin(), vect.end());

    cout<<"S1 = ";
    for(int x : s1)
        cout<<x<<" ";
    cout<<"\n\nS2 = ";
    for(int x : s2)
        cout<<x<<" ";
}
