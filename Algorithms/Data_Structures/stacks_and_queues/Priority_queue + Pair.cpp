#include <iostream>
#include <queue>
#define mp make_pair
#define F first
#define S second
using namespace std;

showPQ(priority_queue<pair<int,int> > pq){
    cout<<"Queue is: ";
    while(pq.empty()){
        cout<<"F,S = "<<pq.top().F<<','<<pq.top().S<<" ";
    }
    cout<<"\n";
}

int main(){
    priority_queue<pair<int,int> > pq;

    pq.push(mp(1,10));
    pq.push(mp(2,20));
    pq.push(mp(3,30));

    showPQ(pq);
}
