/******************************************
* AUTHOR : KHODIDAS CHAUHAN*
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define nl "\n"
using namespace std; 

bool sortq(pair<int, int> a,pair<int, int> b){
    return a.S < b.S;
}
void solve() 
{   
    int N, X, x;
    vector<pair<int, int> > q;
    cin >> N >> X;

    for(int i=0; i<N; i++){
        cin >> x;
        int rounds = ceil((float)x/X);
        q.pb(mp(i+1, rounds));
    }
    //sorting based on rounds
    sort(q.begin(), q.end(), sortq);
    for(int i=0; i<N; i++){
        cout<<q[i].F;
        if(i < N-1)
            cout<<" ";
    }
} 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 

    ll t;
    ll Case = 1;
    cin>>t; 
    while(t--) 
    { 
        //solve(); 
        cout<<"Case #"<<Case++<<": ";
         solve(); cout<<nl;//ans <<"\n"; 
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
}   