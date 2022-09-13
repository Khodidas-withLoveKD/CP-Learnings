/******************************************
* AUTHOR : KHODIDAS CHAUHAN *
* NICK : with_Love_KD *
* INSTITUTION : NIRMA UNIVERSITY *
******************************************/

#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
using namespace std;


void solve()
{
    int n;
    //vector<ll> nums;
    ll x, sum=0, maxi = 0, k, ans;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        sum += x;
        maxi = max(maxi, x);
    }
    ll temp = ceil((float)sum/(n-1)); //cout<<"sum, tempi = "<<sum<<","<<temp<<endl;
    k = max(temp, maxi);
    ans = (n-1)*k - sum;
    cout<<ans;
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
