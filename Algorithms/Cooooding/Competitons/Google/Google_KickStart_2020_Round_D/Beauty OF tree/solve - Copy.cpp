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
using namespace std; 


ll N, A, B, V, num;
double ans;
vector<ll> *adj;

void calcProb(double aCount[], double bCount[], double prob[]){
    for(ll i=1; i<=N; i++){
        aCount[i] /= N;
        bCount[i] /= N;
        prob[i] = aCount[i] + bCount[i] - (aCount[i]*bCount[i]);
        ans += prob[i];
    }
}
void addEdge(int s, int d){
    adj[s].pb(d);
}

void DFSUtil(ll s, vector<bool> &visited, vector<ll> &pathTaken, double aCount[], double bCount[]){
    visited[s] = true;  //cout<<"visited["<<s<<"] = "<<visited[s]<<"\n";
    aCount[s] = 1;
    bCount[s] = 1;
    pathTaken.pb(s);

    //list<ll> :: iterator it;
    //DFS
    for(int d = 0; d < adj[s].size(); d++)
        if(visited[adj[s][d]] == false)
            DFSUtil(adj[s][d], visited, pathTaken, aCount, bCount);

    ll index = pathTaken.size() - 1;
    if(index - A >= 0)
        aCount[pathTaken[index - A]] += aCount[pathTaken[index]];
        
    if(index - B >= 0)
        bCount[pathTaken[index-B]] += bCount[pathTaken[index]];
    //pop the last element
    pathTaken.pop_back();
}
void DFS(ll s){
    double *aCount = new double[V];
    double *bCount = new double[V];
    double *prob = new double[V];
    vector<bool> visited(V, false);
    vector<ll> pathTaken;

    for(ll i=1; i<=N; i++)
        aCount[i] = bCount[i] = prob[i] = 0;

    DFSUtil(s, visited, pathTaken, aCount, bCount);
    //for(int i=0; i<visited.size(); i++)
        //cout<<"visited["<<i<<"] = "<<visited[i]<<"\n";

    calcProb(aCount, bCount, prob);
}
void solve() 
{     
    ans = 0;
    cin >> N >> A >> B;
    V = N+1;    // cout<<"V = "<<V<<"\n";
    adj = new vector<ll>[V];
    //cout<<"Below vector \n";
    //tree t(N);
    for(ll i=2; i<=N; i++){
        cin>>num;
        addEdge(num, i);
    }
    //for(int i=0; i<V; i++)
        //for(int j=0; j<adj[i].size(); j++)
            //cout<<"adj["<<i<<"]["<<j<<"] = "<<adj[i][j]<<"\n";
    DFS(1);
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