/******************************************
* AUTHOR : KHODIDAS CHAUHAN*
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include<bits/stdc++.h>
typedef long long ll;
//typedef double D;
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std; 


ll N, A, B, num;
double ans;

class tree{
    ll V;
    list<ll>* adj;
    void DFSUtil(ll s, bool visited[], vector<ll> &pathTaken, double aCount[], double bCount[]);
public:
    tree(ll V);
    void addEdge(ll s, ll d);
    void DFS(ll s);
};
tree :: tree(ll V){
    this->V = V;
    V++;
    adj = new list<ll>[V];
}
void tree :: addEdge(ll s, ll d){
    adj[s].pb(d);
}
void calcProb(double aCount[], double bCount[], double prob[]){
    //cout<<N == V<<"\n"
    for(ll i=1; i<=N; i++){
        aCount[i] /= N;
        bCount[i] /= N;
        prob[i] = aCount[i] + bCount[i] - (aCount[i]*bCount[i]);
        ans += prob[i];
    }
}
void tree :: DFSUtil(ll s, bool visited[], vector<ll> &pathTaken, double aCount[], double bCount[]){
    visited[s] = true;
    aCount[s] = 1;
    bCount[s] = 1;
    pathTaken.pb(s);

    list<ll> :: iterator it;
    //DFS
    for(it = adj[s].begin(); it != adj[s].end(); it++)
        if(visited[*it] == false)
            DFSUtil(*it, visited, pathTaken, aCount, bCount);

    ll index = pathTaken.size() - 1;
    if(index - A >= 0)
        aCount[pathTaken[index - A]] += aCount[pathTaken[index]];
        
    if(index - B >= 0)
        bCount[pathTaken[index-B]] += bCount[pathTaken[index]];
    //pop the last element
    pathTaken.pop_back();
}
void tree :: DFS(ll s){
    bool *visited = new bool[V];
    double *aCount = new double[V];
    double *bCount = new double[V];
    double *prob = new double[V];
    vector<ll> pathTaken;   
    for(ll i=1; i<=N; i++){
        visited[i] = false;
        aCount[i] = bCount[i] = prob[i] = 0;
    }
    DFSUtil(s, visited, pathTaken, aCount, bCount);

    calcProb(aCount, bCount, prob);
}
void solve() 
{     
    ans = 0;
    cin >> N >> A >> B;
    tree t(N);
    for(ll i=2; i<=N; i++){
        cin>>num;
        t.addEdge(num, i);
    }
    t.DFS(1);
    
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
        solve(); 
        cout<<"Case #"<<Case++<<": "<< ans <<"\n"; 
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0; 
}   