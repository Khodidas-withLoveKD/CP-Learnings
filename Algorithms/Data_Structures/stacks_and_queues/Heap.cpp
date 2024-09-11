#include <iostream>
//#inlcude <heap>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);
    v.push_back(191);

    make_heap(v.begin(),v.end());
    cout<<"\nHeap.Head()="<<v.front();
    v.push_back(200);
    push_heap(v.begin(),v.end());
    cout<<"\nHeap.Head()="<<v.front();

    pop_heap(v.begin(),v.end());
    v.pop_back();
    cout<<"\nHeap.Head()="<<v.front();

    //Let's see if we can traverse the heap
    vector<int> :: iterator it;

    for(it=v.begin(); it!=v.end(); it++)
        cout<<" "<<*it;
    //Nope we cannot :)
}
