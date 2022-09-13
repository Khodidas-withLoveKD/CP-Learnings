/******************************************
* AUTHOR : KHODIDAS CHAUHAN*
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

//int ans;
void solve()
{
    int extra, n, a, b, c, x;
    cin >> n >> a >> b >> c; cin.ignore();
    vector<int> v; v.reserve(n);

    extra = n - (a + b - c);

    if(extra < 0 || (a+b-c == 1 && n>=2)){//(c == 1 && ( extra < 0 || (a == 1 && b == 1 && extra >0)))){
    	cout<<"IMPOSSIBLE";
    	return;
    }
    //else if(c == 1 && )
    /*
    a -= c;
    b -= c;

    if(a > 0){
    	while(a--) v.pb(n-1);
    	while(extra--) v.pb(n-2);
    }
    while(c--) v.pb(n);
    if(b > 0){
    	while(extra > 0){ v.pb(n-2); extra--;}
    	while(b--) v.pb(n-1);
    }
    */
    //while(b--) v.pb(n-1);
    //------learnt from ecnerwala-------//
    for(int i=0; i<a-c; i++) v.pb(n-1);
    for(int i=0; i<c; i++) v.pb(n);
    for(int i=0; i<b-c; i++) v.pb(n-1);
    if(extra > 0)
    	v.insert(v.begin()+1, extra,n-2);		
    //if(v.size() != n){cout<<"IMPOSSIBLE"; return;}

    for(int i=0; i<v.size(); i++){
    	cout<<v[i];
    	if(i < v.size() - 1)
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
    
    int t=1, caser = 1;
    cin >> t;
    while(t--)
    {
        cout<<"Case #"<<caser++<<": ";
        solve();
        cout<<"\n";
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
return 0;
}
