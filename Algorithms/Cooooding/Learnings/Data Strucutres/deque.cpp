#include <iostream>
#include <deque>
using namespace std;

void showDq(deque<int> dq){
    for(int i=0; i<dq.size(); i++)
        cout<<dq[i]<<" ";
}
int main(){
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(100);
    dq.push_front(2);

    cout<<"Inserting all\n";
    showDq(dq);
    cout<<"\nAfter pop_back\n";
    dq.pop_back();
    showDq(dq);
    dq.pop_front();
    cout<<"\nAfter pop_front\n";
    showDq(dq);
    cout<<"\ndequeue.at(1) = "<<dq.at(1);
}
