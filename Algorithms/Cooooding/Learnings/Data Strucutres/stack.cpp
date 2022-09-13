#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

void showStack (stack < pair<int,char> > s)
{
    while(!s.empty()){
       auto it;// pair<int, char> it;
        it=s.top();
        cout<<it.first<<endl;
        s.pop();
    }
}

int main()
{
    /*stack <int> s;
    srand(time(0));
    for (int i=0;i<5; i++)
        s.push(1 + rand()%10);

    showStack(s);

    cout<<"Size = "<<s.size();
    */
    stack< pair<int, char> > st;

    st.push(make_pair(1,'A'));
    st.push(make_pair(12,'B'));

    showStack(st);
}
