
/******************************************
* AUTHOR : KHODIDAS CHAUHAN*
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include<bits/stdc++.h>
typedef long long ll;
typedef double ld;
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std; 


ll N, A, B, num;
ld ans;//, WA, WB;//, aTotal, bTotal;

class tree{
    ll V;
    list<ll>* adj;
    void DFSUtil(ll s, bool visited[], vector<ll> &pathTaken, ld aCount[], ld bCount[]);
public:
    tree(ll V);
    void addEdge(ll s, ll d);
    void DFS(ll s);
};

void calcProb(ld aCount[], ld bCount[], ld prob[]){
    //Doing Probability calculation and
    //Taking weighted average
    for(ll i=1; i<=N; i++){
        prob[i] = aCount[i] + bCount[i] - (aCount[i]*bCount[i]);
        //WA += aCount[i]*i;
        //WB += bCount[i]*i;
        ans += prob[i];
    }
    //cout<<"WA = "<<WA<<" | WB = "<<WB<<"\n";
    //ans = WA + WB - (WA*WB);
    //cout<<"Sum[A] = "<<aTotal<<" | Sum[B] = "<<bTotal<<" | PA = "<<PA<<"\nPB = "<<PB<<" | ans = "<<ans<<"\n";
}
tree :: tree(ll V){
    this->V = V;
    V++;    //numbering is from 1 to N
    adj = new list<ll>[V];
}
void tree :: addEdge(ll s, ll d){
    adj[s].pb(d);
}
void printPath(vector<ll> pathTaken){
    //ll index = pathTaken.size() - 1;
    //for(ll i=0; i < pathTaken.size(); i++){
        //cout<<pathTaken[i]<<" ";
    //}
    //cout<<"\nindex = "<<index<<" pathTaken["<<index<<"] = "<<pathTaken[index]<<" \n";
}

void tree :: DFSUtil(ll s, bool visited[], vector<ll> &pathTaken, ld aCount[], ld bCount[]){
    visited[s] = true;
    aCount[s] = 1;
    bCount[s] = 1;
    pathTaken.pb(s);

    //cout<<"S = "<<s<<endl;
    list<ll> :: iterator it;
    //DFS
    for( it = adj[s].begin(); it != adj[s].end(); it++)
        if(visited[*it] != true)
            DFSUtil(*it, visited, pathTaken, aCount, bCount);
    //cout<<"------------\nExit DFS | S = "<<s<<"\n";
    ll index = pathTaken.size() - 1;
    printPath(pathTaken);
    cout<<" index = "<<index<<" | index-A = "<<index-A<<"\n";
    if(index - A >= 0){ 
        //cout<<"BEFORE | aCount["<<pathTaken[index-A]<<"] = "<<aCount[pathTaken[index - A]]<<"\n";
        aCount[pathTaken[index - A]] += aCount[pathTaken[index]]; 
        //cout<<"Inserted in "<<index- A<<" ketlu = "<<aCount[index]<<"\n";
        //cout<<"AFTER | aCount["<<pathTaken[index-A]<<"] = "<<aCount[pathTaken[index - A]]<<"\n";
    }
    if(index - B >= 0)
        bCount[pathTaken[index - B]] += bCount[pathTaken[index]];

    pathTaken.pop_back(); 
}
void tree :: DFS(ll s){
    bool *visited = new bool[V];
    ld *aCount = new ld[V];
    ld *bCount = new ld[V];
    ld *prob = new ld[V];
    memset(visited, false, V*sizeof(visited));
    memset(aCount, 0, V*sizeof(aCount));
    memset(bCount, 0 ,V*sizeof(bCount));
    memset(prob, 0, V*sizeof(prob));
    vector<ll> pathTaken;
    //cout<<"Above DFSUtil"<<endl;
    DFSUtil(s, visited, pathTaken, aCount, bCount);
    //aTotal = 0, bTotal = 0;

    for(ll i=1; i<=V; i++){
        //caculating probability
        cout<<"BEFORE aCount["<<i<<"] = "<<aCount[i]<<" | ";cout<<"bCount["<<i<<"] = "<<bCount[i]<<"\n ";
        aCount[i] = aCount[i]/N;    cout<<"aCount["<<i<<"] = "<<aCount[i]<<" | ";
        bCount[i] = bCount[i]/N;    cout<<"bCount["<<i<<"] = "<<bCount[i]<<"\n ";
    }
    calcProb(aCount, bCount, prob);
}
void solve() 
{     
    ans = 0;
    cin >> N >> A >> B;
    tree t(N);

    for(ll i=2; i<=N; i++){
        cin >> num;
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