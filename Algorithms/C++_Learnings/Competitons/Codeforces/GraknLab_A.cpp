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
#define nl "\n"
using namespace std;

void solve()
{
	int n, x, last;
    vector<int> a,b,c, ans;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        a.pb(x);
    }
    for(int i=0; i<n; i++){
        cin >> x;
        b.pb(x);
    }
    for(int i=0; i<n; i++){
        cin >> x;
        c.pb(x);
    }

    ans.pb(a[0]);
    last = a[0];
    for(int i=1; i<n-1; i++){
        if(a[i] != last){
            ans.pb(a[i]);
            last = a[i];
        }
        else if(b[i] != last){
            ans.pb(b[i]);
            last = b[i];
        }
        else{
            ans.pb(c[i]);
            last = c[i];
        }
    }
    if(a[n-1] != last && a[n-1] != ans[0])
        ans.pb(a[n-1]);
    else if(b[n-1] != last && b[n-1] != ans[0])
        ans.pb(b[n-1]);
    else
        ans.pb(c[n-1]);

    for(int i=0; i<n; i++){
        cout<<ans[i];
        if(i < n-1)
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

    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }

    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
return 0;
}
