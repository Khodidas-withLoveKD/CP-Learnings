#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

queue <string> p1,p2,temp1,temp2;
void show(queue <string> p, queue <string> q){

    cout<<"\n--------------\nP1: ";
    while(!p.empty()){
        cout<<p.front()<<' ';
        p.pop();
    }
    cout<<"\nP2: ";
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
}
int evaluate(string card){
    
    int val;
    if(card[0] == 'J')
        val=11;
    else if (card[0] == 'Q')
        val=12;
    else if (card[0] == 'K')
        val=13;
    else if(card[0] == 'A')
        val=14;
    else if(card[0] == '1' && card[1] == '0')
        val=10;
    else
        val = card[0] - '0';
    
    return val;
}

void push_temp1(){
    
    while(!temp1.empty()){
        p1.push(temp1.front());
        temp1.pop();
    }
    while(!temp2.empty()){
        p1.push(temp2.front());
        temp2.pop();
    }
}
void push_temp2(){
    
    while(!temp2.empty()){
        p2.push(temp2.front());
        temp2.pop();
    }
    while(!temp1.empty()){
        p2.push(temp1.front());
        temp1.pop();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    string ans;
    bool flag=false,war=false;
    int n,c1,c2,turns=0,c1wins=0,c2wins=0; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        p1.push(cardp1);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        p2.push(cardp2);
    }
    
    while(!flag){
         
         show(p1,p2);

         if(war == true && (p1.empty() || p2.empty())){
            ans="PAT";
            cout<<"Inside PAT"<<endl;
            break;
        }
        
        c1 = evaluate(p1.front());
        c2 = evaluate(p2.front());
    
        temp1.push(p1.front());
        temp2.push(p2.front());
        
        p1.pop();
        p2.pop();
    
        if(c1 > c2){
            turns++;
            c1wins++;
            cout<<"\nC1111111 | c1="<<c1<<" c2="<<c2<<" c1wins="<<c1wins<<" c2wins="<<c2wins<<" turn="<<turns<<endl;
            push_temp1();
            war=false;
        }
        else if(c2 > c1){
            turns++;
            c2wins++;
            cout<<"\ncC22222 | c1="<<c1<<" c2="<<c2<<" c1wins="<<c1wins<<" c2wins="<<c2wins<<" turn="<<turns<<endl;
            push_temp2();
            war=false;
        }
        else{
            cout<<"\nWAR"<<endl;
            war=true;
            FOR(i,0,3){
                if(p1.empty() || p2.empty()){
                    ans="PAT";
                    flag=true;
                    break;
                }
                temp1.push(p1.front());
                temp2.push(p2.front());
        
                p1.pop();
                p2.pop();
            }
        }
        
       if (p1.empty() && temp1.empty()){
         flag=true;
         cout<<"INSIDE ANS = 2"<<endl;
         ans='2';  
       } 
       else if(p2.empty() && temp2.empty()){
         flag=true;
         cout<<"INSIDE ANS = 2"<<endl;
         ans='1';
       }
    }
    if(ans=="PAT")
        cout<<ans<<endl;
    else
        cout <<ans<<' '<<turns<< endl;
}