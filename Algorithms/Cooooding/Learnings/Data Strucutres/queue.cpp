#include <iostream>
#include <queue>

using namespace std;

void show_by_pop (queue <int> q)
{
    while(!q.empty()){
        cout<<" "<<q.front();
        q.pop();
    }
}

int main()
{
    queue <int> q1,q2;

    for(int i=1;i<6;i++){
        q1.push(i*2);
        q2.push(i*3);
    }

    cout<<"\nQueue 1=";
    show_by_pop(q1);
    cout<<"\nQueue 2=";
    show_by_pop(q2);
    cout<<"\nSize of Queue 1= "<<q1.size();
     cout<<"\nFront of Queue 1= "<<q1.front();
      cout<<"\nBAck of Queue 1= "<<q1.back();
}
