#include <iostream>
#include <queue>
using namespace std;

void showPq(priority_queue<int> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}
int main(){
    priority_queue<int> pq;

    pq.push(10);
    pq.push(1);
    pq.push(100);
    pq.push(20);
    cout<<"After pushing\n";
    showPq(pq);

    cout<<"Affter poping\n";
    pq.pop();
    showPq(pq);

    cout<<"Affter inserting 15\n";
    pq.push(15);
    showPq(pq);

}
